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
    pub_->publish(msg);  // safe, node_ is thread-safe for publishing
}