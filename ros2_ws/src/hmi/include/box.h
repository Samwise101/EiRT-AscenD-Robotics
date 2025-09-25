#pragma once

#ifndef BOX_H
#define BOX_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <QThread>

class Box
{
    public:
        explicit Box(int type, float lat, float lon, float alt);
        ~Box();

    public:
        int get_box_type(void);
        void set_box_type(int);

    private:
        int box_type;
        float box_landing_position_lat;
        float box_landing_position_lon;
        float box_landing_position_alt;

    public:
        enum BoxType {
            Slave,
            Master,
            Unknown
        };
};

#endif