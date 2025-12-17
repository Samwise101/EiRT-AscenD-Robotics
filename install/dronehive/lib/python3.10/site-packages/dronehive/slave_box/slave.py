#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from __future__ import annotations

import json
import os
from pathlib import Path
from typing import Optional, Tuple

import rclpy
from rclpy.executors import SingleThreadedExecutor
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
from rclpy.task import Future

from std_msgs.msg import String
from visualization_msgs.msg import Marker
from std_srvs.srv import SetBool

import dronehive.utils as dh

from dronehive_interfaces.msg import (
    BoxBroadcastMessage,
    BoxSetupConfirmationMessage,
    BoxStatusMessage,
)

from dronehive_interfaces.srv import (
    AddRemoveDroneService,
    BoxStatusService,
    BoxStatusSlaveUpdateService,
    DroneTrajectoryWaypointsService,
    RequestBoxOpenService,
    AddRemoveDroneService,
)

qos_profile = QoSProfile(
    reliability=QoSReliabilityPolicy.BEST_EFFORT,
    history=QoSHistoryPolicy.KEEP_LAST,
    depth=1,
)


# -----------------------------------------------------------------------------
# Config helpers (READ-ONLY)
# -----------------------------------------------------------------------------
def _find_config_path() -> Optional[Path]:
    """
    DroneHive configs are typically in one of:
      1) <XDG_CONFIG_HOME>/dronehive/config.json
      2) <XDG_CONFIG_HOME>/config.json
    We'll watch whichever exists.
    """
    xdg = os.environ.get("XDG_CONFIG_HOME", str(Path.home() / ".config"))
    root = Path(xdg)

    p1 = root / "dronehive" / "config.json"
    p2 = root / "config.json"
    if p1.is_file():
        return p1
    if p2.is_file():
        return p2
    return None


def _safe_read_json(path: Path) -> Optional[dict]:
    try:
        return json.loads(path.read_text())
    except Exception:
        return None


def _extract_pos(cfg: dict) -> Tuple[float, float, float]:
    pos = cfg.get("landing_position") or cfg.get("lending_position") or {}
    x = float(pos.get("lat", 0.0))
    y = float(pos.get("lon", 0.0))
    z = float(pos.get("elv", 0.0))
    return x, y, z


def _extract_drone_id(cfg: dict) -> str:
    return str(cfg.get("drone_id", "") or "")


def _resolve_close_service_name() -> str:
    """
    Your dh utils may not define DRONEHIVE_REQUEST_BOX_CLOSE_SERVICE.
    Resolve safely:
      - If constant exists, use it.
      - Else derive it from OPEN by replacing 'open' -> 'close'.
    """
    close_name = getattr(dh, "DRONEHIVE_REQUEST_BOX_CLOSE_SERVICE", None)
    if isinstance(close_name, str) and close_name:
        return close_name

    open_name = getattr(dh, "DRONEHIVE_REQUEST_BOX_OPEN_SERVICE", "")
    if not isinstance(open_name, str) or not open_name:
        # absolute fallback (won't crash, but you'll want to match your naming)
        return "/dronehive/request_box_close_service"

    # common case: "/dronehive/request_box_open_service" -> "/dronehive/request_box_close_service"
    return open_name.replace("open", "close")


# -----------------------------------------------------------------------------
# Slave node
# -----------------------------------------------------------------------------
class SlaveBoxNode(Node):
    """
    IMPORTANT DESIGN RULE (your requirement):
      - RViz colour is derived ONLY from config.json on disk.
      - Yellow  => config drone_id != ""
      - Grey    => config drone_id == ""
    This node does NOT infer occupancy from topics/services.
    """

    def __init__(self) -> None:
        # Load config first
        self.config: dh.Config = dh.dronehive_initialise()

        super().__init__(f"slave_box_node_{self.config.box_id}")

        # temp node for motor client
        self.temp_node: Node = Node(f"temp_node_for_clients_{self.config.box_id}")

        # --- Config file watcher (READ-ONLY source of truth for RViz) ---
        self.cfg_path = _find_config_path()
        if self.cfg_path is None:
            self.get_logger().warn("[Slave] Could not locate config.json on disk; RViz will use initial config only.")
        else:
            self.get_logger().info(f"[Slave] Watching config on disk: {self.cfg_path}")

        # Cached state used for marker (never written back to dh.Config)
        lp = self.config.landing_position
        self._x = float(lp.lat)
        self._y = float(lp.lon)
        self._z = float(lp.elv)
        self._occupied = bool(self.config.drone_id)

        # Timers: reload config -> publish marker
        self.reload_timer = self.create_timer(0.20, self._reload_config_from_disk)
        self.marker_pub = self.create_publisher(Marker, "/dronehive/box_markers", 10)
        self.marker_ns = f"box/slave/{self.config.box_id}"
        self.marker_id = 0
        self.marker_timer = self.create_timer(0.10, self._publish_marker)

        # --- Init handshake / interfaces (keep your existing behaviour) ---
        if not self.config.initialised:
            self.box_init_interfaces()
            self.get_logger().info(
                f"[Slave] Not initialised yet -> broadcasting init request. box_id={self.config.box_id}"
            )
            return

        self.initialise_connections()

    # ------------------------------------------------------------------
    # Init handshake
    # ------------------------------------------------------------------
    def box_init_interfaces(self) -> None:
        self.__init_publisher = self.create_publisher(
            BoxBroadcastMessage, dh.DRONEHIVE_INITIALISE_SLAVE_BOX_TOPIC, qos_profile
        )
        self.__timer = self.create_timer(2.0, self._publish_initialisation)
        self.__confirm_subs = self.create_subscription(
            BoxSetupConfirmationMessage,
            dh.DRONEHIVE_NEW_SLAVE_BOX_CONFIMED_TOPIC,
            self._initialisation_confirmed_callback,
            qos_profile,
        )

    def _publish_initialisation(self) -> None:
        msg = BoxBroadcastMessage()
        msg.box_id = self.config.box_id
        msg.landing_pos = self.config.landing_position
        self.get_logger().info(f"[Slave] Publishing initialisation message: {msg}")
        self.__init_publisher.publish(msg)

    def _initialisation_confirmed_callback(self, msg: BoxSetupConfirmationMessage) -> None:
        self.get_logger().info(f"[Slave] Received init confirmation: {msg}")
        if msg.box_id != self.config.box_id:
            return
        if not getattr(msg, "confirm", False):
            self.get_logger().warn(f"[Slave] Init for {msg.box_id} not confirmed.")
            return

        self.get_logger().info(f"[Slave] Initialisation confirmed for {self.config.box_id}")
        self.config.initialised = True
        self.config.landing_position = msg.landing_pos
        self.config.save()

        self.destroy_publisher(self.__init_publisher)
        self.destroy_timer(self.__timer)
        self.destroy_subscription(self.__confirm_subs)

        # refresh cached marker position from config
        lp = self.config.landing_position
        self._x, self._y, self._z = float(lp.lat), float(lp.lon), float(lp.elv)

        self.initialise_connections()

    # ------------------------------------------------------------------
    # Main connections
    # ------------------------------------------------------------------
    def initialise_connections(self) -> None:
        self.get_logger().info("[Slave] Initialising connections...")

        self.create_services()
        self.create_actions()

        self.client_manager = dh.ServiceClientManager(self, max_clients=32)
        self.get_logger().info(f"[Slave] Initialised with config: {self.config}")

        # publish initial status to master
        request = BoxStatusSlaveUpdateService.Request(
            status=BoxStatusMessage(
                landing_pos=self.config.landing_position,
                box_battery_level=100.0,
                box_id=self.config.box_id,
                drone_id=self.config.drone_id,
                status=(
                    dh.BoxStatusEnum.OCCUPIED.value
                    if self.config.drone_id != ""
                    else dh.BoxStatusEnum.EMPTY.value
                ),
            )
        )

        self.client_manager.call_async(
            BoxStatusSlaveUpdateService,
            dh.DRONEHIVE_BOX_STATUS_SLAVE_UPDATE_SERVICE,
            request,
            lambda fut: self.get_logger().info(
                f"[Slave] Status update response: {fut.result() if fut and fut.result() else 'Update failed'}"
            ),
        )

    # ------------------------------------------------------------------
    # Services (interface stays, but no config.drone_id mutations)
    # ------------------------------------------------------------------
    def create_services(self) -> None:
        # IMPORTANT: your system DOES have BOX_STATUS_REQUEST + OPEN
        self.create_service(
            BoxStatusService,
            dh.DRONEHIVE_BOX_STATUS_REQUEST_SERVICE,
            self.provide_box_status,
        )

        self.create_service(
            DroneTrajectoryWaypointsService,
            dh.DRONEHIVE_GUI_REQUEST_WAYPOINT_TRAJECTORY_SERVICE + f"_{self.config.box_id}",
            self.handle_trajectory_waypoints_request,
        )

        self.create_service(
            RequestBoxOpenService,
            dh.DRONEHIVE_REQUEST_BOX_OPEN_SERVICE + f"_{self.config.box_id}",
            self.handle_box_open_request,
        )

        # FIX: CLOSE constant missing -> resolve safely
        close_srv = _resolve_close_service_name()
        self.create_service(
            RequestBoxOpenService,
            close_srv + f"_{self.config.box_id}",
            self.handle_box_close_request,
        )

        self.create_service(
            AddRemoveDroneService,
            dh.DRONEHIVE_GUI_ADD_REMOVE_DRONE_SERVICE + f"_{self.config.box_id}",
            self.handle_add_remove_drone_request,
        )

    def create_actions(self) -> None:
        pass

    # ------------------------------------------------------------------
    # Service callbacks
    # ------------------------------------------------------------------
    def provide_box_status(
        self, request: BoxStatusService.Request, response: BoxStatusService.Response
    ) -> BoxStatusService.Response:
        if request.box_id != self.config.box_id:
            response.accept = False
            return response

        response.accept = True
        response.landing_pos = self.config.landing_position
        response.drone_id = "" if not self._occupied else self._last_drone_id
        return response

    def open_close_box_via_motor(self, open: bool) -> bool:
        client = self.temp_node.create_client(SetBool, f"/{self.config.box_id}/motor_1/open_box")
        if not client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn("[Slave] Motor service not available.")
            return False

        future: Future = client.call_async(SetBool.Request(data=open))
        exec_ = SingleThreadedExecutor()
        exec_.add_node(self.temp_node)
        exec_.spin_until_future_complete(future)
        exec_.shutdown()

        return bool(future.result() and future.result().success)

    def handle_trajectory_waypoints_request(
        self,
        request: DroneTrajectoryWaypointsService.Request,
        response: DroneTrajectoryWaypointsService.Response,
    ) -> DroneTrajectoryWaypointsService.Response:
        # Drone leaving -> clear occupancy

        response.ack = self.open_close_box_via_motor(open=True)
        return response

    def handle_box_open_request(
        self, request: RequestBoxOpenService.Request, response: RequestBoxOpenService.Response
    ) -> RequestBoxOpenService.Response:
        response.ack = self.open_close_box_via_motor(open=True)
        return response

    def handle_box_close_request(
        self, request: RequestBoxOpenService.Request, response: RequestBoxOpenService.Response
    ) -> RequestBoxOpenService.Response:
        response.ack = self.open_close_box_via_motor(open=False)
        return response

    def handle_add_remove_drone_request(
        self, request: AddRemoveDroneService.Request, response: AddRemoveDroneService.Response
    ) -> AddRemoveDroneService.Response:
        response.ack = True
        return response

    # ------------------------------------------------------------------
    # RViz: marker publishing (derived ONLY from cached disk state)
    # ------------------------------------------------------------------
    def _publish_marker(self) -> None:
        marker = Marker()
        marker.header.frame_id = "map"
        marker.header.stamp = self.get_clock().now().to_msg()

        marker.ns = self.marker_ns
        marker.id = self.marker_id
        marker.type = Marker.CUBE
        marker.action = Marker.ADD

        marker.pose.position.x = float(self._x)
        marker.pose.position.y = float(self._y)
        marker.pose.position.z = float(self._z) + 0.15
        marker.pose.orientation.w = 1.0

        marker.scale.x = 1.0
        marker.scale.y = 1.0
        marker.scale.z = 0.3

        marker.color.a = 0.8
        if self._occupied:
            marker.color.r = 1.0
            marker.color.g = 1.0
            marker.color.b = 0.0  # yellow
        else:
            marker.color.r = 0.5
            marker.color.g = 0.5
            marker.color.b = 0.5  # grey

        self.marker_pub.publish(marker)

    def _reload_config_from_disk(self) -> None:
        if self.cfg_path is None:
            return
        cfg = _safe_read_json(self.cfg_path)
        if not cfg:
            return

        cfg_box_id = str(cfg.get("box_id", "") or "")
        if cfg_box_id and cfg_box_id != self.config.box_id:
            return

        # Occupancy strictly from config file
        drone_id = _extract_drone_id(cfg)
        self._last_drone_id = drone_id
        self._occupied = bool(drone_id.strip())

        # Position strictly from config file
        x, y, z = _extract_pos(cfg)
        self._x, self._y, self._z = float(x), float(y), float(z)

        # (Optional) keep dh.Config landing_position in sync for other APIs
        # but do NOT touch config.drone_id here
        try:
            self.config.landing_position.lat = float(x)
            self.config.landing_position.lon = float(y)
            self.config.landing_position.elv = float(z)
        except Exception:
            pass


def main(args=None) -> None:
    rclpy.init(args=args)
    node = SlaveBoxNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        try:
            node.temp_node.destroy_node()
        except Exception:
            pass
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
