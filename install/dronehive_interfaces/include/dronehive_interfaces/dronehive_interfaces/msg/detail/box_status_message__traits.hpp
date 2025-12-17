// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:msg/BoxStatusMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/msg/detail/box_status_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'landing_pos'
#include "dronehive_interfaces/msg/detail/position_message__traits.hpp"

namespace dronehive_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const BoxStatusMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: landing_pos
  {
    out << "landing_pos: ";
    to_flow_style_yaml(msg.landing_pos, out);
    out << ", ";
  }

  // member: box_battery_level
  {
    out << "box_battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.box_battery_level, out);
    out << ", ";
  }

  // member: box_id
  {
    out << "box_id: ";
    rosidl_generator_traits::value_to_yaml(msg.box_id, out);
    out << ", ";
  }

  // member: drone_id
  {
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BoxStatusMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: landing_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "landing_pos:\n";
    to_block_style_yaml(msg.landing_pos, out, indentation + 2);
  }

  // member: box_battery_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "box_battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.box_battery_level, out);
    out << "\n";
  }

  // member: box_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "box_id: ";
    rosidl_generator_traits::value_to_yaml(msg.box_id, out);
    out << "\n";
  }

  // member: drone_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoxStatusMessage & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::msg::BoxStatusMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::msg::BoxStatusMessage & msg)
{
  return dronehive_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::msg::BoxStatusMessage>()
{
  return "dronehive_interfaces::msg::BoxStatusMessage";
}

template<>
inline const char * name<dronehive_interfaces::msg::BoxStatusMessage>()
{
  return "dronehive_interfaces/msg/BoxStatusMessage";
}

template<>
struct has_fixed_size<dronehive_interfaces::msg::BoxStatusMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::msg::BoxStatusMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::msg::BoxStatusMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__TRAITS_HPP_
