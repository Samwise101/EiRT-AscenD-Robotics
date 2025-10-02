#pragma once

#ifndef NEW_BOX_DIALOG_H
#define NEW_BOX_DIALOG_H

#include <QDialog>
#include <QString>
#include <string>

#include "ui_new_box.h"
#include "box.h"

class NewBoxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewBoxDialog(QWidget *parent = nullptr, float lat=0.0,float lon=0.0,float alt=0.0, std::string box_id = "");
    ~NewBoxDialog();

    int get_box_type(void);
    QString get_box_id(void);
    float get_box_lat(void);
    float get_box_lon(void);
    float get_box_alt(void);

public slots:
    void on_cancle_pushButton_clicked(void);
    void on_add_pushButton_clicked(void);
    void on_comboBox_currentIndexChanged(int);
    void on_boxIdLineEdit_editingFinished(void);
    void on_boxLatLineEdit_editingFinished(void);
    void on_boxLonLineEdit_editingFinished(void);
    void on_boxAltLineEdit_editingFinished(void);

private:
    Ui::Dialog ui;
    int box_type;
    std::string box_id;
    float box_lat;
    float box_lon;
    float box_alt;
    Coordinates coord;
};

#endif