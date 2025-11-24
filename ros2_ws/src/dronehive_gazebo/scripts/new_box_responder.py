#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy
from gazebo_msgs.srv import SpawnEntity
from geometry_msgs.msg import Pose
from dronehive_interfaces.msg import BoxBroadcastMessage
import dronehive.utils as dh
import xacro
import threading


class NewBoxSpawner(Node):
    """
    Listens for new box announcements and spawns a drone_box model in Gazebo.
    Each box is spawned once at given landing position with an offset of -0.45 m
    along the slide (+X) direction so the drone can land on the sliding panel.
    """

    def __init__(self) -> None:
        super().__init__("new_box_spawner")

        qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1,
            durability=QoSDurabilityPolicy.VOLATILE,
        )

        self.declare_parameter("offset", 0.45)
        self.offset = float(self.get_parameter("offset").value)

        pkg_share = self.get_package_share_directory("dronehive_gazebo")
        xacro_path = f"{pkg_share}/urdf/drone_box.xacro"
        urdf_xml = xacro.process_file(xacro_path).toxml()
        self.robot_description = urdf_xml.replace("\n", "")

        self._seen_ids: set[str] = set()
        self._spawn_cli = self.create_client(SpawnEntity, "/spawn_entity")
        self._spawn_lock = threading.Lock()

        self._new_box_sub = self.create_subscription(
            BoxBroadcastMessage,
            dh.DRONEHIVE_NEW_BOX_TOPIC,
            self._on_new_box,
            qos_profile,
        )

        self.get_logger().info(
            f"NewBoxSpawner ready. Subscribing to {dh.DRONEHIVE_NEW_BOX_TOPIC}, "
            f"spawning boxes with offset {self.offset} m along -X from landing_pos."
        )

    def get_package_share_directory(self, pkg_name: str) -> str:
        import ament_index_python.packages as pkg
        return pkg.get_package_share_directory(pkg_name)

    def _on_new_box(self, msg: BoxBroadcastMessage) -> None:
        if msg.box_id in self._seen_ids:
            self.get_logger().debug(f"Ignoring duplicate box_id '{msg.box_id}'")
            return

        # Map PositionMessage -> world pose; offset drone landing point by -X
        pose = Pose()
        pose.position.x = msg.landing_pos.lat - self.offset
        pose.position.y = msg.landing_pos.lon
        pose.position.z = msg.landing_pos.elv
        pose.orientation.w = 1.0

        entity_name = f"box_{msg.box_id}"
        self.get_logger().info(
            f"Spawning box '{entity_name}' at "
            f"x={pose.position.x:.2f}, y={pose.position.y:.2f}, z={pose.position.z:.2f}"
        )
        self._spawn_box(entity_name, pose)
        self._seen_ids.add(msg.box_id)

    def _spawn_box(self, name: str, pose: Pose) -> None:
        req = SpawnEntity.Request()
        req.name = name
        req.xml = self.robot_description
        req.robot_namespace = name
        req.initial_pose = pose

        with self._spawn_lock:
            if not self._spawn_cli.wait_for_service(timeout_sec=5.0):
                self.get_logger().error("Spawn service not available.")
                return
            future = self._spawn_cli.call_async(req)
        future.add_done_callback(self._on_spawn_response)

    def _on_spawn_response(self, future) -> None:
        try:
            resp = future.result()
        except Exception as exc:
            self.get_logger().error(f"Spawn service call failed: {exc}")
            return
        if resp.success:
            self.get_logger().info(f"Spawned entity: {resp.status_message}")
        else:
            self.get_logger().error(f"Failed to spawn entity: {resp.status_message}")


def main() -> None:
    rclpy.init()
    node = NewBoxSpawner()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
