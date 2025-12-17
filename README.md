# DRONEHIVE Bare-Bones Simulation

Bare Bones simulation for project DroneHive by
AscendRobotics.


## 1. Workspace setup

Clone and build the workspace
Then run either of these commands:

```bash
ros2 launch dronehive world_row.launch.py

#or

ros2 launch dronehive world_tower.launch.py

#or

ros2 launch dronehive world_scatter.launch.py

#At the bottom of each of these files found at /home/<usr>/<path_to_workspace>/ros2_ws/src/dronehive/launch
#You can change the parameters of the launch world, such as number of boxes, drones, spacing etc...

#In order to kill all running drones (make them ask for a landing request)
#do the following:

cd /home/<usr>/<path_to_workspace>/EiRT-AscenD-Robotics/ros2_ws/src/scripts
./kill_all_drones.sh

#or to make one of them land:
./drone_lands.sh <drone_id> #e.g drone1, up to droneN