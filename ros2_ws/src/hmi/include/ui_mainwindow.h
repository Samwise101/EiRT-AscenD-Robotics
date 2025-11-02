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
    QPushButton *addBox;
    QFrame *line_20;
    QPushButton *updateSystem;
    QFrame *line;
    QPushButton *pushButton1;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *map_tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *map_layout;
    QVBoxLayout *verticalLayout_6;
    QFrame *line_13;
    QHBoxLayout *slider_layout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *zoomPlusButton;
    QSlider *zoom_slider;
    QPushButton *zoomOutButton;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_21;
    QVBoxLayout *verticalLayout_3;
    QPushButton *loadMapButton;
    QFrame *line_22;
    QPushButton *loadTrajectoryButton;
    QPushButton *clearVisualsButton;
    QSpacerItem *verticalSpacer;
    QWidget *box_tab;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *box_main_layout;
    QHBoxLayout *box_cicle_layout;
    QGridLayout *box_grid_layout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *Box_show_layout;
    QFrame *frame_box;
    QFrame *line_14;
    QVBoxLayout *box_information_layout;
    QHBoxLayout *horizontalLayout_11;
    QLabel *current_box_label;
    QComboBox *boxComboBox;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_7;
    QFrame *line_19;
    QPushButton *requestStatusPushButtin;
    QFrame *line_11;
    QHBoxLayout *horizontalLayout_5;
    QLabel *boxIdLabel;
    QLabel *boxIdValueLabel;
    QFrame *line_12;
    QHBoxLayout *horizontalLayout_3;
    QLabel *boxTypeLabel;
    QLabel *boxTypeValueLabel;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *boxStatusLabel;
    QLabel *boxStatusValueLabel;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *boxNumberLabel;
    QLabel *boxNumberValueLabel;
    QFrame *line_18;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_2;
    QLabel *assignedDroneLabel;
    QFrame *line_24;
    QGridLayout *box_position_layout;
    QLabel *box_latitude_label;
    QLabel *box_longitude_label;
    QLabel *box_altitude_label;
    QLabel *box_latitude_value_label;
    QLabel *box_longitude_value_label;
    QLabel *box_altitude_value_label;
    QWidget *drone_tab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_9;
    QFrame *frame_drone;
    QFrame *line_15;
    QVBoxLayout *verticalLayout_5;
    QFrame *line_10;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label;
    QComboBox *droneComboBox;
    QFrame *line_8;
    QPushButton *removeDroneButton;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_3;
    QLabel *droneIdLabel;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_5;
    QLabel *droneColorCodeLabel;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_6;
    QLabel *parentBoxLabel;
    QFrame *line_23;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QFrame *line_16;
    QFrame *line_17;
    QGridLayout *gridLayout_6;
    QLabel *drone_longitude_label;
    QLabel *latitude_label;
    QLabel *altitude_label;
    QLabel *drone_latitude_value_label;
    QLabel *drone_longitude_value_label;
    QLabel *drone_altitude_value_label;
    QWidget *stat_tab;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QWidget *preset_tab;
    QTreeView *treeView;
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
        MainWindow->resize(1038, 644);
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
        centralwidget->setMinimumSize(QSize(1000, 600));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(50);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addBox = new QPushButton(centralwidget);
        addBox->setObjectName(QString::fromUtf8("addBox"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/icons/add_box.png"), QSize(), QIcon::Normal, QIcon::Off);
        addBox->setIcon(icon8);

        verticalLayout->addWidget(addBox);

        line_20 = new QFrame(centralwidget);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setFrameShape(QFrame::HLine);
        line_20->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_20);

        updateSystem = new QPushButton(centralwidget);
        updateSystem->setObjectName(QString::fromUtf8("updateSystem"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/icons/update_system.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateSystem->setIcon(icon9);

        verticalLayout->addWidget(updateSystem);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        QFont font;
        font.setPointSize(11);
        pushButton1->setFont(font);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/icons/settings2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton1->setIcon(icon10);

        verticalLayout->addWidget(pushButton1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        tabWidget->setFont(font1);
        map_tab = new QWidget();
        map_tab->setObjectName(QString::fromUtf8("map_tab"));
        horizontalLayoutWidget = new QWidget(map_tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 9, 771, 531));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        map_layout = new QVBoxLayout();
        map_layout->setObjectName(QString::fromUtf8("map_layout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));

        map_layout->addLayout(verticalLayout_6);

        line_13 = new QFrame(horizontalLayoutWidget);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        map_layout->addWidget(line_13);

        slider_layout = new QHBoxLayout();
        slider_layout->setObjectName(QString::fromUtf8("slider_layout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        slider_layout->addItem(horizontalSpacer_3);

        zoomPlusButton = new QPushButton(horizontalLayoutWidget);
        zoomPlusButton->setObjectName(QString::fromUtf8("zoomPlusButton"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/icons/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomPlusButton->setIcon(icon11);

        slider_layout->addWidget(zoomPlusButton);

        zoom_slider = new QSlider(horizontalLayoutWidget);
        zoom_slider->setObjectName(QString::fromUtf8("zoom_slider"));
        zoom_slider->setMaximum(50);
        zoom_slider->setSingleStep(1);
        zoom_slider->setValue(10);
        zoom_slider->setSliderPosition(10);
        zoom_slider->setOrientation(Qt::Horizontal);

        slider_layout->addWidget(zoom_slider);

        zoomOutButton = new QPushButton(horizontalLayoutWidget);
        zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/icons/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomOutButton->setIcon(icon12);

        slider_layout->addWidget(zoomOutButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        slider_layout->addItem(horizontalSpacer_4);


        map_layout->addLayout(slider_layout);


        horizontalLayout_8->addLayout(map_layout);

        line_21 = new QFrame(horizontalLayoutWidget);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setFrameShape(QFrame::VLine);
        line_21->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line_21);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        loadMapButton = new QPushButton(horizontalLayoutWidget);
        loadMapButton->setObjectName(QString::fromUtf8("loadMapButton"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        loadMapButton->setFont(font2);

        verticalLayout_3->addWidget(loadMapButton);

        line_22 = new QFrame(horizontalLayoutWidget);
        line_22->setObjectName(QString::fromUtf8("line_22"));
        line_22->setFrameShape(QFrame::HLine);
        line_22->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_22);

        loadTrajectoryButton = new QPushButton(horizontalLayoutWidget);
        loadTrajectoryButton->setObjectName(QString::fromUtf8("loadTrajectoryButton"));
        loadTrajectoryButton->setFont(font2);

        verticalLayout_3->addWidget(loadTrajectoryButton);

        clearVisualsButton = new QPushButton(horizontalLayoutWidget);
        clearVisualsButton->setObjectName(QString::fromUtf8("clearVisualsButton"));
        clearVisualsButton->setFont(font2);

        verticalLayout_3->addWidget(clearVisualsButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_8->addLayout(verticalLayout_3);

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

        box_main_layout->addLayout(box_cicle_layout);

        box_grid_layout = new QGridLayout();
        box_grid_layout->setObjectName(QString::fromUtf8("box_grid_layout"));
        box_grid_layout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Box_show_layout = new QVBoxLayout();
        Box_show_layout->setObjectName(QString::fromUtf8("Box_show_layout"));
        frame_box = new QFrame(verticalLayoutWidget_3);
        frame_box->setObjectName(QString::fromUtf8("frame_box"));
        frame_box->setFrameShape(QFrame::StyledPanel);
        frame_box->setFrameShadow(QFrame::Raised);

        Box_show_layout->addWidget(frame_box);


        horizontalLayout_2->addLayout(Box_show_layout);

        line_14 = new QFrame(verticalLayoutWidget_3);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_14);

        box_information_layout = new QVBoxLayout();
        box_information_layout->setObjectName(QString::fromUtf8("box_information_layout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        current_box_label = new QLabel(verticalLayoutWidget_3);
        current_box_label->setObjectName(QString::fromUtf8("current_box_label"));
        current_box_label->setFont(font2);
        current_box_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(current_box_label);

        boxComboBox = new QComboBox(verticalLayoutWidget_3);
        boxComboBox->setObjectName(QString::fromUtf8("boxComboBox"));

        horizontalLayout_11->addWidget(boxComboBox);

        horizontalLayout_11->setStretch(0, 10);

        box_information_layout->addLayout(horizontalLayout_11);

        line_4 = new QFrame(verticalLayoutWidget_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_7 = new QPushButton(verticalLayoutWidget_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setFont(font2);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/icons/remove_box.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon13);

        horizontalLayout_6->addWidget(pushButton_7);


        box_information_layout->addLayout(horizontalLayout_6);

        line_19 = new QFrame(verticalLayoutWidget_3);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setFrameShape(QFrame::HLine);
        line_19->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_19);

        requestStatusPushButtin = new QPushButton(verticalLayoutWidget_3);
        requestStatusPushButtin->setObjectName(QString::fromUtf8("requestStatusPushButtin"));
        requestStatusPushButtin->setFont(font2);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/icons/request_status.png"), QSize(), QIcon::Normal, QIcon::Off);
        requestStatusPushButtin->setIcon(icon14);

        box_information_layout->addWidget(requestStatusPushButtin);

        line_11 = new QFrame(verticalLayoutWidget_3);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_11);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        boxIdLabel = new QLabel(verticalLayoutWidget_3);
        boxIdLabel->setObjectName(QString::fromUtf8("boxIdLabel"));
        boxIdLabel->setFont(font2);
        boxIdLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(boxIdLabel);

        boxIdValueLabel = new QLabel(verticalLayoutWidget_3);
        boxIdValueLabel->setObjectName(QString::fromUtf8("boxIdValueLabel"));
        boxIdValueLabel->setFont(font2);
        boxIdValueLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(boxIdValueLabel);


        box_information_layout->addLayout(horizontalLayout_5);

        line_12 = new QFrame(verticalLayoutWidget_3);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_12);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        boxTypeLabel = new QLabel(verticalLayoutWidget_3);
        boxTypeLabel->setObjectName(QString::fromUtf8("boxTypeLabel"));
        boxTypeLabel->setFont(font2);
        boxTypeLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(boxTypeLabel);

        boxTypeValueLabel = new QLabel(verticalLayoutWidget_3);
        boxTypeValueLabel->setObjectName(QString::fromUtf8("boxTypeValueLabel"));
        boxTypeValueLabel->setFont(font2);
        boxTypeValueLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(boxTypeValueLabel);


        box_information_layout->addLayout(horizontalLayout_3);

        line_5 = new QFrame(verticalLayoutWidget_3);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        boxStatusLabel = new QLabel(verticalLayoutWidget_3);
        boxStatusLabel->setObjectName(QString::fromUtf8("boxStatusLabel"));
        boxStatusLabel->setFont(font2);
        boxStatusLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(boxStatusLabel);

        boxStatusValueLabel = new QLabel(verticalLayoutWidget_3);
        boxStatusValueLabel->setObjectName(QString::fromUtf8("boxStatusValueLabel"));
        boxStatusValueLabel->setFont(font2);
        boxStatusValueLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(boxStatusValueLabel);


        box_information_layout->addLayout(horizontalLayout_7);

        line_2 = new QFrame(verticalLayoutWidget_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        boxNumberLabel = new QLabel(verticalLayoutWidget_3);
        boxNumberLabel->setObjectName(QString::fromUtf8("boxNumberLabel"));
        boxNumberLabel->setFont(font2);
        boxNumberLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(boxNumberLabel);

        boxNumberValueLabel = new QLabel(verticalLayoutWidget_3);
        boxNumberValueLabel->setObjectName(QString::fromUtf8("boxNumberValueLabel"));
        boxNumberValueLabel->setFont(font2);
        boxNumberValueLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(boxNumberValueLabel);


        box_information_layout->addLayout(horizontalLayout_4);

        line_18 = new QFrame(verticalLayoutWidget_3);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setFrameShape(QFrame::HLine);
        line_18->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_18);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_2);

        assignedDroneLabel = new QLabel(verticalLayoutWidget_3);
        assignedDroneLabel->setObjectName(QString::fromUtf8("assignedDroneLabel"));
        assignedDroneLabel->setFont(font2);
        assignedDroneLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(assignedDroneLabel);


        box_information_layout->addLayout(horizontalLayout_14);

        line_24 = new QFrame(verticalLayoutWidget_3);
        line_24->setObjectName(QString::fromUtf8("line_24"));
        line_24->setFrameShape(QFrame::HLine);
        line_24->setFrameShadow(QFrame::Sunken);

        box_information_layout->addWidget(line_24);

        box_position_layout = new QGridLayout();
        box_position_layout->setObjectName(QString::fromUtf8("box_position_layout"));
        box_latitude_label = new QLabel(verticalLayoutWidget_3);
        box_latitude_label->setObjectName(QString::fromUtf8("box_latitude_label"));
        box_latitude_label->setFont(font2);
        box_latitude_label->setAlignment(Qt::AlignCenter);

        box_position_layout->addWidget(box_latitude_label, 0, 0, 1, 1);

        box_longitude_label = new QLabel(verticalLayoutWidget_3);
        box_longitude_label->setObjectName(QString::fromUtf8("box_longitude_label"));
        box_longitude_label->setFont(font2);
        box_longitude_label->setAlignment(Qt::AlignCenter);

        box_position_layout->addWidget(box_longitude_label, 1, 0, 1, 1);

        box_altitude_label = new QLabel(verticalLayoutWidget_3);
        box_altitude_label->setObjectName(QString::fromUtf8("box_altitude_label"));
        box_altitude_label->setFont(font2);
        box_altitude_label->setAlignment(Qt::AlignCenter);

        box_position_layout->addWidget(box_altitude_label, 2, 0, 1, 1);

        box_latitude_value_label = new QLabel(verticalLayoutWidget_3);
        box_latitude_value_label->setObjectName(QString::fromUtf8("box_latitude_value_label"));
        box_latitude_value_label->setFont(font2);
        box_latitude_value_label->setAlignment(Qt::AlignCenter);

        box_position_layout->addWidget(box_latitude_value_label, 0, 1, 1, 1);

        box_longitude_value_label = new QLabel(verticalLayoutWidget_3);
        box_longitude_value_label->setObjectName(QString::fromUtf8("box_longitude_value_label"));
        box_longitude_value_label->setFont(font2);
        box_longitude_value_label->setAlignment(Qt::AlignCenter);

        box_position_layout->addWidget(box_longitude_value_label, 1, 1, 1, 1);

        box_altitude_value_label = new QLabel(verticalLayoutWidget_3);
        box_altitude_value_label->setObjectName(QString::fromUtf8("box_altitude_value_label"));
        box_altitude_value_label->setFont(font2);
        box_altitude_value_label->setAlignment(Qt::AlignCenter);

        box_position_layout->addWidget(box_altitude_value_label, 2, 1, 1, 1);


        box_information_layout->addLayout(box_position_layout);


        horizontalLayout_2->addLayout(box_information_layout);

        horizontalLayout_2->setStretch(0, 1);

        box_grid_layout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        box_grid_layout->setRowMinimumHeight(0, 10);

        box_main_layout->addLayout(box_grid_layout);

        box_main_layout->setStretch(1, 10);
        tabWidget->addTab(box_tab, icon4, QString());
        drone_tab = new QWidget();
        drone_tab->setObjectName(QString::fromUtf8("drone_tab"));
        verticalLayoutWidget_2 = new QWidget(drone_tab);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 731, 511));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        line_7 = new QFrame(verticalLayoutWidget_2);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        frame_drone = new QFrame(verticalLayoutWidget_2);
        frame_drone->setObjectName(QString::fromUtf8("frame_drone"));
        frame_drone->setFrameShape(QFrame::StyledPanel);
        frame_drone->setFrameShadow(QFrame::Raised);

        horizontalLayout_9->addWidget(frame_drone);

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

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        horizontalLayout_12->addWidget(label);

        droneComboBox = new QComboBox(verticalLayoutWidget_2);
        droneComboBox->setObjectName(QString::fromUtf8("droneComboBox"));

        horizontalLayout_12->addWidget(droneComboBox);


        verticalLayout_5->addLayout(horizontalLayout_12);

        line_8 = new QFrame(verticalLayoutWidget_2);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_8);

        removeDroneButton = new QPushButton(verticalLayoutWidget_2);
        removeDroneButton->setObjectName(QString::fromUtf8("removeDroneButton"));
        removeDroneButton->setFont(font2);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/icons/remove_drone.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeDroneButton->setIcon(icon15);

        verticalLayout_5->addWidget(removeDroneButton);

        line_3 = new QFrame(verticalLayoutWidget_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_3);

        droneIdLabel = new QLabel(verticalLayoutWidget_2);
        droneIdLabel->setObjectName(QString::fromUtf8("droneIdLabel"));
        droneIdLabel->setFont(font2);
        droneIdLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(droneIdLabel);


        verticalLayout_7->addLayout(horizontalLayout_10);

        line_6 = new QFrame(verticalLayoutWidget_2);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_6);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_5);

        droneColorCodeLabel = new QLabel(verticalLayoutWidget_2);
        droneColorCodeLabel->setObjectName(QString::fromUtf8("droneColorCodeLabel"));
        droneColorCodeLabel->setFont(font2);
        droneColorCodeLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(droneColorCodeLabel);


        verticalLayout_7->addLayout(horizontalLayout_13);

        line_9 = new QFrame(verticalLayoutWidget_2);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_9);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(label_6);

        parentBoxLabel = new QLabel(verticalLayoutWidget_2);
        parentBoxLabel->setObjectName(QString::fromUtf8("parentBoxLabel"));
        parentBoxLabel->setFont(font2);
        parentBoxLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(parentBoxLabel);


        verticalLayout_7->addLayout(horizontalLayout_15);


        verticalLayout_5->addLayout(verticalLayout_7);

        line_23 = new QFrame(verticalLayoutWidget_2);
        line_23->setObjectName(QString::fromUtf8("line_23"));
        line_23->setFrameShape(QFrame::HLine);
        line_23->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_23);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton = new QPushButton(verticalLayoutWidget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font2);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/icons/arm_drone.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon16);

        gridLayout_3->addWidget(pushButton, 3, 0, 1, 1);

        pushButton_6 = new QPushButton(verticalLayoutWidget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font2);
        pushButton_6->setLayoutDirection(Qt::LeftToRight);
        pushButton_6->setIcon(icon14);

        gridLayout_3->addWidget(pushButton_6, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font2);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/icons/drone_takeoff.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon17);

        gridLayout_3->addWidget(pushButton_3, 3, 1, 1, 1);

        pushButton_4 = new QPushButton(verticalLayoutWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font2);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/icons/return_home.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon18);

        gridLayout_3->addWidget(pushButton_4, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(verticalLayoutWidget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font2);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/icons/path.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon19);

        gridLayout_3->addWidget(pushButton_5, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font2);
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/images/icons/drone_land.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon20);

        gridLayout_3->addWidget(pushButton_2, 4, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);

        line_16 = new QFrame(verticalLayoutWidget_2);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_16);

        line_17 = new QFrame(verticalLayoutWidget_2);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_17);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        drone_longitude_label = new QLabel(verticalLayoutWidget_2);
        drone_longitude_label->setObjectName(QString::fromUtf8("drone_longitude_label"));
        drone_longitude_label->setFont(font2);
        drone_longitude_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(drone_longitude_label, 1, 0, 1, 1);

        latitude_label = new QLabel(verticalLayoutWidget_2);
        latitude_label->setObjectName(QString::fromUtf8("latitude_label"));
        latitude_label->setFont(font2);
        latitude_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(latitude_label, 0, 0, 1, 1);

        altitude_label = new QLabel(verticalLayoutWidget_2);
        altitude_label->setObjectName(QString::fromUtf8("altitude_label"));
        altitude_label->setFont(font2);
        altitude_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(altitude_label, 2, 0, 1, 1);

        drone_latitude_value_label = new QLabel(verticalLayoutWidget_2);
        drone_latitude_value_label->setObjectName(QString::fromUtf8("drone_latitude_value_label"));
        drone_latitude_value_label->setFont(font2);
        drone_latitude_value_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(drone_latitude_value_label, 0, 1, 1, 1);

        drone_longitude_value_label = new QLabel(verticalLayoutWidget_2);
        drone_longitude_value_label->setObjectName(QString::fromUtf8("drone_longitude_value_label"));
        drone_longitude_value_label->setFont(font2);
        drone_longitude_value_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(drone_longitude_value_label, 1, 1, 1, 1);

        drone_altitude_value_label = new QLabel(verticalLayoutWidget_2);
        drone_altitude_value_label->setObjectName(QString::fromUtf8("drone_altitude_value_label"));
        drone_altitude_value_label->setFont(font2);
        drone_altitude_value_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(drone_altitude_value_label, 2, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_6);


        horizontalLayout_9->addLayout(verticalLayout_5);

        horizontalLayout_9->setStretch(0, 10);

        verticalLayout_4->addLayout(horizontalLayout_9);

        verticalLayout_4->setStretch(1, 10);
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


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(1, 10);

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1038, 22));
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
        QObject::connect(addBox, SIGNAL(clicked()), MainWindow, SLOT(on_add_box_pushButton_clicked()));
        QObject::connect(updateSystem, SIGNAL(clicked()), MainWindow, SLOT(on_updateSystem_pushButton_clicked()));
        QObject::connect(zoomOutButton, SIGNAL(clicked()), MainWindow, SLOT(on_zoomOutButton_pushButton_clicked()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), MainWindow, SLOT(on_return_home_pushButton_clicked()));
        QObject::connect(requestStatusPushButtin, SIGNAL(clicked()), MainWindow, SLOT(on_request_box_status_pushButton_clicked()));
        QObject::connect(clearVisualsButton, SIGNAL(clicked()), MainWindow, SLOT(on_clearVisualsButton_pushButton_clicked()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), MainWindow, SLOT(on_request_status_pushButton_clicked()));
        QObject::connect(boxComboBox, SIGNAL(currentIndexChanged(int)), MainWindow, SLOT(on_boxComboBox_currentIndexChanged(int)));
        QObject::connect(zoomPlusButton, SIGNAL(clicked()), MainWindow, SLOT(on_zoomPlusButton_pushButton_clicked()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(on_land_pushButton_clicked()));
        QObject::connect(removeDroneButton, SIGNAL(clicked()), MainWindow, SLOT(on_removeDroneButton_pushButton_clicked()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(on_takeoff_pushButton_clicked()));
        QObject::connect(droneComboBox, SIGNAL(currentIndexChanged(int)), MainWindow, SLOT(on_droneComboBox_currentIndexChanged(int)));
        QObject::connect(pushButton_7, SIGNAL(clicked()), MainWindow, SLOT(on_remove_box_pushButton_clicked()));
        QObject::connect(zoom_slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(on_zoom_in_out_slider_valueChanged(int)));
        QObject::connect(loadTrajectoryButton, SIGNAL(clicked()), MainWindow, SLOT(on_loadTrajectoryButton_pushButton_clicked()));
        QObject::connect(loadMapButton, SIGNAL(clicked()), MainWindow, SLOT(on_loadMapButton_pushButton_clicked()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(on_arm_pushButton_clicked()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), MainWindow, SLOT(on_path_upload_pushButton_clicked()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), MainWindow, SLOT(on_request_drone_status_pushButton_clicked()));

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
        addBox->setText(QCoreApplication::translate("MainWindow", "Add Box", nullptr));
        updateSystem->setText(QCoreApplication::translate("MainWindow", "Update System Status", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        zoomPlusButton->setText(QString());
        zoomOutButton->setText(QString());
        loadMapButton->setText(QCoreApplication::translate("MainWindow", "Load Map", nullptr));
        loadTrajectoryButton->setText(QCoreApplication::translate("MainWindow", "Load\n"
" Trajectory", nullptr));
        clearVisualsButton->setText(QCoreApplication::translate("MainWindow", "Clear Visuals", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(map_tab), QCoreApplication::translate("MainWindow", "Map", nullptr));
        current_box_label->setText(QCoreApplication::translate("MainWindow", "Selected Box:", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Remove Box", nullptr));
        requestStatusPushButtin->setText(QCoreApplication::translate("MainWindow", "Request \n"
"Box Status", nullptr));
        boxIdLabel->setText(QCoreApplication::translate("MainWindow", "Box ID:", nullptr));
        boxIdValueLabel->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        boxTypeLabel->setText(QCoreApplication::translate("MainWindow", "Box Type:", nullptr));
        boxTypeValueLabel->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        boxStatusLabel->setText(QCoreApplication::translate("MainWindow", "Box Status:", nullptr));
        boxStatusValueLabel->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        boxNumberLabel->setText(QCoreApplication::translate("MainWindow", "Box Number:", nullptr));
        boxNumberValueLabel->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Assigned\n"
"Drone:", nullptr));
        assignedDroneLabel->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        box_latitude_label->setText(QCoreApplication::translate("MainWindow", "Box Lat: ", nullptr));
        box_longitude_label->setText(QCoreApplication::translate("MainWindow", "Box Lon: ", nullptr));
        box_altitude_label->setText(QCoreApplication::translate("MainWindow", "Box alt: ", nullptr));
        box_latitude_value_label->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        box_longitude_value_label->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        box_altitude_value_label->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(box_tab), QCoreApplication::translate("MainWindow", "Box", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Selected Drone:", nullptr));
        removeDroneButton->setText(QCoreApplication::translate("MainWindow", "Remove Drone", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Drone ID:", nullptr));
        droneIdLabel->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Drone Color Code:", nullptr));
        droneColorCodeLabel->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Parent Box:", nullptr));
        parentBoxLabel->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Arm", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Request Drone\n"
" Status", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Take-Off", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Return Home", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Path Upload", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Land", nullptr));
        drone_longitude_label->setText(QCoreApplication::translate("MainWindow", "Drone Lon:", nullptr));
        latitude_label->setText(QCoreApplication::translate("MainWindow", "Drone Lat:", nullptr));
        altitude_label->setText(QCoreApplication::translate("MainWindow", "Drone Alt:", nullptr));
        drone_latitude_value_label->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        drone_longitude_value_label->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        drone_altitude_value_label->setText(QCoreApplication::translate("MainWindow", "Unknown", nullptr));
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
