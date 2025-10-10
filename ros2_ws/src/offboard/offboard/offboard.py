#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math
import numpy as np
import rclpy
import argparse
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, qos_profile_sensor_data
import time

from geometry_msgs.msg import PoseStamped
from mavros_msgs.msg import State
from mavros_msgs.srv import SetMode, CommandBool
# Project specific imports
#from dronehive_interfaces.msg import PositionMessage
#from dronehive_interfaces.srv import RequestDroneLanding

def get_quaternion_from_euler(roll, pitch, yaw):
    """
	Convert an Euler angle to a quaternion.

	Input
		:param roll: The roll (rotation around x-axis) angle in radians.
		:param pitch: The pitch (rotation around y-axis) angle in radians.
		:param yaw: The yaw (rotation around z-axis) angle in radians.

	Output
		:return qx, qy, qz, qw: The orientation in quaternion [x,y,z,w] format
	"""
    qx = np.sin(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) - np.cos(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
    qy = np.cos(roll/2) * np.sin(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.cos(pitch/2) * np.sin(yaw/2)
    qz = np.cos(roll/2) * np.cos(pitch/2) * np.sin(yaw/2) - np.sin(roll/2) * np.sin(pitch/2) * np.cos(yaw/2)
    qw = np.cos(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
    return [qx, qy, qz, qw]


class OffboardControl(Node):

    def __init__(self, simulation_mode=False):
        super().__init__('offboard_ctrl')

        # QoS
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)

        # Publishers
        self.local_pos_pub = self.create_publisher(PoseStamped, '/mavros/setpoint_position/local', qos)

        # Subscribers
        self.state_sub = self.create_subscription(State, '/mavros/state', self.state_cb, 10)
        self.pose_sub = self.create_subscription(PoseStamped, '/mavros/local_position/pose', self.pose_cb, qos_profile_sensor_data)
        
        #self.sub_pose = self.create_subscription(
		#	PoseStamped,
		#	'/mavros/vision_pose/pose',
		#	self.update_last_pos,
		#	10)
        
        # Service clients
        self.set_mode_client = self.create_client(SetMode, '/mavros/set_mode')
        self.arming_client = self.create_client(CommandBool, '/mavros/cmd/arming')

        # === Service Server ===
        # The box node will call this to send the landing position.
        #self.landing_service = self.create_service(
        #    RequestDroneLanding,
        #    '/drone_landing_request',
        #    self.handle_landing_request
        #)

        # Simulation mode argument
        self.simulation_mode = simulation_mode

        # Variables

        self.current_state = State()
        self.current_pose = PoseStamped()
        self.altitude = 2.0
        self.i = 0
        self.target_reached = False
        self.risen = False
        self.distance = None
        self.trajectory = None
        self.index = 0
        # Setpoint message
        self.sp = PoseStamped()

		#TARGET POINT FOR LANDING
        self.pose_land = PoseStamped()
        self.pose_land.pose.position.x = self.sp.pose.position.x
        self.pose_land.pose.position.y = self.sp.pose.position.y
        self.pose_land.pose.position.z = 0.0

		#TEST TARGET POINT
        self.pose_test = PoseStamped()
        self.pose_test.pose.position.x = 5.0
        self.pose_test.pose.position.y = 4.0
        self.pose_test.pose.position.z = 7.0
        
        rot = get_quaternion_from_euler(0, 0, 0)
        self.pose_test.pose.orientation.x = rot[0]
        self.pose_test.pose.orientation.y = rot[1]
        self.pose_test.pose.orientation.z = rot[2]
        self.pose_test.pose.orientation.w = rot[3]

        #Wait for services
        self.get_logger().info("Waiting for services...")
        self.set_mode_client.wait_for_service()
        self.arming_client.wait_for_service()
        self.get_logger().info("Services ready")

        # Timer for publishing setpoints
        self.timer = self.create_timer(0.1, self.timer_cb)

        # Background timer to manage mode switching
        # ONLY IN SIMULATION MODE
        if(self.simulation_mode):
            self.create_timer(2.0, self.sim_mode_sw)

        self.get_logger().info(f"Starting OffboardControl (simulation_mode={self.simulation_mode})")

    def state_cb(self, msg: State):
        self.current_state = msg

    def pose_cb(self, msg: PoseStamped):
        self.current_pose = msg

    def create_traj(self, waypoints, n_points_per_segment=50, yaw_fixed=0.0):
        
        # Extract XYZ positions from PoseStamped waypoints
        positions = np.array([[wp.pose.position.x,
                           wp.pose.position.y,
                           wp.pose.position.z] for wp in waypoints])

        # Generate smooth trajectory using cubic interpolation per segment
        self.trajectory = []
        for i in range(len(positions) - 1):

           p0 = positions[i]
           p1 = positions[i + 1]

           t = np.linspace(0, 1, n_points_per_segment)
           t2 = t**2
           t3 = t**3
           interp = (2*t3 - 3*t2 + 1)[:, None]*p0 + (-2*t3 + 3*t2)[:, None]*p1

           for j in range(n_points_per_segment):
               pose = PoseStamped()
               pose.pose.position.x = float(interp[j, 0])
               pose.pose.position.y = float(interp[j, 1])
               pose.pose.position.z = float(interp[j, 2])

               # Convert yaw to quaternion
               qz = math.sin(yaw_fixed / 2.0)
               qw = math.cos(yaw_fixed / 2.0)
               pose.pose.orientation.z = qz
               pose.pose.orientation.w = qw

               self.trajectory.append(pose)
        self.get_logger().info("Created target trajectory")

    def timer_cb(self):
        # publish setpoints

        self.sp.header.stamp = self.get_clock().now().to_msg()
        #self.circle_callback()
        self.test_timer_callback()
        self.publish_setpoint()

    # Switch flight modes automaticly
    # ONLY IN SIMULATION MODE
    def sim_mode_sw(self):
        if self.current_state.mode != "OFFBOARD":
            req = SetMode.Request(custom_mode="OFFBOARD")
            self.set_mode_client.call_async(req)
            self.get_logger().info("Requesting OFFBOARD mode...")
        elif not self.current_state.armed:
            req = CommandBool.Request(value=True)
            self.arming_client.call_async(req)
            self.get_logger().info("Requesting arm...")

    def rise(self):
        self.sp.pose.position.x = 0.0
        self.sp.pose.position.y = 0.0
        self.sp.pose.position.z = self.altitude

        if(self.current_pose.pose.position.z >= self.altitude-0.5):
            self.risen = True
            self.get_logger().info("Risen to desired altitude")
            self.create_traj([self.sp, self.pose_test],40)
            return

    def go_to_pos(self, pos: PoseStamped):

        self.sp.pose.position.x = pos.pose.position.x
        self.sp.pose.position.y = pos.pose.position.y
        self.sp.pose.position.z = pos.pose.position.z

        self.sp.pose.orientation.x = pos.pose.orientation.x
        self.sp.pose.orientation.y = pos.pose.orientation.y
        self.sp.pose.orientation.z = pos.pose.orientation.z
        self.sp.pose.orientation.w = pos.pose.orientation.w

    def send_landing_request(self, box_id, x, y, z):
        self.landing_req.box_id = box_id


    def dest_callback(self, pos: PoseStamped):
        dx = self.current_pose.pose.position.x - pos.pose.position.x 
        dy = self.current_pose.pose.position.y - pos.pose.position.x
        dz = self.current_pose.pose.position.z - pos.pose.position.x

        self.distance = (dx**2+dy**2+dz**2)**0.5
        self.get_logger().info(f"Distance from A to B: {self.distance}")

		#Stop the drone at target

        if self.distance < 2.3:
            self.get_logger().info("Target reached")
            return True

    def circle_callback(self):
        # Circle trajectory at fixed altitude
        angle = math.radians(self.i)
        radius = 2.0
        self.sp.pose.position.x = radius * math.cos(angle)
        self.sp.pose.position.y = radius * math.sin(angle)
        self.sp.pose.position.z = self.altitude

        q = get_quaternion_from_euler(0, 0, angle)
        self.sp.pose.orientation.x = q[0]
        self.sp.pose.orientation.y = q[1]
        self.sp.pose.orientation.z = q[2]
        self.sp.pose.orientation.w = q[3]

        self.i = (self.i + 2) % 360

        self.local_pos_pub.publish(self.sp)
        self.get_logger().info(f"Publishing circle setpoints at Z={self.altitude:.1f}")

    def test_timer_callback(self):
        if self.pose_test == None:
            self.get_logger().info("Waiting for target position")
            return
        else:
            if not self.risen:
                self.get_logger().info(f"Target position received at X={self.pose_test.pose.position.x}, Y={self.pose_test.pose.position.y}, Z={self.pose_test.pose.position.z}")
                self.rise()
                return
            elif self.risen and not self.target_reached:
                self.get_logger().info("Executing trajectory")
                if self.index >= len(self.trajectory):
                    self.get_logger().info("Reached end of trajectory")
                    self.target_reached = True
                    return
                self.sp = self.trajectory[self.index]
                if self.dest_callback(self.trajectory[self.index]):
                    self.get_logger().info(f"Moving to next trajectory element {self.index}")
                    self.index+=1
                    return
                return
            if self.target_reached:
                self.get_logger().info(f"Landing")
                self.go_to_pos(self.pose_land)
                return
            return
        
    def publish_setpoint(self):
        self.local_pos_pub.publish(self.sp)


def main(args=None):
    parser = argparse.ArgumentParser(description="Offboard control node with simulation toggle.")
    parser.add_argument(
        "--simulation",
        action="store_true",
        help="Run in simulation mode (auto arm + offboard + takeoff)."
    )
    cli_args = parser.parse_args()

    rclpy.init(args=args)
    node = OffboardControl(simulation_mode=cli_args.simulation)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down node.")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()