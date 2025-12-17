// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from dronehive_interfaces:srv/SlaveBoxInformationService.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/srv/detail/slave_box_information_service__rosidl_typesupport_fastrtps_cpp.hpp"
#include "dronehive_interfaces/srv/detail/slave_box_information_service__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace dronehive_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
cdr_serialize(
  const dronehive_interfaces::srv::SlaveBoxInformationService_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: box_id
  cdr << ros_message.box_id;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dronehive_interfaces::srv::SlaveBoxInformationService_Request & ros_message)
{
  // Member: box_id
  cdr >> ros_message.box_id;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
get_serialized_size(
  const dronehive_interfaces::srv::SlaveBoxInformationService_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: box_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.box_id.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
max_serialized_size_SlaveBoxInformationService_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: box_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dronehive_interfaces::srv::SlaveBoxInformationService_Request;
    is_plain =
      (
      offsetof(DataType, box_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SlaveBoxInformationService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const dronehive_interfaces::srv::SlaveBoxInformationService_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SlaveBoxInformationService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dronehive_interfaces::srv::SlaveBoxInformationService_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SlaveBoxInformationService_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dronehive_interfaces::srv::SlaveBoxInformationService_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SlaveBoxInformationService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SlaveBoxInformationService_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SlaveBoxInformationService_Request__callbacks = {
  "dronehive_interfaces::srv",
  "SlaveBoxInformationService_Request",
  _SlaveBoxInformationService_Request__cdr_serialize,
  _SlaveBoxInformationService_Request__cdr_deserialize,
  _SlaveBoxInformationService_Request__get_serialized_size,
  _SlaveBoxInformationService_Request__max_serialized_size
};

static rosidl_message_type_support_t _SlaveBoxInformationService_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SlaveBoxInformationService_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace dronehive_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_dronehive_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<dronehive_interfaces::srv::SlaveBoxInformationService_Request>()
{
  return &dronehive_interfaces::srv::typesupport_fastrtps_cpp::_SlaveBoxInformationService_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dronehive_interfaces, srv, SlaveBoxInformationService_Request)() {
  return &dronehive_interfaces::srv::typesupport_fastrtps_cpp::_SlaveBoxInformationService_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace dronehive_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const dronehive_interfaces::msg::BoxStatusMessage &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  dronehive_interfaces::msg::BoxStatusMessage &);
size_t get_serialized_size(
  const dronehive_interfaces::msg::BoxStatusMessage &,
  size_t current_alignment);
size_t
max_serialized_size_BoxStatusMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
cdr_serialize(
  const dronehive_interfaces::srv::SlaveBoxInformationService_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: status
  dronehive_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.status,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dronehive_interfaces::srv::SlaveBoxInformationService_Response & ros_message)
{
  // Member: status
  dronehive_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.status);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
get_serialized_size(
  const dronehive_interfaces::srv::SlaveBoxInformationService_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: status

  current_alignment +=
    dronehive_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.status, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
max_serialized_size_SlaveBoxInformationService_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: status
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        dronehive_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_BoxStatusMessage(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dronehive_interfaces::srv::SlaveBoxInformationService_Response;
    is_plain =
      (
      offsetof(DataType, status) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SlaveBoxInformationService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const dronehive_interfaces::srv::SlaveBoxInformationService_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SlaveBoxInformationService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dronehive_interfaces::srv::SlaveBoxInformationService_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SlaveBoxInformationService_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dronehive_interfaces::srv::SlaveBoxInformationService_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SlaveBoxInformationService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SlaveBoxInformationService_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SlaveBoxInformationService_Response__callbacks = {
  "dronehive_interfaces::srv",
  "SlaveBoxInformationService_Response",
  _SlaveBoxInformationService_Response__cdr_serialize,
  _SlaveBoxInformationService_Response__cdr_deserialize,
  _SlaveBoxInformationService_Response__get_serialized_size,
  _SlaveBoxInformationService_Response__max_serialized_size
};

static rosidl_message_type_support_t _SlaveBoxInformationService_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SlaveBoxInformationService_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace dronehive_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_dronehive_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<dronehive_interfaces::srv::SlaveBoxInformationService_Response>()
{
  return &dronehive_interfaces::srv::typesupport_fastrtps_cpp::_SlaveBoxInformationService_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dronehive_interfaces, srv, SlaveBoxInformationService_Response)() {
  return &dronehive_interfaces::srv::typesupport_fastrtps_cpp::_SlaveBoxInformationService_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace dronehive_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _SlaveBoxInformationService__callbacks = {
  "dronehive_interfaces::srv",
  "SlaveBoxInformationService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dronehive_interfaces, srv, SlaveBoxInformationService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dronehive_interfaces, srv, SlaveBoxInformationService_Response)(),
};

static rosidl_service_type_support_t _SlaveBoxInformationService__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SlaveBoxInformationService__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace dronehive_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_dronehive_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<dronehive_interfaces::srv::SlaveBoxInformationService>()
{
  return &dronehive_interfaces::srv::typesupport_fastrtps_cpp::_SlaveBoxInformationService__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dronehive_interfaces, srv, SlaveBoxInformationService)() {
  return &dronehive_interfaces::srv::typesupport_fastrtps_cpp::_SlaveBoxInformationService__handle;
}

#ifdef __cplusplus
}
#endif
