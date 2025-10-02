#include <iostream>
#include "new_box_dialog.h"

NewBoxDialog::NewBoxDialog(QWidget *parent, float lat, float lon, float alt, std::string box_id)
    : QDialog(parent), box_alt(alt), box_lat(lat), box_lon(lon), box_id(box_id)
{
    ui.setupUi(this); 
    this->ui.boxAltLineEdit->setText(QString::number(alt));
    this->ui.boxLonLineEdit->setText(QString::number(lon));
    this->ui.boxLatLineEdit->setText(QString::number(lat));
    this->ui.boxIdLineEdit->setText(QString::fromStdString(box_id));
}

NewBoxDialog::~NewBoxDialog(){}

void NewBoxDialog::on_cancle_pushButton_clicked(void)
{
    std::cout << "Reject\n";
    this->reject();
}

void NewBoxDialog::on_add_pushButton_clicked(void)
{
    std::cout << "Accept\n";
    this->accept();
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

QString NewBoxDialog::get_box_id(void)
{
    return QString::fromStdString(this->box_id);
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