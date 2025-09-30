#pragma once

#ifndef APP_H
#define APP_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <dronehive_interfaces/msg/box_broadcast_message.hpp>
#include <dronehive_interfaces/msg/box_setup_confirmation_message.hpp>
#include <dronehive_interfaces/srv/box_broadcast_service.hpp>
#include <memory>
#include <QTimer>
#include <QThread>
#include <string>

class App
{

    public:
        App();
        ~App();

    public:
        void appRun();
        void appHeartBeat();

        void onGuiCommandMessage(const std_msgs::msg::String::SharedPtr msg);

        void onNewBoxCreation(
            const std::shared_ptr<dronehive_interfaces::srv::BoxBroadcastService::Request> request,
            std::shared_ptr<dronehive_interfaces::srv::BoxBroadcastService::Response> response);
        
    private:
        int count;
        bool new_box_message_arrived;
        std::shared_ptr<rclcpp::Node> node_;

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr gui_command_sub_;

        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr to_gui_heart_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr to_gui_command_pub_;

        rclcpp::Service<dronehive_interfaces::srv::BoxBroadcastService>::SharedPtr toBoxNewBoxServ;
};

#endif