// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/ToggleTrajectoryExecutionService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__TOGGLE_TRAJECTORY_EXECUTION_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__TOGGLE_TRAJECTORY_EXECUTION_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/toggle_trajectory_execution_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_ToggleTrajectoryExecutionService_Request_drone_id
{
public:
  explicit Init_ToggleTrajectoryExecutionService_Request_drone_id(::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Request & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Request drone_id(::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Request::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Request msg_;
};

class Init_ToggleTrajectoryExecutionService_Request_start
{
public:
  Init_ToggleTrajectoryExecutionService_Request_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToggleTrajectoryExecutionService_Request_drone_id start(::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Request::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_ToggleTrajectoryExecutionService_Request_drone_id(msg_);
  }

private:
  ::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Request>()
{
  return dronehive_interfaces::srv::builder::Init_ToggleTrajectoryExecutionService_Request_start();
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_ToggleTrajectoryExecutionService_Response_ack
{
public:
  Init_ToggleTrajectoryExecutionService_Response_ack()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Response ack(::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Response::_ack_type arg)
  {
    msg_.ack = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::ToggleTrajectoryExecutionService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_ToggleTrajectoryExecutionService_Response_ack();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__TOGGLE_TRAJECTORY_EXECUTION_SERVICE__BUILDER_HPP_
