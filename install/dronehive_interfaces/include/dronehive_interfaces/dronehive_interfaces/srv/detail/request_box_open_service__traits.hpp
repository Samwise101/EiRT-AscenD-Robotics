// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:srv/RequestBoxOpenService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_BOX_OPEN_SERVICE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_BOX_OPEN_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/srv/detail/request_box_open_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RequestBoxOpenService_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RequestBoxOpenService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RequestBoxOpenService_Request & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::RequestBoxOpenService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::RequestBoxOpenService_Request & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::RequestBoxOpenService_Request>()
{
  return "dronehive_interfaces::srv::RequestBoxOpenService_Request";
}

template<>
inline const char * name<dronehive_interfaces::srv::RequestBoxOpenService_Request>()
{
  return "dronehive_interfaces/srv/RequestBoxOpenService_Request";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::RequestBoxOpenService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::RequestBoxOpenService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dronehive_interfaces::srv::RequestBoxOpenService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RequestBoxOpenService_Response & msg,
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
  const RequestBoxOpenService_Response & msg,
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

inline std::string to_yaml(const RequestBoxOpenService_Response & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::RequestBoxOpenService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::RequestBoxOpenService_Response & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::RequestBoxOpenService_Response>()
{
  return "dronehive_interfaces::srv::RequestBoxOpenService_Response";
}

template<>
inline const char * name<dronehive_interfaces::srv::RequestBoxOpenService_Response>()
{
  return "dronehive_interfaces/srv/RequestBoxOpenService_Response";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::RequestBoxOpenService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::RequestBoxOpenService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dronehive_interfaces::srv::RequestBoxOpenService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dronehive_interfaces::srv::RequestBoxOpenService>()
{
  return "dronehive_interfaces::srv::RequestBoxOpenService";
}

template<>
inline const char * name<dronehive_interfaces::srv::RequestBoxOpenService>()
{
  return "dronehive_interfaces/srv/RequestBoxOpenService";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::RequestBoxOpenService>
  : std::integral_constant<
    bool,
    has_fixed_size<dronehive_interfaces::srv::RequestBoxOpenService_Request>::value &&
    has_fixed_size<dronehive_interfaces::srv::RequestBoxOpenService_Response>::value
  >
{
};

template<>
struct has_bounded_size<dronehive_interfaces::srv::RequestBoxOpenService>
  : std::integral_constant<
    bool,
    has_bounded_size<dronehive_interfaces::srv::RequestBoxOpenService_Request>::value &&
    has_bounded_size<dronehive_interfaces::srv::RequestBoxOpenService_Response>::value
  >
{
};

template<>
struct is_service<dronehive_interfaces::srv::RequestBoxOpenService>
  : std::true_type
{
};

template<>
struct is_service_request<dronehive_interfaces::srv::RequestBoxOpenService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dronehive_interfaces::srv::RequestBoxOpenService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_BOX_OPEN_SERVICE__TRAITS_HPP_
