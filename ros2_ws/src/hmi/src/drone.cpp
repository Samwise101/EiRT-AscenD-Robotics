#include <iostream>
#include "drone.h"

Drone::Drone(int type, Coordinates coord) : drone_type(type), drone_coord(coord){}

Drone::~Drone(){}

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