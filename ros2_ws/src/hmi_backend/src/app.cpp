#include <iostream>
#include <app.h>

App::App() : Node("app_node") 
{
    this->count = 0;
    this->new_box_message_arrived = false;

    auto qos = rclcpp::QoS(10).best_effort();

    to_gui_heart_pub_ = this->create_publisher<std_msgs::msg::String>("/backend/heartbeat", 10);
    to_gui_msg_pub_ = this->create_publisher<std_msgs::msg::String>("/backend/msg", 10);
    to_gui_command_pub_ = this->create_publisher<std_msgs::msg::String>("/backend/command", 10);

    gui_command_sub_ = this->create_subscription<dronehive_interfaces::msg::GuiCommand>("/gui/command", 10, std::bind(&App::onGuiCommand, this, std::placeholders::_1));

    heartbeat_timer_ = this->create_wall_timer(
    std::chrono::seconds(1),
    [this]() {
        std_msgs::msg::String msg;
        msg.data = "heartbeat";
        to_gui_heart_pub_->publish(msg);
    }); 
}

App::~App()
{
    rclcpp::shutdown();
}


void App::onGuiMessage(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Got message: %s", msg->data.c_str());
}

void App::onGuiCommand(const dronehive_interfaces::msg::GuiCommand::SharedPtr command)
{
    RCLCPP_INFO(this->get_logger(), "Got command: %d", command->command);
    
    auto msg = std_msgs::msg::String();
    msg.data = "Got command: " + std::to_string(command->command);
    to_gui_msg_pub_->publish(msg);

    switch(command->command)
    {
        case dronehive_interfaces::msg::GuiCommand::NEW_BOX_CONFIRMED:
        case dronehive_interfaces::msg::GuiCommand::NEW_BOX_DECLINED:
                this->new_box_confirm = false;
        case dronehive_interfaces::msg::GuiCommand::SEARCH_FOR_NEW_BOX:
                this->new_box_message_arrived = true;
    };
}