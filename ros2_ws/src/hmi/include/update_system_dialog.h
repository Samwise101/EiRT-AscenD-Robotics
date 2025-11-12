/********************************************************************************
** Form generated from reading UI file 'update_system_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UPDATE_SYSTEM_DIALOG_H
#define UPDATE_SYSTEM_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpdateSystemDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *UpdateSystemDialog)
    {
        if (UpdateSystemDialog->objectName().isEmpty())
            UpdateSystemDialog->setObjectName(QString::fromUtf8("UpdateSystemDialog"));
        UpdateSystemDialog->resize(407, 203);
        verticalLayoutWidget = new QWidget(UpdateSystemDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 40, 351, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UpdateSystemDialog);

        QMetaObject::connectSlotsByName(UpdateSystemDialog);
    } // setupUi

    void retranslateUi(QDialog *UpdateSystemDialog)
    {
        UpdateSystemDialog->setWindowTitle(QCoreApplication::translate("UpdateSystemDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("UpdateSystemDialog", "Updating system, please wait...", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UpdateSystemDialog", "Cancle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpdateSystemDialog: public Ui_UpdateSystemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UPDATE_SYSTEM_DIALOG_H
