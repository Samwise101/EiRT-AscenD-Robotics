// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:srv/DroneStartStopService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_START_STOP_SERVICE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_START_STOP_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/srv/detail/drone_start_stop_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneStartStopService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: drone_id
  {
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << ", ";
  }

  // member: control_var
  {
    out << "control_var: ";
    rosidl_generator_traits::value_to_yaml(msg.control_var, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneStartStopService_Request & msg,
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

  // member: control_var
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_var: ";
    rosidl_generator_traits::value_to_yaml(msg.control_var, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneStartStopService_Request & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::DroneStartStopService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::DroneStartStopService_Request & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::DroneStartStopService_Request>()
{
  return "dronehive_interfaces::srv::DroneStartStopService_Request";
}

template<>
inline const char * name<dronehive_interfaces::srv::DroneStartStopService_Request>()
{
  return "dronehive_interfaces/srv/DroneStartStopService_Request";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::DroneStartStopService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::DroneStartStopService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::DroneStartStopService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneStartStopService_Response & msg,
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
  const DroneStartStopService_Response & msg,
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

inline std::string to_yaml(const DroneStartStopService_Response & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::DroneStartStopService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::DroneStartStopService_Response & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::DroneStartStopService_Response>()
{
  return "dronehive_interfaces::srv::DroneStartStopService_Response";
}

template<>
inline const char * name<dronehive_interfaces::srv::DroneStartStopService_Response>()
{
  return "dronehive_interfaces/srv/DroneStartStopService_Response";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::DroneStartStopService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::DroneStartStopService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dronehive_interfaces::srv::DroneStartStopService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dronehive_interfaces::srv::DroneStartStopService>()
{
  return "dronehive_interfaces::srv::DroneStartStopService";
}

template<>
inline const char * name<dronehive_interfaces::srv::DroneStartStopService>()
{
  return "dronehive_interfaces/srv/DroneStartStopService";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::DroneStartStopService>
  : std::integral_constant<
    bool,
    has_fixed_size<dronehive_interfaces::srv::DroneStartStopService_Request>::value &&
    has_fixed_size<dronehive_interfaces::srv::DroneStartStopService_Response>::value
  >
{
};

template<>
struct has_bounded_size<dronehive_interfaces::srv::DroneStartStopService>
  : std::integral_constant<
    bool,
    has_bounded_size<dronehive_interfaces::srv::DroneStartStopService_Request>::value &&
    has_bounded_size<dronehive_interfaces::srv::DroneStartStopService_Response>::value
  >
{
};

template<>
struct is_service<dronehive_interfaces::srv::DroneStartStopService>
  : std::true_type
{
};

template<>
struct is_service_request<dronehive_interfaces::srv::DroneStartStopService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dronehive_interfaces::srv::DroneStartStopService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_START_STOP_SERVICE__TRAITS_HPP_
