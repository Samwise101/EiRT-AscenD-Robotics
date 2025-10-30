#include "warehouseframe.h"

WarehouseFrame::WarehouseFrame(QWidget *parent) : QFrame(parent)
{
}

WarehouseFrame::~WarehouseFrame(){};

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
    
    if(!warehouseLines.empty())
    {
        for (const auto &l : warehouseLines)
            p.drawLine(l.x1, l.y1, l.x2, l.y2);
    }

    if(dronePaths.empty()) return;

    for(auto dronePath : dronePaths)
    {
        // Draw path
        if (!dronePath.empty())
        {
            p.setPen(QPen(Qt::red, 2));
            for (size_t i = 0; i < dronePath.size() - 1; i++)
                p.drawLine(dronePath[i].x, dronePath[i].y,
                            dronePath[i+1].x, dronePath[i+1].y);

            p.setBrush(Qt::blue);
            for (auto &pt : dronePath)
                p.drawEllipse(QPointF(pt.x, pt.y), 3, 3);
        }
    }
}