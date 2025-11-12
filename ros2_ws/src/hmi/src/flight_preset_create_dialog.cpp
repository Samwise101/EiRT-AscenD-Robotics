#include <iostream>
#include "flight_preset_create_dialog.h"

FlightCreationDialog::FlightCreationDialog(QWidget* parent)
{
    ui.setupUi(this);

    connect(this->ui.listWidget, &QListWidget::itemDoubleClicked,
    this, &FlightCreationDialog::onListItemDoubleClicked);

    this->curr_list_widget_index = -1;
    this->state = PathPlanStates::NONE;
}

FlightCreationDialog::~FlightCreationDialog()
{
    for (int i = 0; i < this->ui.listWidget->count(); ++i)
    {
        delete this->ui.listWidget->item(i);
    }
}

void FlightCreationDialog::on_cancleButton_pushButton_clicked()
{
    std::cout << "Hello from cancle button" << std::endl;
    this->reject();
}

void FlightCreationDialog::on_createPlanButton_pushButton_clicked()
{
    std::cout << "Hello from create path plan button" << std::endl;
    this->state = PathPlanStates::CREATE_PLAN;
    this->accept();
}

void FlightCreationDialog::on_choosePreset_pushButton_clicked()
{

    QString presetDirPath = QDir(QCoreApplication::applicationDirPath())
                            .filePath("../src/hmi/presets");

    this->file_name = QFileDialog::getOpenFileName(
        this,           
        "Open Preset File",
        presetDirPath,
        "Document files (*.xml)"
    );

    if(file_name.isEmpty()) return;

    this->loadTrajectoryFromXmlFile(file_name);
}

QString FlightCreationDialog::getFileName()
{
    return this->file_name;
}

void FlightCreationDialog::loadTrajectoryFromXmlFile(QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QXmlStreamReader xml(&file);

    drones.clear();

    DroneVis current;
    bool insideDrone = false;

    std::vector<DroneVis> drones;

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
    
    if(drones.empty()) return;

    for(auto drone: drones)
    {
        this->addItemToList(drone);
    }
}

void FlightCreationDialog::addItemToList(DroneVis& drone)
{           
    QListWidgetItem* item = new QListWidgetItem();

    ColorListWidget* widget = new ColorListWidget(this->ui.listWidget, QString::fromStdString(drone.drone_id), drone.drone_color);

    item->setSizeHint(widget->sizeHint());
    this->ui.listWidget->addItem(item);
    this->ui.listWidget->setItemWidget(item, widget);
}

void FlightCreationDialog::onListItemDoubleClicked(QListWidgetItem* item)
{
    curr_list_widget_index = this->ui.listWidget->row(item);
    std::cout << "Item at index = " << curr_list_widget_index << "was selected" << std::endl;

    ColorListWidget *cw = qobject_cast<ColorListWidget*>(this->ui.listWidget->itemWidget(item));
    if (cw)
    {
        cw->setEnabled(true);
        cw->setChecked(true);
    }

    this->state = PathPlanStates::ACCEPTED;
    this->accept();
}

int FlightCreationDialog::getSelectedItemIndex()
{
    return this->curr_list_widget_index;
}

int FlightCreationDialog::getState()
{
    return this->state;
}