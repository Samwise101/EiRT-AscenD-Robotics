#pragma once

#ifndef COLOR_LIST_WIDGET_H
#define COLOR_LIST_WIDGET_H

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPalette>
#include <QString>
#include <QColor>


class ColorListWidget : public QWidget
{
    Q_OBJECT

    public:
        ColorListWidget(QWidget *parent = nullptr, const QString& text = "", const QColor& color = Qt::white);
        ~ColorListWidget();
    
        bool isChecked();
        void setChecked(bool state);

    private:
        bool checked;
        QLabel* textLabel;
        QLabel* colorLabel;
};


#endif
