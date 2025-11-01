#pragma once

#include <QFrame>
#include <QPainter>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDomDocument>
#include <vector>

#include "drone.h"

class WarehouseFrame : public QFrame
{
    Q_OBJECT

public:
    explicit WarehouseFrame(QWidget *parent = nullptr);
    ~WarehouseFrame();

    struct Line { float x1, y1, x2, y2; };
    struct Point { float x, y; };
    float scale_factor;

    std::vector<Line> warehouseLines;
    std::vector<std::vector<Point>> dronePaths;

    void loadWarehouseJson(QString filename);
    void loadTrajectoryXml(QString filename);
    void clearVisuals();
    void setScaleFactor(float value);
    float getScaleFactor();
    void incrementScaleFactor();
    void decrementScaleFactor();

protected:   // <-- paintEvent should be protected, not private
    void paintEvent(QPaintEvent *event) override;
};
