#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Unified Landing Control Node
-----------------------------
Requests a landing position from the master box (`/dronehive/drone_land_request`)
and lands at the received coordinates (master or slave box).

Usage:
  Simulation:
    ros2 run offboard offboard --simulation --drone-id drone69
  Real system:
    ros2 run offboard offboard --drone-id drone69
"""

import math
import time
import argparse
from enum import Enum

import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from rclpy.qos import (
    QoSProfile,
    QoSReliabilityPolicy,
    QoSHistoryPolicy,
)

from geometry_msgs.msg import PoseStamped
from mavros_msgs.msg import State
from mavros_msgs.srv import SetMode
from std_msgs.msg import Bool

from dronehive_interfaces.srv import (
    DroneTrajectoryWaypointsService,
)

from dronehive_interfaces.msg import (
    PositionMessage,
)

qos_profile = QoSProfile(
    reliability=QoSReliabilityPolicy.BEST_EFFORT,
    history=QoSHistoryPolicy.KEEP_LAST,
    depth=1
)

# ---------------------- helpers ---------------------------------

def quat_to_euler(q):
    # roll (x-axis rotation)
    sinr_cosp = 2 * (q.w * q.x + q.y * q.z)
    cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y)
    if hasattr(np, 'arctan2'):
        roll = np.arctan2(sinr_cosp, cosr_cosp)
    else:
        roll = np.atan2(sinr_cosp, cosr_cosp)

    # pitch (y-axis rotation)
    sinp = np.sqrt(1 + 2 * (q.w * q.y - q.x * q.z))
    cosp = np.sqrt(1 - 2 * (q.w * q.y - q.x * q.z))
    if hasattr(np, 'arctan2'):
        pitch = 2 * np.arctan2(sinp, cosp) - np.pi / 2
    else:
        pitch = 2 * np.atan2(sinp, cosp) - np.pi / 2

    # yaw (z-axis rotation)
    siny_cosp = 2 * (q.w * q.z + q.x * q.y)
    cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
    if hasattr(np, 'arctan2'):
        yaw = np.arctan2(siny_cosp, cosy_cosp)
    else:
        yaw = np.atan2(siny_cosp, cosy_cosp)

    return roll, pitch, yaw


def yaw_to_quaternion(yaw_rad: float):
    qz = math.sin(yaw_rad / 2.0)
    qw = math.cos(yaw_rad / 2.0)
    return (0.0, 0.0, qz, qw)


def cubic_coeffs_from_boundary(p0, p1, v0, a0, T):
    c0 = p0
    c1 = v0
    c2 = a0 / 2.0
    c3 = (p1 - (c0 + c1*T + c2*T**2)) / (T**3)
    return np.array([c0, c1, c2, c3], dtype=float)


def eval_cubic(coeffs, t):
    c0, c1, c2, c3 = coeffs
    p = c0 + c1*t + c2*t**2 + c3*t**3
    v = c1 + 2*c2*t + 3*c3*t**2
    a = 2*c2 + 6*c3*t
    return p, v, a


# ---------------------- Flight State Enum ----------------------------------

class FlightState(Enum):
    INIT = 0
    WAIT_ARM = 1
    WAIT_OFFBOARD = 2
    EXECUTE_TRAJ = 3
    REQUEST_LANDING = 4
    DONE = 5


# ---------------------- State base class -----------------------------------

class BaseState:
    """
    Base class for all flight states.

    Subclasses override init(), run(), and deinit() as needed.
    - init()   is called once when the state is first entered.
    - run()    is called every timer tick while in this state.
    - deinit() is called once when the state is exited.
    """

    def __init__(self, node: "LandingControl"):
        self.node = node
        self._initialized = False

    def tick(self):
        """Called by the timer. Handles the init/run lifecycle."""
        if not self._initialized:
            self.init()
            self._initialized = True
        self.run()

    def reset(self):
        """Call this before re-entering a state so init() fires again."""
        self._initialized = False

    def exit(self):
        """Call this when leaving the state."""
        self.deinit()
        self._initialized = False

    # ---- override in subclasses ----

    def init(self):
        pass

    def run(self):
        pass

    def deinit(self):
        pass


# ---------------------- Concrete state classes ----------------------------

class InitState(BaseState):
    """
    Waits until a valid pose is available, then transitions to WAIT_ARM.
    """

    def run(self):
        if not self.node.have_pose:
            self.node._publish_hold_here()
            return
        self.node.get_logger().info("State -> WAIT_ARM (real)")
        self.node.transition_to(FlightState.WAIT_ARM)


class WaitArmState(BaseState):
    """
    Waits until MAVROS reports the vehicle as armed.
    """

    def run(self):
        if self.node._is_armed():
            if self.node.home_xy is None:
                self.node.home_xy = self.node.curr_xyzw[:2].copy()

            if self.node.home_alt0 is None:
                self.node.home_alt0 = float(self.node.curr_xyzw[2])

            self.node.get_logger().info("Operator set ARMED. Waiting for OFFBOARD...")
            self.node.transition_to(FlightState.WAIT_OFFBOARD)


class WaitOffboardState(BaseState):
    """
    Holds position and waits until OFFBOARD mode is active and waypoints are ready.
    """

    def init(self):
        # hold_position will be captured on the first call to _publish_hold_here
        self.node.hold_position = None

    def run(self):
        self.node._publish_hold_here()

        if not self.node._is_armed():
            self.node.get_logger().info("Disarmed, returning to WAIT_ARM.")
            self.node.transition_to(FlightState.WAIT_ARM)
            return

        if self.node._is_offboard() and self.node.waypoints_ready:
            self.node.get_logger().info("Waypoints ready. Planning and executing trajectory.")
            self.node._plan_trajectory()
            self.node.traj_t0_wall = time.time()
            self.node.position_tolerance = 0.3
            self.node.transition_to(FlightState.EXECUTE_TRAJ)


class RequestLandingState(BaseState):
    """
    Holds position while setting up a landing trajectory back to the starting position,
    then transitions to EXECUTE_TRAJ.
    """

    def init(self):
        # Capture hold position once on entry so we don't drift during setup
        self.node.hold_position = None

    def run(self):
        self.node._publish_hold_here()

        now = time.time()
        self.node.get_logger().info(f"Using starting position for landing: {self.node.starting_position}")

        landing = PositionMessage()
        landing.x = float(self.node.starting_position[0])
        landing.y = float(self.node.starting_position[1])
        landing.z = float(self.node.starting_position[2])
        landing.yaw = float(self.node.starting_position[3])

        self.node.setup_waypints([landing])

        self.node.landing_target = np.array(
            [float(landing.x), float(landing.y), float(landing.z) + 0.05, float(landing.yaw)],
            dtype=float,
        )

        self.node.isLanding = True
        self.node._plan_landing_traj()

        self.node.traj_t0_wall = now
        self.node.position_tolerance = 0.1
        self.node.hold_position = None

        self.node.get_logger().info("Landing target received. Executing landing trajectory.")
        self.node.transition_to(FlightState.EXECUTE_TRAJ)


class ExecuteTrajState(BaseState):
    """
    Follows a pre-planned cubic trajectory segment by segment.
    When all segments are done:
      - if landing -> DONE
      - otherwise  -> REQUEST_LANDING
    """

    def init(self):
        self.seg_t0_wall = time.time()
        self.now = time.time()
        self.node.get_logger().info("ExecuteTrajState: trajectory started.")

    def run(self):
        node = self.node

        if node.current_segment_idx >= len(node.traj_segments):
            # All segments completed
            node.get_logger().info("All trajectory segments completed, holding last position.")
            node._publish_xyz(
                node.last_requested_pose[0],
                node.last_requested_pose[1],
                node.last_requested_pose[2],
                node.last_requested_pose[3],
            )
            node.waypoints_ready = False

            if node.isLanding:
                node.get_logger().info("Landing trajectory complete, drone is landing.")
                node._publish_hold_here()
                node.transition_to(FlightState.DONE)
            else:
                node.get_logger().info(
                    "Reached end of trajectory, holding and requesting landing position."
                )
                node._publish_hold_here()
                node.transition_to(FlightState.REQUEST_LANDING)
            return

        coeffs_x, coeffs_y, coeffs_z, coeffs_yaw = node.traj_segments[node.current_segment_idx]
        T = node.segment_times[node.current_segment_idx]

        t_in_seg = self.now - self.seg_t0_wall
        if t_in_seg > T:
            t_in_seg = T

        px, _, _ = eval_cubic(coeffs_x, t_in_seg)
        py, _, _ = eval_cubic(coeffs_y, t_in_seg)
        pz, _, _ = eval_cubic(coeffs_z, t_in_seg)
        pyaw, _, _ = eval_cubic(coeffs_yaw, t_in_seg)
        node.last_requested_pose = np.array([px, py, pz, pyaw], dtype=float)

        node._publish_xyz(px, py, pz, pyaw)

        node.get_logger().info(
            f"Generating setpoint for segment {node.current_segment_idx} "
            f"at t={t_in_seg}/{T}, pos=({px}, {py}, {pz}), yaw={pyaw}"
        )

        target_point = np.array([px, py, pz, pyaw])
        dist = np.linalg.norm(target_point - node.curr_xyzw)
        node.get_logger().info(f"Seg {node.current_segment_idx}: dist={dist}")

        print(
            f"Curr: {node.curr_xyzw[0]} {node.curr_xyzw[1]} {node.curr_xyzw[2]} "
            f"target: {px} {py} {pz} T: {T} now: {self.now} t_in_seg: {t_in_seg}"
        )

        if dist < node.position_tolerance:
            if node.current_segment_idx + 1 >= len(node.traj_segments):
                self.now += 0.05
                node.position_tolerance = 0.1
            else:
                self.now += 0.1

            if t_in_seg >= T:
                node.current_segment_idx += 1
                self.seg_t0_wall = time.time()
                self.now = time.time()
                node.get_logger().info(
                    f"Segment {node.current_segment_idx} reached, moving to next."
                )


class DoneState(BaseState):
    """
    Mission complete. Resets all state and returns to WAIT_ARM.
    """

    def run(self):
        self.node.get_logger().info("Mission complete. Resetting.")
        self.node._reset_all()
        self.node.transition_to(FlightState.WAIT_ARM)


# ---------------------- node ----------------------------------

class LandingControl(Node):
    def __init__(self,
                 publish_hz: float = 60.0):
        super().__init__('landing_control')

        self.publish_dt = 1.0 / float(publish_hz)
        self.landing_box_id: str = ""
        self.landing_future = None

        # ---------------- ROS I/O ----------------
        self.pub_sp = self.create_publisher(PoseStamped, '/mavros/setpoint_position/local', 10)
        self.create_subscription(State, '/mavros/state', self._state_cb, 10)
        self.create_subscription(PoseStamped, '/mavros/local_position/pose', self._pose_cb, qos_profile_sensor_data)
        self.create_subscription(Bool, "/dronehive/pause_trajectory", self._pause_trajectory_execution_cb, qos_profile)

        cli_mode = self.create_client(SetMode, '/mavros/set_mode')
        self.create_service(DroneTrajectoryWaypointsService, f"/dronehive/drone_waypoints", self.waypoint_service_cb)

        # Wait for MAVROS
        self.get_logger().info("Waiting for MAVROS services...")
        cli_mode.wait_for_service()
        self.get_logger().info("MAVROS services available.")

        # ---------------- Flight data ----------------
        self.mav_state = State()
        self.have_pose = False
        self.curr_xyzw = np.zeros(4)
        self.curr_heading = np.zeros(3)  # roll, pitch, yaw
        self.home_xy = None
        self.home_alt0 = None
        self.last_requested_pose = np.zeros(3)
        self.hold_position = None
        self.pause_trajectory = False

        # Landing
        self.landing_target: np.ndarray | None = None
        self.isLanding = False

        # Trajectory
        self.traj_segments = []
        self.segment_times = []
        self.traj_total_T = 0.0
        self.traj_t0_wall: float | None = None
        self.r_waypoints = []
        self.waypoints_ready = False

        # Pre-allocate SP
        self.sp = PoseStamped()
        self.sp.header.frame_id = 'map'
        _, _, qz, qw = yaw_to_quaternion(0.0)
        self.sp.pose.orientation.z = qz
        self.sp.pose.orientation.w = qw

        self.current_segment_idx = 0
        self.position_tolerance = 0.3

        # ---------------- State machine ----------------
        self._state_map: dict[FlightState, BaseState] = {
            FlightState.INIT:            InitState(self),
            FlightState.WAIT_ARM:        WaitArmState(self),
            FlightState.WAIT_OFFBOARD:   WaitOffboardState(self),
            FlightState.REQUEST_LANDING: RequestLandingState(self),
            FlightState.EXECUTE_TRAJ:    ExecuteTrajState(self),
            FlightState.DONE:            DoneState(self),
        }
        self._current_flight_state = FlightState.INIT
        self._active_state: BaseState = self._state_map[self._current_flight_state]

        # Timers
        self.timer = self.create_timer(self.publish_dt, self._timer_cb)

    # -------------------- State machine helpers --------------------

    def transition_to(self, new_state: FlightState):
        """
        Exit the current state and enter the new one.
        """
        self._active_state.exit()
        self._current_flight_state = new_state
        self._active_state = self._state_map[new_state]
        self._active_state.reset()  # ensure init() fires on next tick

    # -------------------- HELPERS --------------------

    def setup_waypints(self, waypoints):
        """
        Make sure waypoints are in the expected format and store them for trajectory planning.

        Args:
            waypoints (list[PositionMessage]): List of waypoints received from the waypoint service, each containing x, y, z,
            and yaw fields.
        """
        self.r_waypoints = waypoints
        self.waypoints_ready = True
        self.hold_position = None  # reset hold position
        self.current_segment_idx = 0
        self.get_logger().info(f"Received {len(self.r_waypoints)} waypoints from waypoint service: {self.r_waypoints}")
        self.get_logger().info(f"Waypoints ready: {self.waypoints_ready}")


    # -------------------- Callbacks --------------------

    def _state_cb(self, msg: State):
        """
        Mavros state callback to keep track of arming and mode status for state transitions.

        Args:
            msg: Mavros State message containing current arming and mode information.
        """
        self.mav_state = msg


    def _pose_cb(self, msg: PoseStamped):
        """
        Mavros local position callback to update current pose and heading information.

        Args:
            msg: PoseStamped message containing current local position and orientation of the drone.
        """
        self.have_pose = True

        self.curr_heading = quat_to_euler(msg.pose.orientation)

        self.curr_xyzw = np.array(
            [msg.pose.position.x, msg.pose.position.y, msg.pose.position.z, self.curr_heading[2]], dtype=float
        )

        if self.home_alt0 is None:
            self.home_alt0 = float(self.curr_xyzw[2])


    def waypoint_service_cb(
        self,
        request: DroneTrajectoryWaypointsService.Request,
        response: DroneTrajectoryWaypointsService.Response
    ) -> DroneTrajectoryWaypointsService.Response:
        """
        Offboard service callback to receive waypoints from the master box and prepare for trajectory execution.

        Args:
            request (DroneTrajectoryWaypointsService.Request): Service request containing a list of waypoints
            (PositionMessage) for the drone to follow.
            response (DroneTrajectoryWaypointsService.Response): Service response to acknowledge receipt of waypoints and
            readiness for trajectory execution.

        Returns:
            DroneTrajectoryWaypointsService.Response: Service response indicating acknowledgment and readiness status.
        """
        self.get_logger().info(f"Waypoint service called with waypoints: {request.waypoints}")
        if request.waypoints is not None:
            self.setup_waypints(request.waypoints)
            response.ack = True
        return response


    def _pause_trajectory_execution_cb(self, msg: Bool):
        """
        Callback to handle pause/resume commands for trajectory execution.

        Args:
            msg: Bool message indicating whether to pause (True) or resume (False) trajectory execution.
        """
        self.pause_trajectory = msg.data
        self.hold_position = None
        state_str = "Resuming" if msg.data else "Pausing"
        self.get_logger().info(f"Toggle execution {state_str} command received.")


    # -------------------- Main Timer --------------------

    def _timer_cb(self):
        """
        Main loop – delegates entirely to the active state object.
        """
        if self.pause_trajectory:
            self._publish_hold_here()
            self.get_logger().info("Control paused, holding position.")
            return

        self._active_state.tick()


    # -------------------- Trajectory planning & execution --------------------

    def _calculate_trajectory_coefficients(self, waypoints: list[np.ndarray]):
        """
        Helper function to calculate cubic trajectory coefficients for a list of waypoints.

        Args:
            waypoints: List of waypoints (numpy arrays of shape (4,)) representing the desired positions and yaw angles
        """
        self.current_segment_idx = 0
        self.traj_segments.clear()
        self.segment_times.clear()

        total_T = 0.0
        v0 = np.zeros(len(waypoints[0]))
        a0 = np.zeros(len(waypoints[0]))

        for i in range(len(waypoints) - 1):
            A = waypoints[i]
            B = waypoints[i + 1]
            d = float(np.linalg.norm(B - A))
            T = max(1.0, d / 0.5)

            self.get_logger().info(f"Planning segment {i}: from {A} to {B}, distance={d} m, time={T} s")
            coeffs_xyzw = []
            for axis in range(len(A)):
                coeffs = cubic_coeffs_from_boundary(A[axis], B[axis], v0[axis], a0[axis], T)
                coeffs_xyzw.append(coeffs)

            self.traj_segments.append(coeffs_xyzw)
            self.segment_times.append(T)
            total_T += T

        self.traj_total_T = total_T
        self.get_logger().info(f"Planned landing trajectory: {len(self.traj_segments)} segments, total {self.traj_total_T:.2f}s")


    def _plan_landing_traj(self):
        """
        Build a two-segment cubic trajectory:
          1) current position -> 1 m above landing target
          2) 1 m above landing target -> landing target
        Each axis planned independently; durations scale with distance (slow descent ~0.5 m/s).
        """
        if self.landing_target is None or not self.have_pose:
            self.get_logger().warn("No valid landing target or pose, cannot plan landing trajectory.")
            return

        p0 = self.curr_xyzw.copy()
        above = self.landing_target.copy()
        above[2] += 1.0  # 1 m above

        self.get_logger().info(f"The distance from current position to landing target is {np.linalg.norm(above - p0)} m")
        waypoints: list[np.ndarray] = [p0]
        if np.linalg.norm(above - p0) > 0.1:
            waypoints.append(above)

        waypoints.append(self.landing_target)
        self.get_logger().info(f"Planning landing trajectory with waypoints: {waypoints}")

        self._calculate_trajectory_coefficients(waypoints)


    def _plan_trajectory(self):
        """
        Build a N-segment trajectory with each segment being a cubic polynomial between two consecutive waypoints:
          1) current position -> 1 m above current position
          2) 1 m above current position -> first waypoint
          3) first waypoint -> second waypoint
          ...
        Each axis planned independently; durations scale with distance (slow descent ~0.5 m/s).
        """
        if not self.have_pose:
            self.get_logger().warn("No valid pose, cannot plan test trajectory.")
            return

        self.get_logger().info(f"Received {len(self.r_waypoints)} waypoints for test trajectory.")
        self.starting_position = self.curr_xyzw.copy()

        p0 = self.curr_xyzw.copy()
        p1 = p0 + np.array([0.0, 0.0, 1.0, 0.0])  # 1 m up
        waypoints = [p0, p1]

        for wp in self.r_waypoints:
            wp_array = np.array([wp.x, wp.y, wp.z, wp.yaw], dtype=float)
            waypoints.append(wp_array)

        self._calculate_trajectory_coefficients(waypoints)


    # -------------------- publishers --------------------

    def _publish_hold_here(self):
        """
        Publish a setpoint to hold current position (keeps OFFBOARD happy).
        If hold_position is None, capture the current position as the hold point.
        This ensures we don't drift while waiting for OFFBOARD or waypoints.
        Once captured, it will keep publishing the same hold_position until we transition states or receive new waypoints.
        """
        if not self.have_pose:
            self.get_logger().warn("No valid pose, cannot publish hold position.")
            return

        if self.hold_position is None:
            self.hold_position = self.curr_xyzw.copy()
            self.get_logger().info(f"Capturing hold position at current location: {self.hold_position}")

        self._publish_xyz(self.hold_position[0], self.hold_position[1], self.hold_position[2], self.hold_position[3])


    def _publish_xyz(self, x: float, y: float, z: float, yaw: float = 0.0):
        """
        Publish a simple position setpoint with yaw (roll/pitch=0).
        """
        self.sp.header.stamp = self.get_clock().now().to_msg()
        qx, qy, qz, qw = yaw_to_quaternion(yaw)
        self.sp.pose.position.x = float(x)
        self.sp.pose.position.y = float(y)
        self.sp.pose.position.z = float(z)
        self.sp.pose.orientation.x = qx
        self.sp.pose.orientation.y = qy
        self.sp.pose.orientation.z = qz
        self.sp.pose.orientation.w = qw
        self.pub_sp.publish(self.sp)

    # -------------------- Utilities --------------------

    def _is_armed(self) -> bool:
        return bool(self.mav_state.armed)

    def _is_offboard(self) -> bool:
        return self.mav_state.mode == "OFFBOARD"

    def _reset_all(self):
        """
        Reset all internal states for a new mission.
        """
        self.landing_target = None
        self.isLanding = False
        self.hold_position = None
        self.traj_segments.clear()
        self.segment_times.clear()
        self.traj_total_T = 0.0
        self.traj_t0_wall = None
        self.r_waypoints = []
        self.waypoints_ready = False
        self.current_segment_idx = 0
        self.position_tolerance = 0.3

        # Reset all state objects so their init() fires again on next entry
        for s in self._state_map.values():
            s.reset()


# ------------------------- Main ---------------------------------------

def main():
    parser = argparse.ArgumentParser(description="Unified Landing Control (simulation or real).")
    parser.add_argument("--publish-hz", type=float, default=60.0,
                        help="Setpoint publish rate (Hz).")
    args = parser.parse_args()

    rclpy.init()
    node = LandingControl(
        publish_hz=args.publish_hz,
    )
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
