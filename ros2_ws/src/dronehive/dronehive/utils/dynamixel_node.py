import rclpy
from rclpy.node import Node
from std_srvs.srv import SetBool
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from .config import Config

from .dynamixel_controller_2 import DynaControl

class DynamixelNode(Node):
	def __init__(self):
		super().__init__('dynamixel_node')
		self.get_logger().info("Dynamixel Node has been started.")
		self.dxl_id = 1  # You can parameterize this as needed
		self.motor = DynaControl('/dev/ttyUSB0', self.dxl_id)
		config = Config.load()

		self.create_service(
			SetBool,
			f'/{config.box_id}/motor_{self.dxl_id}/open_box',
			self.handle_open_box,
			callback_group=MutuallyExclusiveCallbackGroup()
		)


	def handle_open_box(self, request: SetBool.Request, response: SetBool.Response) -> SetBool.Response:
		mode = "in" if request.data else "out"
		response.success = self.motor.extend_or_retract(mode)

		if not response.success:
			response.message = f"Failed to {'retract' if request.data else 'extend'} the motor."

		return response


	def motor_destory(self):
		# Destroy motor instance properly
		pass


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
	main()

