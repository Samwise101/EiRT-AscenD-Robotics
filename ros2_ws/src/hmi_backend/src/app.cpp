#include <iostream>
#include <app.h>

App::App() : Node("app_node") 
{
    this->count = 0;
    this->box_timeout_timer = 0;
    this->new_box_message_arrived = false;

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
        this->box_timeout_timer++;
        if(this->box_timeout_timer > 10)
        {
            dronehive_interfaces::msg::BackendCommand msg;
            msg.command = dronehive_interfaces::msg::BackendCommand::NEW_BOX_SEARCH_TIMEOUT;
            this->to_gui_command_pub_->publish(msg);
            this->box_timeout_timer = 0;
        }
    });
}

App::~App()
{
    rclcpp::shutdown();
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


void App::onGuiMessage(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Got message: %s", msg->data.c_str());
}

void App::onBoxMessage(const dronehive_interfaces::msg::BoxBroadcastMessage::SharedPtr msg)
{
    if(!this->new_box_message_arrived) return;

    this->new_box_message_arrived = false;

    auto box_msg_pub_ = this->create_publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>("/backend/newbox",10);

    auto gui_msg = dronehive_interfaces::msg::BoxSetupConfirmationMessage();

    gui_msg.landing_pos = msg->landing_pos;
    box_msg_pub_->publish(gui_msg);
}


void App::onGuiCommand(const dronehive_interfaces::msg::GuiCommand::SharedPtr command)
{
    RCLCPP_INFO(this->get_logger(), "Got command: %d", command->command);

    switch(command->command)
    {
        case dronehive_interfaces::msg::GuiCommand::SEARCH_FOR_NEW_BOX:
                auto msg = std_msgs::msg::String();
                msg.data = "Got command: " + std::to_string(command->command);
                to_gui_msg_pub_->publish(msg);
                this->new_box_message_arrived = true;
                break;
    };
}