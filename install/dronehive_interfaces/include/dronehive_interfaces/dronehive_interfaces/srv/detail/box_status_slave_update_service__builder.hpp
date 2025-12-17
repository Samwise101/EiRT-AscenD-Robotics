// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/BoxStatusSlaveUpdateService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/box_status_slave_update_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_BoxStatusSlaveUpdateService_Request_status
{
public:
  Init_BoxStatusSlaveUpdateService_Request_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request status(::dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request>()
{
  return dronehive_interfaces::srv::builder::Init_BoxStatusSlaveUpdateService_Request_status();
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_BoxStatusSlaveUpdateService_Response_ack
{
public:
  Init_BoxStatusSlaveUpdateService_Response_ack()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response ack(::dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response::_ack_type arg)
  {
    msg_.ack = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_BoxStatusSlaveUpdateService_Response_ack();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__BUILDER_HPP_
