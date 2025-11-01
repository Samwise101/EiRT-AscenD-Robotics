import rclpy
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

from dronehive_interfaces.srv import RequestDroneLanding
import dronehive.utils as dh


def send_dummy_response(request: RequestDroneLanding.Request, response: RequestDroneLanding.Response) -> RequestDroneLanding.Response:

	response = RequestDroneLanding.Response()
	response.received = True

	rclpy.logging.get_logger('dummy_drone_node').info(f"""
		Dummy drone service received request from box ID: {request.box_id},
		received landing position: {request.landing_pos}
		setting response to {response.received}
	""")

	return response



def main():
	rclpy.init()

	node = rclpy.create_node('dummy_confirm_node')

	node.create_service(
		RequestDroneLanding,
		dh.DRONEHIVE_DRONE_LAND_REQUEST,
		send_dummy_response,
	)

	rclpy.spin_once(node)

	node.destroy_node()
	rclpy.shutdown()


if __name__ == '__main__':
	main()
