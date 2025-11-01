// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/DroneForceLandingMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_FORCE_LANDING_MESSAGE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_FORCE_LANDING_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/drone_force_landing_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_DroneForceLandingMessage_drone_id
{
public:
  explicit Init_DroneForceLandingMessage_drone_id(::dronehive_interfaces::msg::DroneForceLandingMessage & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::DroneForceLandingMessage drone_id(::dronehive_interfaces::msg::DroneForceLandingMessage::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::DroneForceLandingMessage msg_;
};

class Init_DroneForceLandingMessage_landing_pos
{
public:
  Init_DroneForceLandingMessage_landing_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneForceLandingMessage_drone_id landing_pos(::dronehive_interfaces::msg::DroneForceLandingMessage::_landing_pos_type arg)
  {
    msg_.landing_pos = std::move(arg);
    return Init_DroneForceLandingMessage_drone_id(msg_);
  }

private:
  ::dronehive_interfaces::msg::DroneForceLandingMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::DroneForceLandingMessage>()
{
  return dronehive_interfaces::msg::builder::Init_DroneForceLandingMessage_landing_pos();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_FORCE_LANDING_MESSAGE__BUILDER_HPP_
