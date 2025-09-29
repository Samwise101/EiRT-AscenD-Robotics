import rclpy
from rclpy.node import Node
from rclpy.task import Future

# Project specific imports
import dronehive.utils as dh

from dronehive_interfaces.srv import BoxBroadcastService

from typing import Callable

class Initialiser:
	def __init__(self, node: Node, config: dh.Config, on_initialised: Callable[..., None] = lambda: None):
		self.node = node
		self.config = config
		self.on_initialised = on_initialised

		# In case the box is not initialised, it will broadcast its position
		if  self.config.initialised:
			node.get_logger().info("Box already initialised. Skipping initialisation.")
			return

		# Switch off all existing interfaces and switch to initialisation mode
		self.destroy_interfaces();

		node.get_logger().warn("The configuration is not initialised. Broadcasting box.")

		self.setup_service = node.create_client(
			BoxBroadcastService,
			dh.DRONEHIVE_BOX_BROADCAST_SERVICE,
		)

		# Wait for the service to be available. Check every second. Once available, send the request.
		self.wait_timer = self.node.create_timer(1.0, self._try_init)


	def _try_init(self) -> None:
		# Check if the service is available.
		if not self.setup_service.service_is_ready():
			self.node.get_logger().info('Service not available, waiting again...')
			return

		# Once the service is available, cancel the timer and send the request.
		self.send_request()


	def send_request(self) -> BoxBroadcastService.Response | None:
		# This is either called at the constructor or if the previous attempt failed.
		# In both cases we want to cancel the timer to avoid multiple calls.
		self.wait_timer.cancel()

		req = BoxBroadcastService.Request()
		req.box_id = self.config.box_id
		req.landing_pos = self.config.lending_position

		# Create a future for the response and add a callback to handle it.
		# Execute the callback once the service responds with a result.
		self.node.get_logger().info(f'Sending request: {req}')
		future = self.setup_service.call_async(req)
		future.add_done_callback(self._handle_response)


	def _handle_response(self, future: Future) -> None:
		try:
			response: BoxBroadcastService.Response = future.result()
		except Exception as e:
			# If the service call fails, log the error and retry after 2 seconds.
			self.node.get_logger().error(f'Service call failed: {e}')
			self.wait_timer.reset()
			return

		# If the response is None or not confirmed, log the error and retry after 2 seconds.
		if response is None or not response.confirm:
			self.node.get_logger().error("Box initialization NOT confirmed from service. Check the box ID and try again.")
			self.wait_timer.reset()
			return

		# If the response is confirmed change the current state of the box from uninitialised to initialised.
		self.node.get_logger().info("Box initialization confirmed from service.")
		self.config.initialised = True
		self.config.lending_position = response.landing_pos
		dh.dronehive_update_config(self.config)

		self.destroy_interfaces();

		self.on_initialised()


	def destroy_interfaces(self) -> None:
		while self.node._publishers:
			self.node.destroy_publisher(self.node._publishers[0])
		while self.node._subscriptions:
			self.node.destroy_subscription(self.node._subscriptions[0])
		while self.node._clients:
			self.node.destroy_client(self.node._clients[0])
		while self.node._services:
			self.node.destroy_service(self.node._services[0])
		while self.node._timers:
			self.node.destroy_timer(self.node._timers[0])

