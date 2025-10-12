#include <iostream>
#include "box.h"

Box::Box(int type, Coordinates coord, std::string id, int number) : 
box_type(type), coord(coord), id(id), number(number)
{

}

Box::~Box(){}

void Box::set_box_type(int type)
{
    this->box_type = type;
}

int Box::get_box_type()
{
    return this->box_type;
}

float Box::get_box_landing_lat(void)
{
    return this->coord.lat;
}

float Box::get_box_landing_lon(void)
{
    return this->coord.lon;
}

float Box::get_box_landing_alt(void)
{
    return this->coord.alt;
}

std::string Box::get_box_id(void)
{
    return this->id;
}

int Box::get_box_number(void)
{
    return this->number;
}