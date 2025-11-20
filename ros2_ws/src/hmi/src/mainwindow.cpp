#include <iostream>
#include "mainwindow.h"
#include <QDebug>
#include <chrono>
#include <sstream>
#include <thread>
#include <QStringList>

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
    : QMainWindow(parent), ui(new Ui::MainWindow), master_exists(false), number_of_boxes(0), new_box_request(false), currentBoxIndex(0), master_found(true)
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

    this->list_widget = new QListWidget(this);
    this->ui->verticalLayout_3->addWidget(this->list_widget);

    connect(this->list_widget, &QListWidget::itemDoubleClicked,
        this, &MainWindow::onListItemDoubleClicked);

    auto *layout = new QHBoxLayout(this);
    layout->addWidget(scatterContainer, 1);

    // Create ROS2 node
    this->node_ = std::make_shared<rclcpp::Node>("gui_node");

	subscription_options_reentrant_.callback_group = node_->create_callback_group(rclcpp::CallbackGroupType::Reentrant);

    // Create publishers
    new_box_find_pub_ = node_->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/gui/new_box_confirm", qos_profiles::master_qos);
    gui_cmd_pub_ = node_->create_publisher<dronehive_interfaces::msg::GuiCommand>("/gui/command", qos_profiles::master_qos);
    response_pub_ = node_->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/gui/newbox_response", qos_profiles::master_qos);
    gui_add_remove_drone_pub_ = node_->create_publisher<dronehive_interfaces::msg::GuiAddNewDrone>("/gui/add_remove_drone", qos_profiles::master_qos);
    gui_trajectory_pub_ = node_->create_publisher<dronehive_interfaces::msg::GuiDroneTrajectoryUpload>("/gui/drone_trajectory", qos_profiles::master_qos);


    // Create subscribers
    heart_beat_sub_ = node_->create_subscription<std_msgs::msg::String>("/backend/heartbeat",qos_profiles::master_qos, std::bind(&MainWindow::onHeartBeatMessage, this, std::placeholders::_1));
    new_box_gui_sub_ = node_->create_subscription<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/backend/newbox",qos_profiles::master_qos, std::bind(&MainWindow::onNewBoxMessage, this, std::placeholders::_1));
    backend_msg_sub_ = node_->create_subscription<std_msgs::msg::String>("/backend/msg", qos_profiles::master_qos, std::bind(&MainWindow::onBackendMessage, this, std::placeholders::_1));

    node_->create_subscription<dronehive_interfaces::msg::BackendCommand>(
		"/backend/command",
		qos_profiles::master_qos,
		std::bind(&MainWindow::onBackendCommand, this, std::placeholders::_1),
		subscription_options_reentrant_
	);

    backend_box_status_sub_ = node_->create_subscription<dronehive_interfaces::msg::BoxFullStatus>(
		"/backend/box_status",
		qos_profiles::master_qos,
		std::bind(&MainWindow::onBackendBoxStatusMessage, this, std::placeholders::_1),
		subscription_options_reentrant_

	);

    drone_box_status_change_sub_ = node_->create_subscription<dronehive_interfaces::msg::OccupancyMessage>("/backend/drone_update_box_state", qos_profiles::master_qos, std::bind(&MainWindow::onDroneChangedBoxStatus, this, std::placeholders::_1));

    backEndManager = new BackEndManager(this);

    connect(backEndManager, &BackEndManager::backEndCrashed, this, &MainWindow::onBackEndCrashed);
    connect(backEndManager, &BackEndManager::backEndStopped, this, &MainWindow::onBackEndStopped);

    backEndManager->startBackend();

    spinTimer_ = new QTimer(this);
    connect(spinTimer_, &QTimer::timeout, this, [this]() {
        rclcpp::spin_some(node_);
    });
    spinTimer_->start(5);

    warehouseFrame = new WarehouseFrame();
    warehouseFrame->setStyleSheet("background-color:rgb(255,255,255)");
    warehouseFrame->setFrameShape(QFrame::Box);
    warehouseFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    warehouseFrame->setMinimumSize(100, 100); // optional safety

    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REQUEST_FULL_SYSTEM_STATUS;
    gui_cmd_pub_->publish(command);

    this->visuals2dOn = false;

    scatter3D = new QtDataVisualization::Q3DScatter();
    scatterContainer = QWidget::createWindowContainer(scatter3D);

    scatter3D->activeTheme()->setType(QtDataVisualization::Q3DTheme::ThemeQt);
    scatter3D->setShadowQuality(QtDataVisualization::QAbstract3DGraph::ShadowQualityNone);
    scatter3D->scene()->activeCamera()->setCameraPreset(QtDataVisualization::Q3DCamera::CameraPresetIsometricRight);

    scatter3D->axisX()->setTitle("X");
    scatter3D->axisY()->setTitle("Z");
    scatter3D->axisZ()->setTitle("Y");

    QtDataVisualization::Q3DCamera *camera = scatter3D->scene()->activeCamera();
    camera->setCameraPreset(QtDataVisualization::Q3DCamera::CameraPresetIsometricRight); // starting view
    camera->setZoomLevel(100.0f);     // optional starting zoom

    scatter3D->scene()->activeCamera()->setZoomLevel(100.0f);    // zoom
    scatter3D->scene()->activeCamera()->setCameraPreset(QtDataVisualization::Q3DCamera::CameraPresetFront);

    // You can show this container in your UI (e.g. side-by-side)
    scatterContainer = QWidget::createWindowContainer(scatter3D, this);
    scatterContainer->setMinimumSize(100, 100);
    scatterContainer->setFocusPolicy(Qt::StrongFocus);

    this->ui->visLayout->addWidget(scatterContainer, 1);
    this->ui->visualizationButton->setText("2D Visualization");

    this->resume_trajectory_status = true;
}

MainWindow::~MainWindow()
{
    this->cleanup();
}

void MainWindow::cleanup()
{
    delete this->warehouseFrame;
    this->warehouseFrame = nullptr;

    delete this->imageLabel_box;
    delete this->imageLabel_drone;
    delete this->batteryImageLabel_box;
    delete this->batteryTextLabel_box;
    delete this->batteryImageLabel_drone;
    delete this->batteryTextLabel_drone;

    this->backEndManager->stopBackend();

    delete this->backEndManager;
    this->backEndManager = nullptr;
        // Stop timers first
    if (spinTimer_) {
        spinTimer_->stop();
        spinTimer_->disconnect();  // disconnect all signals
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    delete this->spinTimer_;
    delete this->ui;

    const auto existingSeries = scatter3D->seriesList();
    for (auto *series : existingSeries) {
        scatter3D->removeSeries(series);
        delete series;
    }

    const auto existingItems = scatter3D->customItems();
    for (auto *item : existingItems) {
        scatter3D->removeCustomItem(item);
        delete item;
    }

    delete this->scatter3D;
    delete this->trajectorySeries;
    delete this->scatterContainer;

    rclcpp::shutdown();
}

void MainWindow::update3DTrajectories(std::vector<DroneVis> drones)
{
    if (!scatter3D)
        return;

    // --- Remove old series manually ---
    const auto existingSeries = scatter3D->seriesList();
    for (auto *series : existingSeries)
        scatter3D->removeSeries(series);

    // --- Remove old custom items manually ---
    const auto existingItems = scatter3D->customItems();
    for (auto *item : existingItems)
        scatter3D->removeCustomItem(item);

    // --- Rebuild trajectory for each drone ---
    for (DroneVis drone : drones)
    {
        if (!drone.display || drone.drone_waypoints.empty())
            continue;

        // Create scatter points (waypoints)
        auto *series = new QtDataVisualization::QScatter3DSeries();
        series->setMesh(QtDataVisualization::QAbstract3DSeries::MeshSphere);
        series->setItemSize(0.15f);
        series->setBaseColor(drone.drone_color);

        auto *dataArray = new QtDataVisualization::QScatterDataArray;
        dataArray->resize(drone.drone_waypoints.size());

        for (int i = 0; i < drone.drone_waypoints.size(); ++i)
        {
            const auto &wp = drone.drone_waypoints[i];
            (*dataArray)[i].setPosition(QVector3D(wp.x(), wp.z(), wp.y()));
        }

        series->dataProxy()->resetArray(dataArray);
        scatter3D->addSeries(series);
    }
}

void MainWindow::onDroneChangedBoxStatus(const dronehive_interfaces::msg::OccupancyMessage::SharedPtr msg)
{
    std::cout << "Got occupancy message due to drone changing its box\n";

    std::string box_id = msg->box_id;
    std::string drone_id = msg->drone_id;
    bool occupancy = msg->occupancy;

    int box_index = this->ui->boxComboBox->findText(QString::fromStdString(box_id));
    int drone_index = this->ui->droneComboBox->findText(QString::fromStdString(drone_id));

    int old_box_index = -1;

    if(box_index >= 0 && drone_index >= 0)
    {
        for(int i = 0; i < this->boxes.size(); i++)
        {
            if(this->boxes[i].get_assigned_drone_id() == drone_id)
            {
                old_box_index = i;
                break;
            }
        }

        if(old_box_index >= 0)
        {
            this->boxes[old_box_index].set_assigned_drone_id("None");
            this->boxes[old_box_index].set_box_status(boxStatusToString(BoxState::EMPTY));
        }

        this->boxes[box_index].set_assigned_drone_id(drone_id);
        this->boxes[box_index].set_box_status(boxStatusToString(BoxState::OCCUPIED));
        this->drones[drone_index].set_parent_box_id(box_id);

        this->ui->drone_altitude_value_label->setText(QString::number(this->boxes[box_index].get_box_landing_alt(), 'f', 4));
        this->ui->drone_latitude_value_label->setText(QString::number(this->boxes[box_index].get_box_landing_lat(), 'f', 4));
        this->ui->drone_longitude_value_label->setText(QString::number(this->boxes[box_index].get_box_landing_lon(), 'f', 4));

        if(occupancy)
            this->ui->boxStatusValueLabel->setText(QString::fromStdString(boxStatusToString(BoxState::OCCUPIED)));
        else
            this->ui->boxStatusValueLabel->setText(QString::fromStdString(boxStatusToString(BoxState::EMPTY)));
    }
}

void MainWindow::onBackendBoxStatusMessage(const dronehive_interfaces::msg::BoxFullStatus::SharedPtr msg)
{
	std::stringstream ss;
    ss << "Got box id : " << msg->box_id << std::endl;
	RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "%s:%d => %s", __FILE__, __LINE__, ss.str().c_str());
	ss.clear();

    if(msg->box_id.empty()) return;

    ss << msg->box_id << ", " << msg->box_status << std::endl;
	RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "%s:%d => %s", __FILE__, __LINE__, ss.str().c_str());
	ss.clear();
    std::string box_id = msg->box_id;
    std::string drone_id = msg->drone_id;
    std::string box_status =  msg->box_status;

    ss << "Box ID = " << box_id << ", drone_id = " << drone_id << ", box_status = " << box_status << std::endl;
	RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "%s:%d => %s", __FILE__, __LINE__, ss.str().c_str());
	ss.clear();

    float box_lat = msg->landing_pos.lat;
    float box_lon = msg->landing_pos.lon;
    float box_elv = msg->landing_pos.elv;

    bool box_exists = false;
    int box_index = 0;

    for(int i = 0; i < this->boxes.size(); i++)
    {
        if(boxes[i].get_box_id() == box_id)
        {
            std::cout << "Box exists\n";
            box_exists = true;
            box_index = i;
            break;
        }
    }

    if(!box_exists)
    {
        std::cout << "Creating a new box\n";
        QString id = QString::fromStdString(msg->box_id);
        if (ui->boxComboBox) {
            ui->boxComboBox->addItem(id);
        }
        Coordinates coord{box_lat, box_lon, box_elv};
        if(isMaster())
        {
            Box box(BoxType::MASTER, coord, box_id, box_status, this->boxes.size() + 1);
            this->boxes.push_back(box);
        }
        else{
            Box box(BoxType::SLAVE, coord, box_id, box_status, this->boxes.size() + 1);
            this->boxes.push_back(box);
        }
    }
    else
    {
        boxes[box_index].set_assigned_drone_id(drone_id);
        boxes[box_index].set_box_status(box_status);
        boxes[box_index].set_box_landing_alt(box_elv);
        boxes[box_index].set_box_landing_lat(box_lat);
        boxes[box_index].set_box_landing_lon(box_lon);
    }

    if(!drone_id.empty())
    {
        bool drone_exists = false;
        int drone_curr_id = 0;

        for(int j = 0; j < drones.size(); j++)
        {
            if(drone_id == drones[j].get_drone_id())
            {
                drone_exists = true;
                drone_curr_id = j;
                break;
            }
        }

        if(!drone_exists)
        {
            std::cout << "Creating drone\n";
            Coordinates coord{box_lat, box_lon, box_elv};
            Drone drone(DroneType::HexaCopter, coord, drone_id, Drone::randomDroneColor(), box_id);
            drones.push_back(drone);
            this->ui->droneComboBox->addItem(QString::fromStdString(drone_id));

            this->boxes[this->boxes.size() - 1].set_assigned_drone_id(drone_id);
        }
        else
        {
            std::cout << "Drone exists\n";
            drones[drone_curr_id].set_drone_alt(box_elv);
            drones[drone_curr_id].set_drone_lat(box_lat);
            drones[drone_curr_id].set_drone_lon(box_lon);
        }
    }

    std::cout << this->ui->boxComboBox->currentText().toStdString() << ", " << box_id << std::endl;

    if(this->ui->boxComboBox->currentText().toStdString() == box_id)
    {
        std::cout << "updating visualizations for " << this->ui->boxComboBox->currentText().toStdString() << " based on id " << box_id << std::endl;
        if(drone_id.empty())
            this->ui->assignedDroneLabel->setText(QString::fromStdString("None"));
        else
            this->ui->assignedDroneLabel->setText(QString::fromStdString(drone_id));

        this->ui->boxIdValueLabel->setText(QString::fromStdString(box_id));

        if(isMaster())
            this->ui->boxTypeValueLabel->setText("Master");
        else
            this->ui->boxTypeValueLabel->setText("Slave");

        std::cout << "New  box status = " << box_status << std::endl;

        this->ui->boxNumberValueLabel->setText(QString::number(this->boxes.size()));
        this->ui->boxStatusValueLabel->setText(QString::fromStdString(box_status));
        this->ui->box_latitude_value_label->setText(QString::number(box_lat, 'f', 4));
        this->ui->box_longitude_value_label->setText(QString::number(box_lon, 'f', 4));
        this->ui->box_altitude_value_label->setText(QString::number(box_elv, 'f', 4));

        this->setBoxStateGraphics(box_status, 0.0f);
    }
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
    // RCLCPP_INFO(rclcpp::get_logger("MainWindow"), "Got heartbeat: '%s'", msg->data.c_str());
    backEndManager->setMissedHeartBeat(0);
}

void MainWindow::onNewBoxMessage(const dronehive_interfaces::msg::BoxSetupConfirmationMessage::SharedPtr msg)
{
    std::cout << "Got new BOX request\n";
    std::cout << "Got box id: " << msg->box_id << std::endl;

    if(msg->box_id.empty()) return;

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

        if(isMaster())
        {
            std::cout << "Adding a MASTER box\n";
            Box box(BoxType::MASTER, coord, return_msg.box_id, boxStatusToString(BoxState::EMPTY) ,this->boxes.size() + 1);
            this->boxes.push_back(box);
        }
        else{
            std::cout << "Adding a SLAVE box\n";
            Box box(BoxType::SLAVE, coord, return_msg.box_id, boxStatusToString(BoxState::EMPTY) ,this->boxes.size() + 1);
            this->boxes.push_back(box);
        }

        this->ui->boxComboBox->addItem(QString::fromStdString(return_msg.box_id));

        auto command = dronehive_interfaces::msg::GuiCommand();
        command.command = dronehive_interfaces::msg::GuiCommand::REQUEST_BOX_STATUS;
        gui_cmd_pub_->publish(command);
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

}

void MainWindow::onBackEndCrashed()
{
    std::cout << "Hello from crash\n";
    this->backEndManager->stopBackend();

    delete this->backEndManager;
    this->backEndManager = nullptr;
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

    FlightCreationDialog dialog(this);

    if(dialog.exec() == QDialog::Rejected) return;
    else
    {
        int state = dialog.getState();
        int current_drone_index = this->ui->droneComboBox->currentIndex();

        if(state == PathPlanStates::CREATE_PLAN)
        {
            std::cout << "Crating plan" << std::endl;

            if(drones.empty())
                FlightDialog flightPlanDialog(this);
            else
            {
                FlightDialog flightPlanDialog(this, drones[current_drone_index].get_drone_color(), drones[current_drone_index].get_drone_id());
                if(flightPlanDialog.exec() == QDialog::Rejected) return;
                else
                {
                    std::cout << "Accepted" << std::endl;
                    // TO-DO add publisher sending the selected preset path plan
                    auto waypoints = flightPlanDialog.getWaypoints();

                    std::cout << "Number of waypoints: " << waypoints.size() << std::endl;

                    if(waypoints.empty()) return;

                    std::vector<dronehive_interfaces::msg::PositionMessage> pos_messages;

                    for(auto waypoint : waypoints)
                    {
                        dronehive_interfaces::msg::PositionMessage pos_msg;
                        pos_msg.elv = waypoint.z();
                        pos_msg.lat = waypoint.x();
                        pos_msg.lon = waypoint.y();
                        pos_messages.push_back(pos_msg);
                    }

                    dronehive_interfaces::msg::GuiDroneTrajectoryUpload msg;
                    msg.drone_id =  drones[current_drone_index].get_drone_id();
                    msg.waypoints = pos_messages;

                    this->gui_trajectory_pub_->publish(msg);
                }
            }

        }
        else if(state == PathPlanStates::ACCEPTED)
        {
            std::cout << "Accepted" << std::endl;
            // TO-DO add publisher sending the selected preset path plan
            auto waypoints = dialog.getWaypoints();

            std::cout << "Waypoint size: " << waypoints.size() << std::endl;

            if(waypoints.empty()) return;

            std::vector<dronehive_interfaces::msg::PositionMessage> pos_messages;

            for(auto waypoint : waypoints)
            {
                dronehive_interfaces::msg::PositionMessage pos_msg;
                pos_msg.elv = waypoint.z();
                pos_msg.lat = waypoint.x();
                pos_msg.lon = waypoint.y();
                pos_messages.push_back(pos_msg);
            }

            dronehive_interfaces::msg::GuiDroneTrajectoryUpload msg;
            msg.drone_id =  drones[current_drone_index].get_drone_id();
            msg.waypoints = pos_messages;

            this->gui_trajectory_pub_->publish(msg);
        }
    }
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

    if(!this->boxes[current_index].get_assigned_drone_id().empty() && !drones.empty())
    {
        std::cout << "Removing drone\n";
        QString child_drone_id = QString::fromStdString(this->boxes[current_index].get_assigned_drone_id());

        int drone_index = this->ui->droneComboBox->findText(child_drone_id);

        this->ui->droneComboBox->removeItem(drone_index);
        this->drones.erase(this->drones.begin() + drone_index);

        if(this->ui->droneComboBox->count() <= 0)
        {
            this->ui->drone_altitude_value_label->setText("Unknown");;
            this->ui->drone_latitude_value_label->setText("Unknown");;
            this->ui->drone_longitude_value_label->setText("Unknown");;

            this->ui->droneIdLabel->setText("Unknown");

            QPalette palette = this->ui->droneColorCodeLabel->palette();
            palette.setColor(QPalette::Window, Qt::white);
            this->ui->droneColorCodeLabel->setPalette(palette);

            this->ui->parentBoxLabel->setText("None");

            this->imageLabel_drone->clear();
            this->batteryTextLabel_drone->clear();
            this->batteryImageLabel_drone->clear();
        }
        else if(!drones.empty())
        {
            QString current_data = this->ui->droneComboBox->currentText();
            int current_index = this->ui->droneComboBox->currentIndex();

            this->ui->drone_altitude_value_label->setText(QString::number(this->drones[current_index].get_drone_alt(), 'f', 4));;
            this->ui->drone_latitude_value_label->setText(QString::number(this->drones[current_index].get_drone_lat(), 'f', 4));;
            this->ui->drone_longitude_value_label->setText(QString::number(this->drones[current_index].get_drone_lon(), 'f', 4));;

            this->ui->droneIdLabel->setText(QString::fromStdString(this->drones[current_index].get_drone_id()));

            QPalette palette = this->ui->droneColorCodeLabel->palette();
            palette.setColor(QPalette::Window, this->drones[current_index].get_drone_color());
            this->ui->droneColorCodeLabel->setPalette(palette);

            this->ui->parentBoxLabel->setText(QString::fromStdString(this->drones[current_index].get_parent_box_id()));

            this->setDroneGraphics(0.0f);
        }
    }

    this->boxes.erase(this->boxes.begin() + current_index);
    command.box_id = current_data.toStdString();
    gui_cmd_pub_->publish(command);

    std::cout << "Current index = " << current_index << std::endl;
    if (current_index >= 0) {
        this->ui->boxComboBox->removeItem(current_index);

        if(this->ui->boxComboBox->count() <= 0)
        {
            this->ui->box_latitude_value_label->setText("Unknown");
            this->ui->box_longitude_value_label->setText("Unknown");
            this->ui->box_altitude_value_label->setText("Unknown");
            this->ui->boxIdValueLabel->setText("Unknown");
            this->ui->boxNumberValueLabel->setText("Unknown");
            this->ui->boxTypeValueLabel->setText("Unknown");
            this->ui->boxStatusValueLabel->setText("Unknown");

            this->imageLabel_box->clear();
            this->batteryTextLabel_box->clear();
            this->batteryImageLabel_box->clear();

            this->ui->assignedDroneLabel->setText("None");
        }
        else
        {
            QString current_data = this->ui->boxComboBox->currentText();
            int current_index = this->ui->boxComboBox->currentIndex();

            this->ui->box_altitude_value_label->setText(QString::number(this->boxes[current_index].get_box_landing_alt(), 'f', 4));
            this->ui->box_latitude_value_label->setText(QString::number(this->boxes[current_index].get_box_landing_lat(), 'f', 4));
            this->ui->box_longitude_value_label->setText(QString::number(this->boxes[current_index].get_box_landing_lon(), 'f', 4));

            this->ui->boxIdValueLabel->setText(QString::fromStdString(this->boxes[current_index].get_box_id()));
            this->ui->boxNumberValueLabel->setText(QString::number(this->boxes[current_index].get_box_number()));

            this->ui->assignedDroneLabel->setText(QString::fromStdString(this->boxes[current_index].get_assigned_drone_id()));

            std::string box_status = this->boxes[current_index].get_box_status();

            this->ui->boxStatusValueLabel->setText(QString::fromStdString(box_status));

            this->setBoxStateGraphics(box_status, 0.0f);
        }
    }
}

void MainWindow::on_removeDroneButton_pushButton_clicked()
{
    if(this->ui->droneComboBox->count() > 0)
    {
        QString current_data = this->ui->droneComboBox->currentText();
        int current_index = this->ui->droneComboBox->currentIndex();

        auto box_id = this->drones[current_index].get_parent_box_id();
        int box_index = 0;

        for(int i = 0; i < this->boxes.size(); i++)
        {
            if(boxes[i].get_box_id() == box_id)
            {
                box_index = i;
                std::cout << "Box index = " << box_index << std::endl;
                break;
            }
        }

        bool parent_box_selected = false;
        if(this->ui->boxComboBox->currentText().toStdString() == box_id)
        {
            std::cout << "Drone has selected box" << std::endl;
            parent_box_selected = true;
        }

        this->boxes[box_index].set_assigned_drone_id("");
        this->boxes[box_index].set_box_status(boxStatusToString(BoxState::EMPTY));

        dronehive_interfaces::msg::GuiAddNewDrone msg;
        msg.drone_id = "";
        msg.box_id = box_id;
        this->gui_add_remove_drone_pub_->publish(msg);

        this->ui->droneComboBox->removeItem(current_index);

        this->drones.erase(this->drones.begin() + current_index);

        if(this->ui->droneComboBox->count() <= 0)
        {
            this->ui->drone_altitude_value_label->setText("Unknown");;
            this->ui->drone_latitude_value_label->setText("Unknown");;
            this->ui->drone_longitude_value_label->setText("Unknown");;

            this->ui->droneIdLabel->setText("Unknown");
            QPalette palette = this->ui->droneColorCodeLabel->palette();
            palette.setColor(QPalette::Window, Qt::white);
            this->ui->droneColorCodeLabel->setPalette(palette);

            this->ui->parentBoxLabel->setText("None");

            this->imageLabel_drone->clear();
            this->batteryTextLabel_drone->clear();
            this->batteryImageLabel_drone->clear();
        }
        else if(!drones.empty())
        {
            QString current_data = this->ui->droneComboBox->currentText();
            int current_index = this->ui->droneComboBox->currentIndex();
            this->ui->drone_altitude_value_label->setText(QString::number(this->drones[current_index].get_drone_alt(), 'f', 4));;
            this->ui->drone_latitude_value_label->setText(QString::number(this->drones[current_index].get_drone_lat(), 'f', 4));;
            this->ui->drone_longitude_value_label->setText(QString::number(this->drones[current_index].get_drone_lon(), 'f', 4));;
            this->ui->droneIdLabel->setText(QString::fromStdString(this->drones[current_index].get_drone_id()));
            QPalette palette = this->ui->droneColorCodeLabel->palette();
            palette.setColor(QPalette::Window, this->drones[current_index].get_drone_color());
            this->ui->droneColorCodeLabel->setPalette(palette);
            this->ui->parentBoxLabel->setText(QString::fromStdString(this->drones[current_index].get_parent_box_id()));
            this->setDroneGraphics(0.0f);
        }

        if(parent_box_selected)
        {
            std::cout << "Resetting visualization" << std::endl;
            this->ui->assignedDroneLabel->setText("None");
            this->ui->boxStatusValueLabel->setText(QString::fromStdString(this->boxes[box_index].get_box_status()));
            auto box_status = this->boxes[box_index].get_box_status();
            this->setBoxStateGraphics(box_status, 0.0f);

            std::cout << "Box id = " << boxes[box_index].get_assigned_drone_id()  << ", box status = " << boxes[box_index].get_box_status() << std::endl;
        }
    }
}


void MainWindow::on_boxComboBox_currentIndexChanged(int index)
{
    std::cout << "Box combo box value changed\n";

    if(this->ui->boxComboBox->count() > 0 && !this->boxes.empty())
    {
        std::string box_status = this->boxes[index].get_box_status();

        this->ui->box_altitude_value_label->setText(QString::number(this->boxes[index].get_box_landing_alt(), 'f', 4));
        this->ui->box_longitude_value_label->setText(QString::number(this->boxes[index].get_box_landing_lon(), 'f', 4));
        this->ui->box_latitude_value_label->setText(QString::number(this->boxes[index].get_box_landing_lat(), 'f', 4));
        this->ui->boxIdValueLabel->setText(QString::fromStdString(this->boxes[index].get_box_id()));
        this->ui->boxNumberValueLabel->setText(QString::number(this->boxes[index].get_box_number()));
        this->ui->boxStatusValueLabel->setText(QString::fromStdString(this->boxes[index].get_box_status()));
        this->ui->assignedDroneLabel->setText(QString::fromStdString(this->boxes[index].get_assigned_drone_id()));

        std::cout << "Index = " << index << ", box_status = " << box_status << std::endl;

        this->setBoxStateGraphics(box_status, 0.0f);

        int box_type = this->boxes[index].get_box_type();

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

        this->ui->parentBoxLabel->setText(QString::fromStdString(this->drones[index].get_parent_box_id()));

        this->setDroneGraphics(0.0f);
    }
}

void MainWindow::setBoxStateGraphics(std::string& box_status, float box_battery_level)
{
    if(boxStateFromString(box_status) == BoxState::EMPTY)
    {
        QPixmap pixmap(":/resources/box_empty.png");
        this->imageLabel_box->setPixmap(pixmap.scaled(QSize(400,400), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(boxStateFromString(box_status) == BoxState::OCCUPIED)
    {
        QPixmap pixmap(":/resources/box_full.png");
        this->imageLabel_box->setPixmap(pixmap.scaled(QSize(400,400), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    this->imageLabel_box->setAlignment(Qt::AlignCenter);
    this->imageLabel_box->setFixedSize(400, 400);
    this->imageLabel_box->move(50, 50); // <-- offset from top-left corner (x=20, y=20)
    this->imageLabel_box->show();

    if(box_battery_level <= 0.0f)
    {
        QPixmap pixmap(":/resources/icons/battery_empty.png");
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 0.0f && box_battery_level < 20.0f)
    {
        QPixmap pixmap(":/resources/icons/battery_20.png");
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 20.0f && box_battery_level < 40.0f)
    {
        QPixmap pixmap((":/resources/icons/battery_40.png"));
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 40.0f && box_battery_level < 60.0f)
    {
        QPixmap pixmap((":/resources/icons/battery_60.png"));
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(box_battery_level >= 60.0f && box_battery_level < 80.0f)
    {
        QPixmap pixmap((":/resources/battery_80.png"));
        this->batteryImageLabel_box->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else
    {
        QPixmap pixmap((":/resources/battery_full.png"));
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

void MainWindow::setDroneGraphics(float drone_battery_level)
{
    QPixmap pixmap(":/resources/hexa_copter.png");

    this->imageLabel_drone->setPixmap(pixmap.scaled(QSize(400,400), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    this->imageLabel_drone->setAlignment(Qt::AlignCenter);
    this->imageLabel_drone->setFixedSize(400, 400);
    this->imageLabel_drone->move(25, 50); // <-- offset from top-left corner (x=20, y=20)
    this->imageLabel_drone->show();

    if(drone_battery_level <= 0.0f)
    {
        QPixmap pixmap(":/resources/icons/battery_empty.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(drone_battery_level >= 0.0f && drone_battery_level < 20.0f)
    {
        QPixmap pixmap(":/resources/icons/battery_20.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(drone_battery_level >= 20.0f && drone_battery_level < 40.0f)
    {
        QPixmap pixmap(":/resources/icons/battery_40.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(drone_battery_level >= 40.0f && drone_battery_level < 60.0f)
    {
        QPixmap pixmap(":/resources/icons/battery_60.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(drone_battery_level >= 60.0f && drone_battery_level < 80.0f)
    {
        QPixmap pixmap(":/resources/icons/battery_80.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else
    {
        QPixmap pixmap(":/resources/icons/battery_full.png");
        this->batteryImageLabel_drone->setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    QString battery_level = "Battery level: " + QString::number(drone_battery_level, 'f', 1) + "%";
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

void MainWindow::onListItemDoubleClicked(QListWidgetItem *item)
{
    int curr_list_widget_index = this->list_widget->row(item);
    std::cout << "Item at index = " << curr_list_widget_index << "was selected" << std::endl;

    if(warehouseFrame == nullptr) return;

    bool oldValue = warehouseFrame->isDisplaySet(curr_list_widget_index);

    this->warehouseFrame->setDisplayByIndex(curr_list_widget_index, !oldValue);

    ColorListWidget *cw = qobject_cast<ColorListWidget*>(this->list_widget->itemWidget(item));
    if (cw)
    {
        cw->setEnabled(!oldValue);
        cw->setChecked(!oldValue);
    }

    if(!this->visuals2dOn)
        this->update3DTrajectories(this->warehouseFrame->getDroneVisData());
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

    for (int i = 0; i < this->list_widget->count(); ++i)
    {
        QWidget *w = this->list_widget->itemWidget(this->list_widget->item(i));
        delete w;
    }

    this->list_widget->clear();

    auto drone_data = this->warehouseFrame->getDroneVisData();

    for(auto drone : drone_data)
    {
        QColor drone_color = drone.drone_color;
        QString drone_id = QString::fromStdString(drone.drone_id);

        QListWidgetItem* item = new QListWidgetItem(this->list_widget);

        ColorListWidget* widget = new ColorListWidget(this->list_widget, drone_id, drone_color);

        item->setSizeHint(widget->sizeHint());
        this->list_widget->addItem(item);
        this->list_widget->setItemWidget(item, widget);
    }

    if(this->visuals2dOn)
        this->warehouseFrame->update();
    else
        this->update3DTrajectories(drone_data);
}

void MainWindow::on_clearVisualsButton_pushButton_clicked()
{
    this->warehouseFrame->clearVisuals();

    for(auto series : this->scatter3D->seriesList())
        this->scatter3D->removeSeries(series);

    for (int i = 0; i < this->list_widget->count(); ++i)
    {
        QWidget *w = this->list_widget->itemWidget(this->list_widget->item(i));
        delete w;
    }

    this->list_widget->clear();
}

void MainWindow::on_restartButton_pushButton_clicked()
{
    if(this->backEndManager == nullptr)
    {
        this->backEndManager = new BackEndManager(this);
        this->backEndManager->startBackend();
    }
    else
    {
        this->backEndManager->stopBackend();

        delete backEndManager;
        backEndManager = nullptr;
        this->backEndManager = new BackEndManager(this);

        this->backEndManager->startBackend();
    }
}

bool MainWindow::isMaster()
{
    if(this->master_found)
    {
        this->master_found = false;
        return true;
    }

    return this->master_found;
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

void MainWindow::on_resumeTrajectoryButton_pushButton_clicked()
{
    std::cout << "Hello from resume trajectory button" << std::endl;

    this->resume_trajectory_status = (!this->resume_trajectory_status);

    if(this->resume_trajectory_status)
    {
        QIcon icon(":/resources/icons/pause.png");
        this->ui->resumeTrajectoryButton->setIcon(icon);
        this->ui->resumeTrajectoryButton->setText("Stop\nTrajectory");
    }
    else{
        QIcon icon(":/resources/icons/resume.png");
        this->ui->resumeTrajectoryButton->setIcon(icon);
        this->ui->resumeTrajectoryButton->setText("Resume\nTrajectory");
    }
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

void MainWindow::on_addDroneButton_pushButton_clicked()
{
    std::cout << "Hello from the add box button\n";

    if(this->boxes.empty()) return;

    QString box_id = this->ui->boxComboBox->currentText();
    int box_index = this->ui->boxComboBox->currentIndex();

    if(!this->boxes[box_index].get_assigned_drone_id().empty()) return;

    AddDroneDialog dialog(this, box_id);

    if(dialog.exec() == QDialog::Rejected) return;
    else
    {
        std::string drone_id = dialog.getDroneId();
        this->boxes[box_index].set_assigned_drone_id(drone_id);
        this->boxes[box_index].set_box_status("OCCUPIED");


        Coordinates coords{this->boxes[box_index].get_box_landing_lat(),this->boxes[box_index].get_box_landing_lon(),this->boxes[box_index].get_box_landing_alt()};

        Drone drone(DroneType::HexaCopter, coords, drone_id, Drone::randomDroneColor(), box_id.toStdString());

        this->drones.push_back(drone);

        this->ui->boxStatusValueLabel->setText(QString::fromStdString(this->boxes[box_index].get_box_status()));
        this->ui->droneComboBox->addItem(QString::fromStdString(drone_id));
        this->ui->assignedDroneLabel->setText(QString::fromStdString(drone_id));

        auto box_status = this->boxes[box_index].get_box_status();
        this->setBoxStateGraphics(box_status, 0.0f);

        dronehive_interfaces::msg::GuiAddNewDrone msg;
        msg.drone_id = drone_id;
        msg.box_id = box_id.toStdString();
        this->gui_add_remove_drone_pub_->publish(msg);
    }
}

void MainWindow::on_request_box_status_pushButton_clicked()
{
    std::cout << "Hello from the request box status button\n";
    auto command = dronehive_interfaces::msg::GuiCommand();
    command.command = dronehive_interfaces::msg::GuiCommand::REQUEST_BOX_STATUS;
    if(this->ui->boxComboBox->count() > 0)
        command.box_id = this->ui->boxComboBox->currentText().toStdString();
    else
        command.box_id = "";
    std::cout << "Box id  to update: " << command.box_id << std::endl;
    gui_cmd_pub_->publish(command);
}

void MainWindow::on_zoomPlusButton_pushButton_clicked()
{
    std::cout << "Hello from the zoom in button\n";
    if(this->visuals2dOn)
        this->warehouseFrame->incrementScaleFactor();
    else
    {
        auto scale_factor = this->warehouseFrame->getScaleFactor();
        auto zoom = scatter3D->scene()->activeCamera()->zoomLevel();
        scatter3D->scene()->activeCamera()->setZoomLevel(zoom + 10*scale_factor);    // zoom
    }
}

void MainWindow::on_zoomOutButton_pushButton_clicked()
{
    std::cout << "Hello from the zoom in button\n";
    if(this->visuals2dOn)
        this->warehouseFrame->decrementScaleFactor();
    else
    {
        auto scale_factor = this->warehouseFrame->getScaleFactor();
        auto zoom = scatter3D->scene()->activeCamera()->zoomLevel();
        scatter3D->scene()->activeCamera()->setZoomLevel(zoom - 10*scale_factor);    // zoom
    }
}

// Slider slots
void MainWindow::on_zoom_in_out_slider_valueChanged(int value)
{
    std::cout << "Value of slider: " << float(value/10.0f) << std::endl;

    if(this->visuals2dOn)
        this->warehouseFrame->setScaleFactor(float(value/10.0f));
    else
    {
        float zoomFactor = float(value) / 10.0f;
        float minZoom = 10.0f;
        float maxZoom = 500.0f;

        float zoomLevel = minZoom + (maxZoom - minZoom) * (zoomFactor / 10.0f);
        scatter3D->scene()->activeCamera()->setZoomLevel(zoomLevel);
    }
}

 void MainWindow::on_visualizationButton_pushButton_clicked()
 {
    if(this->visuals2dOn)
    {
        // set 3D visuals for map
        this->visuals2dOn = false;
        this->ui->visualizationButton->setText("2D Visualization");

        this->warehouseFrame->hide();
        this->ui->visLayout->removeWidget(warehouseFrame);
        this->ui->visLayout->addWidget(scatterContainer);

        scatterContainer->show();

        std::vector<DroneVis> drone_data = this->warehouseFrame->getDroneVisData();
        this->update3DTrajectories(drone_data);
    }
    else
    {
        // set 2D visuals for map
        this->visuals2dOn = true;
        this->ui->visualizationButton->setText("3D Visualization");

        scatterContainer->hide();
        this->ui->visLayout->removeWidget(scatterContainer);
        this->ui->visLayout->addWidget(warehouseFrame);

        this->warehouseFrame->show();

        this->warehouseFrame->update();
    }
 }


