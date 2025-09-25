# ROS2 imports
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

from std_msgs.msg import Bool

# Project specific imports
from dronehive_interfaces.msg import (
	BoxBroadcastMessage,
	PositionMessage
)

import dronehive.utils as dh


# Python imports
import json
from pathlib import Path

qos_profile = QoSProfile(
	reliability=QoSReliabilityPolicy.BEST_EFFORT,
	durability=QoSDurabilityPolicy.TRANSIENT_LOCAL,
	history=QoSHistoryPolicy.KEEP_LAST,
	depth=1
)

class MasterBoxNode(Node):
	def __init__(self):
		self.lending_position = PositionMessage()
		self.initialised: bool = False

		self.config: dh.Config = dh.dronehive_initialise()

		# In case the box is not initialised, it will broadcast its position
		if not self.config.initialised:
			self.get_logger().warn("The configuration is not initialised. Broadcasting box.")
			self._pub_box_broadcast = self.create_publisher(
				BoxBroadcastMessage,
				dh.DRONEHIVE_NEW_BOX_TOPIC,
				qos_profile
			)

			self._sub_confirm_initialisation = self.create_subscription(
				Bool,
				dh.DRONEHIVE_NEW_BOX_CONFIMED_TOPIC,
				self._confirm_box_initialisation,
				qos_profile
			)

			self._initialise_timer = self.create_timer(1.0, self._broadcast_box_timer_callback)
			return


		############
		# Messages #
		############
		self.create_messages()

		############
		# Services #
		############
		self.create_services()

		###########
		# Actions #
		###########
		self.create_actions()

	##############################
	# Callbacks and methods here #
	##############################

	def _broadcast_box_timer_callback(self):
		self.get_logger().info("Broadcasting box position...")

		msg = BoxBroadcastMessage()
		msg.box_id = self.config.box_id
		msg.landing_pos = self.config.lending_position

		self._pub_box_broadcast.publish(msg)

	def _confirm_box_initialisation(self, msg: Bool):
		if msg.data:
			self.get_logger().info("Box initialization confirmed.")
			self.config.initialised = True
			dh.dronehive_update_config(self.config)

			self.destroy_timer(self._initialise_timer)
			self.destroy_publisher(self._pub_box_broadcast)
			self.destroy_subscription(self._sub_confirm_initialisation)

			self.create_messages()

		else:
			self.get_logger().warn("Box initialization NOT confirmed. Continuing broadcasting.")

	def create_messages(self):
		# Subscribers
		# In the code of the method the subscriber is already saved in internal variable.
		self.create_subscription(
			PositionMessage,
			dh.DRONEHIVE_ADD_LANDING_POS_TOPIC,
			self.add_new_box,
			qos_profile
		)

		self.create_subscription(
			PositionMessage,
			dh.DRONEHIVE_REQUEST_LANDING_POS_TOPIC,
			self.send_landing_position_to_drone,
			qos_profile
		)

		# Publishers
		self._pub_landing_pos_to_drone = self.create_publisher(
			PositionMessage,
			dh.DRONEHIVE_DRONE_TOPIC,
			qos_profile
		)

	def create_services(self):
		pass

	def create_actions(self):
		pass

	def add_new_box(self, pos: PositionMessage):
		self.get_logger().info(__name__)
		pass

	def send_landing_position_to_drone(self, pos: PositionMessage):
		self._pub_landing_pos_to_drone.publish(pos)

