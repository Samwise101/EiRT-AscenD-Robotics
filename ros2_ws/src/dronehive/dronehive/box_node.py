import rclpy
from dronehive.master_box.master import MasterBoxNode

def main():
	rclpy.init()

	master_box = MasterBoxNode()

	try:
		rclpy.spin(master_box)

	except KeyboardInterrupt:
		master_box.get_logger().info("Shutting down master box node...")
		master_box.destroy_node()

	rclpy.shutdown()


if __name__ == '__main__':
	main()
