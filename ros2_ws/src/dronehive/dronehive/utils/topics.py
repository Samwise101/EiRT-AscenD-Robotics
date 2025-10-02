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

# Topic that sends a request for landing position, the drone ID should be formatted in the topic.
DRONEHIVE_DRONE_LAND_REQUEST = "/dronehive/drone_land_request"
# Topic that receives a request for a drone to lend at a specific position.
DRONEHIVE_REQUEST_LANDING_POS_TOPIC = "/dronehive/request_landing_pos"

############
# Services #
############
DRONEHIVE_BOX_BROADCAST_SERVICE = "/dronehive/box_broadcast_service"
DRONEHIVE_DRONE_REQUESTED_LANDING_POS = "/dronehive/drone/landing_pos"

###########
# Actions #
###########
