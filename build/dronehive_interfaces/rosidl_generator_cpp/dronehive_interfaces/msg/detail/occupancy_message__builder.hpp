// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/OccupancyMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__OCCUPANCY_MESSAGE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__OCCUPANCY_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/occupancy_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_OccupancyMessage_occupancy
{
public:
  explicit Init_OccupancyMessage_occupancy(::dronehive_interfaces::msg::OccupancyMessage & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::OccupancyMessage occupancy(::dronehive_interfaces::msg::OccupancyMessage::_occupancy_type arg)
  {
    msg_.occupancy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::OccupancyMessage msg_;
};

class Init_OccupancyMessage_drone_id
{
public:
  explicit Init_OccupancyMessage_drone_id(::dronehive_interfaces::msg::OccupancyMessage & msg)
  : msg_(msg)
  {}
  Init_OccupancyMessage_occupancy drone_id(::dronehive_interfaces::msg::OccupancyMessage::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_OccupancyMessage_occupancy(msg_);
  }

private:
  ::dronehive_interfaces::msg::OccupancyMessage msg_;
};

class Init_OccupancyMessage_box_id
{
public:
  Init_OccupancyMessage_box_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OccupancyMessage_drone_id box_id(::dronehive_interfaces::msg::OccupancyMessage::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return Init_OccupancyMessage_drone_id(msg_);
  }

private:
  ::dronehive_interfaces::msg::OccupancyMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::OccupancyMessage>()
{
  return dronehive_interfaces::msg::builder::Init_OccupancyMessage_box_id();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__OCCUPANCY_MESSAGE__BUILDER_HPP_
