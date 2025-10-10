
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from dronehive_interfaces.msg import PositionMessage
from geometry_msgs.msg import PoseStamped

class DronePositionPublisher(Node):
	def __init__(self):
		super().__init__('drone_pos_pub')
		self.declare_parameter('drone_id', 'drone1')
		self._drone_id = self.get_parameter('drone_id').get_parameter_value().string_value
		self._pub = self.create_publisher(PositionMessage, '/drone_positions', 10) #might need to be changed if the GUI or masterbox expects it somewhere else
		self._sub = self.create_subscription(
			PoseStamped,
			'/mavros/vision_pose/pose',
			self.pose_callback,
			10
		)

	def pose_callback(self, msg):
		pos_msg = PositionMessage()
        pos_msg.drone_id = self._drone_id
		if hasattr(pos_msg, 'drone_id'):
			pos_msg.drone_id = self._drone_id
		pos_msg.lat = msg.pose.position.x
		pos_msg.lon = msg.pose.position.y
		pos_msg.elv = msg.pose.position.z
		self._pub.publish(pos_msg)

def main(args=None):
	rclpy.init(args=args)
	node = DronePositionPublisher()
	rclpy.spin(node)

if __name__ == '__main__':
	main()
