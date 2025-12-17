// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/DroneTrajectoryWaypointsService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORY_WAYPOINTS_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORY_WAYPOINTS_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/drone_trajectory_waypoints_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_DroneTrajectoryWaypointsService_Request_waypoints
{
public:
  explicit Init_DroneTrajectoryWaypointsService_Request_waypoints(::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request waypoints(::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request msg_;
};

class Init_DroneTrajectoryWaypointsService_Request_drone_id
{
public:
  Init_DroneTrajectoryWaypointsService_Request_drone_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneTrajectoryWaypointsService_Request_waypoints drone_id(::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request::_drone_id_type arg)
  {
    msg_.drone_id = std::move(arg);
    return Init_DroneTrajectoryWaypointsService_Request_waypoints(msg_);
  }

private:
  ::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request>()
{
  return dronehive_interfaces::srv::builder::Init_DroneTrajectoryWaypointsService_Request_drone_id();
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_DroneTrajectoryWaypointsService_Response_ack
{
public:
  Init_DroneTrajectoryWaypointsService_Response_ack()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response ack(::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response::_ack_type arg)
  {
    msg_.ack = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_DroneTrajectoryWaypointsService_Response_ack();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORY_WAYPOINTS_SERVICE__BUILDER_HPP_
