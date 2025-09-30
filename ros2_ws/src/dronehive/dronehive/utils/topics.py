#######################
# Uninitialised state #
#######################
DRONEHIVE_NEW_BOX_CONFIMED_TOPIC = "/dronehive/new_box_confirmed"
DRONEHIVE_NEW_BOX_TOPIC = "/dronehive/new_box"

#####################
# Initialised state #
#####################

############
# Messages #
############
DRONEHIVE_DEINITIALISE_BOX_TOPIC = "/dronehive/deinitialise_box"

# Topic that sends a request for landing position, the drone ID should be formatted in the topic.
DRONEHIVE_DRONE_LAND_REQUEST = lambda drone_id: f"/dronehive/{drone_id}/drone"
# Topic that receives a request for a drone to lend at a specific position.
DRONEHIVE_REQUEST_LANDING_POS_TOPIC = "/dronehive/request_landing_pos"

############
# Services #
############
DRONEHIVE_BOX_BROADCAST_SERVICE = "/dronehive/box_broadcast_service"

###########
# Actions #
###########
