#include <iostream>
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), master_exists(false)
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

std::vector<Box> MainWindow::get_boxes()
{
    return this->boxes;
}

bool MainWindow::get_master_exists()
{
    return this->master_exists;
}

void MainWindow::on_settings_pushButton_clicked(bool)
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from settings button!";
    pub_->publish(msg);
}

void MainWindow::on_removedrone_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from remove drone button!";
    pub_->publish(msg);
}

void MainWindow::on_path_upload_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from path upload button!";
    pub_->publish(msg);
}

void MainWindow::on_remove_box_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from remove box button!";
    pub_->publish(msg);
}

void MainWindow::on_changedrone_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from remove drone button!";
    pub_->publish(msg);
}

void MainWindow::on_add_box_push_button_clicked()
{
    NewBoxDialog dialog;

    if(dialog.exec() == QDialog::Accepted)
    {
        int box_type{dialog.get_box_type()};
        std::cout << box_type << std::endl;

        if(box_type == Box::Slave)
        {
            std::cout << "Slave box created\n";
            SlaveBox new_box{Box::Slave};
            this->boxes.push_back(new_box);
        }
        else if(box_type == Box::Master && this->master_exists == false)
        {
            std::cout << "Master box created\n";
            MasterBox new_box{Box::Master};
            this->boxes.insert(this->boxes.begin(), new_box);
            this->master_exists = true;
        }
        else{
            std::cout << "Unknown box config detected or master already exists\n";
        }
    }
}

void MainWindow::on_boxComboBox_currentIndexChanged(int index)
{
    
}

void MainWindow::on_arm_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from Arm Button! Can not ARM since safety is of the essence!";
    pub_->publish(msg);
}

void MainWindow::on_takeoff_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from Takeoff Button! Can not TAKEOFF since safety is of the essence!";
    pub_->publish(msg);
}

void MainWindow::on_return_home_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from Return Home Button! Can not Return Home since safety is of the essence!";
    pub_->publish(msg);
}

void MainWindow::on_land_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from land button! Can not Land since safety is of the essence!";
    pub_->publish(msg);
}

void MainWindow::on_request_status_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from request status button!";
    pub_->publish(msg);
}

void MainWindow::on_upload_path_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from upload path button!";
    pub_->publish(msg);
}

void MainWindow::on_zoom_in_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from zoom in button!";
    pub_->publish(msg);
}

void MainWindow::on_zoom_out_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from zoom out button!";
    pub_->publish(msg);
}

void MainWindow::on_assign_drone_pushButton_clicked()
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from assign drone button!";
    pub_->publish(msg);
}

// Slider slots
void MainWindow::on_zoom_in_out_slider_valueChanged(int value)
{
    auto msg{std_msgs::msg::String()};
    msg.data = "Hello from slider!";
    pub_->publish(msg);
}