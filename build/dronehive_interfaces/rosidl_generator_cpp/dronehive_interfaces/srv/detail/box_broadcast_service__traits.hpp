// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:srv/BoxBroadcastService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_BROADCAST_SERVICE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_BROADCAST_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/srv/detail/box_broadcast_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'landing_pos'
#include "dronehive_interfaces/msg/detail/position_message__traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const BoxBroadcastService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: box_id
  {
    out << "box_id: ";
    rosidl_generator_traits::value_to_yaml(msg.box_id, out);
    out << ", ";
  }

  // member: landing_pos
  {
    out << "landing_pos: ";
    to_flow_style_yaml(msg.landing_pos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BoxBroadcastService_Request & msg,
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

  // member: landing_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "landing_pos:\n";
    to_block_style_yaml(msg.landing_pos, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoxBroadcastService_Request & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::BoxBroadcastService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::BoxBroadcastService_Request & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::BoxBroadcastService_Request>()
{
  return "dronehive_interfaces::srv::BoxBroadcastService_Request";
}

template<>
inline const char * name<dronehive_interfaces::srv::BoxBroadcastService_Request>()
{
  return "dronehive_interfaces/srv/BoxBroadcastService_Request";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::BoxBroadcastService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::BoxBroadcastService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::BoxBroadcastService_Request>
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
  const BoxBroadcastService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: confirm
  {
    out << "confirm: ";
    rosidl_generator_traits::value_to_yaml(msg.confirm, out);
    out << ", ";
  }

  // member: box_id
  {
    out << "box_id: ";
    rosidl_generator_traits::value_to_yaml(msg.box_id, out);
    out << ", ";
  }

  // member: landing_pos
  {
    out << "landing_pos: ";
    to_flow_style_yaml(msg.landing_pos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BoxBroadcastService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: confirm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confirm: ";
    rosidl_generator_traits::value_to_yaml(msg.confirm, out);
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

  // member: landing_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "landing_pos:\n";
    to_block_style_yaml(msg.landing_pos, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoxBroadcastService_Response & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::BoxBroadcastService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::BoxBroadcastService_Response & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::BoxBroadcastService_Response>()
{
  return "dronehive_interfaces::srv::BoxBroadcastService_Response";
}

template<>
inline const char * name<dronehive_interfaces::srv::BoxBroadcastService_Response>()
{
  return "dronehive_interfaces/srv/BoxBroadcastService_Response";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::BoxBroadcastService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::BoxBroadcastService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::BoxBroadcastService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dronehive_interfaces::srv::BoxBroadcastService>()
{
  return "dronehive_interfaces::srv::BoxBroadcastService";
}

template<>
inline const char * name<dronehive_interfaces::srv::BoxBroadcastService>()
{
  return "dronehive_interfaces/srv/BoxBroadcastService";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::BoxBroadcastService>
  : std::integral_constant<
    bool,
    has_fixed_size<dronehive_interfaces::srv::BoxBroadcastService_Request>::value &&
    has_fixed_size<dronehive_interfaces::srv::BoxBroadcastService_Response>::value
  >
{
};

template<>
struct has_bounded_size<dronehive_interfaces::srv::BoxBroadcastService>
  : std::integral_constant<
    bool,
    has_bounded_size<dronehive_interfaces::srv::BoxBroadcastService_Request>::value &&
    has_bounded_size<dronehive_interfaces::srv::BoxBroadcastService_Response>::value
  >
{
};

template<>
struct is_service<dronehive_interfaces::srv::BoxBroadcastService>
  : std::true_type
{
};

template<>
struct is_service_request<dronehive_interfaces::srv::BoxBroadcastService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dronehive_interfaces::srv::BoxBroadcastService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_BROADCAST_SERVICE__TRAITS_HPP_
