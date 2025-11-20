#!/usr/bin/env python3
from rclpy.callback_groups import ReentrantCallbackGroup
from dronehive.utils import Config
import rclpy
from rclpy.utilities import ok as rclpy_ok
from rclpy.node import Node
from rclpy.logging import get_logger
import time
from dynamixel_sdk import PortHandler, PacketHandler
from rclpy.executors import MultiThreadedExecutor

from enum import IntEnum

from std_srvs.srv import SetBool

class CommResult(IntEnum):
	COMM_SUCCESS = 0  # tx or rx packet communication success
	COMM_PORT_BUSY = -1000  # Port is busy (in use)
	COMM_TX_FAIL = -1001  # Failed transmit instruction packet
	COMM_RX_FAIL = -1002  # Failed get status packet
	COMM_TX_ERROR = -2000  # Incorrect instruction packet
	COMM_RX_WAITING = -3000  # Now recieving status packet
	COMM_RX_TIMEOUT = -3001  # There is no status packet
	COMM_RX_CORRUPT = -3002  # Incorrect status packet
	COMM_NOT_AVAILABLE = -9000  #


class OperatingMode(IntEnum):
	MODE_CURRENT = 0
	MODE_VELOCITY = 1
	MODE_POSITION = 3
	MODE_EXTENDED_POSITION = 4
	MODE_CURRENT_BASED_POS = 5


class ControlCommand(IntEnum):
	# --- XL430 Control Table Addresses (from e-Manual) ---
	# https://emanual.robotis.com/docs/en/dxl/x/xl430-w250/#control-table-data
	ADDR_OPERATING_MODE = 11
	ADDR_TORQUE_ENABLE = 64
	ADDR_PROFILE_ACCELERATION = 108
	ADDR_PROFILE_VELOCITY = 112
	ADDR_GOAL_VELOCITY = 104
	ADDR_GOAL_POSITION = 116
	ADDR_PRESENT_CURRENT = 126
	ADDR_PRESENT_VELOCITY = 128
	ADDR_PRESENT_POSITION = 132


class MotorOperation(IntEnum):
	OPEN_BOX = 1
	CLOSE_BOX = 2


MAX_CURRENT = 300

class XL430Controller(Node):
	def __init__(self, device_name='/dev/ttyUSB0', baudrate=57600, *, dxl_id):
		super().__init__(f"xl430_controller_node_{dxl_id}")

		self.device_name = device_name
		self.baudrate = baudrate
		self.dxl_id = dxl_id
		self.protocol_version = 2.0
		self.stopped = True

		config = Config.load()
		callback_group = ReentrantCallbackGroup()
		self.get_logger().info(f"Setting up XL430Controller on service namespace /{config.box_id}/motor_{self.dxl_id}")
		self.create_service(
			SetBool,
			f'/{config.box_id}/motor_{self.dxl_id}/open_box',
			self.handle_open_box,
			callback_group=callback_group
		)

		self.create_service(
			SetBool,
			f'/{config.box_id}/motor_{self.dxl_id}/stop',
			self.handle_stop,
			callback_group=callback_group
		)

		# --- Setup SDK handlers ---
		self.port_handler = PortHandler(self.device_name)
		self.packet_handler = PacketHandler(self.protocol_version)

		if not self.port_handler.openPort():
			raise RuntimeError(f"Failed to open port {self.device_name}")
		if not self.port_handler.setBaudRate(self.baudrate):
			raise RuntimeError(f"Failed to set baudrate {self.baudrate}")
		get_logger(f"motor_{self.dxl_id}").info("Port open & baudrate set")

		# Enable torque
		self.write1(ControlCommand.ADDR_TORQUE_ENABLE, 1)
		get_logger(f"motor_{self.dxl_id}").info("Torque enabled")


	def handle_open_box(self, request: SetBool.Request, response: SetBool.Response) -> SetBool.Response:
		self.get_logger().info(f"Received open_box request: {'open' if request.data else 'close'}")
		if request.data:
			response.success = self.open_box()
			if response.success:
				get_logger(f"motor_{self.dxl_id}").info("Box opened successfully.")
			else:
				response.message = "Failed to open box."
				get_logger(f"motor_{self.dxl_id}").error("Failed to open box.")

		else:
			response.success = self.close_box()
			if response.success:
				get_logger(f"motor_{self.dxl_id}").info("Box closed successfully.")
			else:
				response.message = "Failed to close box."
				get_logger(f"motor_{self.dxl_id}").error("Failed to close box.")

		return response


	def handle_stop(self, request: SetBool.Request, response: SetBool.Response) -> SetBool.Response:
		self.stop()
		response.success = True
		get_logger(f"motor_{self.dxl_id}").info("Motor stopped via service call.")
		return response


	# --- Helpers for read/write ---
	def write1(self, address, value):
		res, err = self.packet_handler.write1ByteTxRx(self.port_handler, self.dxl_id, address, value)
		if res != 0 or err != 0:
			get_logger(f"motor_{self.dxl_id}").error(f"Write1 error at {address}: res={res}, err={err}")


	def write4(self, address, value):
		res, err = self.packet_handler.write4ByteTxRx(self.port_handler, self.dxl_id, address, int(value))
		if res != 0 or err != 0:
			get_logger(f"motor_{self.dxl_id}").error(f"Write4 error at {address}: res={res}, err={err}")


	def read2(self, address, signed=True):
		val, result, error = self.packet_handler.read2ByteTxRx(self.port_handler, self.dxl_id, address)
		# Convert to signed 16-bit value manually:
		if signed and val > 32767:
			val -= 65536
		if result != CommResult.COMM_SUCCESS:
			get_logger(f"motor_{self.dxl_id}").error(f"Read2 error at {address}: res={result}, err={error}")

		return val


	def read4(self, address, signed=True):
		val, result, error = self.packet_handler.read4ByteTxRx(self.port_handler, self.dxl_id, address)
		# Convert to signed 32-bit value manually
		if signed and val > 2147483647:
			val -= 4294967296

		if result != CommResult.COMM_SUCCESS:
			get_logger(f"motor_{self.dxl_id}").error(f"Read2 error at {address}: res={result}, err={error}")
		return val


	def set_mode(self, mode):
		self.write1(ControlCommand.ADDR_TORQUE_ENABLE, 0)  # disable torque before changing
		self.write1(ControlCommand.ADDR_OPERATING_MODE, mode)
		self.write1(ControlCommand.ADDR_TORQUE_ENABLE, 1)
		self.stopped = False
		get_logger(f"motor_{self.dxl_id}").info(f"Operating mode set to {mode}")


	# --- Control methods ---
	def move_extended(self, position_ticks, profile_velocity=200, profile_accel=50) -> bool:
		"""Move >360° using Extended Position Mode."""
		self.set_mode(OperatingMode.MODE_EXTENDED_POSITION)
		self.write4(ControlCommand.ADDR_PROFILE_VELOCITY, profile_velocity)
		self.write4(ControlCommand.ADDR_PROFILE_ACCELERATION, profile_accel)
		self.write4(ControlCommand.ADDR_GOAL_POSITION, position_ticks)
		get_logger(f"motor_{self.dxl_id}").info(f"Moving to {position_ticks} ticks...")

		now = time.time()
		while rclpy_ok() or not self.stopped:
			pos = self.read4(ControlCommand.ADDR_PRESENT_POSITION)
			cur = self.read2(ControlCommand.ADDR_PRESENT_CURRENT)
			get_logger(f"motor_{self.dxl_id}").info(f"REQUESETED: {position_ticks:10f} Pos: {pos}, Current: {cur}")

			if abs(pos - position_ticks) < 20:
				get_logger(f"motor_{self.dxl_id}").info("Target reached.")
				self.stop()
				return True

			if abs(cur) > MAX_CURRENT and (time.time() - now) > 2.0:
				# If the current is too high, the motor is likely stalled or obstructed
				# and the target position is not reached.
				get_logger(f"motor_{self.dxl_id}").warn("High current detected! Stopping.")
				return False

			time.sleep(0.1)

		self.stop()
		return True


	def move_velocity(self, velocity_ticks):
		"""Rotate continuously with given velocity."""
		self.set_mode(OperatingMode.MODE_VELOCITY)
		self.write4(ControlCommand.ADDR_GOAL_VELOCITY, velocity_ticks)
		get_logger(f"motor_{self.dxl_id}").info(f"Velocity set to {velocity_ticks}")

		for _ in range(30):
			vel = self.read4(ControlCommand.ADDR_PRESENT_VELOCITY)
			cur = self.read2(ControlCommand.ADDR_PRESENT_CURRENT)
			get_logger(f"motor_{self.dxl_id}").info(f"Vel: {vel}, Current: {cur}")
			if abs(cur) > MAX_CURRENT:
				get_logger(f"motor_{self.dxl_id}").warn("High load, stopping motor.")
				break
			time.sleep(0.1)
		self.stop()


	def stop(self):
		"""Stop by writing zero velocity and disabling torque."""
		try:
			self.write4(ControlCommand.ADDR_GOAL_VELOCITY, 0)
			self.stopped = True
		except Exception:
			pass
		self.write1(ControlCommand.ADDR_TORQUE_ENABLE, 0)
		get_logger(f"motor_{self.dxl_id}").info("Motor stopped, torque disabled")


	def destroy(self):
		self.stop()
		self.port_handler.closePort()
		self.destroy_node()
		get_logger(f"motor_{self.dxl_id}").info("Port closed")


	def open_box(self) -> bool:
		get_logger(f"motor_{self.dxl_id}").info("Opening box...")
		return self.move_extended(4096 * 6.1, profile_velocity=150, profile_accel=100)


	def close_box(self) -> bool:
		get_logger(f"motor_{self.dxl_id}").info("Closing box...")
		return self.move_extended(-4500, profile_velocity=150, profile_accel=100)




def main(args=None):
	rclpy.init(args=args)
	motor = XL430Controller('/dev/ttyUSB0', 57600, dxl_id=0)
	executor = MultiThreadedExecutor()
	executor.add_node(motor)

	executor.spin()

	motor.destroy()
	rclpy.shutdown()




if __name__ == '__main__':
	# motor1 = XL430Controller('/dev/ttyUSB0', 57600, dxl_id=0)
	motor2 = XL430Controller('/dev/ttyUSB0', 57600, dxl_id=1)
	velocity = 150

	try:
		# Example 1: Multi-turn move
		# 4096 ticks per revolution → 5 turns = 20480 ticks
		# motor1.move_extended(0, profile_velocity=500, profile_accel=100)
		motor2.move_extended(-4500, profile_velocity=velocity, profile_accel=100)

		input("Press Enter to move back...")

		# motor1.move_extended(4096 * 5, profile_velocity=500, profile_accel=100)
		# 20336
		motor2.move_extended(4096 * 5 - 900, profile_velocity=velocity, profile_accel=100)

		# Example 2: Velocity move
		# motor1.move_velocity(200)  # units ≈ 0.229 RPM per tick (depends on model)
	except Exception as e:
		motor2.get_logger().error(f"Error during motor operation: {e}")
		motor2.stop()
		motor2.destroy()
		rclpy.shutdown()

	finally:
		# motor1.destroy()
		motor2.destroy()
		rclpy.shutdown()

