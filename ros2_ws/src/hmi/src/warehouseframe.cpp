#include "warehouseframe.h"
#include <algorithm>

#include <QHBoxLayout>
#include <QVector3D>

#define MAX(x,y) ((x > y) ? x : y)
#define MIN(x,y) ((x < y) ? x : y)

WarehouseFrame::WarehouseFrame(QWidget *parent) : QFrame(parent)
{
    this->scale_factor = 1.0;
}

WarehouseFrame::~WarehouseFrame(){}


void WarehouseFrame::loadWarehouseJson(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonArray walls = doc["walls"].toArray();
    warehouseLines.clear();

    for (auto w : walls)
    {
        QJsonObject obj = w.toObject();
        Line line;
        line.x1 = obj["x1"].toDouble();
        line.y1 = obj["y1"].toDouble();
        line.x2 = obj["x2"].toDouble();
        line.y2 = obj["y2"].toDouble();

        warehouseLines.push_back(line);
    }

    update(); // trigger repaint
}

void WarehouseFrame::clearVisuals()
{
    for(auto drone : drones)
    {
        drone.drone_waypoints.clear();
    }

    drones.clear();
    
    this->warehouseLines.clear();
    update();
}

void WarehouseFrame::loadTrajectoryXml(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    if(!drones.empty())
        drones.clear();

    QXmlStreamReader xml(&file);

    DroneVis current;
    bool insideDrone = false;

    while (!xml.atEnd())
    {
        xml.readNext();

        // <drone ...>
        if (xml.isStartElement() && xml.name() == "drone")
        {
            insideDrone = true;
            current = DroneVis(); // reset
            current.display = true;

            auto attrs = xml.attributes();
            current.drone_id = attrs.value("id").toString().toStdString();
            current.drone_color = QColor(attrs.value("color").toString());
        }

        // <point x="" y=""/>
        if (xml.isStartElement() && xml.name() == "point" && insideDrone)
        {
            auto attrs = xml.attributes();
            Point p;
            p.x = attrs.value("x").toDouble();
            p.y = attrs.value("y").toDouble();
            current.drone_waypoints.push_back(p);
        }

        // </drone>
        if (xml.isEndElement() && xml.name() == "drone")
        {
            drones.push_back(current);
            insideDrone = false;
        }
    }

    file.close();
    update();
}

void WarehouseFrame::setDisplayByIndex(int index, bool value)
{
    if(index < 0 or drones.empty()) return;

    std::cout << "The entry was set to:" << value << std::endl;  
    drones[index].display = value;

    update();
}

bool WarehouseFrame::isDisplaySet(int index)
{
    if(index < 0 || drones.empty()) return false;

    return drones[index].display;
}


void WarehouseFrame::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    p.fillRect(rect(), Qt::white);

    // Draw warehouse
    p.setPen(QPen(Qt::green, 2));

    // Find bounding box
    int minX = INT_MAX, minY = INT_MAX;
    int maxX = INT_MIN, maxY = INT_MIN;

    for (const auto &l : warehouseLines)
    {
        minX = MIN(minX, MIN(l.x1, l.x2));
        minY = MIN(minY, MIN(l.y1, l.y2));
        maxX = MAX(maxX, MAX(l.x1, l.x2));
        maxY = MAX(maxY, MAX(l.y1, l.y2));
    }

    // Warehouse center
    float warehouseCenterX = (minX * this->scale_factor + maxX * this->scale_factor) / 2.0f;
    float warehouseCenterY = (minY * this->scale_factor + maxY * this->scale_factor) / 2.0f;

    // Frame center
    float frameCenterX = width() / 2.0f ;
    float frameCenterY = height() / 2.0f;

    // Offset to center the drawing
    float offsetX = frameCenterX - warehouseCenterX;
    float offsetY = frameCenterY - warehouseCenterY;

    if (!warehouseLines.empty())
    {
        for (const auto &l : warehouseLines)
        {
            p.drawLine(l.x1 * this->scale_factor + offsetX, l.y1 * this->scale_factor + offsetY,
                    l.x2 * this->scale_factor + offsetX, l.y2 * this->scale_factor + offsetY);
        }
    }

    if(drones.empty()) return;

    for(auto drone : drones)
    {
        std::cout << "Drone " << drone.drone_id << " with display = " << drone.display << std::endl;
        if(drone.display == false) 
        {
            std::cout << "Skipping drone" <<std::endl;
            continue;
        }
        // Draw path
        if (!drone.drone_waypoints.empty())
        {
            p.setPen(QPen(drone.drone_color, 2*this->scale_factor));
            for (size_t i = 0; i < drone.drone_waypoints.size() - 1; i++)
                p.drawLine(drone.drone_waypoints[i].x* this->scale_factor + offsetX, drone.drone_waypoints[i].y* this->scale_factor + offsetY,
                            drone.drone_waypoints[i+1].x* this->scale_factor + offsetX, drone.drone_waypoints[i+1].y* this->scale_factor + offsetY);

            p.setBrush(drone.drone_color);
            for (auto &pt : drone.drone_waypoints)
                p.drawEllipse(QPointF(pt.x* this->scale_factor + offsetX, pt.y* this->scale_factor + offsetY), 3, 3);
        }
    }
}

void WarehouseFrame::setScaleFactor(float value)
{
    if(value == 0.0)
        value = 0.1;

    this->scale_factor = value;
    update();
}

float WarehouseFrame::getScaleFactor()
{
    return this->scale_factor;
}

void WarehouseFrame::incrementScaleFactor()
{
    this->scale_factor += 0.1;

    std::cout << "Increasing scale factor to " << this->scale_factor << std::endl;
    update();
}

void WarehouseFrame::decrementScaleFactor()
{
    this->scale_factor -= 0.1;
    if(this->scale_factor <= 0.1)
        this->scale_factor = 0.1;
    
    std::cout << "Decreasing scale factor to " << this->scale_factor << std::endl;
    update();
}

std::vector<DroneVis> WarehouseFrame::getDroneVisData()
{
    return this->drones;
}
