// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/BackendCommand.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BACKEND_COMMAND__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BACKEND_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/backend_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_BackendCommand_confirm
{
public:
  explicit Init_BackendCommand_confirm(::dronehive_interfaces::msg::BackendCommand & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::BackendCommand confirm(::dronehive_interfaces::msg::BackendCommand::_confirm_type arg)
  {
    msg_.confirm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::BackendCommand msg_;
};

class Init_BackendCommand_command
{
public:
  Init_BackendCommand_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BackendCommand_confirm command(::dronehive_interfaces::msg::BackendCommand::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_BackendCommand_confirm(msg_);
  }

private:
  ::dronehive_interfaces::msg::BackendCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::BackendCommand>()
{
  return dronehive_interfaces::msg::builder::Init_BackendCommand_command();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BACKEND_COMMAND__BUILDER_HPP_
