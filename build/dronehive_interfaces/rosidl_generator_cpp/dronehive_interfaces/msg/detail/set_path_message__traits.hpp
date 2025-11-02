// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:msg/SetPathMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__SET_PATH_MESSAGE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__SET_PATH_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/msg/detail/set_path_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoints'
#include "dronehive_interfaces/msg/detail/position_message__traits.hpp"

namespace dronehive_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetPathMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: box_id
  {
    out << "box_id: ";
    rosidl_generator_traits::value_to_yaml(msg.box_id, out);
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
  const SetPathMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: box_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "box_id: ";
    rosidl_generator_traits::value_to_yaml(msg.box_id, out);
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

inline std::string to_yaml(const SetPathMessage & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::msg::SetPathMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::msg::SetPathMessage & msg)
{
  return dronehive_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::msg::SetPathMessage>()
{
  return "dronehive_interfaces::msg::SetPathMessage";
}

template<>
inline const char * name<dronehive_interfaces::msg::SetPathMessage>()
{
  return "dronehive_interfaces/msg/SetPathMessage";
}

template<>
struct has_fixed_size<dronehive_interfaces::msg::SetPathMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::msg::SetPathMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::msg::SetPathMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__SET_PATH_MESSAGE__TRAITS_HPP_
