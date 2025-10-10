#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import numpy as np
import time

from geometry_msgs.msg import PoseStamped, Point, Vector3
from mavros_msgs.msg import PositionTarget
from std_msgs.msg import Header

import dronehive.utils as dh
from dronehive_interfaces.srv import DroneLandingService
from dronehive_interfaces.msg import PositionMessage
#from example_interfaces.srv import Trigger  # simple service type for demo

# ---------------------- Helper math ----------------------------------

def cubic_coeffs_from_boundary(p0, v0, a0, p1, T):
    """Compute cubic coefficients given start pos/vel/acc and end pos."""
    c0 = p0
    c1 = v0
    c2 = a0 / 2.0
    c3 = (p1 - (c0 + c1*T + c2*T**2)) / (T**3)
    return np.array([c0, c1, c2, c3])

def eval_cubic(coeffs, t):
    c0, c1, c2, c3 = coeffs
    p = c0 + c1*t + c2*t**2 + c3*t**3
    v = c1 + 2*c2*t + 3*c3*t**2
    a = 2*c2 + 6*c3*t
    return p, v, a

# ----------------------------------------------------------------------

class LandingTrajNode(Node):
    def timer_cb(self):
        # Publish setpoint to keep MAVROS in offboard mode
        msg = PoseStamped()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'map'

        # Default: hold current position if no trajectory
        if self.current_pos is None:
            self.get_logger().warn('Current position unknown, cannot publish setpoint.')
            return

        msg.pose.orientation.x = float(self.current_pos[0])
        msg.pose.orientation.y = float(self.current_pos[1])
        msg.pose.orientation.z = float(self.current_pos[2])
        # Set type_mask to ignore velocity/acceleration/yaw
        self.pub.publish(msg)

    def __init__(self):
        super().__init__('landing_traj_node')

        # --- Publishers/Subscribers ---
        self.pub = self.create_publisher(PoseStamped, '/mavros/setpoint_position/local', 10) #might need to be changed if the drone uses a different topic
        self.create_subscription(PoseStamped, '/mavros/local_position/pose', self.pose_cb, 10) #might need to be changed if the drone uses a different topic

        # --- Service client to the landing box ---

        self.cli = self.create_client(DroneLandingService, dh.DRONEHIVE_DRONE_LAND_REQUEST)
        while not self.cli.wait_for_service(timeout_sec=2.0):
            self.get_logger().info(f'Waiting for {dh.DRONEHIVE_DRONE_LAND_REQUEST} service...')

        # --- Internal state ---
        self.current_pos = None
        self.landing_pos = None
        self.have_path = False
        self.path_start_time = None
        self.publish_rate = 60.0  # Hz
        self.timer = self.create_timer(1.0/self.publish_rate, self.timer_cb)

        # Once both current_pos and landing_pos are known -> plan trajectory
        self.get_logger().info('LandingTrajNode initialized. Waiting for current position...')

    # ------------------------------------------------------------------

    def pose_cb(self, msg: PoseStamped):
        self.current_pos = np.array([
            msg.pose.position.x,
            msg.pose.position.y,
            msg.pose.position.z
        ])

        if self.landing_pos is None:
            # Try to fetch landing position once we have current pos
            self.request_landing_position()

        if (self.current_pos is not None) and (self.landing_pos is not None) and not self.have_path:
            self.plan_trajectory()
            self.have_path = True

    # ------------------------------------------------------------------

    def future_callback(self, future):
        if future.result() is not None:
            landing_pos_msg = future.result().landing_pos
            self.landing_pos = np.array([landing_pos_msg.lat, landing_pos_msg.lon, landing_pos_msg.elv])
            self.get_logger().info(f"Received landing position: ({self.landing_pos[0]}, {self.landing_pos[1]}, {self.landing_pos[2]})")
        else:
            self.get_logger().warn('Landing service call failed or returned no data')


    def request_landing_position(self):
        """Request landing position from the master box node via DroneLandingService."""
        self.get_logger().info('Requesting landing position from master box...')
        req = DroneLandingService.Request()
        # For now, use current_pos as lat/lon/elv (replace with actual conversion if needed)
        if self.current_pos is None:
            self.get_logger().warn('Current position not available for landing request.')
            return
        pos_msg = PositionMessage()
        pos_msg.lat = self.current_pos[0]
        pos_msg.lon = self.current_pos[1]
        pos_msg.elv = self.current_pos[2]
        pos_msg.drone_id = 'drone69'
        req.drone_pos = pos_msg

        future = self.cli.call_async(req)
        future.add_done_callback(self.future_callback)

    # ------------------------------------------------------------------

    def plan_trajectory(self):
        """Constructs 2-segment cubic trajectory: current -> above -> land."""
        if self.current_pos is None or self.landing_pos is None:
            return

        above = self.landing_pos + np.array([0.0, 0.0, 1.0])  # 1m above landing point
        self.waypoints = [self.current_pos, above, self.landing_pos]

        # --- Build segments ---
        self.segments = []
        v0 = np.zeros(3)
        a0 = np.zeros(3)
        t_accum = 0.0

        for i in range(len(self.waypoints)-1):
            p0 = self.waypoints[i]
            p1 = self.waypoints[i+1]

            d = np.linalg.norm(p1 - p0)
            T = max(1.0, d / 0.5)  # slower descent: 0.5 m/s nominal
            t_accum += T
            coeffs_xyz = []

            for axis in range(3):
                coeffs = cubic_coeffs_from_boundary(p0[axis], p1[axis], v0[axis], a0[axis], T)
                coeffs_xyz.append(coeffs)
            self.segments.append(coeffs_xyz)

        # --- Time allocation ---
        self.total_time = t_accum
        self.get_logger().info(f"Total trajectory time: {self.total_time:.2f} seconds")
