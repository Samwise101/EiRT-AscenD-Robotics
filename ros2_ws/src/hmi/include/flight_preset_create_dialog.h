#pragma once
#ifndef FLIGHT_CREATION_DIALOG_H
#define FLIGHT_CREATION_DIALOG_H

#include "ui_flight_preset_create_dialog.h"
#include <QObject>
#include <QWidget>

class FlightCreationDialog : public QDialog
{
    Q_OBJECT
    
    public:
        explicit FlightCreationDialog(QWidget* parent = nullptr);
        ~FlightCreationDialog();
    
    private slots:
        void on_cancleButton_pushButton_clicked();
        void on_okButton_pushButton_clicked();
        void on_createPlanButton_pushButton_clicked();
        void on_choosePreset_pushButton_clicked();

    private:
        Ui::FlightCreationDialog ui;
};

#endif FLIGHT_CREATION_DIALOG_H