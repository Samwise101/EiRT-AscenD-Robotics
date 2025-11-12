#pragma once
#ifndef FLIGHT_DIALOG_H
#define FLIGHT_DIALOG_H

#include "ui_flight_dialog.h"
#include <QObject>
#include <QWidget>
#include <QPalette>
#include <QColor>
#include <QFileDialog>
#include <QFile>
#include <QXmlStreamReader>
#include <QDateTime>

#include <memory>
#include <string>

#include "drone.h"
#include "helper.h"

#include <QtDataVisualization/Q3DScatter>
#include <QtDataVisualization/QScatter3DSeries>
#include <QtDataVisualization/QScatterDataProxy>
#include <QtDataVisualization/QCustom3DItem>
#include <QtDataVisualization/Q3DCamera>
#include <QtDataVisualization/QValue3DAxis>

class FlightDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit FlightDialog(QWidget* parent = nullptr, QColor drone_color = Qt::white, std::string drone_id = "");
        ~FlightDialog();


    private slots:
        void on_cancleButton_pushButton_clicked();
        void on_applyButton_pushButton_clicked();
        void on_addNewWaypointButton_pushButton_clicked();
        void on_clearWaypointsButton_pushButton_clicked();
        void on_latLineEdit_editingFinished();
        void on_lonLineEdit_editingFinished();
        void on_altLineEdit_editingFinished();
        void on_saveAsPresetButton_pushButton_clicked();
    
    private:
        std::string drone_id;
        QColor drone_color;
        Ui::FlightDialog ui;

        QtDataVisualization::Q3DScatter *scatter3D = nullptr;
        QtDataVisualization::QScatter3DSeries *trajectorySeries = nullptr;
        QWidget *scatterContainer = nullptr;
        
        std::vector<QVector3D> waypoints;

        void update3DTrajectories();
        void saveTrajectoryXml(const QString& filename);
};


#endif
