#include "warehouseframe.h"
#include <algorithm>

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
    this->dronePaths.clear();
    this->warehouseLines.clear();
    update();
}

void WarehouseFrame::loadTrajectoryXml(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QDomDocument doc;
    doc.setContent(&file);
    file.close();

    std::vector<Point> dronePath;
    dronePath.clear();

    QDomNodeList pts = doc.elementsByTagName("point");

    for (int i = 0; i < pts.size(); i++)
    {
        QDomElement e = pts.at(i).toElement();
        Point p;
        p.x = e.attribute("x").toDouble();
        p.y = e.attribute("y").toDouble();
        dronePath.push_back(p);
    }

    dronePaths.push_back(dronePath);

    update(); // trigger repaint
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

    if(dronePaths.empty()) return;

    for(auto dronePath : dronePaths)
    {
        // Draw path
        if (!dronePath.empty())
        {
            p.setPen(QPen(Qt::red, 2));
            for (size_t i = 0; i < dronePath.size() - 1; i++)
                p.drawLine(dronePath[i].x* this->scale_factor + offsetX, dronePath[i].y* this->scale_factor + offsetY,
                            dronePath[i+1].x* this->scale_factor + offsetX, dronePath[i+1].y* this->scale_factor + offsetY);

            p.setBrush(Qt::blue);
            for (auto &pt : dronePath)
                p.drawEllipse(QPointF(pt.x* this->scale_factor + offsetX, pt.y* this->scale_factor + offsetY), 3, 3);
        }
    }
}

void WarehouseFrame::setScaleFactor(float value)
{
    if(value == 0.0)
        value = 1.0;

    this->scale_factor = value;
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