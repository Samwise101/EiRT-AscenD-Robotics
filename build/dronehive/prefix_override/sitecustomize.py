import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/fljv/sim/EiRT-AscenD-Robotics/ros2_ws/install/dronehive'
