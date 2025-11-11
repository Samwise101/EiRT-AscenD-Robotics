#pragma once

#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <QColor>
#include <vector>

struct Line { float x1, y1, x2, y2; };
struct Point { float x, y; };

typedef struct
{
    float lat;
    float lon;
    float alt;
} Coordinates;

struct DroneVis
{
    std::string drone_id;
    QColor drone_color;
    std::vector<Point> drone_waypoints;
    bool display;
};

enum PathPlanStates
{
    CREATE_PLAN,
    ACCEPTED,
    REJECTED,
    NONE
};

#endif
