#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Pure ROS2 simulated offboard drone node (no MAVROS / PX4 / QGC).

- Each instance represents one drone, identified by --drone-id.
- Starts at a given altitude and flies a horizontal circle.
- Publishes its pose as an RViz sphere marker.
- When its landing service is called, it asks the master for a landing pose
  (/dronehive/drone_land_request) and "flies" there, then stops.

Usage example:
  ros2 run offboard offboard_sim \
    --drone-id drone01 \
    --start-x 0.0 --start-y 0.0 --altitude 2.0

Then to trigger landing:
  ros2 service call /dronehive/sim_drone_land_drone01 std_srvs/srv/SetBool "{data: true}"
"""

import math
import argparse
from enum import Enum

import numpy as np
import rclpy
from rclpy.node import Node

from std_srvs.srv import SetBool
from visualization_msgs.msg import Marker

from dronehive_interfaces.srv import DroneLandingService
from dronehive_interfaces.msg import PositionMessage, DroneStatusMessage


class FlightState(Enum):
    CIRCLE = 0
    REQUEST_LANDING = 1
    LANDING = 2
    LANDED = 3


class SimOffboard(Node):
    def __init__(
        self,
        drone_id: str,
        start_x: float = 0.0,
        start_y: float = 0.0,
        altitude: float = 2.0,
        circle_radius: float = 2.0,
        circle_speed: float = 0.3,
        landing_speed: float = 0.5,
        publish_hz: float = 50.0,
    ) -> None:
        super().__init__(f"sim_offboard_{drone_id}")

        # --- Parameters / state ---
        self.drone_id = drone_id
        self.center = np.array([start_x, start_y], dtype=float)
        self.altitude = float(altitude)
        self.radius = float(circle_radius)
        self.omega = float(circle_speed)       # rad/s (angular speed)
        self.landing_speed = float(landing_speed)
        self.dt = 1.0 / float(publish_hz)

        self.state = FlightState.CIRCLE
        self.angle = 0.0
        # Start on the circle at (center.x + r, center.y, altitude)
        self.position = np.array([start_x + circle_radius, start_y, altitude], dtype=float)
        self.target_pos = None  # landing goal (x, y, z)

        # --- ROS I/O ---

        # Talk to master box to get landing pose (same as original offboard) :contentReference[oaicite:3]{index=3}
        self.landing_client = self.create_client(
            DroneLandingService,
            "/dronehive/drone_land_request"
        )

        # Per-drone service to trigger landing with a boolean flag
        self.landing_trigger_srv = self.create_service(
            SetBool,
            f"/dronehive/sim_drone_land_{self.drone_id}",
            self._handle_landing_trigger,
        )

        # RViz marker publisher – all drones share this topic, IDs in Marker.id
        self.marker_pub = self.create_publisher(
            Marker, "/dronehive/drone_markers", 10
        )

        # Status publisher – topic pattern matches what MasterBoxNode expects :contentReference[oaicite:4]{index=4}
        self.status_pub = self.create_publisher(
            DroneStatusMessage,
            f"/dronehive/drone_status_{self.drone_id}",
            10,
        )

        # Main timer driving the “physics”
        self.timer = self.create_timer(self.dt, self._timer_cb)

        self.get_logger().info(
            f"SimOffboard started for '{self.drone_id}' at "
            f"({self.position[0]:.2f}, {self.position[1]:.2f}, {self.position[2]:.2f})"
        )

    # ------------------------------------------------------------------
    # Service: trigger landing
    # ------------------------------------------------------------------
    def _handle_landing_trigger(
        self, request: SetBool.Request, response: SetBool.Response
    ) -> SetBool.Response:
        if not request.data:
            self.get_logger().info("Landing trigger received with 'false' – ignoring.")
            response.success = True
            response.message = "Landing not started (request.data == false)."
            return response

        if self.state in (
            FlightState.REQUEST_LANDING,
            FlightState.LANDING,
            FlightState.LANDED,
        ):
            self.get_logger().info(
                f"Landing already in progress / done (state={self.state.name})."
            )
            response.success = False
            response.message = f"Landing already in state {self.state.name}."
            return response

        if not self.landing_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().warn(
                "Landing service '/dronehive/drone_land_request' not available."
            )
            response.success = False
            response.message = "Landing service not available."
            return response

        # Build request just like the real offboard node :contentReference[oaicite:5]{index=5}
        req = DroneLandingService.Request()
        req.drone_id = self.drone_id

        pm = PositionMessage()
        pm.lat = float(self.position[0])
        pm.lon = float(self.position[1])
        pm.elv = float(self.position[2])
        req.drone_pos = pm

        self.get_logger().info(
            f"Requesting landing position from master for drone '{self.drone_id}' "
            f"at ({pm.lat:.2f}, {pm.lon:.2f}, {pm.elv:.2f})"
        )

        future = self.landing_client.call_async(req)
        future.add_done_callback(self._landing_response_cb)

        self.state = FlightState.REQUEST_LANDING
        response.success = True
        response.message = "Landing request sent to master."
        return response

    def _landing_response_cb(self, future):
        try:
            resp = future.result()
        except Exception as e:  # noqa: BLE001
            self.get_logger().error(f"Landing service call failed: {e}")
            self.state = FlightState.CIRCLE
            return

        if resp is None or resp.landing_pos is None:
            self.get_logger().warn(
                "Landing response invalid (no landing_pos). Staying in CIRCLE."
            )
            self.state = FlightState.CIRCLE
            return

        lp = resp.landing_pos
        self.target_pos = np.array([lp.lat, lp.lon, lp.elv], dtype=float)
        self.get_logger().info(
            f"Landing target received for '{self.drone_id}': "
            f"({self.target_pos[0]:.2f}, {self.target_pos[1]:.2f}, {self.target_pos[2]:.2f})"
        )
        self.state = FlightState.LANDING

    # ------------------------------------------------------------------
    # Main loop
    # ------------------------------------------------------------------
    def _timer_cb(self):
        if self.state == FlightState.CIRCLE:
            self._update_circle()
        elif self.state == FlightState.LANDING:
            self._update_landing()
        # REQUEST_LANDING and LANDED just keep last pose

        self._publish_marker()
        self._publish_status()

    def _update_circle(self):
        """Simple circular motion around self.center at fixed altitude."""
        self.angle = (self.angle + self.omega * self.dt) % (2.0 * math.pi)
        x = self.center[0] + self.radius * math.cos(self.angle)
        y = self.center[1] + self.radius * math.sin(self.angle)
        z = self.altitude
        self.position[:] = [x, y, z]

    def _update_landing(self):
        """Move in a straight line towards target_pos with constant speed."""
        if self.target_pos is None:
            # Shouldn't happen, but be defensive
            self.get_logger().warn(
                "Landing state but no target_pos – reverting to CIRCLE."
            )
            self.state = FlightState.CIRCLE
            return

        vec = self.target_pos - self.position
        dist = float(np.linalg.norm(vec))

        # Close enough → snap to target & mark as landed
        if dist < 0.05:
            self.position[:] = self.target_pos
            if self.position[2] <= self.target_pos[2] + 0.05:
                self.state = FlightState.LANDED
                self.get_logger().info(f"Drone '{self.drone_id}' landed at target.")
            return

        step = self.landing_speed * self.dt
        if step > dist:
            step = dist

        direction = vec / (dist + 1e-6)  # avoid division by zero
        self.position[:] = self.position + direction * step

    # ------------------------------------------------------------------
    # Publishers
    # ------------------------------------------------------------------
    def _publish_marker(self):
        marker = Marker()
        marker.header.frame_id = "map"
        marker.header.stamp = self.get_clock().now().to_msg()

        # UNIQUE per-drone namespace
        marker.ns = f"drone/{self.drone_id}"
        marker.id = 0 

        marker.type = Marker.SPHERE
        marker.action = Marker.ADD

        marker.pose.position.x = float(self.position[0])
        marker.pose.position.y = float(self.position[1])
        marker.pose.position.z = float(self.position[2])

        marker.pose.orientation.w = 1.0

        marker.scale.x = 0.3
        marker.scale.y = 0.3
        marker.scale.z = 0.3

        # Deterministic color from drone_id
        hue = (abs(hash(self.drone_id)) % 360) / 360.0
        r, g, b = self._hsv_to_rgb(hue, 0.8, 1.0)
        marker.color.a = 1.0
        marker.color.r = float(r)
        marker.color.g = float(g)
        marker.color.b = float(b)

        self.marker_pub.publish(marker)

    def _publish_status(self):
        """Publish a simplified DroneStatusMessage so the master can still use it."""
        msg = DroneStatusMessage()
        msg.drone_id = self.drone_id
        msg.battery_voltage = 16.0
        msg.battery_percentage = 100.0
        msg.fligt_state = self.state.name  # note: field is 'fligt_state' in your code :contentReference[oaicite:6]{index=6}

        pos = PositionMessage()
        pos.lat = float(self.position[0])
        pos.lon = float(self.position[1])
        pos.elv = float(self.position[2])
        msg.current_position = pos

        # You can use this flag in the master for "box close" or similar logic.
        msg.reached_first_waypoint = (self.state == FlightState.LANDED)

        self.status_pub.publish(msg)

    # Simple HSV → RGB helper (local, no extra deps)
    @staticmethod
    def _hsv_to_rgb(h: float, s: float, v: float):
        import colorsys

        return colorsys.hsv_to_rgb(h, s, v)


def main():
    parser = argparse.ArgumentParser(
        description="Pure ROS2 simulated offboard drone node."
    )
    parser.add_argument(
        "--drone-id", type=str, required=True, help="Unique drone identifier."
    )
    parser.add_argument(
        "--start-x",
        type=float,
        default=0.0,
        help="Initial X position / circle center X.",
    )
    parser.add_argument(
        "--start-y",
        type=float,
        default=0.0,
        help="Initial Y position / circle center Y.",
    )
    parser.add_argument(
        "--altitude", type=float, default=2.0, help="Hover altitude in meters."
    )
    parser.add_argument(
        "--circle-radius", type=float, default=2.0, help="Circle radius in meters."
    )
    parser.add_argument(
        "--circle-speed",
        type=float,
        default=0.3,
        help="Angular speed (rad/s) around the circle.",
    )
    parser.add_argument(
        "--landing-speed",
        type=float,
        default=0.5,
        help="Landing translation speed (m/s).",
    )
    parser.add_argument(
        "--publish-hz",
        type=float,
        default=50.0,
        help="Publish / simulation update rate.",
    )

    args, unknown = parser.parse_known_args()

    rclpy.init(args=unknown)
    node = SimOffboard(
        drone_id=args.drone_id,
        start_x=args.start_x,
        start_y=args.start_y,
        altitude=args.altitude,
        circle_radius=args.circle_radius,
        circle_speed=args.circle_speed,
        landing_speed=args.landing_speed,
        publish_hz=args.publish_hz,
    )

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down sim offboard node.")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
