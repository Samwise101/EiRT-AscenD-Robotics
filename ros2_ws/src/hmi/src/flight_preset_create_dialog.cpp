#include <iostream>
#include "flight_preset_create_dialog.h"

FlightCreationDialog::FlightCreationDialog(QWidget* parent)
{
    ui.setupUi(this);
}

FlightCreationDialog::~FlightCreationDialog()
{

}

void FlightCreationDialog::on_cancleButton_pushButton_clicked()
{
    std::cout << "Hello from cancle button" << std::endl;
    this->reject();
}

void FlightCreationDialog::on_okButton_pushButton_clicked()
{
    std::cout << "Hello from ok button" << std::endl;
    this->accept();
}

void FlightCreationDialog::on_createPlanButton_pushButton_clicked()
{
    std::cout << "Hello from create path plan button" << std::endl;
}

void FlightCreationDialog::on_choosePreset_pushButton_clicked()
{

}