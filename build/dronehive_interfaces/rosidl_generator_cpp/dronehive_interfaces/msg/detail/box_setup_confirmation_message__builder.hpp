// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:msg/BoxSetupConfirmationMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_SETUP_CONFIRMATION_MESSAGE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_SETUP_CONFIRMATION_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/msg/detail/box_setup_confirmation_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoxSetupConfirmationMessage_landing_pos
{
public:
  explicit Init_BoxSetupConfirmationMessage_landing_pos(::dronehive_interfaces::msg::BoxSetupConfirmationMessage & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::msg::BoxSetupConfirmationMessage landing_pos(::dronehive_interfaces::msg::BoxSetupConfirmationMessage::_landing_pos_type arg)
  {
    msg_.landing_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxSetupConfirmationMessage msg_;
};

class Init_BoxSetupConfirmationMessage_box_id
{
public:
  explicit Init_BoxSetupConfirmationMessage_box_id(::dronehive_interfaces::msg::BoxSetupConfirmationMessage & msg)
  : msg_(msg)
  {}
  Init_BoxSetupConfirmationMessage_landing_pos box_id(::dronehive_interfaces::msg::BoxSetupConfirmationMessage::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return Init_BoxSetupConfirmationMessage_landing_pos(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxSetupConfirmationMessage msg_;
};

class Init_BoxSetupConfirmationMessage_confirm
{
public:
  Init_BoxSetupConfirmationMessage_confirm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxSetupConfirmationMessage_box_id confirm(::dronehive_interfaces::msg::BoxSetupConfirmationMessage::_confirm_type arg)
  {
    msg_.confirm = std::move(arg);
    return Init_BoxSetupConfirmationMessage_box_id(msg_);
  }

private:
  ::dronehive_interfaces::msg::BoxSetupConfirmationMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::msg::BoxSetupConfirmationMessage>()
{
  return dronehive_interfaces::msg::builder::Init_BoxSetupConfirmationMessage_confirm();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_SETUP_CONFIRMATION_MESSAGE__BUILDER_HPP_
