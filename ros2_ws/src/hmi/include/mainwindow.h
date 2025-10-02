#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QTimer>
#include <QString>

#include <memory>
#include <QThread>
#include <vector>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <dronehive_interfaces/msg/box_broadcast_message.hpp>
#include <dronehive_interfaces/msg/box_setup_confirmation_message.hpp>
#include <dronehive_interfaces/srv/box_broadcast_service.hpp>
#include <dronehive_interfaces/msg/gui_command.hpp>

#include "drone.h"
#include "box.h"
#include "new_box_dialog.h"
#include "backend_manager.h"

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

    void onBackendMessage(const std_msgs::msg::String::SharedPtr msg);
    void onHeartBeatMessage(const std_msgs::msg::String::SharedPtr msg);
    void onNewBoxMessage(const dronehive_interfaces::msg::BoxBroadcastMessage::SharedPtr msg);

private slots:

    void onBackEndStopped(void);
    void onBackEndCrashed(void);

    // pushButton slots
    void on_settings_pushButton_clicked(bool);
    void on_arm_pushButton_clicked();
    void on_takeoff_pushButton_clicked();
    void on_return_home_pushButton_clicked();
    void on_land_pushButton_clicked();
    void on_request_status_pushButton_clicked();
    void on_upload_path_pushButton_clicked();
    void on_zoom_in_pushButton_clicked();
    void on_zoom_out_pushButton_clicked();
    void on_assign_drone_pushButton_clicked();
    void on_removedrone_pushButton_clicked();
    void on_changedrone_pushButton_clicked();
    void on_remove_box_pushButton_clicked();
    void on_path_upload_pushButton_clicked();

    void on_boxComboBox_currentIndexChanged(int);
    
    void on_zoom_in_out_slider_valueChanged(int);

    void on_add_box_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<rclcpp::Node> node_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
    rclcpp::Publisher<dronehive_interfaces::msg::GuiCommand>::SharedPtr gui_cmd_pub_;
    rclcpp::Publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>::SharedPtr new_box_find_pub_;

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr heart_beat_sub_;
    rclcpp::Subscription<dronehive_interfaces::msg::BoxBroadcastMessage>::SharedPtr new_box_gui_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr backend_msg_sub_;

    std::vector<Box> boxes;
    int number_of_boxes;
    bool master_exists;
    BackEndManager* backEndManager;
    QTimer* spinTimer_;
    bool new_box_request;
};

#endif // MAINWINDOW_H
