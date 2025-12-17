#!/bin/bash
drone=$1
ros2 service call /dronehive/sim_drone_land_${drone} std_srvs/srv/SetBool "{data: true}"
