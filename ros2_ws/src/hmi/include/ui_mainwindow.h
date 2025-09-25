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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
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
    QHBoxLayout *horizontalLayout_11;
    QLabel *current_box_label;
    QComboBox *boxComboBox;
    QPushButton *add_box_pushButton;
    QPushButton *settings_button;
    QPushButton *pushButton1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *map_tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *map_layout;
    QGridLayout *map_frame_layout;
    QLabel *label_6;
    QFrame *line_13;
    QHBoxLayout *slider_layout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *zoom_in_pushButton;
    QSlider *zoom_slider;
    QPushButton *zoom_out_pushButton;
    QSpacerItem *horizontalSpacer_4;
    QWidget *box_tab;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *box_main_layout;
    QHBoxLayout *box_cicle_layout;
    QLabel *color_label;
    QSpacerItem *horizontalSpacer;
    QFrame *line_3;
    QGridLayout *box_grid_layout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *Box_show_layout;
    QFrame *frame;
    QFrame *line_14;
    QVBoxLayout *box_information_layout;
    QGridLayout *drone_button_layout;
    QFrame *line_21;
    QPushButton *pushButton_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
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
    QFrame *line_18;
    QGridLayout *box_position_layout;
    QLabel *box_longitude_label;
    QLabel *box_latitude_label;
    QLineEdit *box_latitude_lineEdit;
    QLineEdit *box_longitude_lineEdit;
    QFrame *line;
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
    QFrame *line_15;
    QVBoxLayout *verticalLayout_5;
    QFrame *line_10;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QFrame *line_12;
    QFrame *line_11;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QFrame *line_16;
    QSpacerItem *verticalSpacer;
    QFrame *line_17;
    QGridLayout *gridLayout_6;
    QLineEdit *longitude_lineEdit;
    QLineEdit *altitude_lineEdit;
    QLineEdit *latitude_lineEdit;
    QLabel *longitude_label;
    QLabel *latitude_label;
    QLabel *altitude_label;
    QFrame *line_8;
    QFrame *line_9;
    QWidget *stat_tab;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QWidget *preset_tab;
    QTreeView *treeView;
    QGridLayout *gridLayout;
    QFrame *line_6;
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
        MainWindow->resize(971, 672);
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
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        current_box_label = new QLabel(centralwidget);
        current_box_label->setObjectName(QString::fromUtf8("current_box_label"));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        current_box_label->setFont(font);
        current_box_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(current_box_label);

        boxComboBox = new QComboBox(centralwidget);
        boxComboBox->setObjectName(QString::fromUtf8("boxComboBox"));

        horizontalLayout_11->addWidget(boxComboBox);


        verticalLayout->addLayout(horizontalLayout_11);

        add_box_pushButton = new QPushButton(centralwidget);
        add_box_pushButton->setObjectName(QString::fromUtf8("add_box_pushButton"));
        add_box_pushButton->setFont(font);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/icons/add_box.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_box_pushButton->setIcon(icon8);

        verticalLayout->addWidget(add_box_pushButton);

        settings_button = new QPushButton(centralwidget);
        settings_button->setObjectName(QString::fromUtf8("settings_button"));
        QFont font1;
        font1.setPointSize(11);
        settings_button->setFont(font1);

        verticalLayout->addWidget(settings_button);

        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setFont(font1);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/icons/settings2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton1->setIcon(icon9);

        verticalLayout->addWidget(pushButton1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setBaseSize(QSize(0, 0));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        tabWidget->setFont(font3);
        map_tab = new QWidget();
        map_tab->setObjectName(QString::fromUtf8("map_tab"));
        verticalLayoutWidget = new QWidget(map_tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 731, 511));
        map_layout = new QVBoxLayout(verticalLayoutWidget);
        map_layout->setObjectName(QString::fromUtf8("map_layout"));
        map_layout->setContentsMargins(0, 0, 0, 0);
        map_frame_layout = new QGridLayout();
        map_frame_layout->setObjectName(QString::fromUtf8("map_frame_layout"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        map_frame_layout->addWidget(label_6, 1, 1, 1, 1);


        map_layout->addLayout(map_frame_layout);

        line_13 = new QFrame(verticalLayoutWidget);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        map_layout->addWidget(line_13);

        slider_layout = new QHBoxLayout();
        slider_layout->setObjectName(QString::fromUtf8("slider_layout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        slider_layout->addItem(horizontalSpacer_3);

        zoom_in_pushButton = new QPushButton(verticalLayoutWidget);
        zoom_in_pushButton->setObjectName(QString::fromUtf8("zoom_in_pushButton"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/icons/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoom_in_pushButton->setIcon(icon10);

        slider_layout->addWidget(zoom_in_pushButton);

        zoom_slider = new QSlider(verticalLayoutWidget);
        zoom_slider->setObjectName(QString::fromUtf8("zoom_slider"));
        zoom_slider->setOrientation(Qt::Horizontal);

        slider_layout->addWidget(zoom_slider);

        zoom_out_pushButton = new QPushButton(verticalLayoutWidget);
        zoom_out_pushButton->setObjectName(QString::fromUtf8("zoom_out_pushButton"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/icons/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoom_out_pushButton->setIcon(icon11);

        slider_layout->addWidget(zoom_out_pushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        slider_layout->addItem(horizontalSpacer_4);


        map_layout->addLayout(slider_layout);

        map_layout->setStretch(0, 10);
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
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 731, 511));
        box_main_layout = new QVBoxLayout(verticalLayoutWidget_3);
        box_main_layout->setSpacing(0);
        box_main_layout->setObjectName(QString::fromUtf8("box_main_layout"));
        box_main_layout->setSizeConstraint(QLayout::SetNoConstraint);
        box_main_layout->setContentsMargins(0, 0, 0, 0);
        box_cicle_layout = new QHBoxLayout();
        box_cicle_layout->setObjectName(QString::fromUtf8("box_cicle_layout"));
        box_cicle_layout->setSizeConstraint(QLayout::SetNoConstraint);
        color_label = new QLabel(verticalLayoutWidget_3);
        color_label->setObjectName(QString::fromUtf8("color_label"));
        sizePolicy.setHeightForWidth(color_label->sizePolicy().hasHeightForWidth());
        color_label->setSizePolicy(sizePolicy);
        color_label->setMinimumSize(QSize(30, 0));

        box_cicle_layout->addWidget(color_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        box_cicle_layout->addItem(horizontalSpacer);

        box_cicle_layout->setStretch(1, 5);

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

        line_14 = new QFrame(verticalLayoutWidget_3);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_14);

        box_information_layout = new QVBoxLayout();
        box_information_layout->setObjectName(QString::fromUtf8("box_information_layout"));
        drone_button_layout = new QGridLayout();
        drone_button_layout->setObjectName(QString::fromUtf8("drone_button_layout"));
        line_21 = new QFrame(verticalLayoutWidget_3);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setFrameShape(QFrame::HLine);
        line_21->setFrameShadow(QFrame::Sunken);

        drone_button_layout->addWidget(line_21, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(verticalLayoutWidget_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setFont(font);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/icons/remove_box.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon12);

        drone_button_layout->addWidget(pushButton_7, 0, 0, 1, 1);


        box_information_layout->addLayout(drone_button_layout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_5->addWidget(label_7);


        box_information_layout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

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
        label_5->setFont(font);

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
        label_2->setFont(font);

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
        label_4->setFont(font);

        horizontalLayout_6->addWidget(label_4);


        box_information_layout->addLayout(horizontalLayout_6);

        line_18 = new QFrame(verticalLayoutWidget_3);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setFrameShape(QFrame::HLine);
        line_18->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_18);

        box_position_layout = new QGridLayout();
        box_position_layout->setObjectName(QString::fromUtf8("box_position_layout"));
        box_longitude_label = new QLabel(verticalLayoutWidget_3);
        box_longitude_label->setObjectName(QString::fromUtf8("box_longitude_label"));
        box_longitude_label->setFont(font);
        box_longitude_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        box_position_layout->addWidget(box_longitude_label, 1, 0, 1, 1);

        box_latitude_label = new QLabel(verticalLayoutWidget_3);
        box_latitude_label->setObjectName(QString::fromUtf8("box_latitude_label"));
        box_latitude_label->setFont(font);
        box_latitude_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        box_position_layout->addWidget(box_latitude_label, 0, 0, 1, 1);

        box_latitude_lineEdit = new QLineEdit(verticalLayoutWidget_3);
        box_latitude_lineEdit->setObjectName(QString::fromUtf8("box_latitude_lineEdit"));

        box_position_layout->addWidget(box_latitude_lineEdit, 0, 1, 1, 1);

        box_longitude_lineEdit = new QLineEdit(verticalLayoutWidget_3);
        box_longitude_lineEdit->setObjectName(QString::fromUtf8("box_longitude_lineEdit"));

        box_position_layout->addWidget(box_longitude_lineEdit, 1, 1, 1, 1);


        box_information_layout->addLayout(box_position_layout);

        line = new QFrame(verticalLayoutWidget_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line);


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
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 731, 511));
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

        line_15 = new QFrame(verticalLayoutWidget_2);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);

        horizontalLayout_9->addWidget(line_15);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        line_10 = new QFrame(verticalLayoutWidget_2);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_10);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton = new QPushButton(verticalLayoutWidget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/icons/arm_drone.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon13);

        gridLayout_3->addWidget(pushButton, 3, 0, 1, 1);

        pushButton_6 = new QPushButton(verticalLayoutWidget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/icons/request_status.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon14);

        gridLayout_3->addWidget(pushButton_6, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(verticalLayoutWidget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/icons/path.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon15);

        gridLayout_3->addWidget(pushButton_5, 0, 0, 1, 1);

        line_12 = new QFrame(verticalLayoutWidget_2);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_12, 2, 0, 1, 1);

        line_11 = new QFrame(verticalLayoutWidget_2);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_11, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/icons/drone_land.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon16);

        gridLayout_3->addWidget(pushButton_2, 4, 1, 1, 1);

        pushButton_4 = new QPushButton(verticalLayoutWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/icons/return_home.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon17);

        gridLayout_3->addWidget(pushButton_4, 4, 0, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/icons/drone_takeoff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon18);

        gridLayout_3->addWidget(pushButton_3, 3, 1, 1, 1);

        pushButton_8 = new QPushButton(verticalLayoutWidget_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setFont(font);

        gridLayout_3->addWidget(pushButton_8, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(verticalLayoutWidget_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setFont(font);

        gridLayout_3->addWidget(pushButton_9, 1, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);

        line_16 = new QFrame(verticalLayoutWidget_2);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_16);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        line_17 = new QFrame(verticalLayoutWidget_2);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_17);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        longitude_lineEdit = new QLineEdit(verticalLayoutWidget_2);
        longitude_lineEdit->setObjectName(QString::fromUtf8("longitude_lineEdit"));

        gridLayout_6->addWidget(longitude_lineEdit, 1, 1, 1, 1);

        altitude_lineEdit = new QLineEdit(verticalLayoutWidget_2);
        altitude_lineEdit->setObjectName(QString::fromUtf8("altitude_lineEdit"));

        gridLayout_6->addWidget(altitude_lineEdit, 2, 1, 1, 1);

        latitude_lineEdit = new QLineEdit(verticalLayoutWidget_2);
        latitude_lineEdit->setObjectName(QString::fromUtf8("latitude_lineEdit"));

        gridLayout_6->addWidget(latitude_lineEdit, 0, 1, 1, 1);

        longitude_label = new QLabel(verticalLayoutWidget_2);
        longitude_label->setObjectName(QString::fromUtf8("longitude_label"));
        longitude_label->setFont(font);
        longitude_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(longitude_label, 1, 0, 1, 1);

        latitude_label = new QLabel(verticalLayoutWidget_2);
        latitude_label->setObjectName(QString::fromUtf8("latitude_label"));
        latitude_label->setFont(font);
        latitude_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(latitude_label, 0, 0, 1, 1);

        altitude_label = new QLabel(verticalLayoutWidget_2);
        altitude_label->setObjectName(QString::fromUtf8("altitude_label"));
        altitude_label->setFont(font);
        altitude_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(altitude_label, 2, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout_6);

        line_8 = new QFrame(verticalLayoutWidget_2);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_8);

        line_9 = new QFrame(verticalLayoutWidget_2);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_9);

        verticalLayout_5->setStretch(1, 10);

        horizontalLayout_9->addLayout(verticalLayout_5);

        horizontalLayout_9->setStretch(0, 2);

        verticalLayout_4->addLayout(horizontalLayout_9);

        verticalLayout_4->setStretch(2, 10);
        tabWidget->addTab(drone_tab, icon5, QString());
        stat_tab = new QWidget();
        stat_tab->setObjectName(QString::fromUtf8("stat_tab"));
        gridLayoutWidget_2 = new QWidget(stat_tab);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(120, 50, 501, 361));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(stat_tab, icon6, QString());
        preset_tab = new QWidget();
        preset_tab->setObjectName(QString::fromUtf8("preset_tab"));
        treeView = new QTreeView(preset_tab);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(140, 60, 441, 351));
        tabWidget->addTab(preset_tab, icon, QString());

        verticalLayout_2->addWidget(tabWidget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(1, 10);

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 971, 22));
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
        QObject::connect(pushButton1, SIGNAL(clicked()), MainWindow, SLOT(on_settings_pushButton_clicked()));
        QObject::connect(zoom_slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_zoom_in_out_slider_valueChanged(int)));
        QObject::connect(zoom_out_pushButton, SIGNAL(clicked()), MainWindow, SLOT(on_zoom_out_pushButton_clicked()));
        QObject::connect(zoom_in_pushButton, SIGNAL(clicked()), MainWindow, SLOT(on_zoom_in_pushButton_clicked()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(on_land_pushButton_clicked()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), MainWindow, SLOT(on_return_home_pushButton_clicked()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(on_arm_pushButton_clicked()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(on_takeoff_pushButton_clicked()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), MainWindow, SLOT(on_changedrone_pushButton_clicked()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), MainWindow, SLOT(on_request_status_pushButton_clicked()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), MainWindow, SLOT(on_path_upload_pushButton_clicked()));
        QObject::connect(add_box_pushButton, SIGNAL(clicked()), MainWindow, SLOT(on_add_box_push_button_clicked()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), MainWindow, SLOT(on_remove_box_pushButton_clicked()));
        QObject::connect(boxComboBox, SIGNAL(currentIndexChanged(int)), MainWindow, SLOT(on_boxComboBox_currentIndexChanged(int)));

        tabWidget->setCurrentIndex(1);


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
        current_box_label->setText(QCoreApplication::translate("MainWindow", "Selected Box:", nullptr));
        add_box_pushButton->setText(QCoreApplication::translate("MainWindow", "Add New Box", nullptr));
        settings_button->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Drone Hive HMI", nullptr));
        label_6->setText(QString());
        zoom_in_pushButton->setText(QString());
        zoom_out_pushButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(map_tab), QCoreApplication::translate("MainWindow", "Map", nullptr));
        color_label->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Remove Box", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Box ID", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Box Type", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Box Status", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Box Number", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Assigned Drone Number", nullptr));
        box_longitude_label->setText(QCoreApplication::translate("MainWindow", "Box Lon: ", nullptr));
        box_latitude_label->setText(QCoreApplication::translate("MainWindow", "Box Lat: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(box_tab), QCoreApplication::translate("MainWindow", "Box", nullptr));
        current_drone_label->setText(QCoreApplication::translate("MainWindow", "Drone of Box Number:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));

        color_drone_label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Arm", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Request Status", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Path Upload", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Land", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Return Home", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Take-Off", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Change Drone", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        longitude_label->setText(QCoreApplication::translate("MainWindow", "Drone Lon:", nullptr));
        latitude_label->setText(QCoreApplication::translate("MainWindow", "Drone Lat:", nullptr));
        altitude_label->setText(QCoreApplication::translate("MainWindow", "Drone Alt:", nullptr));
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
