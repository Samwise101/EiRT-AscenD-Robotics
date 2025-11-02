// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/SetConfigMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__SET_CONFIG_MESSAGE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__SET_CONFIG_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/set_config_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetConfigMessage_drone_setup
{
public:
  explicit Init_SetConfigMessage_drone_setup(::dronehive_interfaces::msg::SetConfigMessage & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::SetConfigMessage drone_setup(::dronehive_interfaces::msg::SetConfigMessage::_drone_setup_type arg)
  {
    msg_.drone_setup = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::SetConfigMessage msg_;
};

class Init_SetConfigMessage_drone_type
{
public:
  explicit Init_SetConfigMessage_drone_type(::dronehive_interfaces::msg::SetConfigMessage & msg)
  : msg_(msg)
  {}
  Init_SetConfigMessage_drone_setup drone_type(::dronehive_interfaces::msg::SetConfigMessage::_drone_type_type arg)
  {
    msg_.drone_type = std::move(arg);
    return Init_SetConfigMessage_drone_setup(msg_);
  }

private:
  ::dronehive_interfaces::msg::SetConfigMessage msg_;
};

class Init_SetConfigMessage_drone_name
{
public:
  explicit Init_SetConfigMessage_drone_name(::dronehive_interfaces::msg::SetConfigMessage & msg)
  : msg_(msg)
  {}
  Init_SetConfigMessage_drone_type drone_name(::dronehive_interfaces::msg::SetConfigMessage::_drone_name_type arg)
  {
    msg_.drone_name = std::move(arg);
    return Init_SetConfigMessage_drone_type(msg_);
  }

private:
  ::dronehive_interfaces::msg::SetConfigMessage msg_;
};

class Init_SetConfigMessage_drone_id
{
public:
  explicit Init_SetConfigMessage_drone_id(::dronehive_interfaces::msg::SetConfigMessage & msg)
  : msg_(msg)
  {}
  Init_SetConfigMessage_drone_name drone_id(::dronehive_interfaces::msg::SetConfigMessage::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_SetConfigMessage_drone_name(msg_);
  }

private:
  ::dronehive_interfaces::msg::SetConfigMessage msg_;
};

class Init_SetConfigMessage_box_id
{
public:
  Init_SetConfigMessage_box_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetConfigMessage_drone_id box_id(::dronehive_interfaces::msg::SetConfigMessage::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return Init_SetConfigMessage_drone_id(msg_);
  }

private:
  ::dronehive_interfaces::msg::SetConfigMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::SetConfigMessage>()
{
  return dronehive_interfaces::msg::builder::Init_SetConfigMessage_box_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__SET_CONFIG_MESSAGE__BUILDER_HPP_
