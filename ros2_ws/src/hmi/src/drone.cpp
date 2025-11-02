#include <iostream>
#include "drone.h"

Drone::Drone(int type, Coordinates coord, std::string id, QColor color, std::string parent_box_id) : 
drone_type(type), drone_coord(coord), drone_id(id), drone_color(color), parentBoxID(parent_box_id){}

Drone::~Drone(){}

void Drone::set_drone_color(QColor color)
{
    this->drone_color = color;
}

QColor Drone::get_drone_color()
{
    return this->drone_color;
}

int Drone::get_drone_type()
{
    return this->drone_type;
}

void Drone::set_drone_type(int type)
{
    this->drone_type = type;
}

void Drone::set_drone_alt(float value)
{
    this->drone_coord.alt = value;
}

float Drone::get_drone_alt()
{
    return this->drone_coord.alt;
}

void Drone::set_drone_lat(float value)
{
    this->drone_coord.lat = value;
}

float Drone::get_drone_lat()
{
    return this->drone_coord.lat;
}

void Drone::set_drone_lon(float value)
{
    this->drone_coord.lon = value;
}

float Drone::get_drone_lon()
{
    return this->drone_coord.lon;
}

void Drone::set_drone_id(std::string id)
{
    this->drone_id = id;
}

std::string Drone::get_drone_id()
{
    return this->drone_id;   
}

void Drone::set_parent_box_id(std::string box_id)
{
    this->parentBoxID = box_id;
}

std::string Drone::get_parent_box_id(void)
{
    return this->parentBoxID;
}
