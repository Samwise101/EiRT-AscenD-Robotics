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
from mavros_msgs.srv import SetMode, CommandBool
from std_srvs.srv import SetBool
from std_msgs.msg import Bool

from dronehive_interfaces.srv import (
    DroneLandingService,
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
    sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
    cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
    if hasattr(np, 'arctan2'):
        roll = np.arctan2(sinr_cosp, cosr_cosp);
    else:
        roll = np.atan2(sinr_cosp, cosr_cosp);

    # pitch (y-axis rotation)
    sinp = np.sqrt(1 + 2 * (q.w * q.y - q.x * q.z));
    cosp = np.sqrt(1 - 2 * (q.w * q.y - q.x * q.z));
    if hasattr(np, 'arctan2'):
        pitch = 2 * np.arctan2(sinp, cosp) - np.pi / 2;
    else:
        pitch = 2 * np.atan2(sinp, cosp) - np.pi / 2;

    # yaw (z-axis rotation)
    siny_cosp = 2 * (q.w * q.z + q.x * q.y);
    cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
    if hasattr(np, 'arctan2'):
        yaw = np.arctan2(siny_cosp, cosy_cosp);
    else:
        yaw = np.atan2(siny_cosp, cosy_cosp);

    return roll, pitch, yaw;

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


# ---------------------- node ----------------------------------

class FlightState(Enum):
    INIT = 0
    EXECUTE_TRAJ = 4
    DONE = 6
    WAIT_ARM = 7
    WAIT_OFFBOARD = 8
    REQUEST_LANDING = 11

class LandingControl(Node):
    def __init__(self,
                 takeoff_alt: float = 2.0,
                 loiter_radius: float = 2.0,
                 landing_timeout: float = 15.0,
                 publish_hz: float = 60.0):
        super().__init__('landing_control')

        self.takeoff_alt = float(takeoff_alt)
        self.loiter_radius = float(loiter_radius)
        self.landing_timeout = float(landing_timeout)
        self.publish_dt = 1.0 / float(publish_hz)
        self.landing_box_id: str = ""
        self.landing_future = None

        # ---------------- ROS I/O ----------------
        self.pub_sp = self.create_publisher(PoseStamped, '/mavros/setpoint_position/local', 10)
        self.create_subscription(State, '/mavros/state', self._state_cb, 10)
        self.create_subscription(PoseStamped, '/mavros/local_position/pose', self._pose_cb, qos_profile_sensor_data)

        self.create_subscription(Bool, "/dronehive/drone_toggle_trajectory_execution", self._toggle_execution_cb, qos_profile)
        cli_mode = self.create_client(SetMode, '/mavros/set_mode')

        self.create_service(DroneTrajectoryWaypointsService,f"/dronehive/drone_waypoints", self.waypoint_service_cb)


        # Wait for MAVROS
        self.get_logger().info("Waiting for MAVROS services...")
        cli_mode.wait_for_service()
        self.get_logger().info("MAVROS services available.")

        # ---------------- State ----------------
        self.state = FlightState.INIT
        self.mav_state = State()
        self.have_pose = False
        self.curr_xyz = np.zeros(3)
        self.curr_heading = np.zeros(3)  # roll, pitch, yaw
        self.home_xy = None
        self.home_alt0 = None
        self.last_requested_pose = np.zeros(3)
        self.hold_position = None
        self.resume_allowed = True

        # Landing service
        self.landing_target = None
        self.isLanding = False

        # Trajectory
        self.traj_segments = []
        self.segment_times = []
        self.traj_total_T = 0.0
        self.traj_t0_wall = None
        self.r_waypoints = []

        # Waypoint readiness
        self.waypoints_ready = False


        # Pre-allocate SP
        self.sp = PoseStamped()
        self.sp.header.frame_id = 'map'
        _, _, qz, qw = yaw_to_quaternion(0.0)
        self.sp.pose.orientation.z = qz
        self.sp.pose.orientation.w = qw

        self.current_segment_idx = 0
        self.position_tolerance = 0.3  # meters

        # Timers
        self.timer = self.create_timer(self.publish_dt, self._timer_cb)


    # -------------------- HELPERS --------------------

    def setup_waypints(self, waypoints):
        self.r_waypoints = waypoints
        self.waypoints_ready = True
        self.hold_position = None  # reset hold position

        self.current_segment_idx = 0
        self.get_logger().info(f"Received {len(self.r_waypoints)} waypoints from waypoint service: {self.r_waypoints}")
        self.get_logger().info(f"Waypoints ready: {self.waypoints_ready}")

    # -------------------- Callbacks --------------------

    def _state_cb(self, msg: State):
        self.mav_state = msg

    def _pose_cb(self, msg: PoseStamped):
        self.have_pose = True
        # self.get_logger().info(f"Pose received: x={msg.pose.position.x}, y={msg.pose.position.y}, z={msg.pose.position.z}")
        self.curr_xyz = np.array([msg.pose.position.x, msg.pose.position.y, msg.pose.position.z], dtype=float)
        self.curr_heading = quat_to_euler(msg.pose.orientation)

        if self.home_alt0 is None:
            self.home_alt0 = float(self.curr_xyz[2])

    def waypoint_service_cb(self, request, response):

        self.get_logger().info(f"Waypoint service called with waypoints: {request.waypoints}")

        if request.waypoints is not None:
            self.setup_waypints(request.waypoints)
            response.ack = True

        return response


    def _toggle_execution_cb(self, msg: Bool):
        self.resume_allowed = msg.data
        self.hold_position = None

        state_str = "Resuming" if msg.data else "Pausing"
        self.get_logger().info(f"Toggle execution {state_str} command received.")


    # -------------------- Main Timer --------------------

    def _timer_cb(self):
        """
        Main loop - Publishes setpoints continuously (required by MAVROS OFFBOARD)
        """
        now = time.time()

        # Pause and resume control based on external command
        if not self.resume_allowed:
            self._pause_function()
            return


        if self.state == FlightState.INIT:
            # Need valid pose before proceeding
            if not self.have_pose:
                self._publish_hold_here()
                return

            # wait for ARMED
            self.state = FlightState.WAIT_ARM
            self.get_logger().info("State -> WAIT_ARM (real)")

        elif self.state == FlightState.WAIT_ARM:
            if self._is_armed():
                #record "home" where we first see armed
                if self.home_xy is None:
                    self.home_xy = self.curr_xyz[:2].copy()
                if self.home_alt0 is None:
                    self.home_alt0 = float(self.curr_xyz[2])
                self.get_logger().info("Operator set ARMED. Waiting for OFFBOARD...")
                self.state = FlightState.WAIT_OFFBOARD

        elif self.state == FlightState.WAIT_OFFBOARD:
            # Keep feeding setpoints so offboard won't drop if operator switches
            self._publish_hold_here()

            # If taken out of armed, return to WAIT_ARM
            if not self._is_armed():
                self.get_logger().info("Disarmed, returning to WAIT_ARM.")
                self.state = FlightState.WAIT_ARM

            if self._is_offboard() and self.waypoints_ready:
                self.get_logger().info("Waypoints ready. Planning and executing trajectory.")
                self._plan_trajectory()
                self.traj_t0_wall = now
                self.position_tolerance = 0.3
                self.hold_position = None  # reset hold position
                self.state = FlightState.EXECUTE_TRAJ


        elif self.state == FlightState.REQUEST_LANDING:
            # Keep publishing hold here while requesting landing target
            self._publish_hold_here()

            self.get_logger().info(f"Using starting position for landing: {self.starting_position}")
            landing: PositionMessage = PositionMessage()
            landing.lat = float(self.starting_position[0])
            landing.lon = float(self.starting_position[1])
            landing.elv = float(self.starting_position[2])

            self.setup_waypints([ landing ])

            self.landing_target = np.array([float(landing.lat), float(landing.lon), float(landing.elv)+0.05], dtype=float)

            self.isLanding = True
            self._plan_landing_traj()

            self.traj_t0_wall = now
            self.position_tolerance = 0.1
            self.hold_position = None

            self.state = FlightState.EXECUTE_TRAJ
            self.get_logger().info("Landing target received. Executing landing trajectory.")
            return


        elif self.state == FlightState.EXECUTE_TRAJ:
            # Feedback-based trajectory following
            if self.current_segment_idx >= len(self.traj_segments):
                # Already finished all segments
                self.get_logger().info("All trajectory segments completed, holding last position.")
                self._publish_xyz(self.last_requested_pose[0], self.last_requested_pose[1], self.last_requested_pose[2])

                self.waypoints_ready = False
                if self.isLanding:
                    self.get_logger().info("Landing trajectory complete, drone is landing.")
                    self.state = FlightState.DONE
                    self._publish_hold_here()
                    return

                self.get_logger().info("Reached the end of the trajectory holding and requesting landing position.")
                self.state = FlightState.REQUEST_LANDING
                self.landing_request_init_time = time.time()

                self._publish_hold_here()

                return


            coeffs_x, coeffs_y, coeffs_z = self.traj_segments[self.current_segment_idx]
            T = self.segment_times[self.current_segment_idx]

            # Compute desired point for current segment (using elapsed time in this segment)
            if not hasattr(self, 'seg_t0_wall'):
                self.seg_t0_wall = time.time()
                self.get_logger().info("Setting time start")
                self.now = time.time()

            t_in_seg = self.now - self.seg_t0_wall
            if t_in_seg > T:
                t_in_seg = T

            px, _, _ = eval_cubic(coeffs_x, t_in_seg)
            py, _, _ = eval_cubic(coeffs_y, t_in_seg)
            pz, _, _ = eval_cubic(coeffs_z, t_in_seg)
            self.last_requested_pose = np.array([px, py, pz])

            # Publish current target
            self._publish_xyz(px, py, pz, self.curr_heading[2])

            self.get_logger().info(f"Generating setpoint for segment {self.current_segment_idx} at t={t_in_seg}/{T}, pos=({px}, {py}, {pz})")
            # Check distance to target
            target_point = np.array([px, py, pz])
            dist = np.linalg.norm(target_point - self.curr_xyz)
            self.get_logger().info(f"Seg {self.current_segment_idx}: dist={dist}")

            # self.get_logger().info(f"Curr: {self.curr_xyz[0]} {self.curr_xyz[1]} {self.curr_xyz[2]} target: {px} {py} {pz}, T: {T}, now: {self.now}, t_in_seg: {t_in_seg}")
            print(f"Curr: {self.curr_xyz[0]} {self.curr_xyz[1]} {self.curr_xyz[2]} target: {px} {py} {pz} T: {T} now: {self.now} t_in_seg: {t_in_seg}")

            if dist < self.position_tolerance:
                # Advance to next trajectory segment.
                # The descend to the last position is slower.
                if self.current_segment_idx + 1 >= len(self.traj_segments):
                    self.now += 0.05
                    self.position_tolerance = 0.1
                else:
                    self.now += 0.1

                if t_in_seg >= T:
                    self.current_segment_idx += 1
                    self.seg_t0_wall = time.time()
                    self.now = time.time()
                    self.get_logger().info(f"Segment {self.current_segment_idx} reached, moving to next.")

        elif self.state == FlightState.DONE:
            # Keep publishing last SP for a short while to avoid offboard drops
            #self._publish_hold_here()
            self.get_logger().info("Mission complete. Resetting.")
            self.state = FlightState.WAIT_ARM
            self._reset_all()


    # -------------------- Waypoint readiness check --------------------
    def _are_waypoints_ready(self) -> bool:
        return self.waypoints_ready


    # -------------------- Trajectory planning & execution --------------------

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

        self.current_segment_idx = 0
        p0 = self.curr_xyz.copy()
        above = self.landing_target.copy()
        above[2] += 1.0  # 1 m above

        self.get_logger().info(f"The distance from current position to landing target is {np.linalg.norm(above - p0)} m")
        if np.linalg.norm(above - p0) < 0.1:
            waypoints = [p0, self.landing_target]
            self.get_logger().info(f"Landing target very close, planning direct descent. {waypoints}")
        else:
            waypoints = [p0, above, self.landing_target]
            self.get_logger().info(f"Planning landing trajectory with waypoints: {waypoints}")

        self.traj_segments.clear()
        self.segment_times.clear()
        total_T = 0.0

        v0 = np.zeros(3)
        a0 = np.zeros(3)

        for i in range(len(waypoints) - 1):
            A = waypoints[i]
            B = waypoints[i + 1]
            d = float(np.linalg.norm(B - A))
            T = max(1.0, d / 0.5)  # ~0.5 m/s nominal
            self.get_logger().info(f"Planning segment {i}: from {A} to {B}, distance={d} m, time={T} s")
            coeffs_xyz = []
            for axis in range(3):
                coeffs = cubic_coeffs_from_boundary(A[axis], B[axis], v0[axis], a0[axis], T)
                coeffs_xyz.append(coeffs)
            self.traj_segments.append(coeffs_xyz)
            self.segment_times.append(T)
            total_T += T

        self.traj_total_T = total_T
        self.get_logger().info(f"Planned landing trajectory: {len(self.traj_segments)} segments, total {self.traj_total_T:.2f}s")


    def _plan_trajectory(self):
        """
        Plan a trajectory with n-segments
        waypoints are received from the waypoint service
        """
        if not self.have_pose:
            self.get_logger().warn("No valid pose, cannot plan test trajectory.")
            return

        self.get_logger().info(f"Received {len(self.r_waypoints)} waypoints for test trajectory.")
        p0 = self.curr_xyz.copy()
        self.starting_position = p0.copy()
        p1 = p0 + np.array([0.0, 0.0, 1.0])  # 1 m up
        waypoints = [p0, p1]

        for wp in self.r_waypoints:
            wp_array = np.array([wp.lat, wp.lon, wp.elv], dtype=float)
            #self.get_logger().info(f"Planning to waypoint: x={wp_array[0]:.2f}, y={wp_array[1]:.2f}, z={wp_array[2]:.2f}")
            waypoints.append(wp_array)

        self.traj_segments.clear()
        self.segment_times.clear()
        total_T = 0.0
        v0 = np.zeros(3)
        a0 = np.zeros(3)

        for i in range(len(waypoints) - 1):
            A = waypoints[i]
            B = waypoints[i + 1]
            d = float(np.linalg.norm(B - A))
            T = max(1.0, d / 0.5)  # ~0.5 m/s nominal
            self.get_logger().info(f"Planning segment {i}: from {A} to {B}, distance={d} m, time={T} s")
            coeffs_xyz = []
            for axis in range(3):
                coeffs = cubic_coeffs_from_boundary(A[axis], B[axis], v0[axis], a0[axis], T)
                coeffs_xyz.append(coeffs)
            self.traj_segments.append(coeffs_xyz)
            self.segment_times.append(T)
            self.current_segment_idx = 0
            total_T += T

        self.traj_total_T = total_T
        self.get_logger().info(f"Planned test trajectory: {len(self.traj_segments)} segments, total {self.traj_total_T:.2f}s")


    # -------------------- publishers --------------------

    def _publish_hold_here(self):
        """Publish a setpoint to hold current position (keeps OFFBOARD happy)."""
        if not self.have_pose:
            return
        if self.hold_position is None:
            self.hold_position = self.curr_xyz.copy()

        self._publish_xyz(self.hold_position[0], self.hold_position[1], self.hold_position[2])


    def _publish_xyz(self, x: float, y: float, z: float, yaw: float = 0.0):
        """Publish a simple position setpoint with yaw (roll/pitch=0)."""
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

    def _pause_function(self):
        """Pause and resume control based on external command"""
        if not self.resume_allowed:
            self._publish_hold_here()
            self.get_logger().info("Control paused, holding position.")
            return

    def _reset_all(self):
        """Reset all internal states for a new mission."""
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
# ------------------------- Main ---------------------------------------

def main():
    parser = argparse.ArgumentParser(description="Unified Landing Control (simulation or real).")
    parser.add_argument("--takeoff-alt", type=float, default=2.0,
                        help="Takeoff altitude in meters (simulation mode).")
    parser.add_argument("--loiter-radius", type=float, default=2.0,
                        help="Loiter circle radius in meters.")
    parser.add_argument("--landing-timeout", type=float, default=15.0,
                        help="Seconds to wait for landing position before landing at home.")
    parser.add_argument("--publish-hz", type=float, default=60.0,
                        help="Setpoint publish rate (Hz).")
    args = parser.parse_args()

    rclpy.init()
    node = LandingControl(
        takeoff_alt=args.takeoff_alt,
        loiter_radius=args.loiter_radius,
        landing_timeout=args.landing_timeout,
        publish_hz=args.publish_hz)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()

