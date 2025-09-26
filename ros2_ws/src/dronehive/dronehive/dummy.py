import rclpy
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

from dronehive_interfaces.srv import BoxBroadcastService
from dronehive_interfaces.msg import PositionMessage
import dronehive.utils as dh


def send_dummy_response(request: BoxBroadcastService.Request, response: BoxBroadcastService.Response) -> BoxBroadcastService.Response:

	response = BoxBroadcastService.Response()
	response.confirm = True

	landing_pos = PositionMessage()
	landing_pos.lat = 48.8588443
	landing_pos.lon = 2.2943506
	landing_pos.elv = 100.0
	response.landing_pos = landing_pos

	rclpy.logging.get_logger('dummy_confirm_node').info(f"""
		Dummy service received request for box ID: {request.box_id},
		received landing position: {request.landing_pos}
		setting it to {response.landing_pos}
	""")

	return response



def main():
	rclpy.init()

	node = rclpy.create_node('dummy_confirm_node')

	node.create_service(
		BoxBroadcastService,
		dh.DRONEHIVE_BOX_BROADCAST_SERVICE,
		send_dummy_response,
	)

	rclpy.spin_once(node)

	node.destroy_node()
	rclpy.shutdown()


if __name__ == '__main__':
	main()
