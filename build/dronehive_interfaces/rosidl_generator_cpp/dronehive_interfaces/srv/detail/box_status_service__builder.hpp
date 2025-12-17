// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/BoxStatusService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/box_status_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_BoxStatusService_Request_box_id
{
public:
  Init_BoxStatusService_Request_box_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::BoxStatusService_Request box_id(::dronehive_interfaces::srv::BoxStatusService_Request::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxStatusService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::BoxStatusService_Request>()
{
  return dronehive_interfaces::srv::builder::Init_BoxStatusService_Request_box_id();
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_BoxStatusService_Response_landing_pos
{
public:
  explicit Init_BoxStatusService_Response_landing_pos(::dronehive_interfaces::srv::BoxStatusService_Response & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::srv::BoxStatusService_Response landing_pos(::dronehive_interfaces::srv::BoxStatusService_Response::_landing_pos_type arg)
  {
    msg_.landing_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxStatusService_Response msg_;
};

class Init_BoxStatusService_Response_drone_id
{
public:
  explicit Init_BoxStatusService_Response_drone_id(::dronehive_interfaces::srv::BoxStatusService_Response & msg)
  : msg_(msg)
  {}
  Init_BoxStatusService_Response_landing_pos drone_id(::dronehive_interfaces::srv::BoxStatusService_Response::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_BoxStatusService_Response_landing_pos(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxStatusService_Response msg_;
};

class Init_BoxStatusService_Response_accept
{
public:
  Init_BoxStatusService_Response_accept()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxStatusService_Response_drone_id accept(::dronehive_interfaces::srv::BoxStatusService_Response::_accept_type arg)
  {
    msg_.accept = std::move(arg);
    return Init_BoxStatusService_Response_drone_id(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxStatusService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::BoxStatusService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_BoxStatusService_Response_accept();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SERVICE__BUILDER_HPP_
