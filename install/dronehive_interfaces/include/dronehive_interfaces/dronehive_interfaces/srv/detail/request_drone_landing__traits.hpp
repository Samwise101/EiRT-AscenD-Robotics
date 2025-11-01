// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:srv/RequestDroneLanding.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_DRONE_LANDING__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_DRONE_LANDING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/srv/detail/request_drone_landing__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'drone_pos'
#include "dronehive_interfaces/msg/detail/position_message__traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RequestDroneLanding_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: drone_id
  {
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << ", ";
  }

  // member: drone_pos
  {
    out << "drone_pos: ";
    to_flow_style_yaml(msg.drone_pos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestDroneLanding_Request & msg,
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

  // member: drone_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_pos:\n";
    to_block_style_yaml(msg.drone_pos, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestDroneLanding_Request & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::RequestDroneLanding_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::RequestDroneLanding_Request & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::RequestDroneLanding_Request>()
{
  return "dronehive_interfaces::srv::RequestDroneLanding_Request";
}

template<>
inline const char * name<dronehive_interfaces::srv::RequestDroneLanding_Request>()
{
  return "dronehive_interfaces/srv/RequestDroneLanding_Request";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::RequestDroneLanding_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::RequestDroneLanding_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::RequestDroneLanding_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'landing_pos'
// already included above
// #include "dronehive_interfaces/msg/detail/position_message__traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RequestDroneLanding_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: landing_pos
  {
    out << "landing_pos: ";
    to_flow_style_yaml(msg.landing_pos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestDroneLanding_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestDroneLanding_Response & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::RequestDroneLanding_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::RequestDroneLanding_Response & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::RequestDroneLanding_Response>()
{
  return "dronehive_interfaces::srv::RequestDroneLanding_Response";
}

template<>
inline const char * name<dronehive_interfaces::srv::RequestDroneLanding_Response>()
{
  return "dronehive_interfaces/srv/RequestDroneLanding_Response";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::RequestDroneLanding_Response>
  : std::integral_constant<bool, has_fixed_size<dronehive_interfaces::msg::PositionMessage>::value> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::RequestDroneLanding_Response>
  : std::integral_constant<bool, has_bounded_size<dronehive_interfaces::msg::PositionMessage>::value> {};

template<>
struct is_message<dronehive_interfaces::srv::RequestDroneLanding_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dronehive_interfaces::srv::RequestDroneLanding>()
{
  return "dronehive_interfaces::srv::RequestDroneLanding";
}

template<>
inline const char * name<dronehive_interfaces::srv::RequestDroneLanding>()
{
  return "dronehive_interfaces/srv/RequestDroneLanding";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::RequestDroneLanding>
  : std::integral_constant<
    bool,
    has_fixed_size<dronehive_interfaces::srv::RequestDroneLanding_Request>::value &&
    has_fixed_size<dronehive_interfaces::srv::RequestDroneLanding_Response>::value
  >
{
};

template<>
struct has_bounded_size<dronehive_interfaces::srv::RequestDroneLanding>
  : std::integral_constant<
    bool,
    has_bounded_size<dronehive_interfaces::srv::RequestDroneLanding_Request>::value &&
    has_bounded_size<dronehive_interfaces::srv::RequestDroneLanding_Response>::value
  >
{
};

template<>
struct is_service<dronehive_interfaces::srv::RequestDroneLanding>
  : std::true_type
{
};

template<>
struct is_service_request<dronehive_interfaces::srv::RequestDroneLanding_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dronehive_interfaces::srv::RequestDroneLanding_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_DRONE_LANDING__TRAITS_HPP_
