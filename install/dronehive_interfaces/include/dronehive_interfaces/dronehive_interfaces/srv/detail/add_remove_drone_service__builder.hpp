// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/AddRemoveDroneService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__ADD_REMOVE_DRONE_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__ADD_REMOVE_DRONE_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/add_remove_drone_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddRemoveDroneService_Request_box_id
{
public:
  explicit Init_AddRemoveDroneService_Request_box_id(::dronehive_interfaces::srv::AddRemoveDroneService_Request & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::srv::AddRemoveDroneService_Request box_id(::dronehive_interfaces::srv::AddRemoveDroneService_Request::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::AddRemoveDroneService_Request msg_;
};

class Init_AddRemoveDroneService_Request_drone_id
{
public:
  Init_AddRemoveDroneService_Request_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddRemoveDroneService_Request_box_id drone_id(::dronehive_interfaces::srv::AddRemoveDroneService_Request::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_AddRemoveDroneService_Request_box_id(msg_);
  }

private:
  ::dronehive_interfaces::srv::AddRemoveDroneService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::AddRemoveDroneService_Request>()
{
  return dronehive_interfaces::srv::builder::Init_AddRemoveDroneService_Request_drone_id();
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddRemoveDroneService_Response_ack
{
public:
  Init_AddRemoveDroneService_Response_ack()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::AddRemoveDroneService_Response ack(::dronehive_interfaces::srv::AddRemoveDroneService_Response::_ack_type arg)
  {
    msg_.ack = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::AddRemoveDroneService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::AddRemoveDroneService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_AddRemoveDroneService_Response_ack();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__ADD_REMOVE_DRONE_SERVICE__BUILDER_HPP_
