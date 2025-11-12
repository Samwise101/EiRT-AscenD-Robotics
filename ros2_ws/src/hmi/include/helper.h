#pragma once

#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <QColor>
#include <vector>
#include <QtMath>

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

struct Vec3 { double x, y, z; };

class Conversions
{
    // Convert lat/lon/alt to ECEF (helper)
    Vec3 llaToECEF(double lat, double lon, double alt)
    {
        const double a = 6378137.0;
        const double e2 = 6.69437999014e-3;
        double lat_rad = qDegreesToRadians(lat);
        double lon_rad = qDegreesToRadians(lon);
        double N = a / sqrt(1 - e2 * sin(lat_rad) * sin(lat_rad));
        double x = (N + alt) * cos(lat_rad) * cos(lon_rad);
        double y = (N + alt) * cos(lat_rad) * sin(lon_rad);
        double z = (N * (1 - e2) + alt) * sin(lat_rad);
        return {x, y, z};
    }

    // Convert to local ENU frame
    Vec3 llaToENU(double lat, double lon, double alt,
                double lat0, double lon0, double alt0)
    {
        Vec3 ref = llaToECEF(lat0, lon0, alt0);
        Vec3 pos = llaToECEF(lat, lon, alt);

        // delta in ECEF
        double dx = pos.x - ref.x;
        double dy = pos.y - ref.y;
        double dz = pos.z - ref.z;

        // Convert ECEF delta to local ENU coordinates
        double lat0_rad = qDegreesToRadians(lat0);
        double lon0_rad = qDegreesToRadians(lon0);

        double sinLat = sin(lat0_rad), cosLat = cos(lat0_rad);
        double sinLon = sin(lon0_rad), cosLon = cos(lon0_rad);

        double east  = -sinLon * dx + cosLon * dy;
        double north = -sinLat * cosLon * dx - sinLat * sinLon * dy + cosLat * dz;
        double up    =  cosLat * cosLon * dx + cosLat * sinLon * dy + sinLat * dz;

        return {east, north, up};
    }
};

#endif
