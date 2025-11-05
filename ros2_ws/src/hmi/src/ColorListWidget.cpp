#include "ColorListWidget.h"
#include <iostream>


ColorListWidget::ColorListWidget(QWidget *parent, const QString& text, const QColor& color)
{
    auto* layout = new QHBoxLayout(this);

    this->checked = false;

    this->textLabel = new QLabel();
    this->textLabel->setText(text);

    this->colorLabel = new QLabel();
    this->colorLabel->setAutoFillBackground(true);
    this->colorLabel->setFixedSize(20,20);

    this->colorLabel->setStyleSheet(
    QString("background-color: %1; border-radius: 10px; border: 1px solid black;")
        .arg(color.name())
    );

    layout->addWidget(this->colorLabel);
    layout->addWidget(this->textLabel);
    layout->addStretch();
}

ColorListWidget::~ColorListWidget()
{
    delete this->textLabel;
    delete this->colorLabel;
}

bool ColorListWidget::isChecked()
{
    return this->checked;
}

void ColorListWidget::setChecked(bool state)
{
    this->checked = state;
}