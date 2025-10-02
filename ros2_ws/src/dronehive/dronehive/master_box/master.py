# ROS2 imports
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

from rclpy.task import Future
from std_msgs.msg import String

# Project specific imports
from dronehive_interfaces.msg import BoxBroadcastMessage
from dronehive_interfaces.srv import RequestDroneLanding, BoxBroadcastService
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
		self.client_manager = dh.ServiceClientManager(self, max_clients=32)

		# If the box is not initialised (aka setup and cofirmed by the GUI) it will publish its position and ID until it is
		# initialised. Once the initialisation is confirmed, it will call the initialise_connections method.
		if not self.config.initialised:
			self.get_logger().info("Box not initialised yet. Waiting for initialisation...")
			self.initialiser = dh.Initialiser(self, self.config, self.initialise_connections)
			return

		# When the box is initialised at startup we can directly initialise the connections.
		# If everything is fine, the initialiser will be None.
		self.initialise_connections()


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

		self.create_subscription(
			BoxBroadcastMessage,
			dh.DRONEHIVE_BOX_INITIALISE_TOPIC,
			self.__init_new_slave_box,
			qos_profile
		)

		# Publishers
		self.slave_box_confirm_init_pub = self.create_publisher(
			BoxBroadcastMessage,
			dh.DRONEHIVE_NEW_SLAVE_BOX_CONFIMED_TOPIC,
			qos_profile
		)

		self.deinitialise_slave_box_pub = self.create_publisher(
			String,
			dh.DRONEHIVE_DEINITIALISE_SLAVE_BOX_TOPIC,
			qos_profile
		)


	def create_services(self) -> None:
		self.create_service(
			RequestDroneLanding,
			dh.DRONEHIVE_DRONE_LAND_REQUEST,
			self.find_best_lending_place
		)


	def create_actions(self) -> None:
		pass


	#########################
	# Callbacks and methods #
	#########################

	def handle_new_slave_box_response(self, response_future: Future) -> None:
		self.get_logger().info("Received response from box broadcast service.")
		try:
			response: BoxBroadcastService.Response = response_future.result()
		except Exception as e:
			self.get_logger().error(f'Service call failed: {e}')
			return

		if response is None or not response.confirm:
			self.get_logger().error("New slave box NOT confirmed from service. Check the box ID and try again.")
			return

		self.get_logger().info(f"New slave box confirmed for box ID: {response.box_id}")

		# Publish the confirmation to the new slave box
		confirm_msg = BoxBroadcastMessage()
		confirm_msg.box_id = response.box_id
		confirm_msg.landing_pos = response.landing_pos
		self.slave_box_confirm_init_pub.publish(confirm_msg)

		self.config.linked_box_ids.append(response.box_id)
		dh.dronehive_update_config(self.config)


	def __init_new_slave_box(self, msg: BoxBroadcastMessage) -> None:
		request = BoxBroadcastService.Request()
		request.box_id = msg.box_id
		request.landing_pos = msg.landing_pos

		self.get_logger().info(f"Initialisation request for new slave box ID: '{request.box_id}', landing position: '{request.landing_pos}'. Forwarding to service...")
		self.client_manager.call_async(
			BoxBroadcastService,
			dh.DRONEHIVE_BOX_BROADCAST_SERVICE,
			request,
			self.handle_new_slave_box_response,
			None
		)


	def _deinitialise_box_callback(self, msg: String) -> None:
		if msg.data != self.config.box_id:
			self.get_logger().info(f"Deinitialise request for different box ID: {msg.data}. Forwarding...")
			self.deinitialise_slave_box_pub.publish(msg)

			if msg.data in self.config.linked_box_ids:
				self.config.linked_box_ids.remove(msg.data)
				dh.dronehive_update_config(self.config)

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

		def request_drone_landing_response(response: Future) -> None:
			try:
				res: RequestDroneLanding.Response = response.result()
			except Exception as e:
				self.get_logger().error(f'Service call failed: {e}')
				return

			if not res.confirm:
				self.get_logger().error("Landing position NOT confirmed from service. Check the box ID and try again.")
				return

			self.get_logger().info("Landing position confirmed by drone.")


		self.client_manager.call_async(
			RequestDroneLanding,
			dh.DRONEHIVE_DRONE_LAND_REQUEST,
			request_drone_landing_request,
			request_drone_landing_response
		)


	def find_best_lending_place(self, request: RequestDroneLanding.Request, response: RequestDroneLanding.Response) -> None:
		pass
