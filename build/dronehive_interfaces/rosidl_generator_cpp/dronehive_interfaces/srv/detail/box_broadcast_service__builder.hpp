// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/BoxBroadcastService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_BROADCAST_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_BROADCAST_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/box_broadcast_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_BoxBroadcastService_Request_landing_pos
{
public:
  explicit Init_BoxBroadcastService_Request_landing_pos(::dronehive_interfaces::srv::BoxBroadcastService_Request & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::srv::BoxBroadcastService_Request landing_pos(::dronehive_interfaces::srv::BoxBroadcastService_Request::_landing_pos_type arg)
  {
    msg_.landing_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxBroadcastService_Request msg_;
};

class Init_BoxBroadcastService_Request_box_id
{
public:
  Init_BoxBroadcastService_Request_box_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxBroadcastService_Request_landing_pos box_id(::dronehive_interfaces::srv::BoxBroadcastService_Request::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return Init_BoxBroadcastService_Request_landing_pos(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxBroadcastService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::BoxBroadcastService_Request>()
{
  return dronehive_interfaces::srv::builder::Init_BoxBroadcastService_Request_box_id();
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_BoxBroadcastService_Response_landing_pos
{
public:
  explicit Init_BoxBroadcastService_Response_landing_pos(::dronehive_interfaces::srv::BoxBroadcastService_Response & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::srv::BoxBroadcastService_Response landing_pos(::dronehive_interfaces::srv::BoxBroadcastService_Response::_landing_pos_type arg)
  {
    msg_.landing_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxBroadcastService_Response msg_;
};

class Init_BoxBroadcastService_Response_box_id
{
public:
  explicit Init_BoxBroadcastService_Response_box_id(::dronehive_interfaces::srv::BoxBroadcastService_Response & msg)
  : msg_(msg)
  {}
  Init_BoxBroadcastService_Response_landing_pos box_id(::dronehive_interfaces::srv::BoxBroadcastService_Response::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return Init_BoxBroadcastService_Response_landing_pos(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxBroadcastService_Response msg_;
};

class Init_BoxBroadcastService_Response_confirm
{
public:
  Init_BoxBroadcastService_Response_confirm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxBroadcastService_Response_box_id confirm(::dronehive_interfaces::srv::BoxBroadcastService_Response::_confirm_type arg)
  {
    msg_.confirm = std::move(arg);
    return Init_BoxBroadcastService_Response_box_id(msg_);
  }

private:
  ::dronehive_interfaces::srv::BoxBroadcastService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::BoxBroadcastService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_BoxBroadcastService_Response_confirm();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_BROADCAST_SERVICE__BUILDER_HPP_
