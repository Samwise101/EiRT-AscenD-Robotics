#!/usr/bin/env bash

echo -e "\0[33;1mPublishing box setup confirmations...\0[0m"

for i in $(seq $1 $2); do
	ros2 topic pub -1 /dronehive/new_box_confirmed dronehive_interfaces/msg/BoxSetupConfirmationMessage "{confirm: true, box_id: 'slave$i', landing_pos: {lat: 10, lon: 20, elv: 30}}"
	sleep 1
done
