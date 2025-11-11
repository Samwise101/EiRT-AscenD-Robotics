#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QTimer>
#include <QString>
#include <QLabel>
#include <QFileDialog>
#include <QColor>
#include <QThread>
#include <QListWidget>

#include <memory>
#include <vector>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <dronehive_interfaces/msg/box_setup_confirmation_message.hpp>
#include <dronehive_interfaces/srv/box_broadcast_service.hpp>
#include <dronehive_interfaces/msg/gui_command.hpp>
#include <dronehive_interfaces/msg/backend_command.hpp>
#include <dronehive_interfaces/msg/box_full_status.hpp>
#include <dronehive_interfaces/msg/occupancy_message.hpp>

#include "drone.h"
#include "box.h"
#include "new_box_dialog.h"
#include "box_timeout_dialog.h"
#include "backend_manager.h"
#include "warehouseframe.h"
#include "ColorListWidget.h"
#include "flight_plan_dialog.h"
#include "flight_preset_create_dialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    std::vector<Box> get_boxes(void);
    bool get_master_exists();
    void update_box_comboBox(int& new_box_number);
    void cleanup();

    bool isMasterId(std::string box_id);

    void onBackendMessage(const std_msgs::msg::String::SharedPtr msg);
    void onHeartBeatMessage(const std_msgs::msg::String::SharedPtr msg);
    void onNewBoxMessage(const dronehive_interfaces::msg::BoxSetupConfirmationMessage::SharedPtr msg);
    void onBackendCommand(const dronehive_interfaces::msg::BackendCommand::SharedPtr msg);
    void onBackendBoxStatusMessage(const dronehive_interfaces::msg::BoxFullStatus::SharedPtr msg);
    void onDroneChangedBoxStatus(const dronehive_interfaces::msg::OccupancyMessage::SharedPtr msg);

    void setBoxStateGraphics(std::string& box_status, float box_battery_level);
    void setDroneGraphics(float box_battery_level);

private slots:

    void onBackEndStopped(void);
    void onBackEndCrashed(void);

    // pushButton slots
    void on_settings_pushButton_clicked(bool);
    void on_arm_pushButton_clicked();
    void on_takeoff_pushButton_clicked();
    void on_return_home_pushButton_clicked();
    void on_land_pushButton_clicked();
    void on_request_drone_status_pushButton_clicked();
    void on_upload_path_pushButton_clicked();

    void on_remove_box_pushButton_clicked();
    void on_path_upload_pushButton_clicked();
    void on_updateSystem_pushButton_clicked();
    void on_request_box_status_pushButton_clicked();
    void on_loadMapButton_pushButton_clicked();
    void on_loadTrajectoryButton_pushButton_clicked();
    void on_clearVisualsButton_pushButton_clicked();
    void on_zoomPlusButton_pushButton_clicked();
    void on_zoomOutButton_pushButton_clicked();
    void on_removeDroneButton_pushButton_clicked();
    void on_addDroneButton_pushButton_clicked();
    void on_restartButton_pushButton_clicked();

    void on_boxComboBox_currentIndexChanged(int index);
    void on_droneComboBox_currentIndexChanged(int index);

    void on_zoom_in_out_slider_valueChanged(int value);

    void on_add_box_pushButton_clicked();

    void onListItemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    std::shared_ptr<rclcpp::Node> node_;

    rclcpp::Publisher<dronehive_interfaces::msg::GuiCommand>::SharedPtr gui_cmd_pub_;
    rclcpp::Publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>::SharedPtr new_box_find_pub_;
    rclcpp::Publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>::SharedPtr response_pub_;

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr heart_beat_sub_;
    rclcpp::Subscription<dronehive_interfaces::msg::BoxSetupConfirmationMessage>::SharedPtr new_box_gui_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr backend_msg_sub_;
    rclcpp::Subscription<dronehive_interfaces::msg::BackendCommand>::SharedPtr backend_command_sub_;
    rclcpp::Subscription<dronehive_interfaces::msg::BoxFullStatus>::SharedPtr backend_box_status_sub_;
    rclcpp::Subscription<dronehive_interfaces::msg::OccupancyMessage>::SharedPtr drone_box_status_change_sub_;

    std::vector<Box> boxes;
    std::vector<Drone> drones;
    int number_of_boxes;
    bool master_exists;
    WarehouseFrame* warehouseFrame;
    BackEndManager* backEndManager;
    QTimer* spinTimer_;
    bool new_box_request;
    int currentBoxIndex;
    bool box_update_happened;
    QLabel* imageLabel_drone; 
    QLabel* imageLabel_box;
    QLabel* batteryImageLabel_drone;
    QLabel* batteryTextLabel_drone;
    QLabel* batteryImageLabel_box;
    QLabel* batteryTextLabel_box;
    QListWidget* list_widget;
};

#endif
