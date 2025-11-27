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

from geometry_msgs.msg import PoseStamped
from mavros_msgs.msg import State
from mavros_msgs.srv import SetMode, CommandBool
from sensor_msgs.msg import BatteryState
from dronehive_interfaces.srv import DroneLandingService, DroneTrajectoryWaypointsService, DroneStartStopService, FirstWaypointService
from dronehive_interfaces.msg import PositionMessage, DroneStatusMessage


# ---------------------- helpers ---------------------------------

def quat_to_euler(q):
    # roll (x-axis rotation)
    sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
    cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
    roll = np.atan2(sinr_cosp, cosr_cosp);

    # pitch (y-axis rotation)
    sinp = np.sqrt(1 + 2 * (q.w * q.y - q.x * q.z));
    cosp = np.sqrt(1 - 2 * (q.w * q.y - q.x * q.z));
    pitch = 2 * np.atan2(sinp, cosp) - np.pi / 2;

    # yaw (z-axis rotation)
    siny_cosp = 2 * (q.w * q.z + q.x * q.y);
    cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
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
    WAIT_OFFBOARD_AND_ARM = 1
    TAKEOFF = 2
    LOITER_WAIT_SERVICE = 3
    EXECUTE_TRAJ = 4
    LANDING_HOME = 5
    DONE = 6
    WAIT_ARM = 7
    WAIT_OFFBOARD = 8
    WAIT_AND_PLAN_TRAJ = 9
    EXECUTE_TEST_TRAJ = 10
    REQUEST_LANDING = 11
    WAIT = 12

class LandingControl(Node):
    def __init__(self,
                 simulation_mode: bool,
                 drone_id: str,
                 takeoff_alt: float = 2.0,
                 loiter_radius: float = 2.0,
                 landing_timeout: float = 15.0,
                 publish_hz: float = 60.0):
        super().__init__('landing_control')

        self.simulation_mode = simulation_mode
        self.drone_id = drone_id
        self.takeoff_alt = float(takeoff_alt)
        self.loiter_radius = float(loiter_radius)
        self.landing_timeout = float(landing_timeout)
        self.publish_dt = 1.0 / float(publish_hz)

        # ---------------- ROS I/O ----------------
        self.pub_sp = self.create_publisher(PoseStamped, '/mavros/setpoint_position/local', 10)
        self.create_subscription(State, '/mavros/state', self._state_cb, 10)
        self.create_subscription(PoseStamped, '/mavros/local_position/pose', self._pose_cb, qos_profile_sensor_data)
        self.create_subscription(BatteryState, '/mavros/battery', self._battery_cb, 10)

        self.cli_mode = self.create_client(SetMode, '/mavros/set_mode')
        self.cli_arm = self.create_client(CommandBool, '/mavros/cmd/arming')
        self.cli_fws = self.create_client(FirstWaypointService, '/dronehive/first_waypoint')

        self.cli_landing = self.create_client(DroneLandingService, '/dronehive/drone_land_request')

        self.srv = self.create_service(DroneTrajectoryWaypointsService,f"/dronehive/drone_waypoints_{self.drone_id}", self.waypoint_service_cb)
        self.srv = self.create_service(DroneStartStopService, f"/dronehive/drone_start_stop_{self.drone_id}", self.start_stop_service_cb)

        self.pub_status = self.create_publisher(DroneStatusMessage, f"/dronehive/drone_status_{self.drone_id}", 10)

        # Wait for MAVROS
        self.get_logger().info("Waiting for MAVROS services...")
        self.cli_mode.wait_for_service()
        self.cli_arm.wait_for_service()
        self.get_logger().info("MAVROS services available.")

        # ---------------- State ----------------
        self.state = FlightState.INIT
        self.mav_state = State()
        self.have_pose = False
        self.curr_xyz = np.zeros(3)
        self.curr_heading = np.zeros(3)  # roll, pitch, yaw
        self.home_xy = None
        self.home_alt0 = None
        self.takeoff_reached = False
        self.last_requested_pose = np.zeros(3)
        self.latest_xyz = np.zeros(3)

        # Battery
        self.battery_level = 0.0  # percentage

        # Loiter
        self._circle_angle_deg = 0.0

        # Landing service
        self.request_sent = False
        self.request_start_wall = None
        self.landing_received = False
        self.landing_target = None
        self.isLanding = False

        # Trajectory
        self.traj_segments = []
        self.segment_times = []
        self.traj_total_T = 0.0
        self.traj_t0_wall = None
        self.r_waypoints = []
        self.reached_first_waypoint = False

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
        if self.simulation_mode:
            self.sim_timer = self.create_timer(0.5, self._simulation_mode_switcher)

        self.get_logger().info(f"UnifiedLandingControl started (simulation_mode={self.simulation_mode}).")

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
            self.r_waypoints = request.waypoints
            self.waypoints_ready = True
            response.ack = True
            self.current_segment_idx = 0
            self.get_logger().info(f"Received {len(self.r_waypoints)} waypoints from waypoint service: {self.r_waypoints}")
            self.get_logger().info(f"Waypoints ready: {self.waypoints_ready}")
        return response

    def _battery_cb(self, msg: BatteryState):
        self.battery_level = msg.percentage * 100.0  # convert to percentage

    def start_stop_service_cb(self, request, response):
        if request.control_var == 1:  # pause
            self.get_logger().info("Pausing trajectory execution.")
            self.state = FlightState.WAIT
        elif request.control_var == 0:  # resume
            self.get_logger().info("Resuming trajectory execution.")
            if self.traj_segments:
                self.state = FlightState.EXECUTE_TRAJ
            else:
                self.get_logger().info("No trajectory to execute, remaining in current state.")
        elif request.control_var == 2:  # stop
            self.get_logger().info("Stopping trajectory execution and landing home.")
            self.state = FlightState.LANDING_HOME
        response.ack = True
        return response
    # -------------------- Main Timer --------------------

    def _timer_cb(self):
        """
        Main loop - Publishes setpoints continuously (required by MAVROS OFFBOARD)
        """
        now = time.time()
        
        # Publish drone status
        self._publish_status()
        

        if self.state == FlightState.INIT:
            # Need valid pose before proceeding
            if not self.have_pose:
                self._publish_hold_here()
                return

            if self.simulation_mode:
                # Record home XY at start; we will take off to takeoff_alt
                self.home_xy = self.curr_xyz[:2].copy()
                self._publish_takeoff_sp()
                self.state = FlightState.TAKEOFF
                self.get_logger().info("State -> TAKEOFF (simulation)")
            else:
                # Real: wait for OFFBOARD + ARMED by operator
                # self.state = FlightState.WAIT_OFFBOARD_AND_ARM
                # self.get_logger().info("State -> WAIT_OFFBOARD_AND_ARM (real)")

                # wait for ARMED
                self.state = FlightState.WAIT_ARM
                self.get_logger().info("State -> WAIT_ARM (real)")

        elif self.state == FlightState.WAIT_OFFBOARD_AND_ARM:
            # Keep feeding setpoints so offboard won't drop if operator switches
            self._publish_hold_here()
            if self._is_offboard_and_armed():
                # Record "home" where we first see OFFBOARD+armed
                if self.home_xy is None:
                    self.home_xy = self.curr_xyz[:2].copy()
                if self.home_alt0 is None:
                    self.home_alt0 = float(self.curr_xyz[2])
                self._begin_loiter_and_request(now)
                self.get_logger().info("Operator set OFFBOARD+ARMED. Loitering & requesting landing target.")
                self.state = FlightState.LOITER_WAIT_SERVICE

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
            if self.mav_state.mode == "OFFBOARD":
                self._begin_loiter_and_request(now)
                self.get_logger().info("Operator set OFFBOARD. Waiting for waypoints.")
                self.state = FlightState.WAIT_AND_PLAN_TRAJ

        elif self.state == FlightState.TAKEOFF:
            #Simulation or real mode takeoff
            if self.simulation_mode:
                # Drive Z to takeoff altitude over home XY
                self._publish_takeoff_sp()
            else:
                self._publish_takeoff_re()
            # Consider takeoff completed when close in altitude
            if abs(self.takeoff_alt - self.curr_xyz[2]) < 0.2:
                self.takeoff_reached = True
                self.get_logger().info("Takeoff altitude reached. Executing trajectory.")
                self.state = FlightState.WAIT_AND_PLAN_TRAJ
                #self._begin_loiter_and_request(now)
                #self.get_logger().info("Takeoff reached. Loitering & requesting landing target.")
                #self.state = FlightState.LOITER_WAIT_SERVICE

        elif self.state == FlightState.WAIT_AND_PLAN_TRAJ:
            # Wait for waypoints before for the trajectory, keep publishing hold here while waiting
            self._publish_hold_here()
            if self._are_waypoints_ready():
                if self.takeoff_reached is False:
                    self.get_logger().info("Takeoff not yet reached, cannot plan trajectory.")
                    self.get_logger().info("Taking off to altitude...")
                    self.state = FlightState.TAKEOFF
                self.get_logger().info("Waypoints ready. Planning and executing trajectory.")
                self._plan_test_trajectory()
                self.traj_t0_wall = now
                self.position_tolerance = 0.3
                self.state = FlightState.EXECUTE_TRAJ
            else:
                #self._publish_hold_here()
                if not hasattr(self, 'waypoints_ready_logged'):
                    self.waypoints_ready_logged = True
                    self.get_logger().info("Waiting for waypoints to be ready...")

        elif self.state == FlightState.EXECUTE_TEST_TRAJ:
            # Follow the planned test trajectory (two segments)
            t = now - self.traj_t0_wall
            if t >= self.traj_total_T:
                # Final point of second segment
                coeffs_x, coeffs_y, coeffs_z = self.traj_segments[-1]
                px, _, _ = eval_cubic(coeffs_x, self.segment_times[-1])
                py, _, _ = eval_cubic(coeffs_y, self.segment_times[-1])
                pz, _, _ = eval_cubic(coeffs_z, self.segment_times[-1])
                self._publish_xyz(px, py, pz)
                self.state = FlightState.LOITER_WAIT_SERVICE
                self.get_logger().info("Test trajectory complete.")
            else:
                self._publish_traj_at_time(t)

        elif self.state == FlightState.WAIT:
            # Keep publishing hold here while waiting
            self._publish_hold_here()

        elif self.state == FlightState.LOITER_WAIT_SERVICE:
            # Circle while waiting. Publish continuously.
            self._publish_circle_loiter()

            # Send the request once when entering this state (or if service becomes available later)
            if not self.request_sent and self.cli_landing.wait_for_service(timeout_sec=2.0):
                #time.sleep(1.0)
                self._call_landing_service(now)

            # Check for landing response
            if self.landing_received and self.landing_target is not None:
                self._plan_landing_traj()
                self.traj_t0_wall = now
                self.position_tolerance = 0.3
                self.state = FlightState.EXECUTE_TRAJ
                self.get_logger().info("Landing target received. Executing landing trajectory.")
                return

            # Timeout -> go land at home
            if self.request_start_wall is not None and (now - self.request_start_wall) > self.landing_timeout:
                self.state = FlightState.LANDING_HOME
                self.get_logger().warn("Landing request timed out. Landing back at home.")
                return

        elif self.state == FlightState.REQUEST_LANDING:
            # Keep publishing hold here while requesting landing target
            self._publish_hold_here()
            self.get_logger().info("Requesting landing target...")
            if not self.request_sent and self.cli_landing.wait_for_service(timeout_sec=0.01):
                self._call_landing_service(now)
                self.get_logger().info("Requesting landing target...")
            # Check for landing response
            if self.landing_received and self.landing_target is not None:
                self.isLanding = True
                self._plan_landing_traj()
                self.traj_t0_wall = now
                self.position_tolerance = 0.1
                self.state = FlightState.EXECUTE_TRAJ
                self.get_logger().info("Landing target received. Executing landing trajectory.")
                return

        elif self.state == FlightState.EXECUTE_TRAJ:
            # Feedback-based trajectory following
            if self.current_segment_idx >= len(self.traj_segments):
                # Already finished all segments
                """
                self._publish_xyz(self.landing_target[0], self.landing_target[1], 0.0)
                if self.curr_xyz[2] < 0.1:
                    self.state = FlightState.DONE
                    self.get_logger().info("Landing trajectory complete.")
                return
                """
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
                    if not self.reached_first_waypoint:
                        self.reached_first_waypoint = True
                        # Call first waypoint service
                        self._call_fws()
                        self.get_logger().info("Reached first waypoint...")


        elif self.state == FlightState.LANDING_HOME:
            # Go to home XY and descend to initial home altitude)
            self._publish_xyz(self.home_xy[0], self.home_xy[1], self.takeoff_alt)
            self.get_logger().info("Landing back at home position.")
            print(f"Curr: {self.curr_xyz[0]} {self.curr_xyz[1]} {self.curr_xyz[2]} target: {px} {py} {pz}")
            # Once close to home Z, consider done
            if linalg.norm(self.curr_xyz[:2] - self.home_xy) < 0.1:
                self._publish_xyz(self.home_xy[0], self.home_xy[1], self.home_alt0)
                if self.curr_xyz[2] < self.home_alt0 + 0.1:
                    self.state = FlightState.DONE
                    self.get_logger().info("Landed at home. Done.")

        elif self.state == FlightState.DONE:
            # Keep publishing last SP for a short while to avoid offboard drops
            #self._publish_hold_here()
            self.get_logger().info("Mission complete. Resetting.")
            self.state = FlightState.WAIT_ARM
            self._reset_all()
            


    # -------------------- Simulation helper --------------------

    def _simulation_mode_switcher(self):
        """In simulation, periodically request OFFBOARD and ARM."""
        if not self.simulation_mode:
            return
        if self.mav_state.mode != "OFFBOARD" and self.state != FlightState.DONE:
            req = SetMode.Request()
            req.custom_mode = "OFFBOARD"
            self.cli_mode.call_async(req)
            self.get_logger().info("SIM: requesting OFFBOARD...")
        elif not self.mav_state.armed and self.state != FlightState.DONE:
            req = CommandBool.Request()
            req.value = True
            self.cli_arm.call_async(req)
            self.get_logger().info("SIM: requesting ARM...")

    def _disarm(self):
        if self.mav_state.armed:
            req = CommandBool.Request()
            req.value = False
            self.cli_arm.call_async(req)
            self.get_logger().info("SIM: requesting DISARM...")

    # -------------------- Landing Service --------------------
    def _call_fws(self):
        """Call first waypoint service to notify master box."""
        if not self.cli_fws.service_is_ready():
            self.get_logger().warn("First Waypoint Service not yet available.")
            return

        req = FirstWaypointService.Request()
        req.drone_id = self.drone_id
        req.reached_first_waypoint = True

        self.get_logger().info(
            f"Notifying first waypoint reached to /dronehive/first_waypoint_service "
            f"with drone_id='{req.drone_id}'"
        )

        future = self.cli_fws.call_async(req)
        future.add_done_callback(self._fws_future_cb)

    def _fws_future_cb(self, future):
        try:
            resp = future.result()
        except Exception as e:
            self.get_logger().warn(f"First Waypoint Service call failed: {e}")
            return

        if resp is None or not hasattr(resp, 'ack') or not resp.ack:
            self.get_logger().warn("First Waypoint Service returned no valid acknowledgment.")
            return

        self.get_logger().info(f"First Waypoint Service acknowledged by master box.")

    def _call_landing_service(self, now_wall: float):
        """Send landing request to the masterbox."""
        self.request_sent = True
        self.request_start_wall = now_wall

        if not self.cli_landing.service_is_ready():
            self.get_logger().warn("Landing service not yet available.")
            return

        # --- Build request as master expects ---
        req = DroneLandingService.Request()
        req.drone_id = self.drone_id

        pm = PositionMessage()
        pm.lat = float(self.curr_xyz[0])
        pm.lon = float(self.curr_xyz[1])
        pm.elv = float(self.curr_xyz[2])
        req.drone_pos = pm

        self.get_logger().info(
            f"Requesting landing target from /dronehive/drone_land_request "
            f"with drone_id='{req.drone_id}' at pos=({pm.lat:.2f}, {pm.lon:.2f}, {pm.elv:.2f})"
        )

        future = self.cli_landing.call_async(req)
        future.add_done_callback(self._landing_future_cb)

    def _landing_future_cb(self, future):
        try:
            resp = future.result()
        except Exception as e:
            self.get_logger().warn(f"Landing service call failed: {e}")
            return

        if resp is None or not hasattr(resp, 'landing_pos') or resp.landing_pos is None:
            self.get_logger().warn("Landing service returned no valid data.")
            return

        lp = resp.landing_pos
        self.landing_target = np.array([float(lp.lat), float(lp.lon), float(lp.elv)], dtype=float)
        self.landing_received = True
        self.get_logger().info(f"Landing target received: x={self.landing_target[0]:.2f}, y={self.landing_target[1]:.2f}, z={self.landing_target[2]:.2f}")

    # -------------------- Waypoint readiness check --------------------
    def _are_waypoints_ready(self) -> bool:
        return self.waypoints_ready


    def _get_battery_level(self) -> float:
        return self.battery_level


    # -------------------- Trajectory planning & execution --------------------

    def _plan_landing_traj(self):
        """
        Build a two-segment cubic trajectory:
          1) current position -> 1 m above landing target
          2) 1 m above landing target -> landing target
        Each axis planned independently; durations scale with distance (slow descent ~0.5 m/s).
        """
        if self.landing_target is None or not self.have_pose:
            return

        self.current_segment_idx = 0
        p0 = self.curr_xyz.copy()
        above = self.landing_target.copy()
        above[2] += 1.0  # 1 m above

        waypoints = [p0, above, self.landing_target]
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


    def _plan_test_trajectory(self):
        """
        Plan a trajectory with n-segments
        waypoints are received from the waypoint service
        """
        if not self.have_pose:
            self.get_logger().warn("No valid pose, cannot plan test trajectory.")
            return

        self.get_logger().info(f"Received {len(self.r_waypoints)} waypoints for test trajectory.")
        p0 = self.curr_xyz.copy()
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
        # set the latest_xyz to current position and publish that unless the drone has moved more than 0.1m
        if np.linalg.norm(self.curr_xyz - self.latest_xyz) > 0.1:
            self.latest_xyz = self.curr_xyz.copy()
        self._publish_xyz(self.latest_xyz[0], self.latest_xyz[1], self.latest_xyz[2])

    def _publish_takeoff_sp(self):
        """Publish a setpoint at home XY and takeoff_alt Z (simulation takeoff)."""
        if self.home_xy is None:
            self.home_xy = self.curr_xyz[:2].copy()
        self._publish_xyz(self.home_xy[0], self.home_xy[1], self.takeoff_alt)

    def _publish_takeoff_re(self):
        """Publish a setpoint at current XY and takeoff_alt Z (real takeoff)."""
        self._publish_xyz(self.curr_xyz[0], self.curr_xyz[1], self.takeoff_alt)

    def _publish_circle_loiter(self):
        """Generate a small horizontal circle at the takeoff altitude."""
        if self.home_xy is None:
            self.home_xy = self.curr_xyz[:2].copy()
        ang = math.radians(self._circle_angle_deg)
        x = self.home_xy[0] + self.loiter_radius * math.cos(ang)
        y = self.home_xy[1] + self.loiter_radius * math.sin(ang)
        z = self.takeoff_alt if self.simulation_mode else self.curr_xyz[2]  # in real, don't force altitude jumps
        self._publish_xyz(x, y, z)

        self._circle_angle_deg = (self._circle_angle_deg + 2.0) % 360.0  # ~2 deg per tick -> smoother circle

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

    def _publish_status(self):
        """Publish the drone status message."""
        msg = DroneStatusMessage()
        msg.drone_id = self.drone_id
        msg.battery_level = self._get_battery_level()
        msg.fligt_state = self.state.name
        pos_msg = PositionMessage()
        pos_msg.lat = float(self.curr_xyz[0])
        pos_msg.lon = float(self.curr_xyz[1])
        pos_msg.elv = float(self.curr_xyz[2])
        msg.current_position = pos_msg
        msg.reached_first_waypoint = self.reached_first_waypoint
        self.pub_status.publish(msg)


    # -------------------- Utilities --------------------

    def _is_offboard_and_armed(self) -> bool:
        return (self.mav_state.mode == "OFFBOARD") and bool(self.mav_state.armed)

    def _is_armed(self) -> bool:
        return bool(self.mav_state.armed)

    def _begin_loiter_and_request(self, now_wall: float):
        """Start loitering and the landing request."""
        # Try to call the service ASAP
        if self.cli_landing.wait_for_service(timeout_sec=0.1):
            self._call_landing_service(now_wall)
        else:
            # Will retry call as soon as service comes up (handled in LOITER_WAIT_SERVICE)
            self.request_sent = False
            self.request_start_wall = now_wall

    def _reset_all(self):
        """Reset all internal states for a new mission."""
        self.request_sent = False
        self.request_start_wall = None
        self.landing_received = False
        self.landing_target = None
        self.isLanding = False
        self.traj_segments.clear()
        self.segment_times.clear()
        self.traj_total_T = 0.0
        self.traj_t0_wall = None
        self.r_waypoints = []
        self.reached_first_waypoint = False
        self.waypoints_ready = False
        self.current_segment_idx = 0
        self.position_tolerance = 0.3
# ------------------------- Main ---------------------------------------

def main():
    parser = argparse.ArgumentParser(description="Unified Landing Control (simulation or real).")
    parser.add_argument("--simulation", action="store_true",
                        help="Run in simulation mode (auto-arm, OFFBOARD, takeoff, loiter).")
    parser.add_argument("--drone-id", type=str, default="drone69",
                        help="Drone identifier sent to the landing service.")
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
    node = LandingControl(simulation_mode=args.simulation,
                                 drone_id=args.drone_id,
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

