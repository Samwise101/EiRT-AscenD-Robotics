// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/SetPathMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__SET_PATH_MESSAGE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__SET_PATH_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/set_path_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetPathMessage_waypoints
{
public:
  explicit Init_SetPathMessage_waypoints(::dronehive_interfaces::msg::SetPathMessage & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::SetPathMessage waypoints(::dronehive_interfaces::msg::SetPathMessage::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::SetPathMessage msg_;
};

class Init_SetPathMessage_box_id
{
public:
  Init_SetPathMessage_box_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPathMessage_waypoints box_id(::dronehive_interfaces::msg::SetPathMessage::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return Init_SetPathMessage_waypoints(msg_);
  }

private:
  ::dronehive_interfaces::msg::SetPathMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::SetPathMessage>()
{
  return dronehive_interfaces::msg::builder::Init_SetPathMessage_box_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__SET_PATH_MESSAGE__BUILDER_HPP_
