# Message containning the status of the drone

float64 UNKNOWN_POSITION = -1.7976931348623157e+308

string drone_id
float32 battery_voltage
float32 battery_percentage
string fligt_state
bool reached_first_waypoint
PositionMessage current_position
PositionMessage landing_position

