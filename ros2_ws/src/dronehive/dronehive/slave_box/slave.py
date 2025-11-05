from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy
from rclpy.task import Future
from std_msgs.msg import String, Bool

import dronehive.utils as dh

from dronehive_interfaces.msg import BoxBroadcastMessage, BoxSetupConfirmationMessage
from dronehive_interfaces.srv import BoxStatusService

qos_profile = QoSProfile(
	reliability=QoSReliabilityPolicy.BEST_EFFORT,
	history=QoSHistoryPolicy.KEEP_LAST,
	depth=1
)

class SlaveBoxNode(Node):
	def __init__(self) -> None:
		self.config: dh.Config = dh.dronehive_initialise()

		super().__init__(f"slave_box_node_{self.config.box_id}")

		# If the box is not initialised (aka setup and cofirmed by the GUI) it will publish its position and ID until it is
		# initialised. Once the initialisation is confirmed, it will call the initialise_connections method.
		if not self.config.initialised:
			self.box_init_interfaces()
			return

		# When the box is initialised at startup we can directly initialise the connections.
		# If everything is fine, the initialiser will be None.
		self.initialise_connections()
		self.client_manager = dh.ServiceClientManager(self, max_clients=32)


	def box_init_interfaces(self) -> None:
		self.__init_publisher = self.create_publisher(BoxBroadcastMessage, dh.DRONEHIVE_INITIALISE_SLAVE_BOX_TOPIC, qos_profile)
		self.__timer = self.create_timer(2.0, self._publish_initialisation)
		self.__confirm_subs = self.create_subscription(BoxSetupConfirmationMessage, dh.DRONEHIVE_NEW_SLAVE_BOX_CONFIMED_TOPIC, self._initialisation_confirmed_callback, qos_profile)


	def _publish_initialisation(self) -> None:
		msg = BoxBroadcastMessage()
		msg.box_id = self.config.box_id
		msg.landing_pos = self.config.landing_position

		self.get_logger().info(f"Publishing initialisation message: {msg}")
		self.__init_publisher.publish(msg)


	def _initialisation_confirmed_callback(self, msg: BoxBroadcastMessage) -> None:
		self.get_logger().info(f"Received initialisation confirmation message: {msg}")
		if msg.box_id == self.config.box_id:
			self.get_logger().info(f"Initialisation confirmed for box ID: {self.config.box_id}")
			self.config.initialised = True
			self.config.landing_position = msg.landing_pos
			self.config.save()

			# Destroy the initialisation publisher and timer
			self.destroy_publisher(self.__init_publisher)
			self.destroy_timer(self.__timer)
			self.destroy_subscription(self.__confirm_subs)

			# Now we can initialise the connections
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
			dh.DRONEHIVE_DEINITIALISE_SLAVE_BOX_TOPIC,
			self._deinitialise_box_callback,
			qos_profile
		)

		self.create_subscription(
			String,
			dh.DRONEHIVE_REQUEST_LANDING_POS_TOPIC,
			self.landing_drone_requested,
			qos_profile
		)

		# Publishers
		return


	def create_services(self) -> None:
		# self.create_service(
		# 	RequestDroneLanding,
		# 	dh.DRONEHIVE_DRONE_LAND_REQUEST,
		# 	self.find_best_lending_place
		# )

		self.create_service(
			BoxStatusService,
			dh.DRONEHIVE_BOX_STATUS_REQUEST_SERVICE,
			self.provide_box_status
		)


	def create_actions(self) -> None:
		pass

	##################
	# Callbacks etc. #
	##################

	def provide_box_status(self, request: BoxStatusService.Request, response: BoxStatusService.Response) -> BoxStatusService.Response:
		if request.box_id != self.config.box_id:
			response.accept = False
			return response

		response.accept = True
		response.landing_pos = self.config.landing_position
		response.drone_id = self.config.drone_id

		self.get_logger().info(f"Responding with landing position: {response.landing_pos} and drone ID: {response.drone_id}")
		return response


	def landing_drone_requested(self, msg: String) -> None:
		self.get_logger().info(f"Received landing position request for drone ID: {msg.data}")
		self.config.drone_id = msg.data
		self.config.save()


	def _deinitialise_box_callback(self, msg: String) -> None:
		if msg.data == self.config.box_id:
			self.get_logger().warn(f"Deinitialising box with ID: {self.config.box_id}")
			dh.dronehive_deinitialise(self.config)

			# Destroy all connections.
			self.destroy_interfaces()

			# Recreate the initialisation publisher and timer.
			self.box_init_interfaces()


	def destroy_interfaces(self) -> None:
		while self._publishers:
			self.destroy_publisher(self._publishers[0])
		while self._subscriptions:
			self.destroy_subscription(self._subscriptions[0])
		while self._clients:
			self.destroy_client(self._clients[0])
		while self._services:
			self.destroy_service(self._services[0])
		while self._timers:
			self.destroy_timer(self._timers[0])

