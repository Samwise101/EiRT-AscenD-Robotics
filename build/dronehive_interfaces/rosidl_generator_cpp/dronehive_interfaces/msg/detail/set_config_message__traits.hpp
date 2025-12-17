// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:msg/SetConfigMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__SET_CONFIG_MESSAGE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__SET_CONFIG_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/msg/detail/set_config_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dronehive_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetConfigMessage & msg,
  std::ostream & out)
{
  out << "{";
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

  // member: drone_name
  {
    out << "drone_name: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_name, out);
    out << ", ";
  }

  // member: drone_type
  {
    out << "drone_type: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_type, out);
    out << ", ";
  }

  // member: drone_setup
  {
    out << "drone_setup: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_setup, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetConfigMessage & msg,
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

  // member: drone_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << "\n";
  }

  // member: drone_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_name: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_name, out);
    out << "\n";
  }

  // member: drone_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_type: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_type, out);
    out << "\n";
  }

  // member: drone_setup
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_setup: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_setup, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetConfigMessage & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::msg::SetConfigMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::msg::SetConfigMessage & msg)
{
  return dronehive_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::msg::SetConfigMessage>()
{
  return "dronehive_interfaces::msg::SetConfigMessage";
}

template<>
inline const char * name<dronehive_interfaces::msg::SetConfigMessage>()
{
  return "dronehive_interfaces/msg/SetConfigMessage";
}

template<>
struct has_fixed_size<dronehive_interfaces::msg::SetConfigMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::msg::SetConfigMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::msg::SetConfigMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__SET_CONFIG_MESSAGE__TRAITS_HPP_
