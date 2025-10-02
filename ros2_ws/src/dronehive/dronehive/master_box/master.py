# ROS2 imports
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

from rclpy.task import Future
from std_msgs.msg import String

# Project specific imports
from dronehive_interfaces.msg import BoxBroadcastMessage, BoxSetupConfirmationMessage
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
		self.uninitialised_slave_boxes = {}

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
			dh.DRONEHIVE_INITIALISE_SLAVE_BOX_TOPIC,
			self.__init_new_slave_box,
			qos_profile
		)
		self.slave_publish_timer = self.create_timer(2.0, self.__publish_slave_boxes)
		self.slave_publish_timer.cancel()

		self._sub_confirm_initialisation = self.create_subscription(
			BoxSetupConfirmationMessage,
			dh.DRONEHIVE_NEW_BOX_CONFIMED_TOPIC,
			self._confirm_box_initialisation,
			qos_profile
		)

		# Publishers
		self.slave_box_confirm_init_pub = self.create_publisher(
			BoxSetupConfirmationMessage,
			dh.DRONEHIVE_NEW_SLAVE_BOX_CONFIMED_TOPIC,
			qos_profile
		)

		self.deinitialise_slave_box_pub = self.create_publisher(
			String,
			dh.DRONEHIVE_DEINITIALISE_SLAVE_BOX_TOPIC,
			qos_profile
		)

		self._pub_box_broadcast = self.create_publisher(
			BoxBroadcastMessage,
			dh.DRONEHIVE_NEW_BOX_TOPIC,
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

	def _confirm_box_initialisation(self, msg: BoxSetupConfirmationMessage):
		# The message is for a slave box
		if self.config.box_id != msg.box_id:
			self.get_logger().info(f"Box initialization confirmed for slave box ID: '{msg.box_id}'. Forwarding to service...")
			self.slave_box_confirm_init_pub.publish(msg)
			self.config.linked_box_ids.append(msg.box_id)
			self.slave_publish_timer.cancel()
			dh.dronehive_update_config(self.config)
			return

		# The message is for this master box
		if msg.confirm:
			self.get_logger().info("Box initialization confirmed.")
			self.config.initialised = True
			self.config.landing_position = msg.landing_pos
			dh.dronehive_update_config(self.config)
			self._pub_box_broadcast.publish(msg)


	def __publish_slave_boxes(self) -> None:
		if len(self.uninitialised_slave_boxes) == 0:
			self.slave_publish_timer.cancel()
			return

		# Publish all uninitialised slave boxes
		for box_id, msg in self.uninitialised_slave_boxes.items():
			self.get_logger().info(f"Publishing initialisation request for slave box ID: '{box_id}', landing position: '{msg.landing_pos}' to service...")
			self._pub_box_broadcast.publish(msg)


	def __init_new_slave_box(self, msg: BoxBroadcastMessage) -> None:
		request = BoxBroadcastService.Request()
		request.box_id = msg.box_id
		request.landing_pos = msg.landing_pos

		self.uninitialised_slave_boxes[msg.box_id] = msg
		self.slave_publish_timer.reset()
		self.get_logger().info(f"Initialisation request for new slave box ID: '{request.box_id}', landing position: '{request.landing_pos}'. Forwarding to service...")


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
		request = RequestDroneLanding.Request()
		request.box_id = self.config.box_id
		request.landing_pos = self.config.landing_position
		self.get_logger().info(f"Sending landing position '{request.landing_pos}' for box ID '{request.box_id}' to drone...")

		def request_drone_landing_response(response: Future) -> None:
			try:
				res: RequestDroneLanding.Response = response.result()

			except Exception as e:
				self.get_logger().error(f'Service call failed: {e}')
				return

			if not res.received:
				self.get_logger().error("Landing position NOT confirmed from service. Check the box ID and try again.")
				return

			self.get_logger().info("Landing position confirmed by drone.")


		self.client_manager.call_async(
			RequestDroneLanding,
			dh.DRONEHIVE_DRONE_LAND_REQUEST,
			request,
			request_drone_landing_response,
			None
		)


	def find_best_lending_place(self, request: RequestDroneLanding.Request, response: RequestDroneLanding.Response) -> RequestDroneLanding.Response:
		return response
