// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/BoxStatusMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/box_status_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoxStatusMessage_status
{
public:
  explicit Init_BoxStatusMessage_status(::dronehive_interfaces::msg::BoxStatusMessage & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::BoxStatusMessage status(::dronehive_interfaces::msg::BoxStatusMessage::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxStatusMessage msg_;
};

class Init_BoxStatusMessage_drone_id
{
public:
  explicit Init_BoxStatusMessage_drone_id(::dronehive_interfaces::msg::BoxStatusMessage & msg)
  : msg_(msg)
  {}
  Init_BoxStatusMessage_status drone_id(::dronehive_interfaces::msg::BoxStatusMessage::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_BoxStatusMessage_status(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxStatusMessage msg_;
};

class Init_BoxStatusMessage_box_id
{
public:
  explicit Init_BoxStatusMessage_box_id(::dronehive_interfaces::msg::BoxStatusMessage & msg)
  : msg_(msg)
  {}
  Init_BoxStatusMessage_drone_id box_id(::dronehive_interfaces::msg::BoxStatusMessage::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return Init_BoxStatusMessage_drone_id(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxStatusMessage msg_;
};

class Init_BoxStatusMessage_box_battery_level
{
public:
  explicit Init_BoxStatusMessage_box_battery_level(::dronehive_interfaces::msg::BoxStatusMessage & msg)
  : msg_(msg)
  {}
  Init_BoxStatusMessage_box_id box_battery_level(::dronehive_interfaces::msg::BoxStatusMessage::_box_battery_level_type arg)
  {
    msg_.box_battery_level = std::move(arg);
    return Init_BoxStatusMessage_box_id(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxStatusMessage msg_;
};

class Init_BoxStatusMessage_landing_pos
{
public:
  Init_BoxStatusMessage_landing_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxStatusMessage_box_battery_level landing_pos(::dronehive_interfaces::msg::BoxStatusMessage::_landing_pos_type arg)
  {
    msg_.landing_pos = std::move(arg);
    return Init_BoxStatusMessage_box_battery_level(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxStatusMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::BoxStatusMessage>()
{
  return dronehive_interfaces::msg::builder::Init_BoxStatusMessage_landing_pos();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__BUILDER_HPP_
