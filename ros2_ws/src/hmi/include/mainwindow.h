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
    void push_button1_on_clicked(bool);
    void on_clicked_add_box_push_button();
    void on_clicked_arm_pushButton();
    void on_clicked_takeoff_pushButton();
    void on_clicked_return_home_pushButton();
    void on_clicked_land_pushButton();
    void on_clicked_request_status_pushButton();
    void on_clicked_upload_path_pushButton();
    void on_clicked_zoom_in_pushButton();
    void on_clicked_zoom_out_pushButton();
    void on_clicked_assign_drone_pushButton();

    // Slider slots
    void on_value_changed_zoom_in_out_slider();
};

#endif // MAINWINDOW_H
