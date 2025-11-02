// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:srv/RequestFullSystemStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/srv/detail/request_full_system_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RequestFullSystemStatus_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestFullSystemStatus_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestFullSystemStatus_Request & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::RequestFullSystemStatus_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::RequestFullSystemStatus_Request & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::RequestFullSystemStatus_Request>()
{
  return "dronehive_interfaces::srv::RequestFullSystemStatus_Request";
}

template<>
inline const char * name<dronehive_interfaces::srv::RequestFullSystemStatus_Request>()
{
  return "dronehive_interfaces/srv/RequestFullSystemStatus_Request";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::RequestFullSystemStatus_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::RequestFullSystemStatus_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dronehive_interfaces::srv::RequestFullSystemStatus_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'statuses'
#include "dronehive_interfaces/msg/detail/box_full_status__traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RequestFullSystemStatus_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: statuses
  {
    if (msg.statuses.size() == 0) {
      out << "statuses: []";
    } else {
      out << "statuses: [";
      size_t pending_items = msg.statuses.size();
      for (auto item : msg.statuses) {
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
  const RequestFullSystemStatus_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: statuses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.statuses.size() == 0) {
      out << "statuses: []\n";
    } else {
      out << "statuses:\n";
      for (auto item : msg.statuses) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestFullSystemStatus_Response & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::RequestFullSystemStatus_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::RequestFullSystemStatus_Response & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::RequestFullSystemStatus_Response>()
{
  return "dronehive_interfaces::srv::RequestFullSystemStatus_Response";
}

template<>
inline const char * name<dronehive_interfaces::srv::RequestFullSystemStatus_Response>()
{
  return "dronehive_interfaces/srv/RequestFullSystemStatus_Response";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::RequestFullSystemStatus_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::RequestFullSystemStatus_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::RequestFullSystemStatus_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dronehive_interfaces::srv::RequestFullSystemStatus>()
{
  return "dronehive_interfaces::srv::RequestFullSystemStatus";
}

template<>
inline const char * name<dronehive_interfaces::srv::RequestFullSystemStatus>()
{
  return "dronehive_interfaces/srv/RequestFullSystemStatus";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::RequestFullSystemStatus>
  : std::integral_constant<
    bool,
    has_fixed_size<dronehive_interfaces::srv::RequestFullSystemStatus_Request>::value &&
    has_fixed_size<dronehive_interfaces::srv::RequestFullSystemStatus_Response>::value
  >
{
};

template<>
struct has_bounded_size<dronehive_interfaces::srv::RequestFullSystemStatus>
  : std::integral_constant<
    bool,
    has_bounded_size<dronehive_interfaces::srv::RequestFullSystemStatus_Request>::value &&
    has_bounded_size<dronehive_interfaces::srv::RequestFullSystemStatus_Response>::value
  >
{
};

template<>
struct is_service<dronehive_interfaces::srv::RequestFullSystemStatus>
  : std::true_type
{
};

template<>
struct is_service_request<dronehive_interfaces::srv::RequestFullSystemStatus_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dronehive_interfaces::srv::RequestFullSystemStatus_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__TRAITS_HPP_
