// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/DroneLandingService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_LANDING_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_LANDING_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/drone_landing_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_DroneLandingService_Request_drone_pos
{
public:
  explicit Init_DroneLandingService_Request_drone_pos(::dronehive_interfaces::srv::DroneLandingService_Request & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::srv::DroneLandingService_Request drone_pos(::dronehive_interfaces::srv::DroneLandingService_Request::_drone_pos_type arg)
  {
    msg_.drone_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::DroneLandingService_Request msg_;
};

class Init_DroneLandingService_Request_drone_id
{
public:
  Init_DroneLandingService_Request_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneLandingService_Request_drone_pos drone_id(::dronehive_interfaces::srv::DroneLandingService_Request::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_DroneLandingService_Request_drone_pos(msg_);
  }

private:
  ::dronehive_interfaces::srv::DroneLandingService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::DroneLandingService_Request>()
{
  return dronehive_interfaces::srv::builder::Init_DroneLandingService_Request_drone_id();
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_DroneLandingService_Response_landing_pos
{
public:
  Init_DroneLandingService_Response_landing_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::DroneLandingService_Response landing_pos(::dronehive_interfaces::srv::DroneLandingService_Response::_landing_pos_type arg)
  {
    msg_.landing_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::DroneLandingService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::DroneLandingService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_DroneLandingService_Response_landing_pos();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_LANDING_SERVICE__BUILDER_HPP_
