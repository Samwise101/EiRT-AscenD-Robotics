#include <iostream>
#include "new_box_dialog.h"

NewBoxDialog::NewBoxDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this); 
    this->box_type = this->ui.comboBox->currentIndex();
}

NewBoxDialog::~NewBoxDialog(){}


int NewBoxDialog::get_box_type()
{
    return this->box_type;
}

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