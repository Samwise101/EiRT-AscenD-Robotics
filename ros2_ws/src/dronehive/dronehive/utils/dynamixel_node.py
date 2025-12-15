import rclpy
from rclpy.node import Node
from std_srvs.srv import SetBool
from rclpy.callback_groups import ReentrantCallbackGroup
from .config import Config
from rclpy.logging import get_logger

from .dynamixel_controller_2 import DynaControl

class DynamixelNode(Node):
	def __init__(self):
		super().__init__('dynamixel_node')
		self.get_logger().info("Dynamixel Node has been started.")
		self.dxl_id = 1  # You can parameterize this as needed
		self.motor = DynaControl('/dev/ttyUSB0', self.dxl_id)
		config = Config.load()
		callback_group = ReentrantCallbackGroup()

		self.create_service(
			SetBool,
			f'/{config.box_id}/motor_{self.dxl_id}/open_box',
			self.handle_open_box,
			callback_group = callback_group
		)

		self.create_service(
			SetBool,
			f'/{config.box_id}/motor_{self.dxl_id}/stop',
			self.handle_stop,
			callback_group = callback_group
		)
		self.get_logger().info(f"Service '/{config.box_id}/motor_{self.dxl_id}/open_box' is ready.")


	def handle_open_box(self, request: SetBool.Request, response: SetBool.Response) -> SetBool.Response:
		self.get_logger().info(f"Received request to {'extend' if request.data else 'retract'} the motor.")
		mode = "out" if request.data else "in"
		response.success = self.motor.extend_or_retract(mode)

		if not response.success:
			response.message = f"Failed to {'retract' if request.data else 'extend'} the motor."
			self.get_logger().error(response.message)

		return response
	
	def handle_stop(self, request: SetBool.Request, response: SetBool.Response) -> SetBool.Response:
		self.motor_destory()
		response.success = True
		get_logger(f"motor_{self.dxl_id}").info("Motor stopped via service call.")
		return response


	def motor_destory(self):
		self.motor.stop()
		self.motor.porthandler.closePort()
		self.destroy_node()
		get_logger(f"motor_{self.dxl_id}").info("Port closed")


def main(args=None):
	rclpy.init(args=args)
	dynamixel_node = DynamixelNode()

	try:
		rclpy.spin(dynamixel_node)

	except KeyboardInterrupt:
		dynamixel_node.motor_destory()

	dynamixel_node.destroy_node()
	rclpy.shutdown()





if __name__ == '__main__':
	pass

