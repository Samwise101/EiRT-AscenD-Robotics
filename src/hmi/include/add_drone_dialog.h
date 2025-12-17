#pragma once

#ifndef ADD_DRONE_DIALOG_H
#define ADD_DRONE_DIALOG_H

#include "ui_add_drone.h"
#include <QObject>
#include <QWidget>
#include <string>

class AddDroneDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit AddDroneDialog(QWidget* parent = nullptr, QString box_id = "");
        ~AddDroneDialog();

    public:
        std::string getDroneId();
        void setBoxId(QString box_id);

    private slots:
        void on_addButton_pushButton_clicked();
        void on_cancleButton_pushButton_clicked();
        void on_droneIdLineEdit_editingFinished();

    private:
        Ui::AddDroneDialog ui;
        QString box_id;
        std::string drone_id;
};

#endif