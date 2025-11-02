#pragma once

#ifndef DRONE_H
#define DRONE_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <QThread>
#include <string>
#include <QColor>

#include "helper.h"

enum DroneType{
    QuadCopter,
    HexaCopter,
    BiCopter,
    Unknown,
};

class Drone
{
    public:
        explicit Drone(int type, Coordinates coord, std::string id, QColor color);
        ~Drone();

        int get_drone_type();
        void set_drone_type(int drone_type);

        void set_drone_alt(float value);
        float get_drone_alt();

        void set_drone_lat(float value);
        float get_drone_lat();

        void set_drone_lon(float value);
        float get_drone_lon();

        void set_drone_id(std::string id);
        std::string get_drone_id();

        void set_drone_color(QColor color);
        QColor get_drone_color();

    private:
        int drone_type;
        Coordinates drone_coord;
        std::string drone_id;
        QColor drone_color;
};

#endif