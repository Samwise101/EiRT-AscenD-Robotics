#include <iostream>
#include "drone.h"

#include <QRandomGenerator>


static QColor randomColor()
{
    int r = QRandomGenerator::global()->bounded(256);
    int g = QRandomGenerator::global()->bounded(256);
    int b = QRandomGenerator::global()->bounded(256);

    return QColor(r, g, b);
}

static QColor randomDistinctColor(int index, int total)
{
    int hue = (360 * index / total) % 360;
    return QColor::fromHsv(hue, 255, 255);
}

Drone::Drone(int type, Coordinates coord, std::string id, QColor color) : drone_type(type), drone_coord(coord), drone_id(id), drone_color(color){}

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