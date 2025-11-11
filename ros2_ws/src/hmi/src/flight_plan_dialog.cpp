#include <iostream>
#include "flight_plan_dialog.h"

FlightDialog::FlightDialog(QWidget* parent, Drone* drone)
{
    ui.setupUi(this);

    // if(drone != nullptr);
    // {
    //     this->drone = drone;

    //     QPalette palette = this->ui.label_5->palette();
    //     palette.setColor(QPalette::Window, this->drone->get_drone_color());
    //     this->ui.label_5->setPalette(palette);
    // }

    // this->ui.latLineEdit->setText("0.0");
    // this->ui.lonLineEdit->setText("0.0");
    // this->ui.altLineEdit->setText("0.0");
}

FlightDialog::~FlightDialog()
{
    if(this->drone != nullptr)
    {    
        delete this->drone;
        this->drone = nullptr;
    }
}

void FlightDialog::on_openMapButton_pushButton_clicked()
{
    std::cout << "Hello from open map button" << std::endl;
}

void FlightDialog::on_cancleButton_pushButton_clicked()
{
    std::cout << "Hello from cancle button" << std::endl;
    this->reject();
}

void FlightDialog::on_applyButton_pushButton_clicked()
{
    std::cout << "Hello from apply button" << std::endl;
    this->accept();
}

void FlightDialog::on_removeWaypointButton_pushButton_clicked()
{
    std::cout << "Hello from remove waypoint button" << std::endl;
}

void FlightDialog::on_addNewWaypointButton_pushButton_clicked()
{
    std::cout << "Hello from add new waypoint button" << std::endl;
}

void FlightDialog::on_clearWaypointsButton_pushButton_clicked()
{
    std::cout << "Hello from clear waypoints button" << std::endl;
}

void FlightDialog::on_latLineEdit_editingFinished()
{
    std::cout << this->ui.latLineEdit->text().toStdString() << std::endl;
}

void FlightDialog::on_lonLineEdit_editingFinished()
{
    std::cout << this->ui.lonLineEdit->text().toStdString() << std::endl;
}

void FlightDialog::on_altLineEdit_editingFinished()
{
    std::cout << this->ui.altLineEdit->text().toStdString() << std::endl;
}

void FlightDialog::on_saveAsPresetButton_pushButton_clicked()
{
    std::cout << "Hello from save as preset button" << std::endl;
}