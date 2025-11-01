import rclpy
from dronehive.slave_box.slave import SlaveBoxNode
from rclpy.executors import MultiThreadedExecutor

def main():
	rclpy.init()

	executor = MultiThreadedExecutor()
	executor.add_node(SlaveBoxNode())

	try:
		executor.spin()

	except KeyboardInterrupt:
		rclpy.logging.get_logger("box_node").info("Shutting down master box node...")
		executor.shutdown()

	rclpy.shutdown()


if __name__ == '__main__':
	main()
