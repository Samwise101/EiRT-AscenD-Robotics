// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/ExecutePathMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__EXECUTE_PATH_MESSAGE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__EXECUTE_PATH_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/execute_path_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_ExecutePathMessage_execution_type
{
public:
  explicit Init_ExecutePathMessage_execution_type(::dronehive_interfaces::msg::ExecutePathMessage & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::ExecutePathMessage execution_type(::dronehive_interfaces::msg::ExecutePathMessage::_execution_type_type arg)
  {
    msg_.execution_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::ExecutePathMessage msg_;
};

class Init_ExecutePathMessage_waypoints
{
public:
  explicit Init_ExecutePathMessage_waypoints(::dronehive_interfaces::msg::ExecutePathMessage & msg)
  : msg_(msg)
  {}
  Init_ExecutePathMessage_execution_type waypoints(::dronehive_interfaces::msg::ExecutePathMessage::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return Init_ExecutePathMessage_execution_type(msg_);
  }

private:
  ::dronehive_interfaces::msg::ExecutePathMessage msg_;
};

class Init_ExecutePathMessage_plan
{
public:
  explicit Init_ExecutePathMessage_plan(::dronehive_interfaces::msg::ExecutePathMessage & msg)
  : msg_(msg)
  {}
  Init_ExecutePathMessage_waypoints plan(::dronehive_interfaces::msg::ExecutePathMessage::_plan_type arg)
  {
    msg_.plan = std::move(arg);
    return Init_ExecutePathMessage_waypoints(msg_);
  }

private:
  ::dronehive_interfaces::msg::ExecutePathMessage msg_;
};

class Init_ExecutePathMessage_box_id
{
public:
  Init_ExecutePathMessage_box_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecutePathMessage_plan box_id(::dronehive_interfaces::msg::ExecutePathMessage::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return Init_ExecutePathMessage_plan(msg_);
  }

private:
  ::dronehive_interfaces::msg::ExecutePathMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::ExecutePathMessage>()
{
  return dronehive_interfaces::msg::builder::Init_ExecutePathMessage_box_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__EXECUTE_PATH_MESSAGE__BUILDER_HPP_
