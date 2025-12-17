// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:srv/DroneTrajectoryWaypointsService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORY_WAYPOINTS_SERVICE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORY_WAYPOINTS_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/srv/detail/drone_trajectory_waypoints_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoints'
#include "dronehive_interfaces/msg/detail/position_message__traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneTrajectoryWaypointsService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: drone_id
  {
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << ", ";
  }

  // member: waypoints
  {
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []";
    } else {
      out << "waypoints: [";
      size_t pending_items = msg.waypoints.size();
      for (auto item : msg.waypoints) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneTrajectoryWaypointsService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: drone_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << "\n";
  }

  // member: waypoints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []\n";
    } else {
      out << "waypoints:\n";
      for (auto item : msg.waypoints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneTrajectoryWaypointsService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace dronehive_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use dronehive_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request>()
{
  return "dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request";
}

template<>
inline const char * name<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request>()
{
  return "dronehive_interfaces/srv/DroneTrajectoryWaypointsService_Request";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneTrajectoryWaypointsService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: ack
  {
    out << "ack: ";
    rosidl_generator_traits::value_to_yaml(msg.ack, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneTrajectoryWaypointsService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ack
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ack: ";
    rosidl_generator_traits::value_to_yaml(msg.ack, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneTrajectoryWaypointsService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace dronehive_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use dronehive_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response>()
{
  return "dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response";
}

template<>
inline const char * name<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response>()
{
  return "dronehive_interfaces/srv/DroneTrajectoryWaypointsService_Response";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dronehive_interfaces::srv::DroneTrajectoryWaypointsService>()
{
  return "dronehive_interfaces::srv::DroneTrajectoryWaypointsService";
}

template<>
inline const char * name<dronehive_interfaces::srv::DroneTrajectoryWaypointsService>()
{
  return "dronehive_interfaces/srv/DroneTrajectoryWaypointsService";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::DroneTrajectoryWaypointsService>
  : std::integral_constant<
    bool,
    has_fixed_size<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request>::value &&
    has_fixed_size<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response>::value
  >
{
};

template<>
struct has_bounded_size<dronehive_interfaces::srv::DroneTrajectoryWaypointsService>
  : std::integral_constant<
    bool,
    has_bounded_size<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request>::value &&
    has_bounded_size<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response>::value
  >
{
};

template<>
struct is_service<dronehive_interfaces::srv::DroneTrajectoryWaypointsService>
  : std::true_type
{
};

template<>
struct is_service_request<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dronehive_interfaces::srv::DroneTrajectoryWaypointsService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORY_WAYPOINTS_SERVICE__TRAITS_HPP_
