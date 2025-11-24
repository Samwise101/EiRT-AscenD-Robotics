import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

from dronehive_interfaces.msg import BoxBroadcastMessage, BoxSetupConfirmationMessage

import dronehive.utils as dh


class NewBoxResponder(Node):
    """Listens for new box announcements and immediately publishes a confirmation."""

    def __init__(self) -> None:
        super().__init__("new_box_responder")

        qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1,
            durability=QoSDurabilityPolicy.VOLATILE,
        )

        self._seen_ids: set[str] = set()
        self.declare_parameter("allow_reconfirm", False)

        self._confirm_pub = self.create_publisher(
            BoxSetupConfirmationMessage,
            dh.DRONEHIVE_NEW_BOX_CONFIMED_TOPIC,
            qos_profile,
        )

        self._new_box_sub = self.create_subscription(
            BoxBroadcastMessage,
            dh.DRONEHIVE_NEW_BOX_TOPIC,
            self._on_new_box,
            qos_profile,
        )

        self.get_logger().info(
            f"NewBoxResponder ready. Subscribing to {dh.DRONEHIVE_NEW_BOX_TOPIC}, publishing confirmations to {dh.DRONEHIVE_NEW_BOX_CONFIMED_TOPIC}"
        )

    def _on_new_box(self, msg: BoxBroadcastMessage) -> None:
        allow_reconfirm = self.get_parameter("allow_reconfirm").get_parameter_value().bool_value
        if msg.box_id in self._seen_ids and not allow_reconfirm:
            self.get_logger().debug(f"Ignoring duplicate box_id '{msg.box_id}'")
            return

        self.get_logger().info(
            f"New box announcement received: id='{msg.box_id}', landing_pos={msg.landing_pos}"
        )

        confirm = BoxSetupConfirmationMessage()
        confirm.box_id = msg.box_id
        confirm.landing_pos = msg.landing_pos
        # Some interface variants include a 'confirm' flag; set it if available.
        if hasattr(confirm, "confirm"):
            confirm.confirm = True

        self._confirm_pub.publish(confirm)
        self._seen_ids.add(msg.box_id)


def main() -> None:
    rclpy.init()
    node = NewBoxResponder()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
