// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:srv/BoxStatusSlaveUpdateService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/srv/detail/box_status_slave_update_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'status'
#include "dronehive_interfaces/msg/detail/box_status_message__traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const BoxStatusSlaveUpdateService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    to_flow_style_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BoxStatusSlaveUpdateService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status:\n";
    to_block_style_yaml(msg.status, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoxStatusSlaveUpdateService_Request & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request>()
{
  return "dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request";
}

template<>
inline const char * name<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request>()
{
  return "dronehive_interfaces/srv/BoxStatusSlaveUpdateService_Request";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request>
  : std::integral_constant<bool, has_fixed_size<dronehive_interfaces::msg::BoxStatusMessage>::value> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request>
  : std::integral_constant<bool, has_bounded_size<dronehive_interfaces::msg::BoxStatusMessage>::value> {};

template<>
struct is_message<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const BoxStatusSlaveUpdateService_Response & msg,
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
  const BoxStatusSlaveUpdateService_Response & msg,
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

inline std::string to_yaml(const BoxStatusSlaveUpdateService_Response & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response>()
{
  return "dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response";
}

template<>
inline const char * name<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response>()
{
  return "dronehive_interfaces/srv/BoxStatusSlaveUpdateService_Response";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dronehive_interfaces::srv::BoxStatusSlaveUpdateService>()
{
  return "dronehive_interfaces::srv::BoxStatusSlaveUpdateService";
}

template<>
inline const char * name<dronehive_interfaces::srv::BoxStatusSlaveUpdateService>()
{
  return "dronehive_interfaces/srv/BoxStatusSlaveUpdateService";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::BoxStatusSlaveUpdateService>
  : std::integral_constant<
    bool,
    has_fixed_size<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request>::value &&
    has_fixed_size<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response>::value
  >
{
};

template<>
struct has_bounded_size<dronehive_interfaces::srv::BoxStatusSlaveUpdateService>
  : std::integral_constant<
    bool,
    has_bounded_size<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request>::value &&
    has_bounded_size<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response>::value
  >
{
};

template<>
struct is_service<dronehive_interfaces::srv::BoxStatusSlaveUpdateService>
  : std::true_type
{
};

template<>
struct is_service_request<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__TRAITS_HPP_
