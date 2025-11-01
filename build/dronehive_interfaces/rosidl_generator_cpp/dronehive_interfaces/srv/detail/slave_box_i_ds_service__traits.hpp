// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dronehive_interfaces:srv/SlaveBoxIDsService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_I_DS_SERVICE__TRAITS_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_I_DS_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dronehive_interfaces/srv/detail/slave_box_i_ds_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SlaveBoxIDsService_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SlaveBoxIDsService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SlaveBoxIDsService_Request & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::SlaveBoxIDsService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::SlaveBoxIDsService_Request & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::SlaveBoxIDsService_Request>()
{
  return "dronehive_interfaces::srv::SlaveBoxIDsService_Request";
}

template<>
inline const char * name<dronehive_interfaces::srv::SlaveBoxIDsService_Request>()
{
  return "dronehive_interfaces/srv/SlaveBoxIDsService_Request";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::SlaveBoxIDsService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::SlaveBoxIDsService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dronehive_interfaces::srv::SlaveBoxIDsService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace dronehive_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SlaveBoxIDsService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: box_ids
  {
    if (msg.box_ids.size() == 0) {
      out << "box_ids: []";
    } else {
      out << "box_ids: [";
      size_t pending_items = msg.box_ids.size();
      for (auto item : msg.box_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: size
  {
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SlaveBoxIDsService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: box_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.box_ids.size() == 0) {
      out << "box_ids: []\n";
    } else {
      out << "box_ids:\n";
      for (auto item : msg.box_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SlaveBoxIDsService_Response & msg, bool use_flow_style = false)
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
  const dronehive_interfaces::srv::SlaveBoxIDsService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dronehive_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dronehive_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dronehive_interfaces::srv::SlaveBoxIDsService_Response & msg)
{
  return dronehive_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dronehive_interfaces::srv::SlaveBoxIDsService_Response>()
{
  return "dronehive_interfaces::srv::SlaveBoxIDsService_Response";
}

template<>
inline const char * name<dronehive_interfaces::srv::SlaveBoxIDsService_Response>()
{
  return "dronehive_interfaces/srv/SlaveBoxIDsService_Response";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::SlaveBoxIDsService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dronehive_interfaces::srv::SlaveBoxIDsService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dronehive_interfaces::srv::SlaveBoxIDsService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dronehive_interfaces::srv::SlaveBoxIDsService>()
{
  return "dronehive_interfaces::srv::SlaveBoxIDsService";
}

template<>
inline const char * name<dronehive_interfaces::srv::SlaveBoxIDsService>()
{
  return "dronehive_interfaces/srv/SlaveBoxIDsService";
}

template<>
struct has_fixed_size<dronehive_interfaces::srv::SlaveBoxIDsService>
  : std::integral_constant<
    bool,
    has_fixed_size<dronehive_interfaces::srv::SlaveBoxIDsService_Request>::value &&
    has_fixed_size<dronehive_interfaces::srv::SlaveBoxIDsService_Response>::value
  >
{
};

template<>
struct has_bounded_size<dronehive_interfaces::srv::SlaveBoxIDsService>
  : std::integral_constant<
    bool,
    has_bounded_size<dronehive_interfaces::srv::SlaveBoxIDsService_Request>::value &&
    has_bounded_size<dronehive_interfaces::srv::SlaveBoxIDsService_Response>::value
  >
{
};

template<>
struct is_service<dronehive_interfaces::srv::SlaveBoxIDsService>
  : std::true_type
{
};

template<>
struct is_service_request<dronehive_interfaces::srv::SlaveBoxIDsService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dronehive_interfaces::srv::SlaveBoxIDsService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_I_DS_SERVICE__TRAITS_HPP_
