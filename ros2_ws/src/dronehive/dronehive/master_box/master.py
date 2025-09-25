# ROS2 imports
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

from std_msgs.msg import Bool, String

# Project specific imports
from dronehive_interfaces.msg import PositionMessage
import dronehive.utils as dh


# Python imports
import json
from pathlib import Path

qos_profile = QoSProfile(
	reliability=QoSReliabilityPolicy.BEST_EFFORT,
	durability=QoSDurabilityPolicy.VOLATILE,
	history=QoSHistoryPolicy.KEEP_LAST,
	depth=1
)

class MasterBoxNode(Node):
	def __init__(self):
		super().__init__('master_box_node')

		self.config: dh.Config = dh.dronehive_initialise()

		# If the box is not initialised (aka setup and cofirmed by the GUI) it will publish its position and ID until it is
		# initialised. Once the initialisation is confirmed, it will call the initialise_connections method.
		if not self.config.initialised:
			self.initialiser = dh.Initialiser(self, self.config, self.initialise_connections)
			self.get_logger().info("Box not initialised yet. Waiting for initialisation...")
			return

		# When the box is initialised at startup we can directly initialise the connections.
		# If everything is fine, the initialiser will be None.
		self.initialise_connections()

	##############################
	# Callbacks and methods here #
	##############################

	def initialise_connections(self):
		self.get_logger().info("Initialising connections...")

		self.create_messages()
		self.create_services()
		self.create_actions()

		# Drop the initialiser to free memory
		self.initialiser = None

	def create_messages(self):
		# Subscribers
		# In the code of the method the subscriber is already saved in internal variable.
		self.create_subscription(
			String,
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

	def send_landing_position_to_drone(self, pos: String):
		self._pub_landing_pos_to_drone.publish(self.config.lending_position)

