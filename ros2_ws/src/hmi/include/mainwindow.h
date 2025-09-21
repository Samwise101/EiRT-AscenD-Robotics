#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QTimer>
#include <QString>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>
#include <thread>


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
    std::thread ros_thread_;

private slots:
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

    void on_zoom_in_out_slider_valueChanged(int);
};

#endif // MAINWINDOW_H
