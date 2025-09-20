/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionOpen_Recent;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionPreferences;
    QAction *actionExit_2;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *settings_button;
    QPushButton *pushButton1;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *box_main_layout;
    QHBoxLayout *box_cicle_layout;
    QLabel *current_box_label;
    QSpinBox *box_cicle_spin_box;
    QSpacerItem *horizontalSpacer;
    QGridLayout *box_grid_layout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *Box_show_layout;
    QFrame *frame;
    QVBoxLayout *box_information_layout;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_4;
    QWidget *tab_4;
    QWidget *tab_3;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuHelp_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(834, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionOpen_Recent = new QAction(MainWindow);
        actionOpen_Recent->setObjectName(QString::fromUtf8("actionOpen_Recent"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/settings2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreferences->setIcon(icon1);
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName(QString::fromUtf8("actionExit_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/box.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit_2->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 811, 541));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        settings_button = new QPushButton(horizontalLayoutWidget);
        settings_button->setObjectName(QString::fromUtf8("settings_button"));
        QFont font;
        font.setPointSize(14);
        settings_button->setFont(font);

        verticalLayout->addWidget(settings_button);

        pushButton1 = new QPushButton(horizontalLayoutWidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setFont(font);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons/settings2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton1->setIcon(icon3);

        verticalLayout->addWidget(pushButton1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tabWidget = new QTabWidget(horizontalLayoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        tabWidget->setFont(font2);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/icons/map.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget_3 = new QWidget(tab_2);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(20, 20, 681, 441));
        box_main_layout = new QVBoxLayout(verticalLayoutWidget_3);
        box_main_layout->setObjectName(QString::fromUtf8("box_main_layout"));
        box_main_layout->setContentsMargins(0, 0, 0, 0);
        box_cicle_layout = new QHBoxLayout();
        box_cicle_layout->setObjectName(QString::fromUtf8("box_cicle_layout"));
        current_box_label = new QLabel(verticalLayoutWidget_3);
        current_box_label->setObjectName(QString::fromUtf8("current_box_label"));
        current_box_label->setFont(font2);
        current_box_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        box_cicle_layout->addWidget(current_box_label);

        box_cicle_spin_box = new QSpinBox(verticalLayoutWidget_3);
        box_cicle_spin_box->setObjectName(QString::fromUtf8("box_cicle_spin_box"));

        box_cicle_layout->addWidget(box_cicle_spin_box);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        box_cicle_layout->addItem(horizontalSpacer);

        box_cicle_layout->setStretch(1, 2);
        box_cicle_layout->setStretch(2, 5);

        box_main_layout->addLayout(box_cicle_layout);

        box_grid_layout = new QGridLayout();
        box_grid_layout->setObjectName(QString::fromUtf8("box_grid_layout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Box_show_layout = new QVBoxLayout();
        Box_show_layout->setObjectName(QString::fromUtf8("Box_show_layout"));
        frame = new QFrame(verticalLayoutWidget_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        Box_show_layout->addWidget(frame);


        horizontalLayout_2->addLayout(Box_show_layout);

        box_information_layout = new QVBoxLayout();
        box_information_layout->setObjectName(QString::fromUtf8("box_information_layout"));
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        box_information_layout->addWidget(label_3);

        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        box_information_layout->addWidget(label_5);

        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        box_information_layout->addWidget(label_2);

        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        box_information_layout->addWidget(label_4);


        horizontalLayout_2->addLayout(box_information_layout);

        horizontalLayout_2->setStretch(0, 70);

        box_grid_layout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        box_grid_layout->setRowMinimumHeight(0, 10);

        box_main_layout->addLayout(box_grid_layout);

        box_main_layout->setStretch(1, 10);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons/box.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icons/drone.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_4, icon6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/icons/chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon7, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(1, 10);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 834, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuHelp_2 = new QMenu(menubar);
        menuHelp_2->setObjectName(QString::fromUtf8("menuHelp_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuHelp_2->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_Recent);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_2);
        menuEdit->addAction(actionPreferences);

        retranslateUi(MainWindow);
        QObject::connect(pushButton1, SIGNAL(clicked(bool)), MainWindow, SLOT(push_button1_on_clicked(bool)));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionOpen_Recent->setText(QCoreApplication::translate("MainWindow", "Open Recent", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        actionPreferences->setText(QCoreApplication::translate("MainWindow", "Preferences", nullptr));
        actionExit_2->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        settings_button->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Drone Hive HMI", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Map", nullptr));
        current_box_label->setText(QCoreApplication::translate("MainWindow", "Current Box:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Box Type", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Box Number", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Drone Number", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Box", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Drone", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuHelp_2->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
