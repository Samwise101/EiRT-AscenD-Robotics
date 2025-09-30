# ROS2 imports
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

from rclpy.task import Future
from std_msgs.msg import String

# Project specific imports
from dronehive_interfaces.msg import PositionMessage
from dronehive_interfaces.srv import RequestDroneLanding
import dronehive.utils as dh

qos_profile = QoSProfile(
	reliability=QoSReliabilityPolicy.RELIABLE,
	durability=QoSDurabilityPolicy.VOLATILE,
	history=QoSHistoryPolicy.KEEP_LAST,
	depth=1
)

class MasterBoxNode(Node):
	def __init__(self) -> None:
		super().__init__('master_box_node')

		self.config: dh.Config = dh.dronehive_initialise()

		# If the box is not initialised (aka setup and cofirmed by the GUI) it will publish its position and ID until it is
		# initialised. Once the initialisation is confirmed, it will call the initialise_connections method.
		if not self.config.initialised:
			self.get_logger().info("Box not initialised yet. Waiting for initialisation...")
			self.initialiser = dh.Initialiser(self, self.config, self.initialise_connections)
			return

		# When the box is initialised at startup we can directly initialise the connections.
		# If everything is fine, the initialiser will be None.
		self.initialise_connections()
		self.client_manager = dh.ServiceClientManager(self, max_clients=32)


	def initialise_connections(self) -> None:
		self.get_logger().info("Initialising connections...")

		self.create_messages()
		self.create_services()
		self.create_actions()

		# Drop the initialiser to free memory
		self.initialiser = None
		self.get_logger().info(f"Initialised with config : {self.config}")


	##########################
	# Initialisation methods #
	##########################

	def create_messages(self) -> None:
		# Subscribers
		# In the code of the method the subscriber is already saved in internal variable.
		self.create_subscription(
			String,
			dh.DRONEHIVE_DEINITIALISE_BOX_TOPIC,
			self._deinitialise_box_callback,
			qos_profile
		)

		self.create_subscription(
			String,
			dh.DRONEHIVE_REQUEST_LANDING_POS_TOPIC,
			self.send_landing_position_to_drone,
			qos_profile
		)

		# Publishers


	def create_services(self) -> None:
		pass


	def create_actions(self) -> None:
		pass


	#########################
	# Callbacks and methods #
	#########################

	def _deinitialise_box_callback(self, msg: String) -> None:
		if msg.data != self.config.box_id:
			return

		self.get_logger().warn("Deinitialising box as requested...")
		dh.dronehive_deinitialise(self.config)

		def deferred_reinit():
			self.get_logger().warn("Box deinitialised. Restarting initialiser...")
			self.initialiser = dh.Initialiser(self, self.config, self.initialise_connections)

		# Defer to next spin cycle
		self.timer = self.create_timer(0.1, deferred_reinit)


	def send_landing_position_to_drone(self, pos: String) -> None:
		def request_drone_landing_request() -> RequestDroneLanding.Request:
			req = RequestDroneLanding.Request()
			req.landing_pos = self.config.lending_position
			return req

		def request_drone_landing_response_2(response: Future) -> None:
			try:
				res: RequestDroneLanding.Response = response.result()
			except Exception as e:
				self.get_logger().error(f'Service call failed: {e}')
				return

			if not res.confirm:
				self.get_logger().error("Landing position NOT confirmed from service. Check the box ID and try again.")
				return

			self.get_logger().info("Landing position confirmed by drone.")

		def request_drone_landing_response(response: RequestDroneLanding.Response) -> None:
			if not response.confirm:
				self.get_logger().error("Landing position NOT confirmed from service. Check the box ID and try again.")
				return

			self.get_logger().info("Landing position confirmed by drone.")
			# self.drone_landing_client.destory()
			# self.drone_landing_client = None

		# self.drone_landing_client = dh.ServiceLessClient(
		# 	self,
		# 	RequestDroneLanding,
		# 	dh.DRONEHIVE_DRONE_LAND_REQUEST(pos.data),
		# 	request_drone_landing_request,
		# 	request_drone_landing_response,
		# )

		self.client_manager.call_async(
			RequestDroneLanding,
			dh.DRONEHIVE_DRONE_LAND_REQUEST(pos.data),
			request_drone_landing_request,
			request_drone_landing_response_2
		)

