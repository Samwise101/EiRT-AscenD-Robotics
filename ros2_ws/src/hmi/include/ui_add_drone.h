/********************************************************************************
** Form generated from reading UI file 'ui_add_drone.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_DRONE_H
#define UI_ADD_DRONE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDroneDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *boxIdLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *droneIdLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancleButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;

    void setupUi(QDialog *AddDroneDialog)
    {
        if (AddDroneDialog->objectName().isEmpty())
            AddDroneDialog->setObjectName(QString::fromUtf8("AddDroneDialog"));
        AddDroneDialog->resize(406, 192);
        verticalLayoutWidget = new QWidget(AddDroneDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 391, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        boxIdLabel = new QLabel(verticalLayoutWidget);
        boxIdLabel->setObjectName(QString::fromUtf8("boxIdLabel"));

        horizontalLayout_3->addWidget(boxIdLabel);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        droneIdLineEdit = new QLineEdit(verticalLayoutWidget);
        droneIdLineEdit->setObjectName(QString::fromUtf8("droneIdLineEdit"));

        horizontalLayout_2->addWidget(droneIdLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_2);

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

        addButton = new QPushButton(verticalLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/tick_mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon1);

        horizontalLayout->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);

        retranslateUi(AddDroneDialog);
        QObject::connect(cancleButton, SIGNAL(clicked()), AddDroneDialog, SLOT(on_cancleButton_pushButton_clicked()));
        QObject::connect(addButton, SIGNAL(clicked()), AddDroneDialog, SLOT(on_addButton_pushButton_clicked()));
        QObject::connect(droneIdLineEdit, SIGNAL(editingFinished()), AddDroneDialog, SLOT(on_droneIdLineEdit_editingFinished()));

        QMetaObject::connectSlotsByName(AddDroneDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDroneDialog)
    {
        AddDroneDialog->setWindowTitle(QCoreApplication::translate("AddDroneDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddDroneDialog", "Choose a drone ID for the new drone", nullptr));
        label_3->setText(QCoreApplication::translate("AddDroneDialog", "Box ID:", nullptr));
        boxIdLabel->setText(QString());
        label_2->setText(QCoreApplication::translate("AddDroneDialog", "New Drone ID: ", nullptr));
        cancleButton->setText(QCoreApplication::translate("AddDroneDialog", "Cancle", nullptr));
        addButton->setText(QCoreApplication::translate("AddDroneDialog", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDroneDialog: public Ui_AddDroneDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_DRONE_H
