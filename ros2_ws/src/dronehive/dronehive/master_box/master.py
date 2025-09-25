import rclpy
from rclpy.node import Node
from dronehive_interfaces.msg import PositionMessage

from dronehive.utils.position import Position
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

qos_profile = QoSProfile(
	reliability=QoSReliabilityPolicy.BEST_EFFORT,
	durability=QoSDurabilityPolicy.TRANSIENT_LOCAL,
	history=QoSHistoryPolicy.KEEP_LAST,
	depth=1
)

# TODO: send the landing location to the drone

class MasterBoxNode(Node):
	def __init__(self):
		self.lending_position = Position()

		############
		# Messages #
		############
			# Subscribers
			# In the code of the method the subscriber is already saved in internal vairable.
		self.create_subscription(
			PositionMessage,
			"/dronehive/add_landing_position",
			self.add_new_box,
			qos_profile
		)

			# Publishers
		self._pub_landing_pos_to_drone = self.create_publisher(
			PositionMessage,
			"/dronehive/drone",
			qos_profile
		)


		############
		# Services #
		############

		###########
		# Actions #
		###########

	def add_new_box(self, pos: PositionMessage):
		self.get_logger().info(__name__)
		pass


