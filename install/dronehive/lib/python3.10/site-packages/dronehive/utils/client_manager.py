# service_client_manager.py
from collections import OrderedDict
import threading

from rclpy.node import ReentrantCallbackGroup
from rclpy.task import Future
import rclpy

class ServiceClientManager:
	"""Manage rclpy service clients with lazy creation and an LRU eviction policy."""

	def __init__(self, node, max_clients=128, wait_for_service_timeout=2.0):
		"""
		node: rclpy.node.Node instance (must stay alive while clients are used)
		max_clients: max number of cached clients before eviction
		"""
		self.node = node
		self.max_clients = max_clients
		self.wait_for_service_timeout = wait_for_service_timeout
		self._lock = threading.RLock()
		# OrderedDict: key -> {'client': client, 'srv_type': srv_type}
		self._clients = OrderedDict()


	def _make_key(self, srv_type, srv_name):
		return (srv_type.__name__, srv_name)


	def get_or_create_client(self, srv_type, srv_name, timeout_sec: float|None =-1.0):
		if timeout_sec == -1.0:
			timeout_sec = self.wait_for_service_timeout

		key = self._make_key(srv_type, srv_name)
		with self._lock:
			if key in self._clients:
				# mark as recently used
				self._clients.move_to_end(key)
				return self._clients[key]['client']

			client = self.node.create_client(srv_type, srv_name, callback_group=ReentrantCallbackGroup())
			if not client.wait_for_service(timeout_sec=timeout_sec):
				# service didn't appear quickly — you can still use client.call_async later
				self.node.get_logger().error(
					f"Service {srv_name} not available after {self.wait_for_service_timeout}s"
				)

			self._clients[key] = {'client': client, 'srv_type': srv_type}
			self._clients.move_to_end(key)
			# enforce max size
			while len(self._clients) > self.max_clients:
				old_key, old = self._clients.popitem(last=False)
				try:
					self.node.destroy_client(old['client'])
				except Exception:
					# best-effort destroy; log and continue
					self.node.get_logger().warn(f"Failed to destroy client {old_key}")

			return client


	def call_async(self,
				srv_type,
				srv_name,
				request,
				response_callback = lambda fut: None,
				timeout_sec: float|None =-1.0) -> Future:
		"""
		Returns the Future returned by client.call_async(request).
		Caller must arrange for spinning (node executor) so callback fires.
		"""
		if timeout_sec == -1.0:
			timeout_sec = self.wait_for_service_timeout

		client = self.get_or_create_client(srv_type, srv_name, timeout_sec=timeout_sec)
		fut = client.call_async(request)
		fut.add_done_callback(response_callback)
		return fut

