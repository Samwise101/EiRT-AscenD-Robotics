#include <iostream>
#include <app.h>

namespace qos_profiles
{
    static const rclcpp::QoS master_qos = [] {
        rclcpp::QoS qos(rclcpp::KeepLast(1));
        qos.reliability(RMW_QOS_POLICY_RELIABILITY_RELIABLE);
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

    auto qos = rclcpp::QoS(10).best_effort();

    this->to_gui_heart_pub_ = this->create_publisher<std_msgs::msg::String>("/backend/heartbeat", 10);
    this->to_gui_msg_pub_ = this->create_publisher<std_msgs::msg::String>("/backend/msg", 10);
    this->to_gui_command_pub_ = this->create_publisher<dronehive_interfaces::msg::BackendCommand>("/backend/command", 10);

    gui_command_sub_ = this->create_subscription<dronehive_interfaces::msg::GuiCommand>("/gui/command", 10, std::bind(&App::onGuiCommand, this, std::placeholders::_1));

    new_box_sub_ = this->create_subscription<dronehive_interfaces::msg::BoxBroadcastMessage>(
        "/dronehive/new_box", qos, std::bind(&App::onBoxMessage, this, std::placeholders::_1)
    );

    gui_box_confirm_sub_ = this->create_subscription<dronehive_interfaces::msg::BoxSetupConfirmationMessage>(
        "/gui/newbox_response", 10, std::bind(&App::onNewBoxGuiConfirmation, this, std::placeholders::_1)
    );


    box_status_client_ = this->create_client<dronehive_interfaces::srv::RequestBoxStatus>("dronehive/request_status");
    drone_status_client_ = this->create_client<dronehive_interfaces::srv::RequestDroneStatus>("dronehive/request_drone_status");
    drone_landing_client_ = this->create_client<dronehive_interfaces::srv::RequestDroneLanding>("dronehive/request_landing");
    drone_home_return_client_ = this->create_client<dronehive_interfaces::srv::RequestReturnHome>("dronehive/request_return_home");
    system_status_client_ = this->create_client<dronehive_interfaces::srv::RequestFullSystemStatus>("dronehive/request_full_status");

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

     // One timer for all service requests
    service_timer_ = this->create_wall_timer(std::chrono::seconds(5), std::bind(&App::onServiceTimer, this));
}

App::~App()
{
    rclcpp::shutdown();
}

void App::onServiceTimer()
{
    // add requests
    if(this->system_status_client_->wait_for_service(std::chrono::seconds(0)) && this->get_system_status_request_appeared)
    {
        auto req = std::make_shared<dronehive_interfaces::srv::RequestFullSystemStatus::Request>();
        this->system_status_client_->async_send_request(req, std::bind(&App::onSystemStatusRequestResponse, this, std::placeholders::_1));
    }

    if(this->box_status_client_->wait_for_service(std::chrono::seconds(0)) && this->get_box_status_request_appeared)
    {
        auto req = std::make_shared<dronehive_interfaces::srv::RequestBoxStatus::Request>();
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

void App::onSystemStatusRequestResponse(rclcpp::Client<dronehive_interfaces::srv::RequestFullSystemStatus>::SharedFuture f)
{
    auto response = f.get();
    this->get_system_status_request_appeared = false;
}

void App::onBoxStatusRequestResponse(rclcpp::Client<dronehive_interfaces::srv::RequestBoxStatus>::SharedFuture f)
{
    auto response = f.get();
    this->get_box_status_request_appeared = false;
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

    auto qos = rclcpp::QoS(10).best_effort();
    auto to_box_new_box_confirmation_pub = this->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/dronehive/new_box_confirmed",10);
    to_box_new_box_confirmation_pub->publish(*msg);
}

void App::onBoxMessage(const dronehive_interfaces::msg::BoxBroadcastMessage::SharedPtr msg)
{
    if(!this->new_box_message_arrived) return;

    this->new_box_message_arrived = false;

    this->new_search_retry = false;

    auto box_msg_pub_ = this->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/backend/newbox",10);

    auto gui_msg = dronehive_interfaces::msg::BoxSetupConfirmationMessage();

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
    };
}

void App::onRemoveBoxGuiCommand(const std::string& box_id)
{
    auto deinit_msg = std_msgs::msg::String();
    deinit_msg.data = box_id;
    
    auto pub = this->create_publisher<std_msgs::msg::String>("/dronehive/deinitialise_box", qos_profiles::master_qos);
    pub->publish(deinit_msg);
}