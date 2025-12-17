// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/OccupancyService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__OCCUPANCY_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__OCCUPANCY_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/occupancy_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_OccupancyService_Request_box_id
{
public:
  explicit Init_OccupancyService_Request_box_id(::dronehive_interfaces::srv::OccupancyService_Request & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::srv::OccupancyService_Request box_id(::dronehive_interfaces::srv::OccupancyService_Request::_box_id_type arg)
  {
    msg_.box_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::OccupancyService_Request msg_;
};

class Init_OccupancyService_Request_drone_id
{
public:
  Init_OccupancyService_Request_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OccupancyService_Request_box_id drone_id(::dronehive_interfaces::srv::OccupancyService_Request::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_OccupancyService_Request_box_id(msg_);
  }

private:
  ::dronehive_interfaces::srv::OccupancyService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::OccupancyService_Request>()
{
  return dronehive_interfaces::srv::builder::Init_OccupancyService_Request_drone_id();
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_OccupancyService_Response_occupancy_status
{
public:
  Init_OccupancyService_Response_occupancy_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::OccupancyService_Response occupancy_status(::dronehive_interfaces::srv::OccupancyService_Response::_occupancy_status_type arg)
  {
    msg_.occupancy_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::OccupancyService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::OccupancyService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_OccupancyService_Response_occupancy_status();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__OCCUPANCY_SERVICE__BUILDER_HPP_
