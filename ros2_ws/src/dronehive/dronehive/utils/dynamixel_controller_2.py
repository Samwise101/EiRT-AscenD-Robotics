#!/usr/bin/env python3

# -----------------------------
# precision of the drone landing, what is the deviation
# deflection as a spec
# Extraction time as spec
# Optitrack for vibration at takeoff and landing
# -----------------------------

import time
from dynamixel_sdk import PortHandler, PacketHandler  # Uses Dynamixel SDK library
import argparse

# -----------------------------
# USER SETTINGS
# -----------------------------
BAUDRATE = 57600
PROTOCOL_VERSION = 2.0
EXTEND_TIME = 11             # Time it takes to extend and retract the platform, this is a measured value.

ADDR_PRESENT_POSITION = 132  # XL430 Present Position address (4 bytes)
COMM_SUCCESS = 0

ADDR_OPERATING_MODE      = 11   # Operating Mode (1 byte)
ADDR_TORQUE_ENABLE       = 64   # Torque Enable (1 byte)
ADDR_GOAL_POSITION       = 116  # Goal Position (4 bytes)
ADDR_PROFILE_VELOCITY    = 112  # Profile Velocity (4 bytes)
ADDR_PROFILE_ACCEL       = 108  # Profile Acceleration (4 bytes)

TORQUE_ENABLE  = 1
TORQUE_DISABLE = 0
# -----------------------------
# Open port
# -----------------------------
class DynaControl():
    def __init__(self, port, dyna_id):
        self.dxl_id = dyna_id
        self.porthandler = PortHandler(port)
        self.packethandler = PacketHandler(PROTOCOL_VERSION)
        self.zero_offset = 0
        self.flag = 0

        if self.porthandler.openPort():
            print("[OK] Port opened")
        else:
            raise RuntimeError("Could not open port")

        if self.porthandler.setBaudRate(BAUDRATE):
            print("[OK] Baudrate set")
        else:
            raise RuntimeError("Could not set baudrate")

        self.dyna_initilize()

    def dyna_initilize(self):
        # -----------------------------
        # Reset board
        # -----------------------------
        dxl_comm_result, dxl_error = self.packethandler.reboot(self.porthandler, self.dxl_id)
        print("[OK] Motor rebooted")

        time.sleep(0.5)

        # -----------------------------
        # Ensure torque is disabled before setting the addresses
        # -----------------------------
        dxl_comm_result, dxl_error = self.packethandler.write1ByteTxRx(
            self.porthandler, self.dxl_id, ADDR_TORQUE_ENABLE, TORQUE_DISABLE
        )

        if dxl_comm_result != COMM_SUCCESS:
            raise RuntimeError(self.packethandler.getTxRxResult(dxl_comm_result))
        elif dxl_error != 0:
            raise RuntimeError(self.packethandler.getRxPacketError(dxl_error))
        else:
            print("[OK] Torque Disabled")

        # -----------------------------
        # Check communication with motor
        # -----------------------------
        dxl_model, dxl_comm_result, dxl_error = self.packethandler.ping(self.porthandler, self.dxl_id)

        if dxl_comm_result != COMM_SUCCESS:
            raise RuntimeError(f"Ping failed: {self.packethandler.getTxRxResult(dxl_comm_result)}")
        elif dxl_error != 0:
            raise RuntimeError(f"Motor error: {self.packethandler.getRxPacketError(dxl_error)}")
        else:
            print(f"[OK] Connected to Dynamixel ID {self.dxl_id}, model {dxl_model}")

        # -----------------------------
        # Read Present Position
        # -----------------------------
        dxl_present_position, dxl_comm_result, dxl_error = self.packethandler.read4ByteTxRx(
            self.porthandler, self.dxl_id, ADDR_PRESENT_POSITION
        )

        if dxl_comm_result != COMM_SUCCESS:
            print(f"Read error: {self.packethandler.getTxRxResult(dxl_comm_result)}")
        elif dxl_error != 0:
            print(f"Motor returned error: {self.packethandler.getRxPacketError(dxl_error)}")
        else:
            print(f"[OK] Current Motor Position (ticks): {dxl_present_position}")

        self.zero_offset = dxl_present_position
        print(f'Initial position {dxl_present_position}')

        # -----------------------------
        # Set operation mode to 4
        # -----------------------------
        dxl_comm_result, dxl_error = self.packethandler.write1ByteTxRx(
            self.porthandler, self.dxl_id, ADDR_OPERATING_MODE, 4
        )
        print(f'dxl_comm_result: {dxl_comm_result}')
        if dxl_comm_result != COMM_SUCCESS:
            raise RuntimeError(self.packethandler.getTxRxResult(dxl_comm_result))
        elif dxl_error != 0:
            raise RuntimeError(self.packethandler.getRxPacketError(dxl_error))
        else:
            print("[OK] Operating Mode set to 4 (Extended Position)")


        # -----------------------------
        # Enable torque
        # -----------------------------
        dxl_comm_result, dxl_error = self.packethandler.write1ByteTxRx(
            self.porthandler, self.dxl_id, ADDR_TORQUE_ENABLE, TORQUE_ENABLE
        )

        if dxl_comm_result != COMM_SUCCESS:
            raise RuntimeError(self.packethandler.getTxRxResult(dxl_comm_result))
        elif dxl_error != 0:
            raise RuntimeError(self.packethandler.getRxPacketError(dxl_error))
        else:
            print("[OK] Torque enabled")

        # -----------------------------
        # Set velocity and acceleration
        # -----------------------------
        dxl_comm_result, dxl_error = self.packethandler.write4ByteTxRx(
            self.porthandler, self.dxl_id, ADDR_PROFILE_VELOCITY, 150
        )
        self.packethandler.write4ByteTxRx(
            self.porthandler, self.dxl_id, ADDR_PROFILE_ACCEL, 50
        )
        print("[OK] Motion profiles updated")


    def move_and_wait(self, goal_position, mode):

        dxl_comm_result, dxl_error = self.packethandler.write4ByteTxRx(
            self.porthandler, self.dxl_id, ADDR_GOAL_POSITION, goal_position
        )

        if dxl_comm_result != COMM_SUCCESS:
            print(self.packethandler.getTxRxResult(dxl_comm_result))
            return False
        elif dxl_error != 0:
            print(self.packethandler.getRxPacketError(dxl_error))
            return False
        else:
            print(f"Status: Going {mode} \nMoving to: {goal_position} ticks")

        # Wait until it reaches goal
        t0 = time.perf_counter()

        while True:
            ''' Time to make it smart - Not working yet
            # pos, _, _ = self.packethandler.read4ByteTxRx(
            #     self.porthandler, self.dxl_id, ADDR_PRESENT_POSITION
            # )

            # if abs(pos - goal_position) < 20:   # tolerance in ticks
            #     print('smart')
            #     break
            if t0 + 11 < time.perf_counter():
                # Timeout
                print('Timeout')
                break
            # print(f'Current platform position [ticks]: {pos}/{goal_position} : difference {-goal_position}', end='\r')
            time.sleep(0.05)
            '''

            if t0 + EXTEND_TIME < time.perf_counter():
                print('Timeout')
                break
            time.sleep(0.05)

        return True

    def extend_or_retract(self, mode):
        '''
        args:
            mode - [str]:
                'in' for retracting the platform
                'out' for extracting the platform

        Documents on Variables:
            flag - [int]:
                0 = ready to extract platform
                1 = ready to retract platform
        '''

        if mode == 'out' and self.flag == 0:
            target_ticks = int(-4096 * 6.2)
            self.flag = 1
            goal_position = target_ticks + self.zero_offset
        elif mode == 'in' and self.flag == 1:
            target_ticks = int(4096 * 6.2)
            self.flag = 0
            goal_position = self.zero_offset
        elif (mode == 'in' and self.flag == 0) or (mode == 'out' and self.flag == 1):
            print(f'[WARNING] - Can not extract/retract two times in a row. Status: mode {mode}, flag: {self.flag}')
            return 0
        else:
            print('[WARNING] - Invalid mode argument. Can be either in or out')
            return 0

        # -----------------------------
        # Move motors
        # -----------------------------
        return self.move_and_wait(goal_position=goal_position, mode=mode)

    def manual_start(self):
        '''
        This code is for testing the system alone.
        you provide an input in terminal either use in, out or exit comment.
        '''
        while True:
            print('----------GUIDE----------\n'
                  'Write in for retracting\n'
                  'Write out for extracting\n'
                  'Write exit for stopping\n'
                  '-------------------------\n')

            inp = input()

            if inp == 'in' or inp == 'out':
                self.extend_or_retract(inp)

            elif inp == 'exit':
                if self.flag == 1:
                    self.extend_or_retract('in')
                break

            else:
                print('[WARNING] - Invalid mode argument. Can be either in, out or exit')


if __name__ == '__main__':

    parser = argparse.ArgumentParser(description="Control a Dynamixel motor")

    parser.add_argument("--port", "-p", required=True,
                        help="USB port, e.g. COM10 or /dev/ttyUSB0")

    parser.add_argument("--id", "-i", type=int, required=True,
                        help="Dynamixel ID - 1 for slavebox, 0 for masterbox")

    args = parser.parse_args()

    dyna = DynaControl(
        port=args.port,
        dyna_id=args.id
    )

    dyna.manual_start()

    dyna.porthandler.closePort()

    # True - ready to land, so the platform is fully extended
