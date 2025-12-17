// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:msg/ToggleTrajectory.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__TOGGLE_TRAJECTORY__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__TOGGLE_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/msg/detail/toggle_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dronehive_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ToggleTrajectory & msg,
  std::ostream & out)
{
  out << "{";
  // member: drone_id
  {
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << ", ";
  }

  // member: toggle
  {
    out << "toggle: ";
    rosidl_generator_traits::value_to_yaml(msg.toggle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ToggleTrajectory & msg,
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

  // member: toggle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "toggle: ";
    rosidl_generator_traits::value_to_yaml(msg.toggle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ToggleTrajectory & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::msg::ToggleTrajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::msg::ToggleTrajectory & msg)
{
  return dronehive_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::msg::ToggleTrajectory>()
{
  return "dronehive_interfaces::msg::ToggleTrajectory";
}

template<>
inline const char * name<dronehive_interfaces::msg::ToggleTrajectory>()
{
  return "dronehive_interfaces/msg/ToggleTrajectory";
}

template<>
struct has_fixed_size<dronehive_interfaces::msg::ToggleTrajectory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::msg::ToggleTrajectory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::msg::ToggleTrajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__TOGGLE_TRAJECTORY__TRAITS_HPP_
