#include <iostream>
#include "drone.h"

Drone::Drone(int type) : drone_type(type){}

Drone::~Drone(){}

int Drone::get_drone_type()
{
    return this->drone_type;
}

void Drone::set_drone_type(int type)
{
    this->drone_type = type;
}