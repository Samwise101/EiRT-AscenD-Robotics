#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.logging import get_logger
import time
from dynamixel_sdk import PortHandler, PacketHandler

from enum import IntEnum

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


MAX_CURRENT = 300

class XL430Controller:
	def __init__(self, device_name='/dev/ttyUSB0', baudrate=57600, *, dxl_id):

		self.device_name = device_name
		self.baudrate = baudrate
		self.dxl_id = dxl_id
		self.protocol_version = 2.0


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
		get_logger(f"motor_{self.dxl_id}").info(f"Operating mode set to {mode}")


	# --- Control methods ---
	def move_extended(self, position_ticks, profile_velocity=200, profile_accel=50):
		"""Move >360° using Extended Position Mode."""
		self.set_mode(OperatingMode.MODE_EXTENDED_POSITION)
		self.write4(ControlCommand.ADDR_PROFILE_VELOCITY, profile_velocity)
		self.write4(ControlCommand.ADDR_PROFILE_ACCELERATION, profile_accel)
		self.write4(ControlCommand.ADDR_GOAL_POSITION, position_ticks)
		get_logger(f"motor_{self.dxl_id}").info(f"Moving to {position_ticks} ticks...")

		while rclpy.ok():
			pos = self.read4(ControlCommand.ADDR_PRESENT_POSITION)
			cur = self.read2(ControlCommand.ADDR_PRESENT_CURRENT)
			get_logger(f"motor_{self.dxl_id}").info(f"REQUESETED: {position_ticks:10f} Pos: {pos}, Current: {cur}")

			if abs(pos - position_ticks) < 20:
				get_logger(f"motor_{self.dxl_id}").info("Target reached.")
				break
			# if abs(cur) > MAX_CURRENT:
			# 	get_logger(f"motor_{self.dxl_id}").warn("High current detected! Stopping.")
			# 	break
			time.sleep(0.1)

		self.stop()


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
		except Exception:
			pass
		self.write1(ControlCommand.ADDR_TORQUE_ENABLE, 0)
		get_logger(f"motor_{self.dxl_id}").info("Motor stopped, torque disabled")


	def destroy(self):
		self.stop()
		self.port_handler.closePort()
		get_logger(f"motor_{self.dxl_id}").info("Port closed")



def main(args=None):
	rclpy.init(args=args)
	node = Node('dynamixel_controller_node')
	motor1 = XL430Controller('/dev/ttyUSB0', 57600, dxl_id=0)
	motor2 = XL430Controller('/dev/ttyUSB0', 57600, dxl_id=1)

	try:
		# Example 1: Multi-turn move
		# 4096 ticks per revolution → 5 turns = 20480 ticks
		motor1.move_extended(0, profile_velocity=500, profile_accel=100)
		motor2.move_extended(4096 * 5, profile_velocity=500, profile_accel=100)

		motor1.move_extended(4096 * 5, profile_velocity=500, profile_accel=100)
		motor2.move_extended(0, profile_velocity=500, profile_accel=100)

		# Example 2: Velocity move
		# motor1.move_velocity(200)  # units ≈ 0.229 RPM per tick (depends on model)
	finally:
		motor1.destroy()
		motor2.destroy()
		node.destroy_node()
		rclpy.shutdown()

if __name__ == '__main__':
	main()

