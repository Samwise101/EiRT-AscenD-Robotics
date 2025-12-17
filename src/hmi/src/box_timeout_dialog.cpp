#include <iostream>
#include "box_timeout_dialog.h"

BoxTimeoutDialog::BoxTimeoutDialog(QWidget* parent)
{
    ui.setupUi(this); 
}

BoxTimeoutDialog::~BoxTimeoutDialog()
{
    this->reject();
}

void BoxTimeoutDialog::on_ok_pushButton_clicked()
{
    std::cout << "Accepted\n";
    this->accept();
}

void BoxTimeoutDialog::on_cancle_pushButton_clicked()
{
    std::cout << "Rejected\n";
    this->reject();
}