// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dronehive_interfaces:srv/OccupancyService.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/srv/detail/occupancy_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dronehive_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dronehive_interfaces/srv/detail/occupancy_service__struct.h"
#include "dronehive_interfaces/srv/detail/occupancy_service__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // box_id, drone_id
#include "rosidl_runtime_c/string_functions.h"  // box_id, drone_id

// forward declare type support functions


using _OccupancyService_Request__ros_msg_type = dronehive_interfaces__srv__OccupancyService_Request;

static bool _OccupancyService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _OccupancyService_Request__ros_msg_type * ros_message = static_cast<const _OccupancyService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: drone_id
  {
    const rosidl_runtime_c__String * str = &ros_message->drone_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: box_id
  {
    const rosidl_runtime_c__String * str = &ros_message->box_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _OccupancyService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _OccupancyService_Request__ros_msg_type * ros_message = static_cast<_OccupancyService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: drone_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->drone_id.data) {
      rosidl_runtime_c__String__init(&ros_message->drone_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->drone_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'drone_id'\n");
      return false;
    }
  }

  // Field name: box_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->box_id.data) {
      rosidl_runtime_c__String__init(&ros_message->box_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->box_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'box_id'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dronehive_interfaces
size_t get_serialized_size_dronehive_interfaces__srv__OccupancyService_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _OccupancyService_Request__ros_msg_type * ros_message = static_cast<const _OccupancyService_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name drone_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->drone_id.size + 1);
  // field.name box_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->box_id.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _OccupancyService_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dronehive_interfaces__srv__OccupancyService_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dronehive_interfaces
size_t max_serialized_size_dronehive_interfaces__srv__OccupancyService_Request(
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

  // member: drone_id
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
  // member: box_id
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
    using DataType = dronehive_interfaces__srv__OccupancyService_Request;
    is_plain =
      (
      offsetof(DataType, box_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _OccupancyService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dronehive_interfaces__srv__OccupancyService_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_OccupancyService_Request = {
  "dronehive_interfaces::srv",
  "OccupancyService_Request",
  _OccupancyService_Request__cdr_serialize,
  _OccupancyService_Request__cdr_deserialize,
  _OccupancyService_Request__get_serialized_size,
  _OccupancyService_Request__max_serialized_size
};

static rosidl_message_type_support_t _OccupancyService_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_OccupancyService_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, srv, OccupancyService_Request)() {
  return &_OccupancyService_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "dronehive_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "dronehive_interfaces/srv/detail/occupancy_service__struct.h"
// already included above
// #include "dronehive_interfaces/srv/detail/occupancy_service__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _OccupancyService_Response__ros_msg_type = dronehive_interfaces__srv__OccupancyService_Response;

static bool _OccupancyService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _OccupancyService_Response__ros_msg_type * ros_message = static_cast<const _OccupancyService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: occupancy_status
  {
    cdr << (ros_message->occupancy_status ? true : false);
  }

  return true;
}

static bool _OccupancyService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _OccupancyService_Response__ros_msg_type * ros_message = static_cast<_OccupancyService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: occupancy_status
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->occupancy_status = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dronehive_interfaces
size_t get_serialized_size_dronehive_interfaces__srv__OccupancyService_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _OccupancyService_Response__ros_msg_type * ros_message = static_cast<const _OccupancyService_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name occupancy_status
  {
    size_t item_size = sizeof(ros_message->occupancy_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _OccupancyService_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dronehive_interfaces__srv__OccupancyService_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dronehive_interfaces
size_t max_serialized_size_dronehive_interfaces__srv__OccupancyService_Response(
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

  // member: occupancy_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dronehive_interfaces__srv__OccupancyService_Response;
    is_plain =
      (
      offsetof(DataType, occupancy_status) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _OccupancyService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dronehive_interfaces__srv__OccupancyService_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_OccupancyService_Response = {
  "dronehive_interfaces::srv",
  "OccupancyService_Response",
  _OccupancyService_Response__cdr_serialize,
  _OccupancyService_Response__cdr_deserialize,
  _OccupancyService_Response__get_serialized_size,
  _OccupancyService_Response__max_serialized_size
};

static rosidl_message_type_support_t _OccupancyService_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_OccupancyService_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, srv, OccupancyService_Response)() {
  return &_OccupancyService_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "dronehive_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dronehive_interfaces/srv/occupancy_service.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t OccupancyService__callbacks = {
  "dronehive_interfaces::srv",
  "OccupancyService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, srv, OccupancyService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, srv, OccupancyService_Response)(),
};

static rosidl_service_type_support_t OccupancyService__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &OccupancyService__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, srv, OccupancyService)() {
  return &OccupancyService__handle;
}

#if defined(__cplusplus)
}
#endif
