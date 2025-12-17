/********************************************************************************
** Form generated from reading UI file 'flight_preset_or_create_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHT_PRESET_CREATE_DIALOG_H
#define UI_FLIGHT_PRESET_CREATE_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlightCreationDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancleButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *choosePreset;
    QPushButton *createPathPlanButton;

    void setupUi(QDialog *FlightCreationDialog)
    {
        if (FlightCreationDialog->objectName().isEmpty())
            FlightCreationDialog->setObjectName(QString::fromUtf8("FlightCreationDialog"));
        FlightCreationDialog->resize(630, 425);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FlightCreationDialog->sizePolicy().hasHeightForWidth());
        FlightCreationDialog->setSizePolicy(sizePolicy);
        FlightCreationDialog->setMinimumSize(QSize(630, 425));
        verticalLayoutWidget = new QWidget(FlightCreationDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 10, 601, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_2->addWidget(listWidget);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancleButton = new QPushButton(verticalLayoutWidget);
        cancleButton->setObjectName(QString::fromUtf8("cancleButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/cancle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancleButton->setIcon(icon);

        horizontalLayout->addWidget(cancleButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        choosePreset = new QPushButton(verticalLayoutWidget);
        choosePreset->setObjectName(QString::fromUtf8("choosePreset"));

        horizontalLayout->addWidget(choosePreset);

        createPathPlanButton = new QPushButton(verticalLayoutWidget);
        createPathPlanButton->setObjectName(QString::fromUtf8("createPathPlanButton"));

        horizontalLayout->addWidget(createPathPlanButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FlightCreationDialog);
        QObject::connect(cancleButton, SIGNAL(clicked()), FlightCreationDialog, SLOT(on_cancleButton_pushButton_clicked()));
        QObject::connect(createPathPlanButton, SIGNAL(clicked()), FlightCreationDialog, SLOT(on_createPlanButton_pushButton_clicked()));
        QObject::connect(choosePreset, SIGNAL(clicked()), FlightCreationDialog, SLOT(on_choosePreset_pushButton_clicked()));

        QMetaObject::connectSlotsByName(FlightCreationDialog);
    } // setupUi

    void retranslateUi(QDialog *FlightCreationDialog)
    {
        FlightCreationDialog->setWindowTitle(QCoreApplication::translate("FlightCreationDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FlightCreationDialog", "Choose an existing mission preset or create a new one", nullptr));
        cancleButton->setText(QCoreApplication::translate("FlightCreationDialog", "Cancle", nullptr));
        choosePreset->setText(QCoreApplication::translate("FlightCreationDialog", "Choose Preset", nullptr));
        createPathPlanButton->setText(QCoreApplication::translate("FlightCreationDialog", "Create Path Plan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlightCreationDialog: public Ui_FlightCreationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHT_PRESET_CREATE_DIALOG_H
