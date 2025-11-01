// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/RequestFullSystemStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/request_full_system_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::RequestFullSystemStatus_Request>()
{
  return ::dronehive_interfaces::srv::RequestFullSystemStatus_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_RequestFullSystemStatus_Response_statuses
{
public:
  Init_RequestFullSystemStatus_Response_statuses()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::RequestFullSystemStatus_Response statuses(::dronehive_interfaces::srv::RequestFullSystemStatus_Response::_statuses_type arg)
  {
    msg_.statuses = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::RequestFullSystemStatus_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::RequestFullSystemStatus_Response>()
{
  return dronehive_interfaces::srv::builder::Init_RequestFullSystemStatus_Response_statuses();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__BUILDER_HPP_
