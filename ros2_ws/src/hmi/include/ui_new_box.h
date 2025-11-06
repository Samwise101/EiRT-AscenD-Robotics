/********************************************************************************
** Form generated from reading UI file 'new_box_pupup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_BOX_H
#define UI_NEW_BOX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewBoxDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *box_id_label;
    QLineEdit *boxIdLineEdit;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *boxLatLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *boxLonLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *boxAltLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *NewBoxDialog)
    {
        if (NewBoxDialog->objectName().isEmpty())
            NewBoxDialog->setObjectName(QString::fromUtf8("NewBoxDialog"));
        NewBoxDialog->resize(418, 363);
        verticalLayoutWidget = new QWidget(NewBoxDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 401, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        box_id_label = new QLabel(verticalLayoutWidget);
        box_id_label->setObjectName(QString::fromUtf8("box_id_label"));

        horizontalLayout_2->addWidget(box_id_label);

        boxIdLineEdit = new QLineEdit(verticalLayoutWidget);
        boxIdLineEdit->setObjectName(QString::fromUtf8("boxIdLineEdit"));
        boxIdLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(boxIdLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        boxLatLineEdit = new QLineEdit(verticalLayoutWidget);
        boxLatLineEdit->setObjectName(QString::fromUtf8("boxLatLineEdit"));
        boxLatLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(boxLatLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        boxLonLineEdit = new QLineEdit(verticalLayoutWidget);
        boxLonLineEdit->setObjectName(QString::fromUtf8("boxLonLineEdit"));
        boxLonLineEdit->setReadOnly(true);

        horizontalLayout_7->addWidget(boxLonLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        boxAltLineEdit = new QLineEdit(verticalLayoutWidget);
        boxAltLineEdit->setObjectName(QString::fromUtf8("boxAltLineEdit"));
        boxAltLineEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(boxAltLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/cancle.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/tick_mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(NewBoxDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), NewBoxDialog, SLOT(on_cancle_pushButton_clicked()));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), NewBoxDialog, SLOT(on_comboBox_currentIndexChanged()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), NewBoxDialog, SLOT(on_add_pushButton_clicked()));
        QObject::connect(boxIdLineEdit, SIGNAL(editingFinished()), NewBoxDialog, SLOT(on_boxIdLineEdit_editingFinished()));
        QObject::connect(boxLatLineEdit, SIGNAL(editingFinished()), NewBoxDialog, SLOT(on_boxLatLineEdit_editingFinished()));
        QObject::connect(boxLonLineEdit, SIGNAL(editingFinished()), NewBoxDialog, SLOT(on_boxLonLineEdit_editingFinished()));
        QObject::connect(boxAltLineEdit, SIGNAL(editingFinished()), NewBoxDialog, SLOT(on_boxAltLineEdit_editingFinished()));

        QMetaObject::connectSlotsByName(NewBoxDialog);
    } // setupUi

    void retranslateUi(QDialog *NewBoxDialog)
    {
        NewBoxDialog->setWindowTitle(QCoreApplication::translate("NewBoxDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NewBoxDialog", "New Box Settings", nullptr));
        label_2->setText(QCoreApplication::translate("NewBoxDialog", "Box Type:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("NewBoxDialog", "Slave", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("NewBoxDialog", "Master", nullptr));

        box_id_label->setText(QCoreApplication::translate("NewBoxDialog", "Box ID: ", nullptr));
        label_4->setText(QCoreApplication::translate("NewBoxDialog", "Box Landing Position Lat:", nullptr));
        label_5->setText(QCoreApplication::translate("NewBoxDialog", "Box Landing Position Lon:", nullptr));
        label_6->setText(QCoreApplication::translate("NewBoxDialog", "Box Landing Position Alt:", nullptr));
        pushButton->setText(QCoreApplication::translate("NewBoxDialog", "Cancle", nullptr));
        pushButton_2->setText(QCoreApplication::translate("NewBoxDialog", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewBoxDialog: public Ui_NewBoxDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_BOX_H
