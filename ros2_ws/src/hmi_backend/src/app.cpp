#include <iostream>
#include <app.h>

App::App() : Node("app_node") 
{
    this->count = 0;
    this->new_box_message_arrived = false;

    auto qos = rclcpp::QoS(10).best_effort();

    to_gui_heart_pub_ = this->create_publisher<std_msgs::msg::String>("/backend/heartbeat", 10);
    to_gui_command_pub_ = this->create_publisher<std_msgs::msg::String>("/backend/command", 10);

    this->toBoxNewBoxServ = this->create_service<dronehive_interfaces::srv::BoxBroadcastService>(
        "/dronehive/box_broadcast_service",
        [this](const std::shared_ptr<dronehive_interfaces::srv::BoxBroadcastService::Request> request,
    std::shared_ptr<dronehive_interfaces::srv::BoxBroadcastService::Response> response)
        {
            auto msg = std_msgs::msg::String();
            msg.data = "Service created";
            this->to_gui_heart_pub_->publish(msg);
            this->onNewBoxCreation(request, response);
        }
    );

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

void App::onNewBoxCreation(
    const std::shared_ptr<dronehive_interfaces::srv::BoxBroadcastService::Request> request,
    std::shared_ptr<dronehive_interfaces::srv::BoxBroadcastService::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Triggered: %s");
    response->confirm = true;
    response->landing_pos = request->landing_pos;
}

void App::onGuiCommandMessage(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Got message: %s", msg->data.c_str());
}