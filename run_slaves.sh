#!/usr/bin/env bash

cd ~/EIT/EiRT-AscenD-Robotics/ros2_ws/
source install/setup.bash

for i in $(seq $1 $2); do
	# echo "Starting slave node $i"
	export XDG_CONFIG_HOME=$HOME/delete$i
	BOX_ID="slave$i"
	mkdir -p "$XDG_CONFIG_HOME/dronehive"
	OUTPUT_FILE="$XDG_CONFIG_HOME/dronehive/config.json"

	# Write the JSON
cat > "$OUTPUT_FILE" << EOF
{
    "box_id": "$BOX_ID",
    "drone_id": "",
    "initialised": false,
    "lending_position": {
        "lat": 1.1299999952316284,
        "lon": -2.4100000858306885,
        "elv": 0.23999999463558197
    },
    "linked_box_ids": []
}
EOF
	XDG_CONFIG_HOME=$HOME/delete$i ros2 run dronehive slave_node &
	echo $XDG_CONFIG_HOME
done

sleep 30

echo -e "\0[33;1mPublishing box setup confirmations...\0[0m"

for i in $(seq 1 $1); do
	ros2 topic pub -1 /dronehive/new_box_confirmed dronehive_interfaces/msg/BoxSetupConfirmationMessage "{confirm: true, box_id: 'slave$i', landing_pos: {lat: 10, lon: 20, elv: 30}}"
	sleep 1
done
