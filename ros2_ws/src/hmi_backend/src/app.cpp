#include <iostream>
#include <app.h>

App::App()
{
    this->node_ = std::make_shared<rclcpp::Node>("app_node");
    this->count = 0;
    this->new_box_message_arrived = false;

    to_gui_heart_pub_ = this->node_->create_publisher<std_msgs::msg::String>("/backend/heartbeat", 10);
    to_gui_command_pub_ = this->node_->create_publisher<std_msgs::msg::String>("/backend/command", 10);

    this->toBoxNewBoxServ = this->node_->create_service<dronehive_interfaces::srv::BoxBroadcastService>(
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

    auto qos = rclcpp::QoS(10).best_effort();

}

App::~App()
{
    rclcpp::shutdown();
}

void App::onNewBoxCreation(
    const std::shared_ptr<dronehive_interfaces::srv::BoxBroadcastService::Request> request,
    std::shared_ptr<dronehive_interfaces::srv::BoxBroadcastService::Response> response)
{
    RCLCPP_INFO(this->node_->get_logger(), "Triggered: %s");
    response->confirm = true;
    response->landing_pos = request->landing_pos;
}

void App::onGuiCommandMessage(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->node_->get_logger(), "Got message: %s", msg->data.c_str());
}



void App::appRun()
{
    rclcpp::WallRate loop(1.0); // 1 Hz

    while (rclcpp::ok()) 
    {
        this->appHeartBeat();

        rclcpp::spin_some(this->node_);
        loop.sleep();

    }

    rclcpp::shutdown();
}

void App::appHeartBeat()
{
    auto msg = std_msgs::msg::String();
    msg.data = std::to_string(this->count++);
    this->to_gui_heart_pub_->publish(msg);
}