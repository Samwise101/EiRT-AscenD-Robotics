#pragma once
#ifndef FLIGHT_CREATION_DIALOG_H
#define FLIGHT_CREATION_DIALOG_H

#include "ui_flight_preset_create_dialog.h"
#include "ColorListWidget.h"
#include <QObject>
#include <QWidget>
#include <QFileDialog>
#include "helper.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDomDocument>
#include <vector>
#include <string>
#include <QFile>
#include <QXmlStreamReader>

class FlightCreationDialog : public QDialog
{
    Q_OBJECT
    
    public:
        explicit FlightCreationDialog(QWidget* parent = nullptr);
        ~FlightCreationDialog();
        QString getFileName();
        void loadTrajectoryFromXmlFile(QString& file_name);
        void addItemToList(DroneVis& drone);

        int getSelectedItemIndex();
        int getState();
    
    private slots:
        void on_cancleButton_pushButton_clicked();
        void on_createPlanButton_pushButton_clicked();
        void on_choosePreset_pushButton_clicked();

        void onListItemDoubleClicked(QListWidgetItem* item);

    private:
        Ui::FlightCreationDialog ui;
        QString file_name;
        std::vector<DroneVis> drones;
        int curr_list_widget_index;
        int state;
};

#endif FLIGHT_CREATION_DIALOG_H