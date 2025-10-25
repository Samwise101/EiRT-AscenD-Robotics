#pragma once

#ifndef BOX_H
#define BOX_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <QThread>
#include <string>
#include <unordered_map>

#include "helper.h"
#include "drone.h"

enum BoxType {
    SLAVE,
    MASTER,
    UNKNOWN
};


enum class BoxState { UNKNOWN, EMPTY, OCCUPIED };

inline std::string boxStatusToString(BoxState s)
{
    switch(s)
    {
        case BoxState::EMPTY: return "EMPTY";
        case BoxState::UNKNOWN: return "UNKNOWN";
        case BoxState::OCCUPIED: return "OCCUPIED";
        default: return "UNKNOWN";
    }
}

inline BoxState boxStateFromString(const std::string& str) {
    if (str == "EMPTY")     return BoxState::EMPTY;
    if (str == "OCCUPIED")  return BoxState::OCCUPIED;
    return BoxState::UNKNOWN;
}



class Box
{
    public:
        explicit Box(int type, Coordinates coord, std::string id, std::string status, int number);
        ~Box();

    public:
        int get_box_type(void);
        void set_box_type(int);
        void set_box_status(std::string status);

        float get_box_landing_lat(void);
        float get_box_landing_lon(void);
        float get_box_landing_alt(void);

        std::string get_box_id(void);
        std::string get_box_status(void);

        int get_box_number(void);

    private:
        int box_type;
        float box_landing_position_lat;
        float box_landing_position_lon;
        float box_landing_position_alt;
        
        std::string id;
        std::string status;
        int number;
        Coordinates coord;

};

#endif