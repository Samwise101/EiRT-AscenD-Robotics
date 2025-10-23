import rclpy
from dronehive.master_box.master import MasterBoxNode
from rclpy.executors import MultiThreadedExecutor

def main():
	rclpy.init()

	executor = MultiThreadedExecutor()
	executor.add_node(MasterBoxNode())

	try:
		executor.spin()

	except KeyboardInterrupt:
		rclpy.logging.get_logger("box_node").info("Shutting down master box node...")
		executor.shutdown()

	rclpy.shutdown()


if __name__ == '__main__':
	main()
