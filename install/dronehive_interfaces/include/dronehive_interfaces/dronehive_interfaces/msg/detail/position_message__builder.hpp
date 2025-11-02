// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/PositionMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__POSITION_MESSAGE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__POSITION_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/position_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_PositionMessage_elv
{
public:
  explicit Init_PositionMessage_elv(::dronehive_interfaces::msg::PositionMessage & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::PositionMessage elv(::dronehive_interfaces::msg::PositionMessage::_elv_type arg)
  {
    msg_.elv = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::PositionMessage msg_;
};

class Init_PositionMessage_lon
{
public:
  explicit Init_PositionMessage_lon(::dronehive_interfaces::msg::PositionMessage & msg)
  : msg_(msg)
  {}
  Init_PositionMessage_elv lon(::dronehive_interfaces::msg::PositionMessage::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_PositionMessage_elv(msg_);
  }

private:
  ::dronehive_interfaces::msg::PositionMessage msg_;
};

class Init_PositionMessage_lat
{
public:
  Init_PositionMessage_lat()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PositionMessage_lon lat(::dronehive_interfaces::msg::PositionMessage::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_PositionMessage_lon(msg_);
  }

private:
  ::dronehive_interfaces::msg::PositionMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::PositionMessage>()
{
  return dronehive_interfaces::msg::builder::Init_PositionMessage_lat();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__POSITION_MESSAGE__BUILDER_HPP_
