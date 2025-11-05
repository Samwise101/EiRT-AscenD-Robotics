#include <iostream>
#include <app.h>

namespace qos_profiles
{
    static const rclcpp::QoS master_qos = [] {
        rclcpp::QoS qos(rclcpp::KeepLast(1));
        qos.reliability(RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
        qos.durability(RMW_QOS_POLICY_DURABILITY_VOLATILE);
        return qos;
    }();
}

App::App() : Node("app_node") 
{
    this->count = 0;
    this->box_timeout_timer = 0;
    this->new_box_message_arrived = false;
    this->new_box_confirm = false;
    this->new_search_retry = false;
    this->get_system_status_request_appeared = false;
    this->get_box_status_request_appeared = false;
    this->get_drone_status_request_appeared = false;
    this->drone_return_home_request_appeared = false;
    this->drone_landing_request_appeared = false;

    this->pending_box_responses_ = 0;

    this->to_gui_heart_pub_ = this->create_publisher<std_msgs::msg::String>("/backend/heartbeat", qos_profiles::master_qos);
    this->to_gui_msg_pub_ = this->create_publisher<std_msgs::msg::String>("/backend/msg", qos_profiles::master_qos);
    this->to_gui_command_pub_ = this->create_publisher<dronehive_interfaces::msg::BackendCommand>("/backend/command", qos_profiles::master_qos);
    this->to_box_new_box_confirmation_pub = this->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/dronehive/new_box_confirmed",qos_profiles::master_qos);
    this->box_status_pub_ = this->create_publisher<dronehive_interfaces::msg::BoxFullStatus>("/backend/box_status", qos_profiles::master_qos);
    this->box_msg_pub_ = this->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/backend/newbox",qos_profiles::master_qos);
    this->box_deinit_pub_ = this->create_publisher<std_msgs::msg::String>("/dronehive/deinitialise_box", qos_profiles::master_qos);
    this->notify_gui_on_ccupancy_change_pub_ = this->create_publisher<dronehive_interfaces::msg::OccupancyMessage>("/backend/drone_update_box_state", qos_profiles::master_qos);

    gui_command_sub_ = this->create_subscription<dronehive_interfaces::msg::GuiCommand>("/gui/command", qos_profiles::master_qos, std::bind(&App::onGuiCommand, this, std::placeholders::_1));

    new_box_sub_ = this->create_subscription<dronehive_interfaces::msg::BoxBroadcastMessage>(
        "/dronehive/new_box", qos_profiles::master_qos, std::bind(&App::onBoxMessage, this, std::placeholders::_1)
    );

    gui_box_confirm_sub_ = this->create_subscription<dronehive_interfaces::msg::BoxSetupConfirmationMessage>(
        "/gui/newbox_response", qos_profiles::master_qos, std::bind(&App::onNewBoxGuiConfirmation, this, std::placeholders::_1)
    );

    box_status_client_ = this->create_client<dronehive_interfaces::srv::SlaveBoxInformationService>("/dronehive/gui_slave_box_info_service");
    drone_status_client_ = this->create_client<dronehive_interfaces::srv::RequestDroneStatus>("/dronehive/gui_drone_id_service");
    drone_landing_client_ = this->create_client<dronehive_interfaces::srv::RequestDroneLanding>("/dronehive/request_landing");
    drone_home_return_client_ = this->create_client<dronehive_interfaces::srv::RequestReturnHome>("/dronehive/request_return_home");
    system_status_client_ = this->create_client<dronehive_interfaces::srv::SlaveBoxIDsService>("/dronehive/gui_boxes_id_service");

    heartbeat_timer_ = this->create_wall_timer(
    std::chrono::seconds(1),
    [this]() {
        std_msgs::msg::String msg;
        msg.data = "heartbeat";
        to_gui_heart_pub_->publish(msg);
    }); 

    newbox_timeout_timer_ = this->create_wall_timer(
    std::chrono::milliseconds(200),
    [this](){
        if(this->box_timeout_timer > 10)
        {
            dronehive_interfaces::msg::BackendCommand msg;
            msg.command = dronehive_interfaces::msg::BackendCommand::NEW_BOX_SEARCH_TIMEOUT;
            this->to_gui_command_pub_->publish(msg);
            this->box_timeout_timer = 0;
            this->new_search_retry = false;
            this->new_box_confirm = false;
            this->new_box_message_arrived = false;
        }
        else if(this->new_search_retry)
        { 
            this->box_timeout_timer++;
        }
    });
    this->notify_gui_srv_ = this->create_service<dronehive_interfaces::srv::OccupancyService>("/dronehive/drone_update_box_state",std::bind(&App::onNotifyGui, this, std::placeholders::_1, std::placeholders::_2));
     // One timer for all service requests
    service_timer_ = this->create_wall_timer(std::chrono::seconds(5), std::bind(&App::onServiceTimer, this));
}

App::~App()
{
    rclcpp::shutdown();
}

void App::onNotifyGui(const std::shared_ptr<dronehive_interfaces::srv::OccupancyService::Request> request, std::shared_ptr<dronehive_interfaces::srv::OccupancyService::Response> response)
{

    std_msgs::msg::String msg2;
    msg2.data = "Got Notify client request";
    to_gui_msg_pub_->publish(msg2);

    std::string box_id = request->box_id;
    std::string drone_id = request->drone_id;

    response->occupancy_status = true;

    dronehive_interfaces::msg::OccupancyMessage msg;
    msg.drone_id = drone_id;
    msg.box_id = box_id;
    msg.occupancy = true;

    this->notify_gui_on_ccupancy_change_pub_->publish(msg);
}


void App::onServiceTimer()
{
    // add requests
    if(this->system_status_client_->wait_for_service(std::chrono::seconds(0)) && this->get_system_status_request_appeared)
    {
        auto req = std::make_shared<dronehive_interfaces::srv::SlaveBoxIDsService::Request>();
        this->system_status_client_->async_send_request(req, std::bind(&App::onSystemStatusRequestResponse, this, std::placeholders::_1));
    }

    if(this->box_status_client_->wait_for_service(std::chrono::seconds(0)) && this->get_box_status_request_appeared)
    {
        auto req = std::make_shared<dronehive_interfaces::srv::SlaveBoxInformationService::Request>();
        this->box_status_client_->async_send_request(req, std::bind(&App::onBoxStatusRequestResponse, this, std::placeholders::_1));
    }

    if(this->drone_status_client_->wait_for_service(std::chrono::seconds(0)) && this->get_drone_status_request_appeared)
    {
        auto req = std::make_shared<dronehive_interfaces::srv::RequestDroneStatus::Request>();
        this->drone_status_client_->async_send_request(req, std::bind(&App::onDroneStatusRequestResponse, this, std::placeholders::_1));
    }

    if(this->drone_landing_client_->wait_for_service(std::chrono::seconds(0)) && this->drone_landing_request_appeared)
    {
        auto req = std::make_shared<dronehive_interfaces::srv::RequestDroneLanding::Request>();
        this->drone_landing_client_->async_send_request(req, std::bind(&App::onDroneLandingRequestResponse, this, std::placeholders::_1));
    }

    if(this->drone_home_return_client_->wait_for_service(std::chrono::seconds(0)) && this->drone_return_home_request_appeared)
    {
        auto req = std::make_shared<dronehive_interfaces::srv::RequestReturnHome::Request>();
        this->drone_home_return_client_->async_send_request(req, std::bind(&App::onDroneReturnHomeRequestResponse, this, std::placeholders::_1));
    }
}

void App::onSystemStatusRequestResponse(rclcpp::Client<dronehive_interfaces::srv::SlaveBoxIDsService>::SharedFuture f)
{
    auto response = f.get();
    this->get_system_status_request_appeared = false;

    auto msg2 = std_msgs::msg::String();
    msg2.data = "Confirming, got SYSTEM status response";
    to_gui_msg_pub_->publish(msg2);

    std::vector<std::string> box_ids = response->box_ids;
    int box_ids_size = response->size;

    this->pending_box_responses_ = box_ids_size;

    for (int i = 0; i < box_ids_size; i++)
    {
        auto msg2 = std_msgs::msg::String();
        msg2.data = "Starting status request for box id " + response->box_ids[i];
        to_gui_msg_pub_->publish(msg2);

        if (this->box_status_client_->wait_for_service(std::chrono::seconds(10)))
        {
            auto req = std::make_shared<dronehive_interfaces::srv::SlaveBoxInformationService::Request>();
            req->box_id = box_ids[i];

            this->box_status_client_->async_send_request(
                req,
                std::bind(&App::onBoxStatusRequestResponse, this, std::placeholders::_1)
            );
        }
        else
        {
            pending_box_responses_--;
        }
    }
}

void App::onBoxStatusRequestResponse(rclcpp::Client<dronehive_interfaces::srv::SlaveBoxInformationService>::SharedFuture f)
{
    auto response = f.get();
    this->get_box_status_request_appeared = false;

    auto msg2 = std_msgs::msg::String();
    msg2.data = "Got box status request";
    to_gui_msg_pub_->publish(msg2);
    

    if(this->pending_box_responses_ != 0)
        this->pending_box_responses_--; 

    auto msg = dronehive_interfaces::msg::BoxFullStatus();
    msg.box_id = response->box_id;
    msg.drone_id = response->drone_id;
    msg.landing_pos = response->landing_pos;
    msg.box_status = response->status;

    box_status_pub_->publish(msg);
}

void App::onDroneStatusRequestResponse(rclcpp::Client<dronehive_interfaces::srv::RequestDroneStatus>::SharedFuture f)
{
    auto response = f.get();
    this->get_drone_status_request_appeared = false;
}

void App::onDroneLandingRequestResponse(rclcpp::Client<dronehive_interfaces::srv::RequestDroneLanding>::SharedFuture f)
{
    auto response = f.get();
    this->drone_landing_request_appeared = false;
}

void App::onDroneReturnHomeRequestResponse(rclcpp::Client<dronehive_interfaces::srv::RequestReturnHome>::SharedFuture f)
{
    auto response = f.get();
    this->drone_return_home_request_appeared = false;
}

void App::onNewBoxGuiConfirmation(const dronehive_interfaces::msg::BoxSetupConfirmationMessage::SharedPtr msg)
{
    auto msg2 = std_msgs::msg::String();
    msg2.data = "Confirming:";
    to_gui_msg_pub_->publish(msg2);

    this->to_box_new_box_confirmation_pub->publish(*msg);
}

void App::onBoxMessage(const dronehive_interfaces::msg::BoxBroadcastMessage::SharedPtr msg)
{
    if(!this->new_box_message_arrived) return;

    this->new_box_message_arrived = false;

    this->new_search_retry = false;

    dronehive_interfaces::msg::BoxSetupConfirmationMessage gui_msg;

    gui_msg.box_id = msg->box_id;
    gui_msg.landing_pos = msg->landing_pos;
    box_msg_pub_->publish(gui_msg);
}


void App::onGuiCommand(const dronehive_interfaces::msg::GuiCommand::SharedPtr command)
{
    auto msg = std_msgs::msg::String();
    msg.data = "Got command: " + std::to_string(command->command);
    to_gui_msg_pub_->publish(msg);

    switch(command->command)
    {
        case dronehive_interfaces::msg::GuiCommand::SEARCH_FOR_NEW_BOX:
        {
            this->new_box_message_arrived = true;
            this->new_search_retry = true;
            this->box_timeout_timer = 0;
            break;
        }
        case dronehive_interfaces::msg::GuiCommand::REMOVE_BOX:
        {   
            this->onRemoveBoxGuiCommand(command->box_id);
            break;
        }
        case dronehive_interfaces::msg::GuiCommand::REQUEST_BOX_STATUS:
        {
            this->get_box_status_request_appeared = true;
            break;   
        }
        case dronehive_interfaces::msg::GuiCommand::REQUEST_LANDING:
        {
            this->drone_landing_request_appeared = true;
            break;
        }
        case dronehive_interfaces::msg::GuiCommand::REQUEST_RETURN_HOME:
        {
            this->drone_return_home_request_appeared = true;
            break;
        }
        case dronehive_interfaces::msg::GuiCommand::REQUEST_FULL_SYSTEM_STATUS:
        {
            this->get_system_status_request_appeared = true;
            break;
        }
        case dronehive_interfaces::msg::GuiCommand::REQUEST_DRONE_STATUS:
        {
            this->get_drone_status_request_appeared = true;
            break;   
        }

        case dronehive_interfaces::msg::GuiCommand::REQUEST_EXECUTE_PATH:
        {
            // add flag to enable a timer to recieve the path
            break;
        }

        case dronehive_interfaces::msg::GuiCommand::SEARCH_FOR_NEW_DRONE:
        {
            break;
        }
    };
}

void App::onRemoveBoxGuiCommand(const std::string& box_id)
{
    auto deinit_msg = std_msgs::msg::String();
    deinit_msg.data = box_id;
    
    this->box_deinit_pub_->publish(deinit_msg);
}