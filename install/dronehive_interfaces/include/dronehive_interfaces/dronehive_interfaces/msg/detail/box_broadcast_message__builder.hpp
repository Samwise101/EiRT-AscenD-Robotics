// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/BoxBroadcastMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_BROADCAST_MESSAGE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_BROADCAST_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/box_broadcast_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoxBroadcastMessage_landing_pos
{
public:
  explicit Init_BoxBroadcastMessage_landing_pos(::dronehive_interfaces::msg::BoxBroadcastMessage & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::BoxBroadcastMessage landing_pos(::dronehive_interfaces::msg::BoxBroadcastMessage::_landing_pos_type arg)
  {
    msg_.landing_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxBroadcastMessage msg_;
};

class Init_BoxBroadcastMessage_box_id
{
public:
  Init_BoxBroadcastMessage_box_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxBroadcastMessage_landing_pos box_id(::dronehive_interfaces::msg::BoxBroadcastMessage::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return Init_BoxBroadcastMessage_landing_pos(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxBroadcastMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::BoxBroadcastMessage>()
{
  return dronehive_interfaces::msg::builder::Init_BoxBroadcastMessage_box_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_BROADCAST_MESSAGE__BUILDER_HPP_
