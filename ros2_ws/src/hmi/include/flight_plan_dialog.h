#pragma once
#ifndef FLIGHT_DIALOG_H
#define FLIGHT_DIALOG_H

#include "ui_flight_dialog.h"
#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QPalette>
#include <QColor>
#include <QFileDialog>

#include <memory>
#include <string>

#include "drone.h"

class FlightDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit FlightDialog(QWidget* parent = nullptr, Drone* drone = nullptr);
        ~FlightDialog();


    private slots:
        void on_openMapButton_pushButton_clicked();
        void on_cancleButton_pushButton_clicked();
        void on_applyButton_pushButton_clicked();
        void on_removeWaypointButton_pushButton_clicked();
        void on_addNewWaypointButton_pushButton_clicked();
        void on_clearWaypointsButton_pushButton_clicked();
        void on_latLineEdit_editingFinished();
        void on_lonLineEdit_editingFinished();
        void on_altLineEdit_editingFinished();
        void on_saveAsPresetButton_pushButton_clicked();
    
    private:
        Drone* drone;
        Ui::FlightDialog ui;
};


#endif FLIGHT_DIALOG_H
