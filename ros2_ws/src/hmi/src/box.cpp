#include <iostream>
#include "box.h"

Box::Box(int type, Coordinates coord, std::string id, std::string status, int number) : 
box_type(type), coord(coord), id(id), number(number), status(status), assigned_drone_id("")
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

void Box::set_box_status(std::string status)
{
    this->status = status;
}

std::string Box::get_box_status()
{
    return this->status;
}

void Box::set_assigned_drone_id(std::string drone_id)
{
    this->assigned_drone_id = drone_id;
}

std::string Box::get_assigned_drone_id()
{
    return this->assigned_drone_id;
}