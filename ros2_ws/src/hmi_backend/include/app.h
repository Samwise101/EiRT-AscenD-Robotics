#pragma once

#ifndef APP_H
#define APP_H

#include <rclcpp/rclcpp.hpp>
#include <rclcpp/timer.hpp>

#include <std_msgs/msg/string.hpp>

#include <dronehive_interfaces/msg/box_broadcast_message.hpp>
#include <dronehive_interfaces/msg/box_setup_confirmation_message.hpp>
#include <dronehive_interfaces/msg/gui_command.hpp>
#include <dronehive_interfaces/msg/backend_command.hpp>
#include <dronehive_interfaces/msg/execute_path_message.hpp>

#include <dronehive_interfaces/srv/box_broadcast_service.hpp>
#include <dronehive_interfaces/srv/occupancy_service.hpp>
#include <dronehive_interfaces/srv/request_box_status.h>
#include <dronehive_interfaces/srv/request_drone_status.hpp>
#include <dronehive_interfaces/srv/request_drone_landing.hpp>
#include <dronehive_interfaces/srv/request_return_home.hpp>
#include <dronehive_interfaces/srv/request_full_system_status.hpp>
#include <dronehive_interfaces/srv/request_box_status.hpp>
#include <dronehive_interfaces/srv/get_config.hpp>
#include <dronehive_interfaces/srv/get_flightlog.hpp>

#include <thread>
#include <mutex>
#include <condition_variable>

#include <memory>
#include <string>

class App : public rclcpp::Node
{

    public:
        explicit App();
        ~App();

        void onGuiCommand(const dronehive_interfaces::msg::GuiCommand::SharedPtr command);
        void onNewBoxGuiConfirmation(const dronehive_interfaces::msg::BoxSetupConfirmationMessage::SharedPtr msg);
        void onBoxMessage(const dronehive_interfaces::msg::BoxBroadcastMessage::SharedPtr msg);
        void onServiceTimer();

        void onSystemStatusRequestResponse(rclcpp::Client<dronehive_interfaces::srv::RequestFullSystemStatus>::SharedFuture f);
        void onBoxStatusRequestResponse(rclcpp::Client<dronehive_interfaces::srv::RequestBoxStatus>::SharedFuture f);
        void onDroneStatusRequestResponse(rclcpp::Client<dronehive_interfaces::srv::RequestDroneStatus>::SharedFuture f);
        void onDroneLandingRequestResponse(rclcpp::Client<dronehive_interfaces::srv::RequestDroneLanding>::SharedFuture f);
        void onDroneReturnHomeRequestResponse(rclcpp::Client<dronehive_interfaces::srv::RequestReturnHome>::SharedFuture f);

        void onRemoveBoxGuiCommand(const std::string& box_id);

    private:
        int count;
        int box_timeout_timer;
        bool new_box_message_arrived;
        bool new_box_confirm;
        bool new_search_retry;
        bool drone_landing_request_appeared;
        bool drone_return_home_request_appeared;
        bool get_system_status_request_appeared;
        bool get_box_status_request_appeared;
        bool get_drone_status_request_appeared;

        rclcpp::Subscription<dronehive_interfaces::msg::GuiCommand>::SharedPtr gui_command_sub_;
        rclcpp::Subscription<dronehive_interfaces::msg::BoxSetupConfirmationMessage>::SharedPtr gui_box_confirm_sub_;
        rclcpp::Subscription<dronehive_interfaces::msg::BoxBroadcastMessage>::SharedPtr new_box_sub_;

        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr to_gui_heart_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr to_gui_msg_pub_;
        rclcpp::Publisher<dronehive_interfaces::msg::BackendCommand>::SharedPtr to_gui_command_pub_;

        rclcpp::Client<dronehive_interfaces::srv::RequestDroneLanding>::SharedPtr drone_landing_client_;
        rclcpp::Client<dronehive_interfaces::srv::RequestReturnHome>::SharedPtr drone_home_return_client_;
        rclcpp::Client<dronehive_interfaces::srv::RequestFullSystemStatus>::SharedPtr system_status_client_;
        rclcpp::Client<dronehive_interfaces::srv::RequestDroneStatus>::SharedPtr drone_status_client_;
        rclcpp::Client<dronehive_interfaces::srv::RequestBoxStatus>::SharedPtr box_status_client_;

        rclcpp::TimerBase::SharedPtr heartbeat_timer_;
        rclcpp::TimerBase::SharedPtr newbox_timeout_timer_;   
        rclcpp::TimerBase::SharedPtr service_timer_;     
};

#endif