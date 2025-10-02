#pragma once

#ifndef APP_H
#define APP_H

#include <rclcpp/rclcpp.hpp>
#include <rclcpp/timer.hpp>
#include <std_msgs/msg/string.hpp>
#include <dronehive_interfaces/msg/box_broadcast_message.hpp>
#include <dronehive_interfaces/msg/box_setup_confirmation_message.hpp>
#include <dronehive_interfaces/srv/box_broadcast_service.hpp>
#include <dronehive_interfaces/msg/gui_command.hpp>
#include <dronehive_interfaces/msg/backend_command.hpp>

#include <memory>
#include <QTimer>
#include <QThread>
#include <string>

#include <thread>
#include <mutex>
#include <condition_variable>

class App : public rclcpp::Node
{

    public:
        App();
        ~App();

    public:
        void onGuiMessage(const std_msgs::msg::String::SharedPtr msg);
        void onGuiCommand(const dronehive_interfaces::msg::GuiCommand::SharedPtr command);
        void onNewBoxGuiConfirmation(const dronehive_interfaces::msg::BoxSetupConfirmationMessage::SharedPtr msg);
        void onBoxMessage(const dronehive_interfaces::msg::BoxBroadcastMessage::SharedPtr msg);

    private:
        int count;
        bool new_box_message_arrived;
        bool new_box_confirm = false;

        rclcpp::Subscription<dronehive_interfaces::msg::GuiCommand>::SharedPtr gui_command_sub_;
        rclcpp::Subscription<dronehive_interfaces::msg::BoxSetupConfirmationMessage>::SharedPtr gui_box_confirm_sub_;

        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr to_gui_heart_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr to_gui_command_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr to_gui_msg_pub_;

        std::shared_ptr<dronehive_interfaces::srv::BoxBroadcastService::Request> pending_request_;
        std::shared_ptr<dronehive_interfaces::srv::BoxBroadcastService::Response> pending_response_;

        
        rclcpp::TimerBase::SharedPtr heartbeat_timer_;
        
};

#endif