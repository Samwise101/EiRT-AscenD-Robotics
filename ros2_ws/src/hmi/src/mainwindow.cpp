#include <iostream>
#include "mainwindow.h"
#include <QDebug>
#include <chrono>
#include <thread>
   
namespace qos_profiles
{
    static const rclcpp::QoS master_qos = [] {
        rclcpp::QoS qos(rclcpp::KeepLast(1));
        qos.reliability(RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
        qos.durability(RMW_QOS_POLICY_DURABILITY_VOLATILE);
        return qos;
    }();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), master_exists(false), number_of_boxes(0), new_box_request(false), currentBoxIndex(0)
{
    this->ui->setupUi(this);

    this->ui->frame_box->setFrameShape(QFrame::Box);
    this->ui->frame_box->setStyleSheet("background-color:rgb(255,255,255)");

    this->ui->frame_drone->setFrameShape(QFrame::Box);
    this->ui->frame_drone->setStyleSheet("background-color:rgb(255,255,255)");

    this->imageLabel_drone = new QLabel(ui->frame_drone);
    this->imageLabel_box = new QLabel(ui->frame_box);

    this->batteryImageLabel_box = new QLabel(ui->frame_box);
    this->batteryTextLabel_box = new QLabel(ui->frame_box);
    
    this->batteryImageLabel_drone = new QLabel(ui->frame_drone);
    this->batteryTextLabel_drone = new QLabel(ui->frame_drone);
    
    // Create ROS2 node
    this->node_ = std::make_shared<rclcpp::Node>("gui_node");

    // Create publishers
    new_box_find_pub_ = node_->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/gui/new_box_confirm", qos_profiles::master_qos);
    gui_cmd_pub_ = node_->create_publisher<dronehive_interfaces::msg::GuiCommand>("/gui/command", qos_profiles::master_qos);
    response_pub_ = node_->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/gui/newbox_response", qos_profiles::master_qos);

    // Create subscribers
    heart_beat_sub_ = node_->create_subscription<std_msgs::msg::String>("/backend/heartbeat",qos_profiles::master_qos, std::bind(&MainWindow::onHeartBeatMessage, this, std::placeholders::_1));
    new_box_gui_sub_ = node_->create_subscription<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/backend/newbox",qos_profiles::master_qos, std::bind(&MainWindow::onNewBoxMessage, this, std::placeholders::_1));
    backend_msg_sub_ = node_->create_subscription<std_msgs::msg::String>("/backend/msg", qos_profiles::master_qos, std::bind(&MainWindow::onBackendMessage, this, std::placeholders::_1));
    backend_command_sub_ = node_->create_subscription<dronehive_interfaces::msg::BackendCommand>("/backend/command", qos_profiles::master_qos, std::bind(&MainWindow::onBackendCommand, this, std::placeholders::_1));
    backend_box_status_sub_ = node_->create_subscription<dronehive_interfaces::msg::BoxFullStatus>("/backend/box_status", qos_profiles::master_qos, std::bind(&MainWindow::onBackendBoxStatusMessage, this, std::placeholders::_1));

    backEndManager = new BackEndManager(this);

    connect(backEndManager, &BackEndManager::backEndCrashed, this, &MainWindow::onBackEndCrashed);
    connect(backEndManager, &BackEndManager::backEndStopped, this, &MainWindow::onBackEndStopped);

    backEndManager->startBackend();

    spinTimer_ = new QTimer(this);
    connect(spinTimer_, &QTimer::timeout, this, [this]() {
        rclcpp::spin_some(node_);
    });
    spinTimer_->start(5);

    box_update_happened = false;

    warehouseFrame = new WarehouseFrame();
    warehouseFrame->setStyleSheet("background-color:rgb(255,255,255)");
    warehouseFrame->setFrameShape(QFrame::Box);
    warehouseFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    warehouseFrame->setMinimumSize(200, 200); // optional safety
    this->ui->verticalLayout_6->addWidget(warehouseFrame);
}

MainWindow::~MainWindow()
{
    this->cleanup();
}

void MainWindow::cleanup()
{
    delete this->warehouseFrame;
    delete this->imageLabel_box;
    delete this->imageLabel_drone;
    delete this->batteryImageLabel_box;
    delete this->batteryTextLabel_box;
    delete this->batteryImageLabel_drone;
    delete this->batteryTextLabel_drone;

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

void MainWindow::onBackendBoxStatusMessage(const dronehive_interfaces::msg::BoxFullStatus::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "Got box status : %s", msg->box_status);

    std::cout << msg->box_id << ", " << msg->box_status << std::endl;
    std::string box_id = msg->box_id;
    std::string drone_id = msg->drone_id;
    std::string box_status =  msg->box_status;
    float box_lat = msg->landing_pos.lat;
    float box_lon = msg->landing_pos.lon;
    float box_elv = msg->landing_pos.elv;

    bool box_exists = false;

    for(Box box : this->boxes)
    {
        if(box.get_box_id() == box_id)
        {
            std::cout << "Box exists\n";
            box_exists = true;
            break;
        }
    }

    if(!box_exists)
    {
        QString id = QString::fromStdString(msg->box_id);
        if (ui->boxComboBox) {
            box_update_happened = true;
            ui->boxComboBox->addItem(id);
        }
        Coordinates coord{box_lat, box_lon, box_elv};
        if(box_id == "Master")
        {
            Box box(BoxType::MASTER, coord, box_id, box_status, this->boxes.size() + 1);
            this->boxes.push_back(box);
        }
        else{
            Box box(BoxType::SLAVE, coord, box_id, box_status, this->boxes.size() + 1);
            this->boxes.push_back(box);
        }
    }

    if(!drone_id.empty())
    {
        bool drone_exists = false;

        for(Drone drone : drones)
        {
            if(drone_id == drone.get_drone_id())
            {
                drone_exists = true;
                break;
            }
        }

        if(!drone_exists)
        {
            Coordinates coord{box_lat, box_lon, box_elv};
            Drone drone(DroneType::HexaCopter, coord, drone_id, Drone::randomDroneColor(), box_id);
            drones.push_back(drone);
            this->ui->droneComboBox->addItem(QString::fromStdString(drone_id));
        }

        this->ui->assignedDroneLabel->setText(QString::fromStdString(drone_id));
    }

    this->ui->boxIdValueLabel->setText(QString::fromStdString(box_id));
    this->ui->boxTypeValueLabel->setText("Slave");
    this->ui->boxNumberValueLabel->setText(QString::number(this->boxes.size()));
    this->ui->boxStatusValueLabel->setText(QString::fromStdString(box_status));
    this->ui->box_latitude_value_label->setText(QString::number(box_lat, 'f', 4));
    this->ui->box_longitude_value_label->setText(QString::number(box_lon, 'f', 4));
    this->ui->box_altitude_value_label->setText(QString::number(box_elv, 'f', 4));
    box_update_happened = false;

    this->setBoxStateGraphics(box_status, 0.0f);
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
    std::cout << "Got box id: " << msg->box_id << std::endl;

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

        Coordinates coord{dialog.get_box_lat(),dialog.get_box_lon(),dialog.get_box_alt()};
        std::cout << "Coord" << coord.alt << std::endl;

        if(msg->box_id == "Master")
        {
            std::cout << "Adding a MASTER box\n";
            Box box(BoxType::MASTER, coord, return_msg.box_id, boxStatusToString(BoxState::EMPTY) ,this->boxes.size() + 1);
            this->boxes.push_back(box);
        }
        else{
            std::cout << "Adding a SLAVE box\n";
            Box box(BoxType::SLAVE, coord, return_msg.box_id, boxStatusToString(BoxState::EMPTY) ,this->boxes.size() + 1);
            this->boxes.push_back(box);
            std::cout << "Hello1\n";
        }

        this->ui->boxComboBox->addItem(QString::fromStdString(return_msg.box_id));
    } 
    else 
    {
        std::cout << "Rejected\n";
        dronehive_interfaces::msg::BoxSetupConfirmationMessage return_msg;
        return_msg.confirm = false;
        response_pub_->publish(return_msg);
    }
    std::cout << "Hello2\n";
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
    std::cout << "Hello from settings button!\n";
}

void MainWindow::on_path_upload_pushButton_clicked()
{
    std::cout << "Hello from path upload button!\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::PATH_UPLOAD;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_updateSystem_pushButton_clicked()
{
    std::cout << "Hello from update system button!\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REQUEST_FULL_SYSTEM_STATUS;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_remove_box_pushButton_clicked()
{
    std::cout << "Hello from remove box button!\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REMOVE_BOX;
    QString current_data = this->ui->boxComboBox->currentText();
    int current_index = this->ui->boxComboBox->currentIndex();

    command.box_id = current_data.toStdString();
    gui_cmd_pub_->publish(command);

    std::cout << "Current index = " << current_index << std::endl; 
    if (current_index >= 0) {
        this->ui->boxComboBox->removeItem(current_index);
    }

    this->ui->box_latitude_value_label->setText("Unknown");
    this->ui->box_longitude_value_label->setText("Unknown");
    this->ui->box_altitude_value_label->setText("Unknown");
    this->ui->boxIdValueLabel->setText("Unknown");
    this->ui->boxNumberValueLabel->setText("Unknown");
    this->ui->boxTypeValueLabel->setText("Unknown");

    this->imageLabel_box->clear();
    this->batteryTextLabel_box->clear();
    this->batteryImageLabel_box->clear();

    this->ui->assignedDroneLabel->setText("None");
}

void MainWindow::on_removeDroneButton_pushButton_clicked()
{
    if(this->ui->droneComboBox->count() > 0)
    {
        QString current_data = this->ui->droneComboBox->currentText();
        int current_index = this->ui->droneComboBox->currentIndex();

        this->ui->droneComboBox->removeItem(current_index);

        this->ui->drone_altitude_value_label->setText("Unknown");;
        this->ui->drone_latitude_value_label->setText("Unknown");;
        this->ui->drone_longitude_value_label->setText("Unknown");;

        this->ui->droneIdLabel->setText("Unknown");
        this->ui->droneColorCodeLabel->setPalette(QPalette());

        this->ui->parentBoxLabel->setText("None");
    }
}

void MainWindow::on_arm_pushButton_clicked()
{
    std::cout << "Hello from Arm Button! Can not ARM since safety is of the essence!\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REQUEST_ARMING;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_takeoff_pushButton_clicked()
{
    std::cout << "Hello from Takeoff Button! Can not TAKEOFF since safety is of the essence!\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REQUEST_TAKEOFF;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_return_home_pushButton_clicked()
{
    std::cout << "Hello from Return Home Button! Can not Return Home since safety is of the essence!\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REQUEST_RETURN_HOME;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_land_pushButton_clicked()
{
    std::cout << "Hello from land button! Can not Land since safety is of the essence!\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REQUEST_LANDING;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_request_drone_status_pushButton_clicked()
{
    std::cout << "Hello from request status button!\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REQUEST_DRONE_STATUS;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_upload_path_pushButton_clicked()
{
    std::cout << "Hello from upload path button!\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::PATH_UPLOAD;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_add_box_pushButton_clicked()
{
    std::cout << "Hello from the add box button\n";
    dronehive_interfaces::msg::GuiCommand command;
    command.command = dronehive_interfaces::msg::GuiCommand::SEARCH_FOR_NEW_BOX;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_request_box_status_pushButton_clicked()
{
    std::cout << "Hello from the request box status button\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REQUEST_BOX_STATUS;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_zoomPlusButton_pushButton_clicked()
{
    std::cout << "Hello from the zoom in button\n";
    this->warehouseFrame->incrementScaleFactor();
}

void MainWindow::on_zoomOutButton_pushButton_clicked()
{
    std::cout << "Hello from the zoom in button\n";
    this->warehouseFrame->decrementScaleFactor();
}

// Slider slots
void MainWindow::on_zoom_in_out_slider_valueChanged(int value)
{
    std::cout << "Value of slider: " << float(value/10.0) << std::endl;
    this->warehouseFrame->setScaleFactor(float(value/10.0));
}

void MainWindow::on_boxComboBox_currentIndexChanged(int index)
{
    if(this->ui->boxComboBox->count() > 0 && !box_update_happened && !this->boxes.empty())
    {
        this->currentBoxIndex = index;

        float box_altitude = this->boxes[this->currentBoxIndex].get_box_landing_alt();
        float box_longitude = this->boxes[this->currentBoxIndex].get_box_landing_lon();
        float box_latitude = this->boxes[this->currentBoxIndex].get_box_landing_lat();
        std::string box_id = this->boxes[this->currentBoxIndex].get_box_id();
        int box_number = this->boxes[this->currentBoxIndex].get_box_number();
        int box_type = this->boxes[this->currentBoxIndex].get_box_type();
        std::string box_status = this->boxes[this->currentBoxIndex].get_box_status();

        this->ui->box_altitude_value_label->setText(QString::number(box_altitude, 'f', 4));
        this->ui->box_longitude_value_label->setText(QString::number(box_longitude, 'f', 4));
        this->ui->box_latitude_value_label->setText(QString::number(box_latitude, 'f', 4));
        this->ui->boxIdValueLabel->setText(QString::fromStdString(box_id));
        this->ui->boxNumberValueLabel->setText(QString::number(box_number));
        this->ui->boxStatusValueLabel->setText(QString::fromStdString(box_status));

        this->setBoxStateGraphics(box_status, 0.0f);

        if(box_type == BoxType::SLAVE)
            this->ui->boxTypeValueLabel->setText("Slave");
        else if(box_type == BoxType::MASTER)
            this->ui->boxTypeValueLabel->setText("Master");
    }
}

void MainWindow::on_droneComboBox_currentIndexChanged(int index)
{
    std::cout << "Drone combo box index changed\n";

    if(this->ui->droneComboBox->count() > 0 && !this->drones.empty())
    {
        float drone_altitude = this->drones[index].get_drone_alt();
        float drone_latitude = this->drones[index].get_drone_lat();
        float drone_longitude = this->drones[index].get_drone_lon();

        QString drone_id = QString::fromStdString(this->drones[index].get_drone_id());
        QColor drone_color = this->drones[index].get_drone_color();

        this->ui->drone_altitude_value_label->setText(QString::number(drone_altitude, 'f', 4));
        this->ui->drone_latitude_value_label->setText(QString::number(drone_latitude, 'f', 4));
        this->ui->drone_longitude_value_label->setText(QString::number(drone_longitude, 'f', 4));

        this->ui->droneIdLabel->setText(drone_id);

        this->ui->droneColorCodeLabel->setAutoFillBackground(true);
        QPalette palette = this->ui->droneColorCodeLabel->palette();
        palette.setColor(QPalette::Window, drone_color);
        this->ui->droneColorCodeLabel->setPalette(palette);

        this->setDroneGraphics(0.0f);
    }
}

void MainWindow::setBoxStateGraphics(std::string& box_status, float box_battery_level)
{
    if(boxStateFromString(box_status) == BoxState::EMPTY)
    {
        QPixmap pixmap("src/hmi/resources/box_empty.png");
        this->imageLabel_box->setPixmap(pixmap.scaled(QSize(400,400), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(boxStateFromString(box_status) == BoxState::OCCUPIED)
    {
        QPixmap pixmap("src/hmi/resources/box_full.png");
        this->imageLabel_box->setPixmap(pixmap.scaled(QSize(400,400), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    this->imageLabel_box->setAlignment(Qt::AlignCenter);
    this->imageLabel_box->setFixedSize(400, 400);
    this->imageLabel_box->move(50, 50); // <-- offset from top-left corner (x=20, y=20)
    this->imageLabel_box->show();

    if(box_battery_level <= 0.0f)
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_empty.png");
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 0.0f && box_battery_level < 20.0f)
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_20.png");
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 20.0f && box_battery_level < 40.0f)
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_40.png");
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 40.0f && box_battery_level < 60.0f)
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_60.png");
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 60.0f && box_battery_level < 80.0f)
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_80.png");
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_full.png");
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    QString battery_level = "Battery level: " + QString::number(box_battery_level, 'f', 1) + "%";
    this->batteryTextLabel_box->setText(battery_level);
    this->batteryTextLabel_box->setAlignment(Qt::AlignCenter);
    this->batteryTextLabel_box->setFixedSize(240, 50);
    this->batteryTextLabel_box->move(265, 15);

    this->batteryImageLabel_box->setAlignment(Qt::AlignCenter);
    this->batteryImageLabel_box->setFixedSize(50, 50);
    this->batteryImageLabel_box->move(450, 15);
    this->batteryImageLabel_box->raise();
    this->batteryImageLabel_box->show();
}

void MainWindow::setDroneGraphics(float box_battery_level)
{
    QPixmap pixmap("src/hmi/resources/hexa_copter.png");
    this->imageLabel_drone->setPixmap(pixmap.scaled(QSize(400,400), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    this->imageLabel_drone->setAlignment(Qt::AlignCenter);
    this->imageLabel_drone->setFixedSize(400, 400);
    this->imageLabel_drone->move(25, 50); // <-- offset from top-left corner (x=20, y=20)
    this->imageLabel_drone->show();

    if(box_battery_level <= 0.0f)
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_empty.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 0.0f && box_battery_level < 20.0f)
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_20.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 20.0f && box_battery_level < 40.0f)
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_40.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 40.0f && box_battery_level < 60.0f)
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_60.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 60.0f && box_battery_level < 80.0f)
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_80.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else
    {
        QPixmap pixmap("src/hmi/resources/icons/battery_full.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    QString battery_level = "Battery level: " + QString::number(box_battery_level, 'f', 1) + "%";
    this->batteryTextLabel_drone->setText(battery_level);
    this->batteryTextLabel_drone->setAlignment(Qt::AlignCenter);
    this->batteryTextLabel_drone->setFixedSize(250, 50);
    this->batteryTextLabel_drone->move(190, 15);

    this->batteryImageLabel_drone->setAlignment(Qt::AlignCenter);
    this->batteryImageLabel_drone->setFixedSize(50, 50);
    this->batteryImageLabel_drone->move(400, 15);
    this->batteryImageLabel_drone->raise();
    this->batteryImageLabel_drone->show();
}


void MainWindow::on_loadMapButton_pushButton_clicked()
{
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Open Map File",
          QDir::currentPath(),
          "Document files (*.json)"
    );

    this->warehouseFrame->loadWarehouseJson(filename);
}

void MainWindow::on_loadTrajectoryButton_pushButton_clicked()
{
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Open Trajectory File",
          QDir::currentPath(),
          "Document files (*.xml)"
    );

    this->warehouseFrame->loadTrajectoryXml(filename);
}


void MainWindow::on_clearVisualsButton_pushButton_clicked()
{
    this->warehouseFrame->clearVisuals();
}