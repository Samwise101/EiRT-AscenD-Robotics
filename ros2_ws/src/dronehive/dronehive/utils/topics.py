#######################
# Uninitialised state #
#######################
DRONEHIVE_NEW_BOX_CONFIMED_TOPIC = "/dronehive/new_box_confirmed"
DRONEHIVE_NEW_SLAVE_BOX_CONFIMED_TOPIC = "/dronehive/new_slave_box_confirmed"
DRONEHIVE_NEW_BOX_TOPIC = "/dronehive/new_box"

#####################
# Initialised state #
#####################

############
# Messages #
############
DRONEHIVE_DEINITIALISE_BOX_TOPIC = "/dronehive/deinitialise_box"
DRONEHIVE_INITIALISE_BOX_TOPIC = "/dronehive/box_initialise"

DRONEHIVE_INITIALISE_SLAVE_BOX_TOPIC = "/dronehive/box_slave_initialise"
DRONEHIVE_DEINITIALISE_SLAVE_BOX_TOPIC = "/dronehive/deinitialise_slave_box"

# HMI sends request to return a drone to home position
DRONEHIVE_GUI_REQUEST_RETURN_HOME_TOPIC = "/dronehive/request_return_home"
# Topic that sends a request to the drone to land at a specific position.
DRONEHIVE_DRONE_RETURN_TO_HOME = "/dronehive/drone_return_to_home_request"

# Topic that sends a request for landing position, the drone ID should be formatted in the topic.
DRONEHIVE_DRONE_LAND_REQUEST = "/dronehive/drone_land_request"
# Topic that receives a request for a drone to lend at a specific position.
DRONEHIVE_REQUEST_LANDING_POS_TOPIC = "/dronehive/request_landing_pos"

############
# Services #
############
DRONEHIVE_DRONE_REQUESTED_LANDING_POS = "/dronehive/drone/landing_pos"
DRONEHIVE_BOX_STATUS_REQUEST_SERVICE = "/dronehive/box_status_request_service"
DRONEHIVE_BOX_STATUS_SLAVE_UPDATE_SERVICE = "/dronehive/box_status_slave_update_service"
DRONEHIVE_GUI_BOXES_ID_SERVICE = "/dronehive/gui_boxes_id_service"
DRONEHIVE_GUI_SLAVE_BOX_INFO_SERVICE = "/dronehive/gui_slave_box_info_service"

DRONEHIVE_DRONE_LAND_NOTIFY_GUI = "/dronehive/drone_update_box_state"
DRONEHIVE_GUI_REQUEST_WAYPOINT_TRAJECTORY_SERVICE = "/dronehive/gui_request_waypoint_trajectory"
DRONEHIVE_DRONE_SEND_TRAJECTORY_SERVICE = "/dronehive/drone_waypoints_"

DRONEHIVE_GUI_REQUEST_DRONE_LAND_SERVICE = "/dronehive/gui_request_drone_land_service"
DRONEHIVE_GUI_REQUEST_DRONE_RETURN_HOME_SERVICE = "/dronehive/gui_request_drone_return_home_service"

DRONEHIVE_REQUEST_BOX_OPEN_SERVICE = "/dronehive/request_box_open_service"

###########
# Actions #
###########
