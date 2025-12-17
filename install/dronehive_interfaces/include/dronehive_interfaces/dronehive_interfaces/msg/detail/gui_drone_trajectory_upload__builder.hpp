// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/GuiDroneTrajectoryUpload.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_TRAJECTORY_UPLOAD__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_TRAJECTORY_UPLOAD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/gui_drone_trajectory_upload__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_GuiDroneTrajectoryUpload_waypoints
{
public:
  explicit Init_GuiDroneTrajectoryUpload_waypoints(::dronehive_interfaces::msg::GuiDroneTrajectoryUpload & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::GuiDroneTrajectoryUpload waypoints(::dronehive_interfaces::msg::GuiDroneTrajectoryUpload::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::GuiDroneTrajectoryUpload msg_;
};

class Init_GuiDroneTrajectoryUpload_drone_id
{
public:
  Init_GuiDroneTrajectoryUpload_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GuiDroneTrajectoryUpload_waypoints drone_id(::dronehive_interfaces::msg::GuiDroneTrajectoryUpload::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_GuiDroneTrajectoryUpload_waypoints(msg_);
  }

private:
  ::dronehive_interfaces::msg::GuiDroneTrajectoryUpload msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::GuiDroneTrajectoryUpload>()
{
  return dronehive_interfaces::msg::builder::Init_GuiDroneTrajectoryUpload_drone_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_TRAJECTORY_UPLOAD__BUILDER_HPP_
