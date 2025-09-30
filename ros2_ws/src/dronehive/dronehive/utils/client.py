from rclpy.node import Node
from rclpy.task import Future

from typing import Callable

class ServiceLessClient:
	def __init__(self, node: Node,
				 service_type: type,
				 service_topic: str,
				 rquest_callback: Callable,
				 response_callback: Callable,
				 delay_s = 2.0) -> None:
		self.__node = node
		self.__request_callback = rquest_callback
		self.__response_callback = response_callback

		self.__client = node.create_client(service_type, service_topic)
		self.__wait_timer = self.__node.create_timer(delay_s, self.__try_init)


	def __try_init(self) -> None:
		# Check if the service is available.
		if not self.__client.service_is_ready():
			self.__node.get_logger().info('Service not available, waiting again...')
			return

		# Once the service is available, cancel the timer and send the request.
		request = self.__request_callback()
		future = self.__client.call_async(request)
		future.add_done_callback(self.__handle_response)


	def __handle_response(self, future: Future) -> None:
		try:
			response = future.result()
		except Exception as e:
			# If the service call fails, log the error and retry after 2 seconds.
			self.__node.get_logger().error(f'Service call failed: {e}')
			self.__wait_timer.reset()
			return

		# If the response is None or not confirmed, log the error and retry after 2 seconds.
		if response is None or not response.confirm:
			self.__node.get_logger().error("Box initialization NOT confirmed from service. Check the box ID and try again.")
			self.__wait_timer.reset()
			return

		self.__response_callback(response)


	def destory(self) -> None:
		self.__node.destroy_client(self.__client)
		self.__node.destroy_timer(self.__wait_timer)
