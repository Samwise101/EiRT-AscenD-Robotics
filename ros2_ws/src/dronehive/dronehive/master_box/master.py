# ROS2 imports
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

from rclpy.task import Future
from std_msgs.msg import String

# Project specific imports
from dronehive_interfaces.msg import BoxBroadcastMessage, BoxSetupConfirmationMessage, PositionMessage
from dronehive_interfaces.srv import (
	BoxBroadcastService,
	BoxStatusService,
	DroneLandingService,
	SlaveBoxIDsService,
	SlaveBoxInformationService
)
import dronehive.utils as dh

from dataclasses import dataclass
from enum import Enum
from typing import Dict
import time

qos_profile = QoSProfile(
	reliability=QoSReliabilityPolicy.RELIABLE,
	durability=QoSDurabilityPolicy.VOLATILE,
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
		self.client_manager = dh.ServiceClientManager(self, max_clients=32)
		self.uninitialised_slave_boxes = {}
		self.linked_slave_boxes: Dict[str, BoxStatus] = {}

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
				10
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

	#####################
	# Message callbacks #
	#####################

	def _deinitialise_box_callback(self, msg: String) -> None:
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

		def deferred_reinit():
			self.get_logger().warn("Box deinitialised. Restarting initialiser...")
			self.initialiser = dh.Initialiser(self, self.config, self.initialise_connections)

		# Defer to next spin cycle
		self.timer = self.create_timer(0.1, deferred_reinit)


	def __init_new_slave_box(self, msg: BoxBroadcastMessage) -> None:
		request = BoxBroadcastService.Request()
		request.box_id = msg.box_id
		request.landing_pos = msg.landing_pos

		self.uninitialised_slave_boxes[msg.box_id] = (msg, time.time())
		self.slave_publish_timer.reset()
		self.get_logger().info(f"Initialisation request for new slave box ID: '{request.box_id}', landing position: '{request.landing_pos}'. Forwarding to service...")


	def _confirm_box_initialisation(self, msg: BoxSetupConfirmationMessage):
		# The message is for a slave box
		if self.config.box_id != msg.box_id:
			self.get_logger().info(f"Box initialization confirmed for slave box ID: '{msg.box_id}'. Forwarding to service...")
			self.slave_box_confirm_init_pub.publish(msg)
			self.config.linked_box_ids.append(msg.box_id)
			self.slave_publish_timer.cancel()
			self.uninitialised_slave_boxes.pop(msg.box_id)
			dh.dronehive_update_config(self.config)
			return

		# The message is for this master box
		if msg.confirm:
			self.get_logger().info("Box initialization confirmed.")
			self.config.initialised = True
			self.config.landing_position = msg.landing_pos
			dh.dronehive_update_config(self.config)
			self._pub_box_broadcast.publish(msg)


	#################
	# Create TIMERS #
	#################

	def create_timers(self) -> None:
		self.slave_publish_timer = self.create_timer(2.0, self.__publish_slave_boxes)
		self.slave_publish_timer.cancel()

	###################
	# TIMER Callbacks #
	###################

	def __publish_slave_boxes(self) -> None:
		if len(self.uninitialised_slave_boxes) == 0:
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
			del self.uninitialised_slave_boxes[box_id]


	###################
	# Create SERVICES #
	###################

	def create_services(self) -> None:
		self.create_service(
			DroneLandingService,
			dh.DRONEHIVE_DRONE_LAND_REQUEST,
			self.find_best_lending_place
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

	#####################
	# SERVICE Callbacks #
	#####################

	def find_best_lending_place(self, request: DroneLandingService.Request, response: DroneLandingService.Response) -> DroneLandingService.Response:
		closest_box_id = ""
		closest_distance = float('inf')
		landing_pos = PositionMessage()

		*_, drone_easing, drone_northing = dh.utmconv().geodetic_to_utm(request.drone_pos.lat, request.drone_pos.lon)
		for box_id, box_status in self.linked_slave_boxes.items():
			if box_status.status == BoxStatusEnum.EMPTY:
				self.get_logger().info(f"Found empty slave box ID: {box_id} for drone ID: {request.drone_id}. Assigning landing position: {box_status.position}")
				*_, box_easting, box_northing = dh.utmconv().geodetic_to_utm(box_status.position.lat, box_status.position.lon)
				distance = ((box_easting - drone_easing) ** 2 + (box_northing - drone_northing) ** 2) ** 0.5
				if distance < closest_distance:
					closest_distance = distance
					closest_box_id = box_id
					landing_pos = box_status.position


		if closest_box_id == "":
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

		response.landing_pos = landing_pos
		return response


	def _handle_slave_box_ids_request(self, request: SlaveBoxIDsService.Request, response: SlaveBoxIDsService.Response) -> SlaveBoxIDsService.Response:
		response.box_ids = self.linked_slave_boxes.keys()
		response.size = len(self.linked_slave_boxes.keys())
		self.get_logger().info(f"Slave box IDs request received. Responding with: {response.box_ids}")
		return response


	def _handle_slave_box_info_request(self, request: SlaveBoxInformationService.Request, response: SlaveBoxInformationService.Response) -> SlaveBoxInformationService.Response:
		box_info = self.linked_slave_boxes.get(request.box_id, None)

		if box_info is None:
			self.get_logger().warn(f"Slave box info request received for unknown box ID: '{request.box_id}'. Responding with empty info.")
			response.drone_id = ""
			response.landing_pos = PositionMessage()
			response.status = BoxStatusEnum.UNKNOWN.value

		else:
			self.get_logger().info(f"Slave box info request received for box ID: '{request.box_id}'. Responding with info: {box_info}")
			response.drone_id = box_info.drone_id
			response.landing_pos = box_info.position
			response.status = box_info.status.value

		return response


	##################
	# Create ACTIONS #
	##################

	def create_actions(self) -> None:
		pass

	####################
	# ACTION Callbacks #
	####################

