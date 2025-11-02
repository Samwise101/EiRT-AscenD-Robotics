// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:srv/GetFlightlog.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__GET_FLIGHTLOG__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__GET_FLIGHTLOG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/srv/detail/get_flightlog__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetFlightlog_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: box_id
  {
    out << "box_id: ";
    rosidl_generator_traits::value_to_yaml(msg.box_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetFlightlog_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetFlightlog_Request & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::GetFlightlog_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::GetFlightlog_Request & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::GetFlightlog_Request>()
{
  return "dronehive_interfaces::srv::GetFlightlog_Request";
}

template<>
inline const char * name<dronehive_interfaces::srv::GetFlightlog_Request>()
{
  return "dronehive_interfaces/srv/GetFlightlog_Request";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::GetFlightlog_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::GetFlightlog_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::GetFlightlog_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetFlightlog_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: log
  {
    out << "log: ";
    rosidl_generator_traits::value_to_yaml(msg.log, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetFlightlog_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: log
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "log: ";
    rosidl_generator_traits::value_to_yaml(msg.log, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetFlightlog_Response & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::GetFlightlog_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::GetFlightlog_Response & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::GetFlightlog_Response>()
{
  return "dronehive_interfaces::srv::GetFlightlog_Response";
}

template<>
inline const char * name<dronehive_interfaces::srv::GetFlightlog_Response>()
{
  return "dronehive_interfaces/srv/GetFlightlog_Response";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::GetFlightlog_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::GetFlightlog_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::GetFlightlog_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dronehive_interfaces::srv::GetFlightlog>()
{
  return "dronehive_interfaces::srv::GetFlightlog";
}

template<>
inline const char * name<dronehive_interfaces::srv::GetFlightlog>()
{
  return "dronehive_interfaces/srv/GetFlightlog";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::GetFlightlog>
  : std::integral_constant<
    bool,
    has_fixed_size<dronehive_interfaces::srv::GetFlightlog_Request>::value &&
    has_fixed_size<dronehive_interfaces::srv::GetFlightlog_Response>::value
  >
{
};

template<>
struct has_bounded_size<dronehive_interfaces::srv::GetFlightlog>
  : std::integral_constant<
    bool,
    has_bounded_size<dronehive_interfaces::srv::GetFlightlog_Request>::value &&
    has_bounded_size<dronehive_interfaces::srv::GetFlightlog_Response>::value
  >
{
};

template<>
struct is_service<dronehive_interfaces::srv::GetFlightlog>
  : std::true_type
{
};

template<>
struct is_service_request<dronehive_interfaces::srv::GetFlightlog_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dronehive_interfaces::srv::GetFlightlog_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__GET_FLIGHTLOG__TRAITS_HPP_
