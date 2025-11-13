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
#include <dronehive_interfaces/msg/box_full_status.hpp>
#include <dronehive_interfaces/msg/occupancy_message.hpp>
#include <dronehive_interfaces/msg/gui_drone_landing_request.hpp>
#include <dronehive_interfaces/msg/gui_drone_trajectory_upload.hpp>
#include <dronehive_interfaces/msg/gui_add_new_drone.hpp>

#include <dronehive_interfaces/srv/box_broadcast_service.hpp>
#include <dronehive_interfaces/srv/occupancy_service.hpp>
#include <dronehive_interfaces/srv/request_box_status.hpp>
#include <dronehive_interfaces/srv/request_drone_status.hpp>
#include <dronehive_interfaces/srv/request_drone_landing.hpp>
#include <dronehive_interfaces/srv/request_return_home.hpp>
#include <dronehive_interfaces/srv/request_full_system_status.hpp>
#include <dronehive_interfaces/srv/request_box_status.hpp>
#include <dronehive_interfaces/srv/get_config.hpp>
#include <dronehive_interfaces/srv/get_flightlog.hpp>
#include <dronehive_interfaces/srv/slave_box_information_service.hpp>
#include <dronehive_interfaces/srv/slave_box_i_ds_service.hpp>
#include <dronehive_interfaces/srv/drone_landing_service.hpp>
#include <dronehive_interfaces/srv/drone_status_service.hpp>
#include <dronehive_interfaces/srv/drone_trajectory_waypoints_service.hpp>
#include <dronehive_interfaces/srv/add_remove_drone_service.hpp>

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

    private:
        void onGuiCommand(const dronehive_interfaces::msg::GuiCommand::SharedPtr command);
        void onNewBoxGuiConfirmation(const dronehive_interfaces::msg::BoxSetupConfirmationMessage::SharedPtr msg);
        void onBoxMessage(const dronehive_interfaces::msg::BoxBroadcastMessage::SharedPtr msg);
        void onServiceTimer();

        void onGuiTrajectoryRecieved(const dronehive_interfaces::msg::GuiDroneTrajectoryUpload::SharedPtr msg);
        void onGuiAddRemoveDrone(const dronehive_interfaces::msg::GuiAddNewDrone::SharedPtr msg);

        void onSystemStatusRequestResponse(rclcpp::Client<dronehive_interfaces::srv::SlaveBoxIDsService>::SharedFuture f);
        void onBoxStatusRequestResponse(rclcpp::Client<dronehive_interfaces::srv::SlaveBoxInformationService>::SharedFuture f);
        void onAddRemoveDroneRequestResponse(rclcpp::Client<dronehive_interfaces::srv::AddRemoveDroneService>::SharedFuture f);
        void onTrajectoryRequestResponse(rclcpp::Client<dronehive_interfaces::srv::DroneTrajectoryWaypointsService>::SharedFuture f);

        void onDroneLandingRequestResponse(rclcpp::Client<dronehive_interfaces::srv::DroneLandingService>::SharedFuture f);

        void onRemoveBoxGuiCommand(const std::string& box_id);

        void onNotifyGui(const std::shared_ptr<dronehive_interfaces::srv::OccupancyService::Request> request, std::shared_ptr<dronehive_interfaces::srv::OccupancyService::Response> response);

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
        bool gui_trajectory_request_appeared;
        bool gui_add_remove_request_appeared;

        int pending_box_responses_;

        rclcpp::Subscription<dronehive_interfaces::msg::GuiCommand>::SharedPtr gui_command_sub_;
        rclcpp::Subscription<dronehive_interfaces::msg::GuiCommand>::SharedPtr gui_command_sub2_;
        rclcpp::Subscription<dronehive_interfaces::msg::BoxSetupConfirmationMessage>::SharedPtr gui_box_confirm_sub_;
        rclcpp::Subscription<dronehive_interfaces::msg::BoxBroadcastMessage>::SharedPtr new_box_sub_;
        rclcpp::Subscription<dronehive_interfaces::msg::GuiAddNewDrone>::SharedPtr gui_add_remove_drone_sub_;
        rclcpp::Subscription<dronehive_interfaces::msg::GuiDroneTrajectoryUpload>::SharedPtr gui_drone_trajectory_sub_;

        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr to_gui_heart_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr to_gui_msg_pub_;
        rclcpp::Publisher<dronehive_interfaces::msg::BackendCommand>::SharedPtr to_gui_command_pub_;
        rclcpp::Publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>::SharedPtr to_box_new_box_confirmation_pub;
        rclcpp::Publisher<dronehive_interfaces::msg::BoxFullStatus>::SharedPtr box_status_pub_;
        rclcpp::Publisher<dronehive_interfaces::msg::BoxSetupConfirmationMessage>::SharedPtr box_msg_pub_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr box_deinit_pub_;
        rclcpp::Publisher<dronehive_interfaces::msg::OccupancyMessage>::SharedPtr notify_gui_on_ccupancy_change_pub_;

        rclcpp::Client<dronehive_interfaces::srv::DroneLandingService>::SharedPtr drone_landing_client_;
        rclcpp::Client<dronehive_interfaces::srv::AddRemoveDroneService>::SharedPtr drone_add_client_;
        rclcpp::Client<dronehive_interfaces::srv::DroneTrajectoryWaypointsService>::SharedPtr drone_upload_trajectory_client_;

        rclcpp::Client<dronehive_interfaces::srv::RequestReturnHome>::SharedPtr drone_home_return_client_;
        rclcpp::Client<dronehive_interfaces::srv::SlaveBoxIDsService>::SharedPtr system_status_client_;
        rclcpp::Client<dronehive_interfaces::srv::RequestDroneStatus>::SharedPtr drone_status_client_;
        rclcpp::Client<dronehive_interfaces::srv::SlaveBoxInformationService>::SharedPtr box_status_client_;


        rclcpp::Service<dronehive_interfaces::srv::OccupancyService>::SharedPtr notify_gui_srv_;

        rclcpp::TimerBase::SharedPtr heartbeat_timer_;
        rclcpp::TimerBase::SharedPtr newbox_timeout_timer_;   
        rclcpp::TimerBase::SharedPtr service_timer_;
        
        std::string box_id;
        std::string drone_id;
        std::vector<dronehive_interfaces::msg::PositionMessage> waypoints;
};

#endif