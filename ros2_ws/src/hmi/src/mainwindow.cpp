#include <iostream>
#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), master_exists(false), number_of_boxes(0)
{
    ui->setupUi(this);

    // Create ROS2 node
    node_ = std::make_shared<rclcpp::Node>("gui_node");

    // Create publisher
    pub_ = node_->create_publisher<std_msgs::msg::String>("/gui/command", 10);
    sub_ = node_->create_subscription<std_msgs::msg::String>("/backend/heartbeat",10, std::bind(&MainWindow::onHeartBeatMessage, this, std::placeholders::_1));

    BackEndManager* backEndManager = new BackEndManager(this);

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
    delete this->backEndManager;
    delete this->spinTimer_;
    delete this->ui;
}

void MainWindow::onHeartBeatMessage(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "Got message: '%s'", msg->data.c_str());
    backEndManager->setMissedHeartBeat(0);
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

void MainWindow::on_add_box_push_button_clicked()
{
    NewBoxDialog dialog;

    if(dialog.exec() == QDialog::Accepted)
    {
        int box_type{dialog.get_box_type()};

        if(box_type == SLAVE || (box_type == MASTER && this->master_exists == false))
        {   
            std::cout << "Slave box created\n";
            int box_id{dialog.get_box_id()};
            float box_lat{dialog.get_box_lat()};
            float box_lon{dialog.get_box_lon()};
            float box_alt{dialog.get_box_alt()};

            std::cout << box_type << std::endl;

            Coordinates box_coord{box_lat, box_lon, box_alt};

            std::cout << "Box type: " << box_type << std::endl;
            std::cout << "Box ID: " << box_id << std::endl;
            std::cout << "Box number: " << this->number_of_boxes << std::endl;
            std::cout << "Box coord: [" << box_coord.lat << ", " << box_coord.lon << ", " << box_coord.alt << "]" << std::endl;

            if(box_type == MASTER)
            {
                MasterBox box{box_type, box_coord, box_id, this->number_of_boxes++};
                this->boxes.insert(this->boxes.begin(), box);
            }
            else
            {
                SlaveBox box{box_type, box_coord, box_id, this->number_of_boxes++};
                this->boxes.push_back(box);
            }
        }
        else{
            std::cout << "Unknown box config detected or master already exists\n";
            return;
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