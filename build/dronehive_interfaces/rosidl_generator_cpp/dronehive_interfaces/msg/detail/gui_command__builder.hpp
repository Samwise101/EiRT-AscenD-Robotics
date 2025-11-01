// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/GuiCommand.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/gui_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_GuiCommand_box_id
{
public:
  explicit Init_GuiCommand_box_id(::dronehive_interfaces::msg::GuiCommand & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::GuiCommand box_id(::dronehive_interfaces::msg::GuiCommand::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::GuiCommand msg_;
};

class Init_GuiCommand_confirm
{
public:
  explicit Init_GuiCommand_confirm(::dronehive_interfaces::msg::GuiCommand & msg)
  : msg_(msg)
  {}
  Init_GuiCommand_box_id confirm(::dronehive_interfaces::msg::GuiCommand::_confirm_type arg)
  {
    msg_.confirm = std::move(arg);
    return Init_GuiCommand_box_id(msg_);
  }

private:
  ::dronehive_interfaces::msg::GuiCommand msg_;
};

class Init_GuiCommand_command
{
public:
  Init_GuiCommand_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GuiCommand_confirm command(::dronehive_interfaces::msg::GuiCommand::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_GuiCommand_confirm(msg_);
  }

private:
  ::dronehive_interfaces::msg::GuiCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::GuiCommand>()
{
  return dronehive_interfaces::msg::builder::Init_GuiCommand_command();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__BUILDER_HPP_
