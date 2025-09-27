#include <iostream>
#include "new_box_dialog.h"

NewBoxDialog::NewBoxDialog(QWidget *parent)
    : QDialog(parent), box_lat(-0.0f), box_lon(0.0f), box_alt(0.0f)
{
    ui.setupUi(this); 
    this->box_type = this->ui.comboBox->currentIndex();
}

NewBoxDialog::~NewBoxDialog(){}

void NewBoxDialog::on_cancle_pushButton_clicked(void)
{
    std::cout << "Reject\n";
    this->reject();
}

void NewBoxDialog::on_add_pushButton_clicked(void)
{
    if(this->ui.boxIdLineEdit->text().isEmpty())
    {
        std::cout << "Forgot to assign ID!n";
    }

    else if(this->ui.boxLatLineEdit->text().isEmpty())
    {
        std::cout << "Forgot to assign Latitude!\n";
    }

    else if(this->ui.boxLonLineEdit->text().isEmpty())
    {
        std::cout << "Forgot to assign Longitude!\n";
    }

    else if(this->ui.boxAltLineEdit->text().isEmpty())
    {
        std::cout << "Forgot to assign Altitude!\n";
    }

    else{
        std::cout << "Accept\n";
        this->accept();
    }
}

void NewBoxDialog::on_comboBox_currentIndexChanged(int index)
{
    this->box_type = index;
}

void NewBoxDialog::on_boxIdLineEdit_editingFinished(void)
{
    this->box_id = this->ui.boxIdLineEdit->text().toInt();
}

void NewBoxDialog::on_boxLatLineEdit_editingFinished(void)
{
    this->box_lat = this->ui.boxLatLineEdit->text().toFloat();
}

void NewBoxDialog::on_boxLonLineEdit_editingFinished(void)
{
    this->box_lon = this->ui.boxLonLineEdit->text().toFloat();
}

void NewBoxDialog::on_boxAltLineEdit_editingFinished(void)
{
    this->box_alt = this->ui.boxAltLineEdit->text().toFloat();
}

int NewBoxDialog::get_box_id(void)
{
    return this->box_id;
}

int NewBoxDialog::get_box_type()
{
    return this->box_type;
}

float NewBoxDialog::get_box_lat(void)
{
    return this->box_lat;
}

float NewBoxDialog::get_box_lon(void)
{
    return this->box_lon;
}

float NewBoxDialog::get_box_alt(void)
{
    return this->box_alt;
}