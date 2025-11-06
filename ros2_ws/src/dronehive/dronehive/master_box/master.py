# ROS2 imports
import rclpy
from rclpy.callback_groups import (
	ReentrantCallbackGroup,
	MutuallyExclusiveCallbackGroup,
)

from rclpy.executors import SingleThreadedExecutor

from rclpy.node import Node
from rclpy.qos import (
	QoSProfile,
	QoSReliabilityPolicy,
	QoSHistoryPolicy,
)

from rclpy.task import Future
from std_msgs.msg import String

# Project specific imports
from dronehive_interfaces.msg import (
	BoxBroadcastMessage,
	BoxSetupConfirmationMessage,
	DroneForceLandingMessage,
	PositionMessage
)

from dronehive_interfaces.srv import (
	BoxBroadcastService,
	BoxStatusService,
	DroneLandingService,
	OccupancyService,
	RequestReturnHome,
	SlaveBoxIDsService,
	SlaveBoxInformationService,
	DroneTrajectoryWaypointsService,
)
import dronehive.utils as dh

from dataclasses import dataclass
from enum import Enum
from typing import Dict
import time

qos_profile = QoSProfile(
	reliability=QoSReliabilityPolicy.BEST_EFFORT,
	history=QoSHistoryPolicy.KEEP_LAST,
	depth=1
)

class BoxStatusEnum(Enum):
	UNKNOWN = "UNKNOWN"
	INITIALISING = "INITIALISING"
	OCCUPIED = "OCCUPIED"
	EMPTY = "EMPTY"


@dataclass
class BoxStatus:
	box_id: str
	drone_id: str
	position: PositionMessage
	status: BoxStatusEnum = BoxStatusEnum.UNKNOWN


class MasterBoxNode(Node):
	def __init__(self) -> None:
		super().__init__('master_box_node')

		self.config: dh.Config = dh.dronehive_initialise()
		self.uninitialised_slave_boxes = {}
		self.linked_slave_boxes: Dict[str, BoxStatus] = {}
		self.motor: dh.XL430Controller | None = None
		self.temp_node = Node('temp_waypoint_client_node')


		# If the box is not initialised (aka setup and cofirmed by the GUI) it will publish its position and ID until it is
		# initialised. Once the initialisation is confirmed, it will call the initialise_connections method.
		if not self.config.initialised:
			self.get_logger().info("Box not initialised yet. Waiting for initialisation...")
			self.initialiser = dh.Initialiser(self, self.config, self.initialise_connections)
			return

		# When the box is initialised at startup we can directly initialise the connections.
		# If everything is fine, the initialiser will be None.
		self.initialise_connections()


	##########################
	# Initialisation methods #
	##########################

	def initialise_connections(self) -> None:
		"""
		Initialises the connections of the master box node.
		Creates the service client manager, messages, timers, services and actions.
		Gathers the states of the linked slave boxes.
		Drops the initialiser to free memory.
		"""
		self.client_manager = dh.ServiceClientManager(self, max_clients=32)
		self.get_logger().info("Initialising connections...")

		self.create_messages()
		self.create_timers()
		self.create_services()
		self.create_actions()

		self.gather_slave_boxes_states()

		# Initialise the motor controller
		try:
			self.motor = dh.XL430Controller(dxl_id=1)
		except Exception as e:
			self.get_logger().error(f"Failed to initialise motor controller: {e}")
			self.motor = None

		# Drop the initialiser to free memory
		self.initialiser = None

		self.get_logger().info(f"Initialised with config : {self.config}")


	def gather_slave_boxes_states(self) -> None:
		"""
		Go through all the box_id's in the config and gather their states.
		For each box, it will call the RequestBoxStatus service and update the linked_slave_boxes dictionary.
		If the service call fails, it will set the box status to UNKNOWN.
		"""
		request = BoxStatusService.Request()

		# Add master box status

		self.get_logger().info(f"Gathering state of master box ID: {self.config.box_id}...")
		self.linked_slave_boxes[self.config.box_id] = BoxStatus(
			box_id=self.config.box_id,
			drone_id=self.config.drone_id,
			position=self.config.landing_position,
			status=BoxStatusEnum.EMPTY if self.config.drone_id == "" else BoxStatusEnum.OCCUPIED
		)

		# Add slave box statuses
		def callback(future: Future, box_id: str) -> None:
			response: BoxStatusService.Response | None = future.result()
			if response and not response.accept:
				self.get_logger().error(f"Service call to get box status for box ID: '{box_id}' was not accepted.")
				return

			if response is not None:
				self.get_logger().info(f"Got box status for box ID: {box_id}: {response}")
				self.linked_slave_boxes[box_id] = BoxStatus(
					box_id=box_id,
					drone_id=response.drone_id,
					position=response.landing_pos,
					status=BoxStatusEnum.EMPTY if response.drone_id == "" else BoxStatusEnum.OCCUPIED
				)

			else:
				self.get_logger().error("Failed to get box status. Setting status to UNKNOWN.")
				self.linked_slave_boxes[box_id] = BoxStatus(
					box_id=box_id,
					drone_id="",
					position=PositionMessage(),
					status=BoxStatusEnum.UNKNOWN
				)


		for box_id in self.config.linked_box_ids:
			request.box_id = box_id
			self.get_logger().info(f"Gathering state of linked slave box ID: {box_id}...")
			self.client_manager.call_async(
				BoxStatusService,
				dh.DRONEHIVE_BOX_STATUS_REQUEST_SERVICE,
				request,
				lambda future: callback(future, box_id),
				2
			)

		self.get_logger().info(f"Gathered states of linked slave boxes: {self.linked_slave_boxes}")


	def create_messages(self) -> None:
		# Subscribers
		# In the code of the method the subscriber is already saved in internal variable.

		# Topic used to deinitialise a box (both master and slave)
		self.create_subscription(
			String,
			dh.DRONEHIVE_DEINITIALISE_BOX_TOPIC,
			self._deinitialise_box_callback,
			qos_profile
		)

		# Topic used by slave boxes to let the master box know they want to be initialised. The message is then forwarded
		# to the GUI.
		self.create_subscription(
			BoxBroadcastMessage,
			dh.DRONEHIVE_INITIALISE_SLAVE_BOX_TOPIC,
			self.__init_new_slave_box,
			qos_profile
		)

		# Topic used by the GUI to confirm the initialisation of a box (both master and slave).
		self.create_subscription(
			BoxSetupConfirmationMessage,
			dh.DRONEHIVE_NEW_BOX_CONFIMED_TOPIC,
			self._confirm_box_initialisation,
			qos_profile
		)

		# Publishers
		# Topic used to forward the initialisation confirmation of a slave box from the GUI to the slave box.
		self.slave_box_confirm_init_pub = self.create_publisher(
			BoxSetupConfirmationMessage,
			dh.DRONEHIVE_NEW_SLAVE_BOX_CONFIMED_TOPIC,
			qos_profile
		)

		# Topic used to forward the deinitialisation request of a different box from the GUI to the respective slave box.
		self.deinitialise_slave_box_pub = self.create_publisher(
			String,
			dh.DRONEHIVE_DEINITIALISE_SLAVE_BOX_TOPIC,
			qos_profile
		)

		# Topic used to broadcast the initialisation request of a box (both master and slave) to the GUI.
		self._pub_box_broadcast = self.create_publisher(
			BoxBroadcastMessage,
			dh.DRONEHIVE_NEW_BOX_TOPIC,
			qos_profile
		)

		self.slave_box_incoming_dron_pub = self.create_publisher(
			String,
			dh.DRONEHIVE_REQUEST_LANDING_POS_TOPIC,
			qos_profile
		)

		self.drone_rth_pub = self.create_publisher(
			DroneForceLandingMessage,
			dh.DRONEHIVE_DRONE_RETURN_TO_HOME,
			qos_profile
		)

	#####################
	# Message callbacks #
	#####################

	def _deinitialise_box_callback(self, msg: String) -> None:
		"""
		Callback for the deinitialise box topic. This callback is used as an interface between
		the boxes (master and slave) and the GUI. When a box (both master and slave) needs to be deinitialised,
		it will receive a message from the GUI.

		Args:
			msg: String - The message containing the box ID to deinitialise.
		"""
		# If the message is intended for a different box, forward it to the respective slave box.
		if msg.data != self.config.box_id:
			self.get_logger().info(f"Deinitialise request for different box ID: {msg.data}. Forwarding...")
			self.deinitialise_slave_box_pub.publish(msg)
			self.linked_slave_boxes.pop(msg.data, None)

			if msg.data in self.config.linked_box_ids:
				self.config.linked_box_ids.remove(msg.data)
				dh.dronehive_update_config(self.config)

			return

		# The message is for this box, deinitialise it.
		self.get_logger().warn("Deinitialising box as requested...")
		dh.dronehive_deinitialise(self.config)
		self.linked_slave_boxes = {}
		self.motor = None

		def deferred_reinit():
			self.get_logger().warn("Box deinitialised. Restarting initialiser...")
			self.initialiser = dh.Initialiser(self, self.config, self.initialise_connections)

		# Defer to next spin cycle
		self.create_timer(0.1, deferred_reinit)


	def __init_new_slave_box(self, msg: BoxBroadcastMessage) -> None:
		"""
		Callback for the BoxBroadcastMessage topic. This callback is used as an interface between
		the boxes (master and slave) and the GUI. When a slave box wants to be initialised, it will
		send a message to the master box which will then forward it to the GUI.

		This only works if the box is already initialised (aka setup and confirmed by the GUI).

		Args:
			msg: BoxBroadcastMessage - The message containing the box ID and landing position.
		"""
		request = BoxBroadcastService.Request()
		request.box_id = msg.box_id
		request.landing_pos = msg.landing_pos

		self.uninitialised_slave_boxes[msg.box_id] = (msg, time.time())
		self.slave_publish_timer.reset()
		self.get_logger().info(f"Initialisation request for new slave box ID: '{request.box_id}', landing position: '{request.landing_pos}'. Forwarding to service...")


	def _confirm_box_initialisation(self, msg: BoxSetupConfirmationMessage):
		"""
		Callback for the BoxSetupConfirmationMessage topic. This callback is used as an interface between
		the boxes (master and slave) and the GUI. When a box (both master and slave) is initialised, it will
		receive a confirmation message from the GUI.

		Args:
			msg: BoxSetupConfirmationMessage - The message containing the box ID and landing position.
		"""
		self.get_logger().info(f"Received box initialisation confirmation message: {msg}")
		self.get_logger().info(f"Master box id: {self.config.box_id} | Message box id: {msg.box_id}")
		self.get_logger().info(f"Current uninitialised slave boxes: {self.uninitialised_slave_boxes.keys()}")

		# The message is for a slave box
		if self.config.box_id != msg.box_id and msg.box_id in self.uninitialised_slave_boxes:
			self.get_logger().info(f"\n\n\n\nBox initialization confirmed for slave box ID: '{msg.box_id}'. Forwarding to service...")
			# Let the slave box know it has been initialised.
			self.slave_box_confirm_init_pub.publish(msg)
			self.slave_publish_timer.cancel()

			# Remove from uninitialised list.
			self.get_logger().info(f"Removing slave box ID: '{msg.box_id}' from uninitialised list {self.uninitialised_slave_boxes}")
			self.uninitialised_slave_boxes.pop(msg.box_id, None)

			# Update config.
			self.config.linked_box_ids.add(msg.box_id)

			self.linked_slave_boxes[msg.box_id] = BoxStatus(
				box_id=msg.box_id,
				drone_id="",
				position=msg.landing_pos,
				status=BoxStatusEnum.EMPTY
			)

			dh.dronehive_update_config(self.config)
			return

		# The message is for this master box
		if msg.confirm and self.config.initialised == False:
			self.get_logger().info("Box initialization confirmed.")
			# Update config.
			self.config.initialised = True
			self.config.landing_position = msg.landing_pos
			dh.dronehive_update_config(self.config)

			# Initialise connections.
			response = BoxBroadcastMessage()
			response.box_id = self.config.box_id
			response.landing_pos = self.config.landing_position
			self._pub_box_broadcast.publish(response)


	#################
	# Create TIMERS #
	#################

	def create_timers(self) -> None:
		""" Creates the timers used by the master box node. """
		self.slave_publish_timer = self.create_timer(1.0, self.__publish_slave_boxes)
		self.slave_publish_timer.cancel()

	###################
	# TIMER Callbacks #
	###################

	def __publish_slave_boxes(self) -> None:
		"""
		Publishes the initialisation request for all uninitialised slave boxes every 2 seconds.
		If all the uninitialised slave boxes have been initialised, the timer is cancelled.
		"""
		if len(self.uninitialised_slave_boxes) == 0:
			self.get_logger().info("All slave boxes initialised. Cancelling slave publish timer.")
			self.slave_publish_timer.cancel()
			return

		to_remove = []
		# Publish all uninitialised slave boxes
		for box_id, (msg, t) in self.uninitialised_slave_boxes.items():
			if time.time() - t > 10:
				to_remove.append(box_id)
				self.get_logger().warn(f"Slave box ID: '{box_id}' initialisation timed out. Removing from uninitialised list.")
				continue

			self.get_logger().info(f"Publishing initialisation request for slave box ID: '{box_id}', landing position: '{msg.landing_pos}' to service...")
			self._pub_box_broadcast.publish(msg)

		for box_id in to_remove:
			self.uninitialised_slave_boxes.pop(box_id, None)


	###################
	# Create SERVICES #
	###################

	def create_services(self) -> None:
		""" Initialilse the services provided by the master box node. """
		self.create_service(
			DroneLandingService,
			dh.DRONEHIVE_DRONE_LAND_REQUEST,
			self.find_best_lending_place
		)

		self.create_service(
			RequestReturnHome,
			dh.DRONEHIVE_HMI_REQUEST_RETURN_HOME_TOPIC,
			self.return_home_request
		)

		self.create_service(
			SlaveBoxIDsService,
			dh.DRONEHIVE_GUI_BOXES_ID_SERVICE,
			self._handle_slave_box_ids_request
		)

		self.create_service(
			SlaveBoxInformationService,
			dh.DRONEHIVE_GUI_SLAVE_BOX_INFO_SERVICE,
			self._handle_slave_box_info_request
		)

		self.create_service(
			DroneTrajectoryWaypointsService,
			dh.DRONEHIVE_GUI_REQUEST_WAYPOINT_TRAJECTORY_SERVICE,
			self.handle_trajectory_waypoints_request,
			callback_group=ReentrantCallbackGroup()
		)

	#####################
	# SERVICE Callbacks #
	#####################

	def find_best_lending_place(self, request: DroneLandingService.Request, response: DroneLandingService.Response) -> DroneLandingService.Response:
		"""
		Finds the best landing place for a drone based on its current position.
		It will look for the closest empty slave box and assign it to the drone.
		If no empty slave box is found, it will return an empty position.
		If the closest empty slave box is the master box, it will assign the drone to the master box, otherwise it will
		assign the drone to the slave box and publish the drone ID to the respective slave box.

		Args:
			request: DroneLandingService.Request - The request containing the drone ID and current position and the drone ID.
			response: DroneLandingService.Response - The response containing the landing position.

		Returns:
			DroneLandingService.Response - The response containing the landing position.
		"""
		closest_box_id: str | None = None
		closest_distance: float = float('inf')
		landing_pos: PositionMessage = PositionMessage()

		positions = [box_status.position for box_status in self.linked_slave_boxes.values()]
		info = zip(self.linked_slave_boxes.keys(), positions)
		print(f"Linked boxes: {list(info)}")
		print(f"Drone position: {request.drone_pos}")

		for box_id, box_status in self.linked_slave_boxes.items():
			if box_status.status != BoxStatusEnum.EMPTY:
				print(f"Box ID: {box_id} is not empty (status: {box_status.status}). Skipping...")
				continue

			distance = ((box_status.position.lat - request.drone_pos.lat) ** 2 + (box_status.position.lon - request.drone_pos.lon) ** 2) ** 0.5
			print(f"Box ID: {box_id} is empty. Distance to drone: {distance}")
			if distance < closest_distance:
				closest_distance = distance
				closest_box_id = box_id
				landing_pos = box_status.position
				self.get_logger().info(f"Found empty slave box ID: {box_id} for drone ID: {request.drone_id}. Assigning landing position: {box_status.position}")

		if closest_box_id == None:
			self.get_logger().warn(f"No empty slave box found for drone ID: {request.drone_id}. Cannot assign landing position.")
			response.landing_pos = PositionMessage()
			return response

		if closest_box_id == self.config.box_id:
			self.get_logger().info(f"Assigning landing position of master box ID: {self.config.box_id} to drone ID: {request.drone_id}")
			self.config.drone_id = request.drone_id
			dh.dronehive_update_config(self.config)
			landing_pos = self.config.landing_position

		self.linked_slave_boxes[closest_box_id].drone_id = request.drone_id
		self.linked_slave_boxes[closest_box_id].status = BoxStatusEnum.OCCUPIED
		if closest_box_id != self.config.box_id:
			self.get_logger().info(f"Assigning landing position of slave box ID: {closest_box_id} to drone ID: {request.drone_id}")
			self.slave_box_incoming_dron_pub.publish(String(data=request.drone_id))

		self.notify_gui_drone_landed(closest_box_id, request.drone_id, landing_pos)
		response.landing_pos = landing_pos
		return response


	def notify_gui_drone_landed(self, box_id: str, drone_id: str, landing_pos: PositionMessage) -> None:
		request = OccupancyService.Request()
		request.box_id = box_id
		request.drone_id = drone_id

		self.get_logger().info(f"Notifying GUI of drone ID: {drone_id} landing at box ID: {box_id}...")

		self.client_manager.call_async(
			DroneLandingService,
			dh.DRONEHIVE_DRONE_LAND_NOTIFY_GUI,
			request,
			lambda future: self.get_logger().info(f"Notified GUI of drone ID: {drone_id} landing at box ID: {box_id}"),
			10
		)


	def return_home_request(self, request: RequestReturnHome.Request, response: RequestReturnHome.Response) -> RequestReturnHome.Response:
		status: BoxStatus = self.linked_slave_boxes[request.box_id]
		if status.drone_id == "":
			self.get_logger().warn(f"Return home request for box ID: {request.box_id} but no drone is present.")
			response.confirm = False
			return response

		self.get_logger().info(f"Return home request for box ID: {request.box_id} with drone ID: {status.drone_id}.")
		if request.box_id == self.config.box_id:
			self.get_logger().info(f"Box ID: {request.box_id} is the master box. Setting drone ID: {status.drone_id} to return home.")

		msg = DroneForceLandingMessage()
		msg.drone_id = status.drone_id
		msg.landing_pos = status.position
		self.drone_rth_pub.publish(msg)

		response.confirm = True
		return response


	def _handle_slave_box_ids_request(self, request: SlaveBoxIDsService.Request, response: SlaveBoxIDsService.Response) -> SlaveBoxIDsService.Response:
		"""
		Handles the request for the IDs of all linked slave boxes. If a request arrives to fetch the IDs of all linked slave
		boxes, this method will be called. It will populate the response with the IDs of all linked slave boxes. (including
		the master box ID)

		Args:
			request: SlaveBoxIDsService.Request - Empty request.
			response: SlaveBoxIDsService.Response - The response containing the list of box IDs and the size of the list.

		Returns:
			SlaveBoxIDsService.Response - The response containing the list of box IDs and the size of the list.
		"""
		response.box_ids = self.linked_slave_boxes.keys()
		response.size = len(self.linked_slave_boxes.keys())
		self.get_logger().info(f"Slave box IDs request received. Responding with: {response.box_ids}")
		return response


	def _handle_slave_box_info_request(self, request: SlaveBoxInformationService.Request, response: SlaveBoxInformationService.Response) -> SlaveBoxInformationService.Response:
		"""
		Handles the request for the information of a specific linked slave box. If a request arrives to fetch the information
		of a specific linked slave box, this method will be called. It will populate the response with the information of the
		specified slave box. If the box ID is not found, it will respond with empty information and status UNKNOWN.

		Args:
			request: SlaveBoxInformationService.Request - The request containing the box ID.
			response: SlaveBoxInformationService.Response - The response containing the box information (drone ID, landing
			position, status).

		Returns:
			SlaveBoxInformationService.Response - The response containing the box information (drone ID, landing position,
			status).
		"""
		box_info = self.linked_slave_boxes.get(request.box_id, None)
		response.status.box_id = request.box_id

		if box_info is None:
			self.get_logger().warn(f"Slave box info request received for unknown box ID: '{request.box_id}'. Responding with empty info.")
			response.status.drone_id = ""
			response.status.landing_pos = PositionMessage()
			response.status.status = BoxStatusEnum.UNKNOWN.value

		else:
			self.get_logger().info(f"Slave box info request received for box ID: '{request.box_id}'. Responding with info: {box_info}")
			response.status.drone_id = box_info.drone_id
			response.status.landing_pos = box_info.position
			response.status.status = box_info.status.value

		return response


	def find_box_id_from_drone_id(self, drone_id: str) -> str | None:
		for box_id, box_status in self.linked_slave_boxes.items():
			if box_status.drone_id == drone_id:
				return box_id
		return None

	def handle_trajectory_waypoints_request(self,
										 request: DroneTrajectoryWaypointsService.Request,
										 response: DroneTrajectoryWaypointsService.Response) -> DroneTrajectoryWaypointsService.Response:
		self.get_logger().info(f"Received trajectory waypoints request for drone ID: '{request.drone_id}'")
		box_id = self.find_box_id_from_drone_id(request.drone_id)
		if box_id is None:
			self.get_logger().warn(f"Trajectory waypoints request received for unknown drone ID: '{request.drone_id}'. Cannot provide waypoints.")
			response.ack = False
			return response

		if box_id == self.config.box_id:
			response.ack = True
			self.get_logger().info(f"Trajectory waypoints request received for drone ID: '{request.drone_id}' in master box ID: '{box_id}'. Acknowledging directly.")
			return response

		# Create a transient node to make the client call
		client = self.temp_node.create_client(
			DroneTrajectoryWaypointsService,
			dh.DRONEHIVE_GUI_REQUEST_WAYPOINT_TRAJECTORY_SERVICE + f"_{box_id}"
		)

		# wait for service
		if not client.wait_for_service(timeout_sec=5.0):
			self.temp_node.get_logger().error("Target service not available")
			self.temp_node.destroy_node()
			response.ack = False
			return response

		future = client.call_async(request)

		# Spin a temporary executor that only has the temp node
		exec = SingleThreadedExecutor()
		exec.add_node(self.temp_node)
		exec.spin_until_future_complete(future)
		exec.shutdown()

		if not future or future.result() is None:
			self.get_logger().error(f"Failed to get trajectory waypoints for drone ID: '{request.drone_id}' from box ID: '{box_id}'.")
			response.ack = False
			return response

		self.get_logger().info(f"Forwarded trajectory waypoints request for drone ID: '{request.drone_id}' to box ID: '{box_id}'"),
		response.ack = future.result().ack
		return response


	##################
	# Create ACTIONS #
	##################

	def create_actions(self) -> None:
		""" Creates the actions used by the master box node. """
		pass

	####################
	# ACTION Callbacks #
	####################

