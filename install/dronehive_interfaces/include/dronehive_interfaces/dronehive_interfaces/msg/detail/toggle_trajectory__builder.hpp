// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/ToggleTrajectory.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__TOGGLE_TRAJECTORY__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__TOGGLE_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/toggle_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_ToggleTrajectory_toggle
{
public:
  explicit Init_ToggleTrajectory_toggle(::dronehive_interfaces::msg::ToggleTrajectory & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::ToggleTrajectory toggle(::dronehive_interfaces::msg::ToggleTrajectory::_toggle_type arg)
  {
    msg_.toggle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::ToggleTrajectory msg_;
};

class Init_ToggleTrajectory_drone_id
{
public:
  Init_ToggleTrajectory_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToggleTrajectory_toggle drone_id(::dronehive_interfaces::msg::ToggleTrajectory::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_ToggleTrajectory_toggle(msg_);
  }

private:
  ::dronehive_interfaces::msg::ToggleTrajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::ToggleTrajectory>()
{
  return dronehive_interfaces::msg::builder::Init_ToggleTrajectory_drone_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__TOGGLE_TRAJECTORY__BUILDER_HPP_
