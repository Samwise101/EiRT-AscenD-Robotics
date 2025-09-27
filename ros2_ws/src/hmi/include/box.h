#pragma once

#ifndef BOX_H
#define BOX_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <QThread>

typedef struct
{
    float lat;
    float lon;
    float alt;
} Coordinates;

enum BoxType {
    SLAVE,
    MASTER,
    UNKNOWN
};

class Box
{
    public:
        explicit Box(int type, Coordinates coord, int id, int number);
        ~Box();

    public:
        int get_box_type(void);
        void set_box_type(int);

        float get_box_landing_lat(void);
        float get_box_landing_lon(void);
        float get_box_landing_alt(void);

        int get_box_id(void);

        int get_box_number(void);

    private:
        int box_type;
        float box_landing_position_lat;
        float box_landing_position_lon;
        float box_landing_position_alt;
    
    private:
        
        int id;
        int number;
        Coordinates coord;

};

#endif