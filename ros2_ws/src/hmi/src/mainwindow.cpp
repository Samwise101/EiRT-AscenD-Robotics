#include <iostream>
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create ROS2 node
    node_ = std::make_shared<rclcpp::Node>("gui_node");

    // Create publisher
    pub_ = node_->create_publisher<std_msgs::msg::String>("topic_from_gui", 10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_settings_pushButton_clicked(bool)
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from settings button!";
    pub_->publish(msg);
}

void MainWindow::on_removedrone_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from remove drone button!";
    pub_->publish(msg);
}

void MainWindow::on_path_upload_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from path upload button!";
    pub_->publish(msg);
}

void MainWindow::on_remove_box_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from remove box button!";
    pub_->publish(msg);
}

void MainWindow::on_changedrone_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from remove drone button!";
    pub_->publish(msg);
}

void MainWindow::on_add_box_push_button_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from Add Box Button!";
    pub_->publish(msg);
}

void MainWindow::on_arm_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from Arm Button!";
    pub_->publish(msg);
}

void MainWindow::on_takeoff_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from Takeoff Button!";
    pub_->publish(msg);
}

void MainWindow::on_return_home_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from Return Home Button!";
    pub_->publish(msg);
}

void MainWindow::on_land_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from land button!";
    pub_->publish(msg);
}

void MainWindow::on_request_status_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from request status button!";
    pub_->publish(msg);
}

void MainWindow::on_upload_path_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from upload path button!";
    pub_->publish(msg);
}

void MainWindow::on_zoom_in_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from zoom in button!";
    pub_->publish(msg);
}

void MainWindow::on_zoom_out_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from zoom out button!";
    pub_->publish(msg);
}

void MainWindow::on_assign_drone_pushButton_clicked()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from assign drone button!";
    pub_->publish(msg);
}

// Slider slots
void MainWindow::on_zoom_in_out_slider_valueChanged(int value)
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from slider!";
    pub_->publish(msg);
}