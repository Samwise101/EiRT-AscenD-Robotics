#include <iostream>
#include "box.h"

Box::Box(int type, float lat, float lon, float alt) : 
box_type(type), box_landing_position_alt(alt), box_landing_position_lat(lat), box_landing_position_lon(lon)
{}

Box::~Box(){}

void Box::set_box_type(int type)
{
    this->box_type = type;
}

int Box::get_box_type()
{
    return this->box_type;
}