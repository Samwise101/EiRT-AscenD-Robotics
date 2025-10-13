#include <iostream>
#include <app.h>

App::App() : Node("app_node") 
{
    this->count = 0;
    this->box_timeout_timer = 0;
    this->new_box_message_arrived = false;
    this->new_box_confirm = false;
    this->new_search_retry = false;

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
    std::chrono::seconds(1),
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
    service_timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&App::onServiceTimer, this));
}

App::~App()
{
    rclcpp::shutdown();
}

void App::onServiceTimer()
{
    // add requests
    if(system_status_client_->wait_for_service(std::chrono::seconds(0))){

    }

    if(box_status_client_->wait_for_service(std::chrono::seconds(0))){
        
    }

    if(drone_status_client_->wait_for_service(std::chrono::seconds(0))){
        
    }
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
            // add flag for serice to start polling
            break;   
        }
        case dronehive_interfaces::msg::GuiCommand::REQUEST_LANDING:
        {
            // add flag for serice to start polling
            break;
        }
        case dronehive_interfaces::msg::GuiCommand::REQUEST_RETURN_HOME:
        {
            // add flag for serice to start polling
            break;
        }
        case dronehive_interfaces::msg::GuiCommand::REQUEST_FULL_SYSTEM_STATUS:
        {
            // add flag for serice to start polling
            break;
        }
        case dronehive_interfaces::msg::GuiCommand::REQUEST_DRONE_STATUS:
        {
            // add flag for serice to start polling
            break;   
        }
    };
}

void App::onRemoveBoxGuiCommand(const std::string& box_id)
{
    auto deinit_msg = std_msgs::msg::String();
    deinit_msg.data = box_id;

    rclcpp::QoS qos_profile(rclcpp::KeepLast(1));
    qos_profile.reliability(RMW_QOS_POLICY_RELIABILITY_RELIABLE);
    qos_profile.durability(RMW_QOS_POLICY_DURABILITY_VOLATILE);
    
    auto pub = this->create_publisher<std_msgs::msg::String>("/dronehive/deinitialise_box", qos_profile);
    pub->publish(deinit_msg);
}