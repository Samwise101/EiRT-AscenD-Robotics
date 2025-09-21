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

void MainWindow::push_button1_on_clicked(bool)
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from GUI!";
    pub_->publish(msg);
}

void MainWindow::on_clicked_add_box_push_button()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from Add Box Button!";
    pub_->publish(msg);
}

void MainWindow::on_clicked_arm_pushButton()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from Arm Button!";
    pub_->publish(msg);
}

void MainWindow::on_clicked_takeoff_pushButton()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from Takeoff Button!";
    pub_->publish(msg);
}

void MainWindow::on_clicked_return_home_pushButton()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from Return Home Button!";
    pub_->publish(msg);
}

void MainWindow::on_clicked_land_pushButton()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from land button!";
    pub_->publish(msg);
}

void MainWindow::on_clicked_request_status_pushButton()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from request status button!";
    pub_->publish(msg);
}

void MainWindow::on_clicked_upload_path_pushButton()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from upload path button!";
    pub_->publish(msg);
}

void MainWindow::on_clicked_zoom_in_pushButton()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from zoom in button!";
    pub_->publish(msg);
}

void MainWindow::on_clicked_zoom_out_pushButton()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from zoom out button!";
    pub_->publish(msg);
}

void MainWindow::on_clicked_assign_drone_pushButton()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from assign drone button!";
    pub_->publish(msg);
}

// Slider slots
void MainWindow::on_value_changed_zoom_in_out_slider()
{
    auto msg = std_msgs::msg::String();
    msg.data = "Hello from slider!";
    pub_->publish(msg);
}