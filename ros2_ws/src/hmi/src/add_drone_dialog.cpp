#include <iostream>
#include "add_drone_dialog.h"

AddDroneDialog::AddDroneDialog(QWidget* parent, QString box_id) : box_id(box_id)
{
    ui.setupUi(this);

    this->ui.boxIdLabel->setText(this->box_id);
}

AddDroneDialog::~AddDroneDialog(){}


void AddDroneDialog::on_addButton_pushButton_clicked()
{
    std::cout << "Hello from add button" << std::endl;
    this->accept();
}

void AddDroneDialog::on_cancleButton_pushButton_clicked()
{
    std::cout << "Hello from add button" << std::endl;
    this->reject();
}

void AddDroneDialog::on_droneIdLineEdit_editingFinished()
{
    this->drone_id = this->ui.droneIdLineEdit->text().toStdString();
}

std::string AddDroneDialog::getDroneId()
{
    return this->drone_id;
}