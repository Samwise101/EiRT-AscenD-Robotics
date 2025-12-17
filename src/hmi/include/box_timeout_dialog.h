#pragma once

#ifndef BOX_TIMEOUT_DIALOG_H
#define BOX_TIMEOUT_DIALOG_H

#include "ui_box_timeout_dialog.h"
#include <QDialog>
#include <QString>

class BoxTimeoutDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit BoxTimeoutDialog(QWidget *parent = nullptr);
        ~BoxTimeoutDialog();

    public slots:
        void on_ok_pushButton_clicked();
        void on_cancle_pushButton_clicked();

    private:
        Ui::BoxTimeoutDialog ui;
};

#endif