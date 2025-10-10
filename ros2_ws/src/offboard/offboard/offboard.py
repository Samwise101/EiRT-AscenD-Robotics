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
from dronehive_interfaces.msg import PositionMessage
from dronehive_interfaces.srv import RequestDroneLanding

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

		self.sub_pose = self.create_subscription(
			PoseStamped,
			'/mavros/vision_pose/pose',
			self.update_last_pos,
			10)

		self.sub_target_pose = self.create_subscription(
			PoseStamped,
			'/mavros/vision_pose/target_pose',
			self.receive_target_pos,
			10)

		# Service clients
		self.set_mode_client = self.create_client(SetMode, '/mavros/set_mode')
		self.arming_client = self.create_client(CommandBool, '/mavros/cmd/arming')

		# Simulation mode argument
		self.simulation_mode = simulation_mode

		# Variables

		self.current_state = State()
		self.current_pose = PoseStamped()
		self.offboard_active = False
		self.altitude = 2.0
		self.i = 0
		self.pose_target = None
		self.target_locked = False
		self.simple_traj = None
		self.stop = False
		self.target_reached = False
		self.risen = False
		self.last_pos = None
		self.distance = None
		self.descent = False
		self._auto_started = False

		# Control flags / counters
		self.published_count = 0		  # count initial setpoints
		self.startup_required = 50	   # publish ~50 setpoints (at 10Hz => 5s) before mode change
		self.offboard_requested = False
		self.arm_requested = False
		self.offboard_active = False

		#TARGET POINT BEFORE LANDING
		self.pose_descent = PoseStamped()
		self.pose_descent.pose.position.x = 0.0
		self.pose_descent.pose.position.y = 0.0
		self.pose_descent.pose.position.z = 2.0

		rot = get_quaternion_from_euler(0, 0, 0)
		self.pose_descent.pose.orientation.x = rot[0]
		self.pose_descent.pose.orientation.y = rot[1]
		self.pose_descent.pose.orientation.z = rot[2]
		self.pose_descent.pose.orientation.w = rot[3]

		#TARGET POINT FOR LANDING
		self.pose_land = PoseStamped()
		self.pose_land.pose.position.x = 0.0
		self.pose_land.pose.position.y = 0.0
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

		# Setpoint message
		self.sp = PoseStamped()

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

	def update_last_pos(self, pos: PoseStamped):
		self.last_pos = pos

	def receive_target_pos(self, pos: PoseStamped):
		self.pose_target = pos

	def state_cb(self, msg: State):
		self.current_state = msg

	def pose_cb(self, msg: PoseStamped):
		self.current_pose = msg

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
			return
		#self.risen = True

	def go_to_pos(self, pos: PoseStamped, target_flag):

		self.sp.pose.position.x = pos.pose.position.x
		self.sp.pose.position.y = pos.pose.position.y
		self.sp.pose.position.z = pos.pose.position.z

		self.sp.pose.orientation.x = pos.pose.orientation.x
		self.sp.pose.orientation.y = pos.pose.orientation.y
		self.sp.pose.orientation.z = pos.pose.orientation.z
		self.sp.pose.orientation.w = pos.pose.orientation.w

		self.dest_callback(pos, target_flag)

	def send_landing_request(self, box_id, x, y, z):
		self.landing_req.box_id = box_id


	def dest_callback(self, pos: PoseStamped, target_flag):
		dx = self.current_pose.pose.position.x - pos.pose.position.x
		dy = self.current_pose.pose.position.y - pos.pose.position.x
		dz = self.current_pose.pose.position.z - pos.pose.position.x

		self.distance = (dx**2+dy**2+dz**2)**0.5
		self.get_logger().info(f"Distance from A to B: {self.distance}")

		#Stop the drone at target

		if self.distance < 2.5:
			self.sp.pose.position.x = 0.0
			self.sp.pose.position.y = 0.0
			self.sp.pose.position.z = self.altitude

			rot = get_quaternion_from_euler(0, 0, -math.pi * self.i / 100)
			self.sp.pose.orientation.x = rot[0]
			self.sp.pose.orientation.y = rot[1]
			self.sp.pose.orientation.z = rot[2]
			self.sp.pose.orientation.w = rot[3]

			target_flag = True
			self.get_logger().info("Target reached")

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

		if not self.risen:
			self.get_logger().info(f"Rising to target position")
			self.rise()
			return

		if self.risen and not self.target_reached:
			self.get_logger().info(f"Going to target position")
			self.go_to_pos(self.pose_test, self.target_reached)
			return

		elif self.altitude > 0.0:
			self.get_logger().info(f"Descending to target position")
			while(not self.descent):
				self.go_to_pos(self.pose_descent, self.descent)
			return

		if self.descent:
			self.get_logger().info(f"Landing to target position")
			self.go_to_pos(self.pose_land)
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

