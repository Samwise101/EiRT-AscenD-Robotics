/********************************************************************************
** Form generated from reading UI file 'flight_plan_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHT_DIALOG_H
#define UI_FLIGHT_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlightDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *latLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lonLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *altLineEdit;
    QPushButton *addNewWaypointButton;
    QPushButton *removeWaypointButton;
    QPushButton *clearWaypointsButton;
    QPushButton *saveAsPresetButton;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancleButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;

    void setupUi(QDialog *FlightDialog)
    {
        if (FlightDialog->objectName().isEmpty())
            FlightDialog->setObjectName(QString::fromUtf8("FlightDialog"));
        FlightDialog->resize(704, 565);
        verticalLayoutWidget = new QWidget(FlightDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 701, 538));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(30);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_7);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        latLineEdit = new QLineEdit(verticalLayoutWidget);
        latLineEdit->setObjectName(QString::fromUtf8("latLineEdit"));

        horizontalLayout_5->addWidget(latLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lonLineEdit = new QLineEdit(verticalLayoutWidget);
        lonLineEdit->setObjectName(QString::fromUtf8("lonLineEdit"));

        horizontalLayout_3->addWidget(lonLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        altLineEdit = new QLineEdit(verticalLayoutWidget);
        altLineEdit->setObjectName(QString::fromUtf8("altLineEdit"));

        horizontalLayout_4->addWidget(altLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout_3);

        addNewWaypointButton = new QPushButton(verticalLayoutWidget);
        addNewWaypointButton->setObjectName(QString::fromUtf8("addNewWaypointButton"));

        verticalLayout_2->addWidget(addNewWaypointButton);

        removeWaypointButton = new QPushButton(verticalLayoutWidget);
        removeWaypointButton->setObjectName(QString::fromUtf8("removeWaypointButton"));

        verticalLayout_2->addWidget(removeWaypointButton);

        clearWaypointsButton = new QPushButton(verticalLayoutWidget);
        clearWaypointsButton->setObjectName(QString::fromUtf8("clearWaypointsButton"));

        verticalLayout_2->addWidget(clearWaypointsButton);

        saveAsPresetButton = new QPushButton(verticalLayoutWidget);
        saveAsPresetButton->setObjectName(QString::fromUtf8("saveAsPresetButton"));

        verticalLayout_2->addWidget(saveAsPresetButton);

        verticalLayout_2->setStretch(3, 10);
        verticalLayout_2->setStretch(4, 10);
        verticalLayout_2->setStretch(5, 10);

        horizontalLayout->addLayout(verticalLayout_2);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));

        horizontalLayout->addLayout(verticalLayout_4);

        horizontalLayout->setStretch(2, 10);

        verticalLayout->addLayout(horizontalLayout);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cancleButton = new QPushButton(verticalLayoutWidget);
        cancleButton->setObjectName(QString::fromUtf8("cancleButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/cancle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancleButton->setIcon(icon);

        horizontalLayout_2->addWidget(cancleButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        applyButton = new QPushButton(verticalLayoutWidget);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/tick_mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        applyButton->setIcon(icon1);

        horizontalLayout_2->addWidget(applyButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 10);

        retranslateUi(FlightDialog);
        QObject::connect(latLineEdit, SIGNAL(editingFinished()), FlightDialog, SLOT(on_latLineEdit_editingFinished()));
        QObject::connect(lonLineEdit, SIGNAL(editingFinished()), FlightDialog, SLOT(on_lonLineEdit_editingFinished()));
        QObject::connect(altLineEdit, SIGNAL(editingFinished()), FlightDialog, SLOT(on_altLineEdit_editingFinished()));
        QObject::connect(addNewWaypointButton, SIGNAL(clicked()), FlightDialog, SLOT(on_addNewWaypointButton_pushButton_clicked()));
        QObject::connect(removeWaypointButton, SIGNAL(clicked()), FlightDialog, SLOT(on_removeWaypointButton_pushButton_clicked()));
        QObject::connect(cancleButton, SIGNAL(clicked()), FlightDialog, SLOT(on_cancleButton_pushButton_clicked()));
        QObject::connect(applyButton, SIGNAL(clicked()), FlightDialog, SLOT(on_applyButton_pushButton_clicked()));
        QObject::connect(saveAsPresetButton, SIGNAL(clicked()), FlightDialog, SLOT(on_saveAsPresetButton_pushButton_clicked()));
        QObject::connect(clearWaypointsButton, SIGNAL(clicked()), FlightDialog, SLOT(on_clearWaypointsButton_pushBUtton_clicked()));

        QMetaObject::connectSlotsByName(FlightDialog);
    } // setupUi

    void retranslateUi(QDialog *FlightDialog)
    {
        FlightDialog->setWindowTitle(QCoreApplication::translate("FlightDialog", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("FlightDialog", "Selected\n"
"Drone ID: ", nullptr));
        label_5->setText(QString());
        label_7->setText(QCoreApplication::translate("FlightDialog", "Selected\n"
"Drone Color", nullptr));
        label_6->setText(QString());
        label_3->setText(QCoreApplication::translate("FlightDialog", "Lat: ", nullptr));
        label->setText(QCoreApplication::translate("FlightDialog", "Lon: ", nullptr));
        label_2->setText(QCoreApplication::translate("FlightDialog", "Alt: ", nullptr));
        addNewWaypointButton->setText(QCoreApplication::translate("FlightDialog", "Add New Waypoint", nullptr));
        removeWaypointButton->setText(QCoreApplication::translate("FlightDialog", "Remove Last Waypoint", nullptr));
        clearWaypointsButton->setText(QCoreApplication::translate("FlightDialog", "Clear All Waypoints", nullptr));
        saveAsPresetButton->setText(QCoreApplication::translate("FlightDialog", "Save As Preset", nullptr));
        cancleButton->setText(QCoreApplication::translate("FlightDialog", "Cancle", nullptr));
        applyButton->setText(QCoreApplication::translate("FlightDialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlightDialog: public Ui_FlightDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHT_DIALOG_H
