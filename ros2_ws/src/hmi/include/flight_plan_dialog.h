#pragma once
#ifndef FLIGHT_PLAN_DIALOG_H
#define FLIGHT_PLAN_DIALOG_H

#include "ui_flight_dialog.h"
#include <QObject>
#include <QWidget>
#include <QFrame>

#include <memory>
#include <string>

class FlightPlanDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit FlightPlanDialog(QWidget* parent = nullptr);
        ~FlightPlanDialog();

    private:

};


#endif FLIGHT_PLAN_DIALOG_H
