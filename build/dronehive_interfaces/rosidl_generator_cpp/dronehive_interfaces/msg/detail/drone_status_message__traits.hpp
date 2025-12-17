// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:msg/DroneStatusMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/msg/detail/drone_status_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'current_position'
#include "dronehive_interfaces/msg/detail/position_message__traits.hpp"

namespace dronehive_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DroneStatusMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: drone_id
  {
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << ", ";
  }

  // member: battery_voltage
  {
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << ", ";
  }

  // member: battery_percentage
  {
    out << "battery_percentage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_percentage, out);
    out << ", ";
  }

  // member: fligt_state
  {
    out << "fligt_state: ";
    rosidl_generator_traits::value_to_yaml(msg.fligt_state, out);
    out << ", ";
  }

  // member: reached_first_waypoint
  {
    out << "reached_first_waypoint: ";
    rosidl_generator_traits::value_to_yaml(msg.reached_first_waypoint, out);
    out << ", ";
  }

  // member: current_position
  {
    out << "current_position: ";
    to_flow_style_yaml(msg.current_position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneStatusMessage & msg,
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

  // member: battery_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << "\n";
  }

  // member: battery_percentage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_percentage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_percentage, out);
    out << "\n";
  }

  // member: fligt_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fligt_state: ";
    rosidl_generator_traits::value_to_yaml(msg.fligt_state, out);
    out << "\n";
  }

  // member: reached_first_waypoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reached_first_waypoint: ";
    rosidl_generator_traits::value_to_yaml(msg.reached_first_waypoint, out);
    out << "\n";
  }

  // member: current_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_position:\n";
    to_block_style_yaml(msg.current_position, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneStatusMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace dronehive_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use dronehive_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dronehive_interfaces::msg::DroneStatusMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::msg::DroneStatusMessage & msg)
{
  return dronehive_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::msg::DroneStatusMessage>()
{
  return "dronehive_interfaces::msg::DroneStatusMessage";
}

template<>
inline const char * name<dronehive_interfaces::msg::DroneStatusMessage>()
{
  return "dronehive_interfaces/msg/DroneStatusMessage";
}

template<>
struct has_fixed_size<dronehive_interfaces::msg::DroneStatusMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::msg::DroneStatusMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::msg::DroneStatusMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__TRAITS_HPP_
