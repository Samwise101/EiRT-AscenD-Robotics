#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QTimer>
#include <QString>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <QThread>
#include <vector>
#include <thread>

#include "drone.h"
#include "master_box.h"
#include "slave_box.h"
#include "new_box_dialog.h"
#include "backend_manager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<rclcpp::Node> node_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
    std::thread ros_thread_;

public:
    std::vector<Box> get_boxes(void);
    bool get_master_exists();
    void update_box_comboBox(int& new_box_number);

private slots:

    void onBackEndStopped(void);
    void onBackEndCrashed(void);
    void onHeartBeatMessage(const std_msgs::msg::String::SharedPtr msg);

    // pushButton slots
    void on_settings_pushButton_clicked(bool);
    void on_add_box_push_button_clicked();
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

private:
    std::vector<Box> boxes;
    int number_of_boxes;
    bool master_exists;
    BackEndManager* backEndManager;
    QTimer* spinTimer_;
};

#endif // MAINWINDOW_H
