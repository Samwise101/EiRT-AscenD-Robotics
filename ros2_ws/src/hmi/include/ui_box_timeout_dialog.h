/********************************************************************************
** Form generated from reading UI file 'box_search_timeout_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOX_TIMEOUT_DIALOG_H
#define UI_BOX_TIMEOUT_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoxTimeoutDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancle;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok;

    void setupUi(QDialog *BoxTimeoutDialog)
    {
        if (BoxTimeoutDialog->objectName().isEmpty())
            BoxTimeoutDialog->setObjectName(QString::fromUtf8("BoxTimeoutDialog"));
        BoxTimeoutDialog->resize(367, 172);
        verticalLayoutWidget = new QWidget(BoxTimeoutDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 9, 351, 151));
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancle = new QPushButton(verticalLayoutWidget);
        cancle->setObjectName(QString::fromUtf8("cancle"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/cancle.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancle->setIcon(icon);

        horizontalLayout->addWidget(cancle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ok = new QPushButton(verticalLayoutWidget);
        ok->setObjectName(QString::fromUtf8("ok"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/tick_mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        ok->setIcon(icon1);

        horizontalLayout->addWidget(ok);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);

        retranslateUi(BoxTimeoutDialog);
        QObject::connect(ok, SIGNAL(clicked()), BoxTimeoutDialog, SLOT(on_ok_pushButton_clicked()));
        QObject::connect(cancle, SIGNAL(clicked()), BoxTimeoutDialog, SLOT(on_cancle_pushButton_clicked()));

        QMetaObject::connectSlotsByName(BoxTimeoutDialog);
    } // setupUi

    void retranslateUi(QDialog *BoxTimeoutDialog)
    {
        BoxTimeoutDialog->setWindowTitle(QCoreApplication::translate("BoxTimeoutDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("BoxTimeoutDialog", "New box search timed out, click \"Ok\" to retry.", nullptr));
        cancle->setText(QCoreApplication::translate("BoxTimeoutDialog", "Cancle", nullptr));
        ok->setText(QCoreApplication::translate("BoxTimeoutDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoxTimeoutDialog: public Ui_BoxTimeoutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOX_TIMEOUT_DIALOG_H
