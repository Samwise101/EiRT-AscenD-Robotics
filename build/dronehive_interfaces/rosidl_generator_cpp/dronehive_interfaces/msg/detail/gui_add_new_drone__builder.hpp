// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/GuiAddNewDrone.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_ADD_NEW_DRONE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_ADD_NEW_DRONE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/gui_add_new_drone__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_GuiAddNewDrone_box_id
{
public:
  explicit Init_GuiAddNewDrone_box_id(::dronehive_interfaces::msg::GuiAddNewDrone & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::GuiAddNewDrone box_id(::dronehive_interfaces::msg::GuiAddNewDrone::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::GuiAddNewDrone msg_;
};

class Init_GuiAddNewDrone_drone_id
{
public:
  Init_GuiAddNewDrone_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GuiAddNewDrone_box_id drone_id(::dronehive_interfaces::msg::GuiAddNewDrone::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_GuiAddNewDrone_box_id(msg_);
  }

private:
  ::dronehive_interfaces::msg::GuiAddNewDrone msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::GuiAddNewDrone>()
{
  return dronehive_interfaces::msg::builder::Init_GuiAddNewDrone_drone_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_ADD_NEW_DRONE__BUILDER_HPP_
