// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/RequestReturnHome.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_RETURN_HOME__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_RETURN_HOME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/request_return_home__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_RequestReturnHome_Request_box_id
{
public:
  Init_RequestReturnHome_Request_box_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::RequestReturnHome_Request box_id(::dronehive_interfaces::srv::RequestReturnHome_Request::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::RequestReturnHome_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::RequestReturnHome_Request>()
{
  return dronehive_interfaces::srv::builder::Init_RequestReturnHome_Request_box_id();
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_RequestReturnHome_Response_confirm
{
public:
  Init_RequestReturnHome_Response_confirm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::RequestReturnHome_Response confirm(::dronehive_interfaces::srv::RequestReturnHome_Response::_confirm_type arg)
  {
    msg_.confirm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::RequestReturnHome_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::RequestReturnHome_Response>()
{
  return dronehive_interfaces::srv::builder::Init_RequestReturnHome_Response_confirm();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_RETURN_HOME__BUILDER_HPP_
