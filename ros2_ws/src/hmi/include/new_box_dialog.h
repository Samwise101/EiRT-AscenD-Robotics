#pragma once

#ifndef NEW_BOX_DIALOG_H
#define NEW_BOX_DIALOG_H

#include <QDialog>
#include <QString>
#include "ui_new_box.h"

class NewBoxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewBoxDialog(QWidget *parent = nullptr);
    ~NewBoxDialog();

    int get_box_type();

public slots:
    void on_cancle_pushButton_clicked(void);
    void on_add_pushButton_clicked(void);
    void on_comboBox_currentIndexChanged(int);

private:
    Ui::Dialog ui;
    int box_type;
};

#endif