// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/DroneStatusMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/drone_status_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_DroneStatusMessage_current_position
{
public:
  explicit Init_DroneStatusMessage_current_position(::dronehive_interfaces::msg::DroneStatusMessage & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::DroneStatusMessage current_position(::dronehive_interfaces::msg::DroneStatusMessage::_current_position_type arg)
  {
    msg_.current_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::DroneStatusMessage msg_;
};

class Init_DroneStatusMessage_reached_first_waypoint
{
public:
  explicit Init_DroneStatusMessage_reached_first_waypoint(::dronehive_interfaces::msg::DroneStatusMessage & msg)
  : msg_(msg)
  {}
  Init_DroneStatusMessage_current_position reached_first_waypoint(::dronehive_interfaces::msg::DroneStatusMessage::_reached_first_waypoint_type arg)
  {
    msg_.reached_first_waypoint = std::move(arg);
    return Init_DroneStatusMessage_current_position(msg_);
  }

private:
  ::dronehive_interfaces::msg::DroneStatusMessage msg_;
};

class Init_DroneStatusMessage_fligt_state
{
public:
  explicit Init_DroneStatusMessage_fligt_state(::dronehive_interfaces::msg::DroneStatusMessage & msg)
  : msg_(msg)
  {}
  Init_DroneStatusMessage_reached_first_waypoint fligt_state(::dronehive_interfaces::msg::DroneStatusMessage::_fligt_state_type arg)
  {
    msg_.fligt_state = std::move(arg);
    return Init_DroneStatusMessage_reached_first_waypoint(msg_);
  }

private:
  ::dronehive_interfaces::msg::DroneStatusMessage msg_;
};

class Init_DroneStatusMessage_battery_percentage
{
public:
  explicit Init_DroneStatusMessage_battery_percentage(::dronehive_interfaces::msg::DroneStatusMessage & msg)
  : msg_(msg)
  {}
  Init_DroneStatusMessage_fligt_state battery_percentage(::dronehive_interfaces::msg::DroneStatusMessage::_battery_percentage_type arg)
  {
    msg_.battery_percentage = std::move(arg);
    return Init_DroneStatusMessage_fligt_state(msg_);
  }

private:
  ::dronehive_interfaces::msg::DroneStatusMessage msg_;
};

class Init_DroneStatusMessage_battery_voltage
{
public:
  explicit Init_DroneStatusMessage_battery_voltage(::dronehive_interfaces::msg::DroneStatusMessage & msg)
  : msg_(msg)
  {}
  Init_DroneStatusMessage_battery_percentage battery_voltage(::dronehive_interfaces::msg::DroneStatusMessage::_battery_voltage_type arg)
  {
    msg_.battery_voltage = std::move(arg);
    return Init_DroneStatusMessage_battery_percentage(msg_);
  }

private:
  ::dronehive_interfaces::msg::DroneStatusMessage msg_;
};

class Init_DroneStatusMessage_drone_id
{
public:
  Init_DroneStatusMessage_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneStatusMessage_battery_voltage drone_id(::dronehive_interfaces::msg::DroneStatusMessage::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_DroneStatusMessage_battery_voltage(msg_);
  }

private:
  ::dronehive_interfaces::msg::DroneStatusMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::DroneStatusMessage>()
{
  return dronehive_interfaces::msg::builder::Init_DroneStatusMessage_drone_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__BUILDER_HPP_
