from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy
from std_msgs.msg import Bool, String

# Project specific imports
import dronehive.utils as dh
from dronehive_interfaces.msg import (
	BoxBroadcastMessage,
)

from typing import Callable

qos_profile = QoSProfile(
	reliability=QoSReliabilityPolicy.BEST_EFFORT,
	durability=QoSDurabilityPolicy.TRANSIENT_LOCAL,
	history=QoSHistoryPolicy.KEEP_LAST,
	depth=1
)

class Initialiser:
	def __init__(self, node: Node, config: dh.Config, on_initialised: Callable[..., None] = lambda: None):
		self.node = node
		self.config = config
		self.on_initialised = on_initialised

		# In case the box is not initialised, it will broadcast its position
		if not self.config.initialised:
			node.get_logger().warn("The configuration is not initialised. Broadcasting box.")
			self._pub_box_broadcast = node.create_publisher(
				BoxBroadcastMessage,
				dh.DRONEHIVE_NEW_BOX_TOPIC,
				qos_profile
			)

			self._sub_confirm_initialisation = node.create_subscription(
				Bool,
				dh.DRONEHIVE_NEW_BOX_CONFIMED_TOPIC,
				self._confirm_box_initialisation,
				qos_profile
			)

			self._initialise_timer = node.create_timer(1.0, self._broadcast_box_timer_callback)

	def _broadcast_box_timer_callback(self):
		self.node.get_logger().info("Creating box broadcast message...")

		msg = BoxBroadcastMessage()
		msg.box_id = self.config.box_id
		msg.landing_pos.lat = self.config.lending_position.lat
		msg.landing_pos.lon = self.config.lending_position.lon
		msg.landing_pos.elv = self.config.lending_position.elv

		self.node.get_logger().info("Broadcasting box position...")
		self._pub_box_broadcast.publish(msg)

	def _confirm_box_initialisation(self, msg: Bool):
		if msg.data:
			self.node.get_logger().info("Box initialization confirmed.")
			self.config.initialised = True
			dh.dronehive_update_config(self.config)

			self.node.destroy_timer(self._initialise_timer)
			self.node.destroy_publisher(self._pub_box_broadcast)
			self.node.destroy_subscription(self._sub_confirm_initialisation)

			self.on_initialised()

		else:
			self.node.get_logger().warn("Box initialization NOT confirmed. Continuing broadcasting.")

