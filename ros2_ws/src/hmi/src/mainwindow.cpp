#include <iostream>
#include "mainwindow.h"
#include <QDebug>
#include <chrono>
#include <thread>
   

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), master_exists(false), number_of_boxes(0), new_box_request(false)
{
    ui->setupUi(this);

    // Create ROS2 node
    node_ = std::make_shared<rclcpp::Node>("gui_node");

    // Create publisher
    pub_ = node_->create_publisher<std_msgs::msg::String>("/gui/command", 10);
    new_box_confirm_pub_ = node_->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/gui/new_box_confirm", 10);
    
    heart_beat_sub_ = node_->create_subscription<std_msgs::msg::String>("/backend/heartbeat",10, std::bind(&MainWindow::onHeartBeatMessage, this, std::placeholders::_1));
    
    auto qos = rclcpp::QoS(10).best_effort();

    new_box_gui_sub_ = node_->create_subscription<dronehive_interfaces::msg::BoxBroadcastMessage>("/backend/new_box",10, std::bind(&MainWindow::onNewBoxMessage, this, std::placeholders::_1));

    backEndManager = new BackEndManager(this);

    connect(backEndManager, &BackEndManager::backEndCrashed, this, &MainWindow::onBackEndCrashed);
    connect(backEndManager, &BackEndManager::backEndStopped, this, &MainWindow::onBackEndStopped);

    backEndManager->startBackend();

    spinTimer_ = new QTimer(this);
    connect(spinTimer_, &QTimer::timeout, this, [this]() {
        rclcpp::spin_some(node_);
    });
    spinTimer_->start(5);
}

MainWindow::~MainWindow()
{
    this->cleanup();
}

void MainWindow::cleanup()
{
    delete this->backEndManager;
        // Stop timers first
    if (spinTimer_) {
        spinTimer_->stop();
        spinTimer_->disconnect();  // disconnect all signals
    }

    // Shutdown ROS 2
    rclcpp::shutdown();

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    delete this->spinTimer_;
    delete this->ui;
}

void MainWindow::onHeartBeatMessage(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "Got message: '%s'", msg->data.c_str());
    backEndManager->setMissedHeartBeat(0);
}

void MainWindow::onNewBoxMessage(const dronehive_interfaces::msg::BoxBroadcastMessage::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "Got message: '%s'", msg->box_id.c_str());
    backEndManager->setMissedHeartBeat(0);

    std::cout << "Got new BOX request\n";

    if(!this->new_box_request)
    {
        NewBoxDialog dialog;
        this->new_box_request = true;

        // if(msg->box_id.empty())
        // {
        //     std::cout << "Empty box id, aborting\n";
        //     return;
        // }

        // int box_id{std::stoi(msg->box_id)};
        // double box_lat{msg->landing_pos.lat};
        // double box_lon{msg->landing_pos.lon};
        // double box_alt{msg->landing_pos.elv};


        if(dialog.exec() == QDialog::Accepted)
        {
            std::cout << "Accepted" << std::endl;

            double box_lat{dialog.get_box_lat()};
            double box_lon{dialog.get_box_lon()};
            double box_alt{dialog.get_box_alt()};

            // Coordinates coord{box_lat, box_lon, box_alt};
            std::cout << "Box coord: [" << box_lat << ", " << box_lon << ", " << box_alt << "]" << std::endl;
            // SlaveBox box(coord, box_id, this->number_of_boxes++);

            // this->boxes.push_back(box);

            dronehive_interfaces::msg::BoxSetupConfirmationMessage msg;
            dronehive_interfaces::msg::PositionMessage position_msg;
            position_msg.elv = box_alt;
            position_msg.lat = box_lat;
            position_msg.lon = box_lon;

            msg.confirm = true;
            this->new_box_confirm_pub_->publish(msg);
        }
        else
        {
            std::cout << "Rejected" << std::endl;

            dronehive_interfaces::msg::BoxSetupConfirmationMessage msg;
            dronehive_interfaces::msg::PositionMessage position_msg;
            position_msg.elv = 0.0;
            position_msg.lat = 0.0;
            position_msg.lon = 0.0;

            msg.confirm = false;
            this->new_box_confirm_pub_->publish(msg);
        }
    }
}

void MainWindow::onBackEndStopped()
{

}

void MainWindow::onBackEndCrashed()
{
    
}

void MainWindow::update_box_comboBox(int& new_box_number)
{
    this->ui->comboBox->addItem(QString::number(new_box_number));
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