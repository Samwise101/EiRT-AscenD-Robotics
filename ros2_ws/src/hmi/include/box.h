#pragma once

#ifndef BOX_H
#define BOX_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <QThread>
#include <string>

#include "helper.h"
#include "drone.h"

enum BoxType {
    SLAVE,
    MASTER,
    UNKNOWN
};

class Box
{
    public:
        explicit Box(int type, Coordinates coord, std::string id, int number);
        ~Box();

    public:
        int get_box_type(void);
        void set_box_type(int);

        float get_box_landing_lat(void);
        float get_box_landing_lon(void);
        float get_box_landing_alt(void);

        std::string get_box_id(void);

        int get_box_number(void);

    private:
        int box_type;
        float box_landing_position_lat;
        float box_landing_position_lon;
        float box_landing_position_alt;
        
        std::string id;
        int number;
        Coordinates coord;

};

#endif