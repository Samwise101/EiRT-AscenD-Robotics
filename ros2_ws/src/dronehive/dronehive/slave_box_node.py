import rclpy
from dronehive.slave_box.slave import SlaveBoxNode
from rclpy.executors import MultiThreadedExecutor

def main():
	rclpy.init()

	executor = MultiThreadedExecutor(3)
	node = SlaveBoxNode()
	executor.add_node(node)

	try:
		executor.spin()

	except KeyboardInterrupt:
		node.get_logger().info("Shutting down master box node...")
		executor.shutdown()

	rclpy.shutdown()


if __name__ == '__main__':
	main()
