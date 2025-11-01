// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/BoxFullStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_FULL_STATUS__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_FULL_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/box_full_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoxFullStatus_landing_pos
{
public:
  explicit Init_BoxFullStatus_landing_pos(::dronehive_interfaces::msg::BoxFullStatus & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::BoxFullStatus landing_pos(::dronehive_interfaces::msg::BoxFullStatus::_landing_pos_type arg)
  {
    msg_.landing_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxFullStatus msg_;
};

class Init_BoxFullStatus_drone_id
{
public:
  explicit Init_BoxFullStatus_drone_id(::dronehive_interfaces::msg::BoxFullStatus & msg)
  : msg_(msg)
  {}
  Init_BoxFullStatus_landing_pos drone_id(::dronehive_interfaces::msg::BoxFullStatus::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_BoxFullStatus_landing_pos(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxFullStatus msg_;
};

class Init_BoxFullStatus_box_status
{
public:
  explicit Init_BoxFullStatus_box_status(::dronehive_interfaces::msg::BoxFullStatus & msg)
  : msg_(msg)
  {}
  Init_BoxFullStatus_drone_id box_status(::dronehive_interfaces::msg::BoxFullStatus::_box_status_type arg)
  {
    msg_.box_status = std::move(arg);
    return Init_BoxFullStatus_drone_id(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxFullStatus msg_;
};

class Init_BoxFullStatus_box_id
{
public:
  Init_BoxFullStatus_box_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxFullStatus_box_status box_id(::dronehive_interfaces::msg::BoxFullStatus::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return Init_BoxFullStatus_box_status(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxFullStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::BoxFullStatus>()
{
  return dronehive_interfaces::msg::builder::Init_BoxFullStatus_box_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_FULL_STATUS__BUILDER_HPP_
