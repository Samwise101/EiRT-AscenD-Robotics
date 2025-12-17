// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/GuiDroneLandingRequest.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_LANDING_REQUEST__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_LANDING_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/gui_drone_landing_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_GuiDroneLandingRequest_drone_id
{
public:
  Init_GuiDroneLandingRequest_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::msg::GuiDroneLandingRequest drone_id(::dronehive_interfaces::msg::GuiDroneLandingRequest::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::GuiDroneLandingRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::GuiDroneLandingRequest>()
{
  return dronehive_interfaces::msg::builder::Init_GuiDroneLandingRequest_drone_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_LANDING_REQUEST__BUILDER_HPP_
