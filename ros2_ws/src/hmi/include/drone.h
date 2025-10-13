#pragma once

#ifndef DRONE_H
#define DRONE_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <QThread>

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
        explicit Drone(int type, Coordinates coord);
        ~Drone();

        int get_drone_type();
        void set_drone_type(int drone_type);

        void set_drone_alt(float value);
        float get_drone_alt();

        void set_drone_lat(float value);
        float get_drone_lat();

        void set_drone_lon(float value);
        float get_drone_lon();

    private:
        int drone_type;
        Coordinates drone_coord;
};

#endif