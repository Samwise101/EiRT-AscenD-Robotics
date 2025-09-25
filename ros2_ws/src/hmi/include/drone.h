#pragma once

#ifndef DRONE_H
#define DRONE_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <QThread>

class Drone
{
    public:
        explicit Drone(int type);
        ~Drone();

        int get_drone_type();
        void set_drone_type(int drone_type);

    public:
        enum DroneType{
            QuadCopter,
            HexaCopter,
            BiCopter,
        };
    
    private:
        int drone_type;
};

#endif