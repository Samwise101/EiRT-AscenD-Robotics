// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/DroneStatusService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_STATUS_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_STATUS_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/drone_status_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_DroneStatusService_Request_box_id
{
public:
  Init_DroneStatusService_Request_box_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::DroneStatusService_Request box_id(::dronehive_interfaces::srv::DroneStatusService_Request::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::DroneStatusService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::DroneStatusService_Request>()
{
  return dronehive_interfaces::srv::builder::Init_DroneStatusService_Request_box_id();
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_DroneStatusService_Response_drone_name
{
public:
  explicit Init_DroneStatusService_Response_drone_name(::dronehive_interfaces::srv::DroneStatusService_Response & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::srv::DroneStatusService_Response drone_name(::dronehive_interfaces::srv::DroneStatusService_Response::_drone_name_type arg)
  {
    msg_.drone_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::DroneStatusService_Response msg_;
};

class Init_DroneStatusService_Response_drone_id
{
public:
  explicit Init_DroneStatusService_Response_drone_id(::dronehive_interfaces::srv::DroneStatusService_Response & msg)
  : msg_(msg)
  {}
  Init_DroneStatusService_Response_drone_name drone_id(::dronehive_interfaces::srv::DroneStatusService_Response::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_DroneStatusService_Response_drone_name(msg_);
  }

private:
  ::dronehive_interfaces::srv::DroneStatusService_Response msg_;
};

class Init_DroneStatusService_Response_battery_level
{
public:
  Init_DroneStatusService_Response_battery_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneStatusService_Response_drone_id battery_level(::dronehive_interfaces::srv::DroneStatusService_Response::_battery_level_type arg)
  {
    msg_.battery_level = std::move(arg);
    return Init_DroneStatusService_Response_drone_id(msg_);
  }

private:
  ::dronehive_interfaces::srv::DroneStatusService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::DroneStatusService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_DroneStatusService_Response_battery_level();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_STATUS_SERVICE__BUILDER_HPP_
