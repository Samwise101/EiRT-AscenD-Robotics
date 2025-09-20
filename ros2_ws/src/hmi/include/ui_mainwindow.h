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
#include <QtWidgets/QComboBox>
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
    QAction *actionOpen_Map_View;
    QAction *actionOpen_Box_View;
    QAction *actionOpen_Drone_View;
    QAction *actionOpen_Statistics;
    QAction *actionUser;
    QAction *actionOpen_Presets;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *settings_button;
    QPushButton *pushButton1;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QFrame *line_6;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *map_tab;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_5;
    QFrame *frame_4;
    QWidget *box_tab;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *box_main_layout;
    QHBoxLayout *box_cicle_layout;
    QLabel *current_box_label;
    QSpinBox *box_cicle_spin_box;
    QLabel *color_label;
    QSpacerItem *horizontalSpacer;
    QFrame *line_3;
    QGridLayout *box_grid_layout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *Box_show_layout;
    QFrame *frame;
    QVBoxLayout *box_information_layout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLabel *label_8;
    QWidget *drone_tab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *current_drone_label;
    QComboBox *comboBox;
    QLabel *color_drone_label;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_9;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QFrame *line_10;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *line_9;
    QWidget *stat_tab;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QFrame *frame_3;
    QWidget *preset_tab;
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
        MainWindow->resize(875, 667);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        icon1.addFile(QString::fromUtf8(":/images/icons/settings1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreferences->setIcon(icon1);
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName(QString::fromUtf8("actionExit_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/box.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit_2->setIcon(icon2);
        actionOpen_Map_View = new QAction(MainWindow);
        actionOpen_Map_View->setObjectName(QString::fromUtf8("actionOpen_Map_View"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons/map.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Map_View->setIcon(icon3);
        actionOpen_Box_View = new QAction(MainWindow);
        actionOpen_Box_View->setObjectName(QString::fromUtf8("actionOpen_Box_View"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/icons/box.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Box_View->setIcon(icon4);
        actionOpen_Drone_View = new QAction(MainWindow);
        actionOpen_Drone_View->setObjectName(QString::fromUtf8("actionOpen_Drone_View"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons/drone.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Drone_View->setIcon(icon5);
        actionOpen_Statistics = new QAction(MainWindow);
        actionOpen_Statistics->setObjectName(QString::fromUtf8("actionOpen_Statistics"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icons/chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Statistics->setIcon(icon6);
        actionUser = new QAction(MainWindow);
        actionUser->setObjectName(QString::fromUtf8("actionUser"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/icons/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUser->setIcon(icon7);
        actionOpen_Presets = new QAction(MainWindow);
        actionOpen_Presets->setObjectName(QString::fromUtf8("actionOpen_Presets"));
        actionOpen_Presets->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(875, 625));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        settings_button = new QPushButton(centralwidget);
        settings_button->setObjectName(QString::fromUtf8("settings_button"));
        QFont font;
        font.setPointSize(14);
        settings_button->setFont(font);

        verticalLayout->addWidget(settings_button);

        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setFont(font);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/icons/settings2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton1->setIcon(icon8);

        verticalLayout->addWidget(pushButton1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 2, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        tabWidget->setFont(font2);
        map_tab = new QWidget();
        map_tab->setObjectName(QString::fromUtf8("map_tab"));
        gridLayoutWidget_3 = new QWidget(map_tab);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(270, 150, 160, 80));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(gridLayoutWidget_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);

        gridLayout_5->addWidget(frame_4, 0, 0, 1, 1);

        tabWidget->addTab(map_tab, icon3, QString());
        box_tab = new QWidget();
        box_tab->setObjectName(QString::fromUtf8("box_tab"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(box_tab->sizePolicy().hasHeightForWidth());
        box_tab->setSizePolicy(sizePolicy1);
        verticalLayoutWidget_3 = new QWidget(box_tab);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 721, 521));
        box_main_layout = new QVBoxLayout(verticalLayoutWidget_3);
        box_main_layout->setSpacing(0);
        box_main_layout->setObjectName(QString::fromUtf8("box_main_layout"));
        box_main_layout->setSizeConstraint(QLayout::SetNoConstraint);
        box_main_layout->setContentsMargins(0, 0, 0, 0);
        box_cicle_layout = new QHBoxLayout();
        box_cicle_layout->setObjectName(QString::fromUtf8("box_cicle_layout"));
        box_cicle_layout->setSizeConstraint(QLayout::SetNoConstraint);
        current_box_label = new QLabel(verticalLayoutWidget_3);
        current_box_label->setObjectName(QString::fromUtf8("current_box_label"));
        current_box_label->setFont(font2);
        current_box_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        box_cicle_layout->addWidget(current_box_label);

        box_cicle_spin_box = new QSpinBox(verticalLayoutWidget_3);
        box_cicle_spin_box->setObjectName(QString::fromUtf8("box_cicle_spin_box"));

        box_cicle_layout->addWidget(box_cicle_spin_box);

        color_label = new QLabel(verticalLayoutWidget_3);
        color_label->setObjectName(QString::fromUtf8("color_label"));
        sizePolicy.setHeightForWidth(color_label->sizePolicy().hasHeightForWidth());
        color_label->setSizePolicy(sizePolicy);
        color_label->setMinimumSize(QSize(30, 0));

        box_cicle_layout->addWidget(color_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        box_cicle_layout->addItem(horizontalSpacer);

        box_cicle_layout->setStretch(1, 2);
        box_cicle_layout->setStretch(3, 5);

        box_main_layout->addLayout(box_cicle_layout);

        line_3 = new QFrame(verticalLayoutWidget_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        box_main_layout->addWidget(line_3);

        box_grid_layout = new QGridLayout();
        box_grid_layout->setObjectName(QString::fromUtf8("box_grid_layout"));
        box_grid_layout->setSizeConstraint(QLayout::SetNoConstraint);
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
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        label_3->setFont(font3);

        horizontalLayout_3->addWidget(label_3);


        box_information_layout->addLayout(horizontalLayout_3);

        line_5 = new QFrame(verticalLayoutWidget_3);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font3);

        horizontalLayout_7->addWidget(label_5);


        box_information_layout->addLayout(horizontalLayout_7);

        line_2 = new QFrame(verticalLayoutWidget_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font3);

        horizontalLayout_4->addWidget(label_2);


        box_information_layout->addLayout(horizontalLayout_4);

        line_4 = new QFrame(verticalLayoutWidget_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font3);

        horizontalLayout_6->addWidget(label_4);


        box_information_layout->addLayout(horizontalLayout_6);

        line = new QFrame(verticalLayoutWidget_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font3);

        verticalLayout_3->addWidget(label_6);

        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font3);

        verticalLayout_3->addWidget(label_8);


        horizontalLayout_5->addLayout(verticalLayout_3);


        box_information_layout->addLayout(horizontalLayout_5);


        horizontalLayout_2->addLayout(box_information_layout);

        horizontalLayout_2->setStretch(0, 1);

        box_grid_layout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        box_grid_layout->setRowMinimumHeight(0, 10);

        box_main_layout->addLayout(box_grid_layout);

        box_main_layout->setStretch(2, 10);
        tabWidget->addTab(box_tab, icon4, QString());
        drone_tab = new QWidget();
        drone_tab->setObjectName(QString::fromUtf8("drone_tab"));
        verticalLayoutWidget_2 = new QWidget(drone_tab);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 721, 511));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        current_drone_label = new QLabel(verticalLayoutWidget_2);
        current_drone_label->setObjectName(QString::fromUtf8("current_drone_label"));

        horizontalLayout_8->addWidget(current_drone_label);

        comboBox = new QComboBox(verticalLayoutWidget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_8->addWidget(comboBox);

        color_drone_label = new QLabel(verticalLayoutWidget_2);
        color_drone_label->setObjectName(QString::fromUtf8("color_drone_label"));
        sizePolicy.setHeightForWidth(color_drone_label->sizePolicy().hasHeightForWidth());
        color_drone_label->setSizePolicy(sizePolicy);
        color_drone_label->setMinimumSize(QSize(30, 0));

        horizontalLayout_8->addWidget(color_drone_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_8);

        line_7 = new QFrame(verticalLayoutWidget_2);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        frame_2 = new QFrame(verticalLayoutWidget_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_9->addWidget(frame_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pushButton_5 = new QPushButton(verticalLayoutWidget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(false);
        font4.setWeight(50);
        pushButton_5->setFont(font4);

        horizontalLayout_11->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(verticalLayoutWidget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font4);

        horizontalLayout_11->addWidget(pushButton_6);


        verticalLayout_5->addLayout(horizontalLayout_11);

        line_10 = new QFrame(verticalLayoutWidget_2);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_10);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font4);

        gridLayout_3->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font4);

        gridLayout_3->addWidget(pushButton_3, 1, 1, 1, 1);

        pushButton = new QPushButton(verticalLayoutWidget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font4);

        gridLayout_3->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(verticalLayoutWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font4);

        gridLayout_3->addWidget(pushButton_4, 2, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        line_8 = new QFrame(verticalLayoutWidget_2);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_8);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font3);

        horizontalLayout_13->addWidget(label_11);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_12 = new QLabel(verticalLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font3);

        verticalLayout_6->addWidget(label_12);

        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font3);

        verticalLayout_6->addWidget(label_13);


        horizontalLayout_13->addLayout(verticalLayout_6);


        verticalLayout_5->addLayout(horizontalLayout_13);

        line_9 = new QFrame(verticalLayoutWidget_2);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_9);

        verticalLayout_5->setStretch(0, 5);
        verticalLayout_5->setStretch(2, 10);

        horizontalLayout_9->addLayout(verticalLayout_5);

        horizontalLayout_9->setStretch(0, 2);

        verticalLayout_4->addLayout(horizontalLayout_9);

        verticalLayout_4->setStretch(2, 10);
        tabWidget->addTab(drone_tab, icon5, QString());
        stat_tab = new QWidget();
        stat_tab->setObjectName(QString::fromUtf8("stat_tab"));
        gridLayoutWidget_2 = new QWidget(stat_tab);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(120, 50, 160, 80));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(gridLayoutWidget_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);

        gridLayout_4->addWidget(frame_3, 0, 0, 1, 1);

        tabWidget->addTab(stat_tab, icon6, QString());
        preset_tab = new QWidget();
        preset_tab->setObjectName(QString::fromUtf8("preset_tab"));
        tabWidget->addTab(preset_tab, icon, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(1, 10);

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 875, 22));
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
        menuFile->addAction(actionExit_2);
        menuEdit->addAction(actionPreferences);
        menuEdit->addAction(actionUser);
        menuHelp->addAction(actionOpen_Map_View);
        menuHelp->addAction(actionOpen_Box_View);
        menuHelp->addAction(actionOpen_Drone_View);
        menuHelp->addAction(actionOpen_Statistics);
        menuHelp->addAction(actionOpen_Presets);

        retranslateUi(MainWindow);
        QObject::connect(pushButton1, SIGNAL(clicked(bool)), MainWindow, SLOT(push_button1_on_clicked(bool)));

        tabWidget->setCurrentIndex(2);


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
        actionOpen_Map_View->setText(QCoreApplication::translate("MainWindow", "Open Map View", nullptr));
        actionOpen_Box_View->setText(QCoreApplication::translate("MainWindow", "Open Box View", nullptr));
        actionOpen_Drone_View->setText(QCoreApplication::translate("MainWindow", "Open Drone View", nullptr));
        actionOpen_Statistics->setText(QCoreApplication::translate("MainWindow", "Open Statistics", nullptr));
        actionUser->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        actionOpen_Presets->setText(QCoreApplication::translate("MainWindow", "Open Presets", nullptr));
        settings_button->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Drone Hive HMI", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(map_tab), QCoreApplication::translate("MainWindow", "Map", nullptr));
        current_box_label->setText(QCoreApplication::translate("MainWindow", "Current Box:", nullptr));
        color_label->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Box Type", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Box Occupied", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Box Number", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Drone Number", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Box Position:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Lat:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Lon:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(box_tab), QCoreApplication::translate("MainWindow", "Box", nullptr));
        current_drone_label->setText(QCoreApplication::translate("MainWindow", "Drone of Box:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));

        color_drone_label->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Path Upload", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Request Status", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Land", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Take-Off", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Arm", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Return Home", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Drone Position", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Lat:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Lon:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(drone_tab), QCoreApplication::translate("MainWindow", "Drone", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(stat_tab), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(preset_tab), QCoreApplication::translate("MainWindow", "Presets", nullptr));
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
