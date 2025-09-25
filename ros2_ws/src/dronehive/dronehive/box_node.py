import rclpy
from dronehive.master_box.master import MasterBoxNode

def main():
	print('Hi from dronehive.')
	rclpy.init()

	master_box = MasterBoxNode()
	rclpy.spin(master_box)

	master_box.destroy_node()
	rclpy.shutdown()


if __name__ == '__main__':
	main()
