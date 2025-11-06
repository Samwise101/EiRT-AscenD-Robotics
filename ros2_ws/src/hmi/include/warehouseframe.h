#pragma once

#include <QFrame>
#include <QPainter>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDomDocument>
#include <vector>
#include <string>
#include <QFile>
#include <QXmlStreamReader>
#include <string>

#include "drone.h"

struct Line { float x1, y1, x2, y2; };
struct Point { float x, y; };

struct DroneVis
{
    std::string drone_id;
    QColor drone_color;
    std::vector<Point> drone_waypoints;
    bool display;
};


class WarehouseFrame : public QFrame
{
    Q_OBJECT

public:
    explicit WarehouseFrame(QWidget *parent = nullptr);
    ~WarehouseFrame();

    float scale_factor;

    std::vector<Line> warehouseLines;

    void loadWarehouseJson(QString filename);
    void loadTrajectoryXml(QString filename);
    void clearVisuals();
    void setScaleFactor(float value);
    float getScaleFactor();
    void incrementScaleFactor();
    void decrementScaleFactor();
    void setDisplayByIndex(int index, bool value);
    bool isDisplaySet(int index);

    std::vector<DroneVis> getDroneVisData();

    std::vector<DroneVis> drones;

protected:   // <-- paintEvent should be protected, not private
    void paintEvent(QPaintEvent *event) override;
};
