// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/RequestBoxOpenService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_BOX_OPEN_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_BOX_OPEN_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/request_box_open_service__struct.hpp"
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
auto build<::dronehive_interfaces::srv::RequestBoxOpenService_Request>()
{
  return ::dronehive_interfaces::srv::RequestBoxOpenService_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_RequestBoxOpenService_Response_ack
{
public:
  Init_RequestBoxOpenService_Response_ack()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::RequestBoxOpenService_Response ack(::dronehive_interfaces::srv::RequestBoxOpenService_Response::_ack_type arg)
  {
    msg_.ack = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::RequestBoxOpenService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::RequestBoxOpenService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_RequestBoxOpenService_Response_ack();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_BOX_OPEN_SERVICE__BUILDER_HPP_
