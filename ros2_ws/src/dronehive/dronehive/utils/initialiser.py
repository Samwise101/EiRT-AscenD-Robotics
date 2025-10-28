from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy
from std_msgs.msg import Bool

# Project specific imports
import dronehive.utils as dh
from dronehive_interfaces.msg import (
	BoxBroadcastMessage,
	BoxSetupConfirmationMessage
)

from typing import Callable

qos_profile = QoSProfile(
	reliability=QoSReliabilityPolicy.BEST_EFFORT,
	history=QoSHistoryPolicy.KEEP_LAST,
	depth=1
)

class Initialiser:
	"""Class to handle the initialisation of a box node.

	This class removes all existing interfaces of the node and creates a publisher to broadcast the box position
	and a subscriber to listen for the confirmation of the initialisation. Once the initialisation is confirmed,
	it destroys the initialisation interfaces and calls the provided callback function

	Attributes:
	node: rclpy.node.Node - The ROS2 node to which the initialiser is attached
	config: dh.Config - The configuration object containing box details
	on_initialised: Callable[..., None] - A callback function to be called once the box is initialised
	"""
	def __init__(self, node: Node, config: dh.Config, on_initialised: Callable[..., None] = lambda: None):
		self.node = node
		self.config = config
		self.on_initialised = on_initialised

		# In case the box is not initialised, it will broadcast its position
		if not self.config.initialised:
			# Switch off all existing interfaces and switch to initialisation mode
			self.destroy_interfaces();

			node.get_logger().warn("The configuration is not initialised. Broadcasting box.")
			self._pub_box_broadcast = node.create_publisher(
				BoxBroadcastMessage,
				dh.DRONEHIVE_NEW_BOX_TOPIC,
				qos_profile
			)

			self._sub_confirm_initialisation = node.create_subscription(
				BoxSetupConfirmationMessage,
				dh.DRONEHIVE_NEW_BOX_CONFIMED_TOPIC,
				self._confirm_box_initialisation,
				qos_profile
			)

			self._initialise_timer = node.create_timer(1.0, self._broadcast_box_timer_callback)


	def destroy_interfaces(self):
		while self.node._publishers:
			self.node.destroy_publisher(self.node._publishers[0])
		while self.node._subscriptions:
			self.node.destroy_subscription(self.node._subscriptions[0])
		while self.node._clients:
			self.node.destroy_client(self.node._clients[0])
		while self.node._services:
			self.node.destroy_service(self.node._services[0])
		while self.node._timers:
			self.node.destroy_timer(self.node._timers[0])
		while self.node._guards:
			self.node.destroy_guard_condition(self.node._guards[0])


	def _broadcast_box_timer_callback(self):
		self.node.get_logger().info("Creating box broadcast message...")

		msg = BoxBroadcastMessage()
		msg.box_id = self.config.box_id
		msg.landing_pos.lat = self.config.landing_position.lat
		msg.landing_pos.lon = self.config.landing_position.lon
		msg.landing_pos.elv = self.config.landing_position.elv

		self.node.get_logger().info("Broadcasting box position...")
		self._pub_box_broadcast.publish(msg)


	def _confirm_box_initialisation(self, msg: BoxSetupConfirmationMessage):
		if msg.confirm:
			self.node.get_logger().info("Box initialization confirmed.")
			self.config.initialised = True
			self.config.landing_position = msg.landing_pos
			dh.dronehive_update_config(self.config)

			self.node.destroy_timer(self._initialise_timer)
			self.node.destroy_publisher(self._pub_box_broadcast)
			self.node.destroy_subscription(self._sub_confirm_initialisation)

			self.on_initialised()

		else:
			self.node.get_logger().warn("Box initialization NOT confirmed. Continuing broadcasting.")

