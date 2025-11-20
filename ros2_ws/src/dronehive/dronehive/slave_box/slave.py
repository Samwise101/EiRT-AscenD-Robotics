from typing import Optional
from rclpy.node import Node
from rclpy.executors import SingleThreadedExecutor
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy
from rclpy.task import Future
from std_msgs.msg import String, Bool

import dronehive.utils as dh

from dronehive_interfaces.msg import (
	BoxBroadcastMessage,
	BoxSetupConfirmationMessage,
	BoxStatusMessage,
)

from dronehive_interfaces.srv import (
	AddRemoveDroneService,
	BoxStatusService,
	BoxStatusSlaveUpdateService,
	DroneTrajectoryWaypointsService,
	RequestBoxOpenService,
)

qos_profile = QoSProfile(
	reliability=QoSReliabilityPolicy.BEST_EFFORT,
	history=QoSHistoryPolicy.KEEP_LAST,
	depth=1
)

class SlaveBoxNode(Node):
	def __init__(self) -> None:
		self.config: dh.Config = dh.dronehive_initialise()
		self.temp_node: Node = Node("temp_node_for_clients")

		super().__init__(f"slave_box_node_{self.config.box_id}")

		# If the box is not initialised (aka setup and cofirmed by the GUI) it will publish its position and ID until it is
		# initialised. Once the initialisation is confirmed, it will call the initialise_connections method.
		if not self.config.initialised:
			self.box_init_interfaces()
			return

		# When the box is initialised at startup we can directly initialise the connections.
		# If everything is fine, the initialiser will be None.
		self.initialise_connections()


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

		self.client_manager = dh.ServiceClientManager(self, max_clients=32)

		try:
			self.motor = dh.XL430Controller(dxl_id=0)
		except Exception as e:
			self.get_logger().error(f"Failed to initialise motor controller: {e}")
			self.motor = None
		self.get_logger().info(f"Initialised with config : {self.config}")

		request=BoxStatusSlaveUpdateService.Request(
			status=BoxStatusMessage(
				landing_pos=self.config.landing_position,
				box_battery_level=100.0,
				box_id=self.config.box_id,
				drone_id=self.config.drone_id,
				status=dh.BoxStatusEnum.OCCUPIED.value if self.config.drone_id != "" else dh.BoxStatusEnum.EMPTY.value
			)
		)

		self.client_manager.call_async(
			BoxStatusSlaveUpdateService,
			dh.DRONEHIVE_BOX_STATUS_SLAVE_UPDATE_SERVICE,
			request,
			lambda fut: self.get_logger().info(f"Box status update response: {fut.result() or 'Update failed'}")
		)


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

		self.create_service(
			DroneTrajectoryWaypointsService,
			dh.DRONEHIVE_GUI_REQUEST_WAYPOINT_TRAJECTORY_SERVICE + f"_{self.config.box_id}",
			self.handle_trajectory_waypoints_request
		)

		self.create_service(
			RequestBoxOpenService,
			dh.DRONEHIVE_REQUEST_BOX_OPEN_SERVICE + f"_{self.config.box_id}",
			self.handle_box_open_request
		)

		self.create_service(
			AddRemoveDroneService,
			dh.DRONEHIVE_GUI_ADD_REMOVE_DRONE_SERVICE + f"_{self.config.box_id}",
			self.handle_add_remove_drone_request
		)


	def create_actions(self) -> None:
		pass

	##################
	# Callbacks etc. #
	##################

	def provide_box_status(self, request: BoxStatusService.Request, response: BoxStatusService.Response) -> BoxStatusService.Response:
		if request.box_id != self.config.box_id:
			self.get_logger().info(f"Box status request for different box ID: {request.box_id}, expected: {self.config.box_id}")
			response.accept = False
			return response

		response.accept = True
		response.landing_pos = self.config.landing_position
		response.drone_id = self.config.drone_id

		self.get_logger().info(f"Responding with landing position: {response.landing_pos} and drone ID: {response.drone_id}")
		return response

	def handle_trajectory_waypoints_request(self,
										 request: DroneTrajectoryWaypointsService.Request,
										 response: DroneTrajectoryWaypointsService.Response) -> DroneTrajectoryWaypointsService.Response:
		self.get_logger().info(f"Received trajectory waypoints request for box ID: {request.drone_id}")

		self.config.drone_id = ""
		self.config.save()

		if not self.motor:
			response.ack = False
			self.get_logger().error("Motor controller not initialised.")
			return response

		response.ack = self.motor.open_box()
		self.get_logger().info("Box opened.")

		return response


	def handle_box_open_request(self, request: RequestBoxOpenService.Request,
								response: RequestBoxOpenService.Response) -> RequestBoxOpenService.Response:

		if not self.motor:
			response.ack = False
			self.get_logger().error("Motor controller not initialised.")
			return response

		response.ack = self.motor.open_box()
		if response.ack:
			self.get_logger().info(f"Box ID: {self.config.box_id} opened successfully.")
		else:
			self.get_logger().error(f"Failed to open box ID: {self.config.box_id}.")

		return response


	def handle_add_remove_drone_request(self,
										request: AddRemoveDroneService.Request,
										response: AddRemoveDroneService.Response) -> AddRemoveDroneService.Response:

		self.get_logger().info(f"Received add/remove drone request for box ID: {self.config.box_id} with drone ID: {request.drone_id}")
		self.config.drone_id = request.drone_id
		self.config.save()

		response.ack = True

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

			# Destroy motor controller if exists.
			if self.motor is not None:
				self.motor.destroy()


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

