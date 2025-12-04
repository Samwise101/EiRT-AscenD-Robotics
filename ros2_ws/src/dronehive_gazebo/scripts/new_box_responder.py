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
import subprocess
import tempfile
import os
import yaml
import time
import re


class NewBoxSpawner(Node):
    """
    Listens for new box announcements and spawns a drone_box model in Gazebo.
    Each box is spawned once at given landing position with an offset of -0.90 m
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

        self.declare_parameter("offset", 1.0)
        self.offset = float(self.get_parameter("offset").value)

        pkg_share = self.get_package_share_directory("dronehive_gazebo")
        xacro_path = f"{pkg_share}/urdf/drone_box.xacro"

        # Generate URDF from xacro
        urdf_xml = xacro.process_file(xacro_path).toxml()

        # --- Sanitize URDF like the old launch file did --- 
        # 1) Remove XML declaration (first line / <?xml ...?>)
        urdf_xml = re.sub(r"<\?xml.*?\?>", "", urdf_xml, flags=re.DOTALL)

        # 2) Remove all comments <!-- ... -->
        urdf_xml = re.sub(r"<!--.*?-->", "", urdf_xml, flags=re.DOTALL)

        # 3) Remove newlines
        urdf_xml = urdf_xml.replace("\n", "")

        # Optional: trim stray whitespace
        urdf_xml = urdf_xml.strip()

        self.robot_description = urdf_xml
        self.controllers_yaml = f"{pkg_share}/config/drone_box_controllers.yaml"

        self._rsp_params: dict[str, str] = {}
        self._rsp_started: set[str] = set()

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

        # Ensure robot_state_publisher is running before spawning so the Gazebo
        # ros2_control plugin can fetch robot_description immediately.
        try:
            self._ensure_robot_state_publisher(entity_name)
            if not self._wait_for_rsp(timeout_sec=10.0):
                self.get_logger().error(
                    "robot_state_publisher services not detected; aborting spawn."
                )
                return
        except Exception as exc:
            self.get_logger().error(
                f"Failed to start robot_state_publisher for '{entity_name}': {exc}"
            )
            return

        self._spawn_box(entity_name, pose, self.robot_description)
        self._seen_ids.add(msg.box_id)

    def _spawn_box(self, name: str, pose: Pose, xml: str) -> None:
        req = SpawnEntity.Request()
        req.name = name
        req.xml = xml
        # Use the global namespace so the gazebo_ros2_control plugin can find the
        # robot_state_publisher and start controller_manager reliably.
        req.robot_namespace = ""
        req.initial_pose = pose

        with self._spawn_lock:
            if not self._spawn_cli.wait_for_service(timeout_sec=5.0):
                self.get_logger().error("Spawn service not available.")
                return
            future = self._spawn_cli.call_async(req)
        future.add_done_callback(lambda f, name=name: self._on_spawn_response(name, f))

    def _on_spawn_response(self, entity_name: str, future) -> None:
        try:
            resp = future.result()
        except Exception as exc:
            self.get_logger().error(f"Spawn service call failed: {exc}")
            return
        if resp.success:
            self.get_logger().info(f"Spawned entity: {resp.status_message}")
            self._spawn_controllers_async(entity_name)
        else:
            self.get_logger().error(f"Failed to spawn entity: {resp.status_message}")

    def _spawn_controllers_async(self, entity_name: str) -> None:
        thread = threading.Thread(
            target=self._spawn_controllers, args=(entity_name,), daemon=True
        )
        thread.start()

    def _spawn_controllers(self, entity_name: str) -> None:
        # Start controllers after controller_manager is available.
        manager_ns = self._wait_for_controller_manager(entity_name)
        if manager_ns is None:
            self.get_logger().error(
                f"controller_manager for '{entity_name}' not detected; skipping controller spawn."
            )
            return

        for controller in ("joint_state_broadcaster", "door_controller"):
            if not self._spawn_controller(entity_name, controller, manager_ns):
                return

        self.get_logger().info(
            f"Controllers ready for '{entity_name}'. Command via '/{entity_name}/door_controller/joint_trajectory'."
        )

    def _ensure_robot_state_publisher(self, entity_name: str) -> None:
        if entity_name in self._rsp_started:
            return

        params_file = self._rsp_params.get(entity_name)
        if params_file is None:
            params_file = self._write_robot_state_publisher_params(entity_name)
            self._rsp_params[entity_name] = params_file

        self._start_robot_state_publisher(entity_name, params_file)
        self._rsp_started.add(entity_name)

    def _write_robot_state_publisher_params(self, entity_name: str) -> str:
        """Write a temporary params file for robot_state_publisher with namespaced frames."""
        data = {
            "/**": {
                "ros__parameters": {
                    "robot_description": self.robot_description,
                    "frame_prefix": f"{entity_name}/",
                    "use_sim_time": True,
                }
            }
        }
        tmp_dir = tempfile.mkdtemp(prefix=f"{entity_name}_rsp_")
        params_path = os.path.join(tmp_dir, "params.yaml")
        with open(params_path, "w", encoding="utf-8") as handle:
            yaml.safe_dump(data, handle)
        return params_path

    def _prepare_entity_description(self, entity_name: str) -> str:
        """Return the shared robot_description (no per-entity rewrites)."""
        return self.robot_description

    def _start_robot_state_publisher(self, entity_name: str, params_file: str) -> None:
        # Run in the global namespace but keep frames unique via frame_prefix in params.
        cmd = [
            "ros2",
            "run",
            "robot_state_publisher",
            "robot_state_publisher",
            "--ros-args",
            "--params-file",
            params_file,
        ]
        subprocess.Popen(cmd)
        self.get_logger().info(
            f"Started robot_state_publisher for '{entity_name}' (global namespace, frame_prefix '{entity_name}/')."
        )

    def _wait_for_controller_manager(self, entity_name: str, timeout_sec: float = 30.0):
        """Poll for the controller_manager service; return its base name if found."""
        target = "/controller_manager/list_controllers"
        deadline = time.time() + timeout_sec
        while time.time() < deadline:
            services = self._list_services()
            if target in services:
                return "/controller_manager"
            time.sleep(0.5)
        return None

    def _list_services(self) -> set[str]:
        result = subprocess.run(
            ["ros2", "service", "list"], capture_output=True, text=True
        )
        if result.returncode != 0:
            return set()
        return set(line.strip().split()[0] for line in result.stdout.splitlines())

    def _wait_for_rsp(self, entity_name: str | None = None, timeout_sec: float = 10.0) -> bool:
        """Ensure robot_state_publisher parameter services exist before spawning (global RSP)."""
        needed = {
            "/robot_state_publisher/get_parameters",
            "/robot_state_publisher/describe_parameters",
        }
        deadline = time.time() + timeout_sec
        while time.time() < deadline:
            services = self._list_services()
            if needed.issubset(services):
                return True
            time.sleep(0.2)
        return False

    def _spawn_controller(
        self, entity_name: str, controller_name: str, manager_ns: str
    ) -> bool:
        env = os.environ.copy()
        env["ROS_NAMESPACE"] = f"/{entity_name}"
        cmd = [
            "ros2",
            "run",
            "controller_manager",
            "spawner",
            controller_name,
            "--controller-manager",
            f"{manager_ns}",
            "--controller-manager-timeout",
            "120",
            "--param-file",
            self.controllers_yaml,
        ]
        result = subprocess.run(cmd, capture_output=True, text=True, env=env)
        if result.returncode != 0:
            details = result.stderr.strip() or result.stdout.strip() or "No output."
            self.get_logger().error(
                f"Failed to spawn controller '{controller_name}' for '{entity_name}': {details}"
            )
            return False
        self.get_logger().info(
            f"Controller '{controller_name}' ready for '{entity_name}'."
        )
        return True


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
