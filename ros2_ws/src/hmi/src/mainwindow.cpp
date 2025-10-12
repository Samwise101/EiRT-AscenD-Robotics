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
    auto qos = rclcpp::QoS(10).best_effort();

    // Create publishers
    pub_ = node_->create_publisher<std_msgs::msg::String>("/gui/msg", 10);
    new_box_find_pub_ = node_->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/gui/new_box_confirm", 10);
    gui_cmd_pub_ = node_->create_publisher<dronehive_interfaces::msg::GuiCommand>("/gui/command", 10);

    // Create subscribers
    heart_beat_sub_ = node_->create_subscription<std_msgs::msg::String>("/backend/heartbeat",10, std::bind(&MainWindow::onHeartBeatMessage, this, std::placeholders::_1));
    new_box_gui_sub_ = node_->create_subscription<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/backend/newbox",10, std::bind(&MainWindow::onNewBoxMessage, this, std::placeholders::_1));
    backend_msg_sub_ = node_->create_subscription<std_msgs::msg::String>("/backend/msg", 10, std::bind(&MainWindow::onBackendMessage, this, std::placeholders::_1));
    backend_command_sub_ = node_->create_subscription<dronehive_interfaces::msg::BackendCommand>("/backend/command", 10, std::bind(&MainWindow::onBackendCommand, this, std::placeholders::_1));
    
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

void MainWindow::onBackendCommand(const dronehive_interfaces::msg::BackendCommand::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "Got command: %d", msg->command);

    switch(msg->command)
    {
        case dronehive_interfaces::msg::BackendCommand::NEW_BOX_SEARCH_TIMEOUT:
            std::cout << "The new box search request timed out" << std::endl;

            BoxTimeoutDialog dialog(this);

            if(dialog.exec() == QDialog::Accepted)
            {
                std::cout << "Retrying looking for new boxes\n";
                auto command = dronehive_interfaces::msg::GuiCommand();
                command.command = dronehive_interfaces::msg::GuiCommand::SEARCH_FOR_NEW_BOX;
                gui_cmd_pub_->publish(command);
            }
            else
            {
                std::cout << "Stopping looking for new boxes\n";
            }

            break;
    }
}

void MainWindow::onBackendMessage(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "Got message: %s", msg->data.c_str());
}

void MainWindow::onHeartBeatMessage(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "Got heartbeat: '%s'", msg->data.c_str());
    backEndManager->setMissedHeartBeat(0);
}

void MainWindow::onNewBoxMessage(const dronehive_interfaces::msg::BoxSetupConfirmationMessage::SharedPtr msg)
{
    std::cout << "Got new BOX request\n";

    auto response_pub_ = node_->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/gui/newbox_response", 10);

    NewBoxDialog dialog(this, msg->landing_pos.lat, msg->landing_pos.lon, msg->landing_pos.elv, msg->box_id);

    // Run the dialog modally
    if (dialog.exec() == QDialog::Accepted) {
        std::cout << "Accepted\n";

        dronehive_interfaces::msg::BoxSetupConfirmationMessage return_msg;

        return_msg.confirm = true;
        return_msg.box_id = dialog.get_box_id().toStdString();
        return_msg.landing_pos.elv = dialog.get_box_alt();
        return_msg.landing_pos.lat = dialog.get_box_lat();
        return_msg.landing_pos.lon = dialog.get_box_lon();

        response_pub_->publish(return_msg);

        Coordinates coord{return_msg.landing_pos.lat,return_msg.landing_pos.lon,return_msg.landing_pos.elv};
        Box newBox(SLAVE, coord, return_msg.box_id, this->boxes.size() + 1);
        this->boxes.push_back(newBox);

        this->ui->boxComboBox->addItem(QString::fromStdString(return_msg.box_id));
    } 
    else 
    {
        std::cout << "Rejected\n";
        dronehive_interfaces::msg::BoxSetupConfirmationMessage return_msg;
        return_msg.confirm = false;
        response_pub_->publish(return_msg);
    }
}

void MainWindow::onBackEndStopped()
{
    std::cout << "Hello from stopped\n";
    delete this->backEndManager;
}

void MainWindow::onBackEndCrashed()
{
    std::cout << "Hello from crash\n";
    delete this->backEndManager;
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
    std::cout << "Hello from remove box button!\n";

    // if(this->ui->boxComboBox->currentText().isEmpty()) return;

    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REMOVE_BOX;

    QString current_data = this->ui->boxComboBox->currentText();
    command.box_id = current_data.toStdString();
    gui_cmd_pub_->publish(command);
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

void MainWindow::on_add_box_pushButton_clicked()
{
    std::cout << "Hello from the add box button\n";

    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::SEARCH_FOR_NEW_BOX;

    gui_cmd_pub_->publish(command);
}