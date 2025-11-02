// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:srv/DroneStatusService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_STATUS_SERVICE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_STATUS_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/srv/detail/drone_status_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneStatusService_Request & msg,
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
  const DroneStatusService_Request & msg,
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

inline std::string to_yaml(const DroneStatusService_Request & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::DroneStatusService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::DroneStatusService_Request & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::DroneStatusService_Request>()
{
  return "dronehive_interfaces::srv::DroneStatusService_Request";
}

template<>
inline const char * name<dronehive_interfaces::srv::DroneStatusService_Request>()
{
  return "dronehive_interfaces/srv/DroneStatusService_Request";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::DroneStatusService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::DroneStatusService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::DroneStatusService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneStatusService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: battery_level
  {
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneStatusService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: battery_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneStatusService_Response & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::DroneStatusService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::DroneStatusService_Response & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::DroneStatusService_Response>()
{
  return "dronehive_interfaces::srv::DroneStatusService_Response";
}

template<>
inline const char * name<dronehive_interfaces::srv::DroneStatusService_Response>()
{
  return "dronehive_interfaces/srv/DroneStatusService_Response";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::DroneStatusService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::DroneStatusService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::DroneStatusService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dronehive_interfaces::srv::DroneStatusService>()
{
  return "dronehive_interfaces::srv::DroneStatusService";
}

template<>
inline const char * name<dronehive_interfaces::srv::DroneStatusService>()
{
  return "dronehive_interfaces/srv/DroneStatusService";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::DroneStatusService>
  : std::integral_constant<
    bool,
    has_fixed_size<dronehive_interfaces::srv::DroneStatusService_Request>::value &&
    has_fixed_size<dronehive_interfaces::srv::DroneStatusService_Response>::value
  >
{
};

template<>
struct has_bounded_size<dronehive_interfaces::srv::DroneStatusService>
  : std::integral_constant<
    bool,
    has_bounded_size<dronehive_interfaces::srv::DroneStatusService_Request>::value &&
    has_bounded_size<dronehive_interfaces::srv::DroneStatusService_Response>::value
  >
{
};

template<>
struct is_service<dronehive_interfaces::srv::DroneStatusService>
  : std::true_type
{
};

template<>
struct is_service_request<dronehive_interfaces::srv::DroneStatusService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dronehive_interfaces::srv::DroneStatusService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_STATUS_SERVICE__TRAITS_HPP_
