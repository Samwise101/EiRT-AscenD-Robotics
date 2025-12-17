#!/usr/bin/env bash
set -euo pipefail

# Calls all per-drone landing trigger services exposed by offboard.py:
#   /dronehive/sim_drone_land_<drone_id>  (std_srvs/srv/SetBool)

SERVICES=$(ros2 service list | grep -E '^/dronehive/sim_drone_land_' || true)

if [[ -z "${SERVICES}" ]]; then
  echo "No drone landing trigger services found (/dronehive/sim_drone_land_*)."
  exit 0
fi

echo "Requesting LAND for all drones:"
echo "${SERVICES}"

while IFS= read -r srv; do
  [[ -z "${srv}" ]] && continue
  echo " -> ${srv}"
  ros2 service call "${srv}" std_srvs/srv/SetBool "{data: true}" >/dev/null 2>&1 ||     echo "    (warn) call failed for ${srv}"
done <<< "${SERVICES}"

echo "Done."
