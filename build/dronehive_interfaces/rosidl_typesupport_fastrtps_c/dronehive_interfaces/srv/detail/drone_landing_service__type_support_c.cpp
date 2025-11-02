// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dronehive_interfaces:srv/DroneLandingService.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/srv/detail/drone_landing_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dronehive_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dronehive_interfaces/srv/detail/drone_landing_service__struct.h"
#include "dronehive_interfaces/srv/detail/drone_landing_service__functions.h"
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

#include "dronehive_interfaces/msg/detail/position_message__functions.h"  // drone_pos
#include "rosidl_runtime_c/string.h"  // drone_id
#include "rosidl_runtime_c/string_functions.h"  // drone_id

// forward declare type support functions
size_t get_serialized_size_dronehive_interfaces__msg__PositionMessage(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dronehive_interfaces__msg__PositionMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, msg, PositionMessage)();


using _DroneLandingService_Request__ros_msg_type = dronehive_interfaces__srv__DroneLandingService_Request;

static bool _DroneLandingService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DroneLandingService_Request__ros_msg_type * ros_message = static_cast<const _DroneLandingService_Request__ros_msg_type *>(untyped_ros_message);
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

  // Field name: drone_pos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, dronehive_interfaces, msg, PositionMessage
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->drone_pos, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _DroneLandingService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DroneLandingService_Request__ros_msg_type * ros_message = static_cast<_DroneLandingService_Request__ros_msg_type *>(untyped_ros_message);
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

  // Field name: drone_pos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, dronehive_interfaces, msg, PositionMessage
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->drone_pos))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dronehive_interfaces
size_t get_serialized_size_dronehive_interfaces__srv__DroneLandingService_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DroneLandingService_Request__ros_msg_type * ros_message = static_cast<const _DroneLandingService_Request__ros_msg_type *>(untyped_ros_message);
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
  // field.name drone_pos

  current_alignment += get_serialized_size_dronehive_interfaces__msg__PositionMessage(
    &(ros_message->drone_pos), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _DroneLandingService_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dronehive_interfaces__srv__DroneLandingService_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dronehive_interfaces
size_t max_serialized_size_dronehive_interfaces__srv__DroneLandingService_Request(
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
  // member: drone_pos
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_dronehive_interfaces__msg__PositionMessage(
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
    using DataType = dronehive_interfaces__srv__DroneLandingService_Request;
    is_plain =
      (
      offsetof(DataType, drone_pos) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _DroneLandingService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dronehive_interfaces__srv__DroneLandingService_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DroneLandingService_Request = {
  "dronehive_interfaces::srv",
  "DroneLandingService_Request",
  _DroneLandingService_Request__cdr_serialize,
  _DroneLandingService_Request__cdr_deserialize,
  _DroneLandingService_Request__get_serialized_size,
  _DroneLandingService_Request__max_serialized_size
};

static rosidl_message_type_support_t _DroneLandingService_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DroneLandingService_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, srv, DroneLandingService_Request)() {
  return &_DroneLandingService_Request__type_support;
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
// #include "dronehive_interfaces/srv/detail/drone_landing_service__struct.h"
// already included above
// #include "dronehive_interfaces/srv/detail/drone_landing_service__functions.h"
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

// already included above
// #include "dronehive_interfaces/msg/detail/position_message__functions.h"  // landing_pos

// forward declare type support functions
size_t get_serialized_size_dronehive_interfaces__msg__PositionMessage(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dronehive_interfaces__msg__PositionMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, msg, PositionMessage)();


using _DroneLandingService_Response__ros_msg_type = dronehive_interfaces__srv__DroneLandingService_Response;

static bool _DroneLandingService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DroneLandingService_Response__ros_msg_type * ros_message = static_cast<const _DroneLandingService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: landing_pos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, dronehive_interfaces, msg, PositionMessage
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->landing_pos, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _DroneLandingService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DroneLandingService_Response__ros_msg_type * ros_message = static_cast<_DroneLandingService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: landing_pos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, dronehive_interfaces, msg, PositionMessage
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->landing_pos))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dronehive_interfaces
size_t get_serialized_size_dronehive_interfaces__srv__DroneLandingService_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DroneLandingService_Response__ros_msg_type * ros_message = static_cast<const _DroneLandingService_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name landing_pos

  current_alignment += get_serialized_size_dronehive_interfaces__msg__PositionMessage(
    &(ros_message->landing_pos), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _DroneLandingService_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dronehive_interfaces__srv__DroneLandingService_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dronehive_interfaces
size_t max_serialized_size_dronehive_interfaces__srv__DroneLandingService_Response(
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

  // member: landing_pos
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_dronehive_interfaces__msg__PositionMessage(
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
    using DataType = dronehive_interfaces__srv__DroneLandingService_Response;
    is_plain =
      (
      offsetof(DataType, landing_pos) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _DroneLandingService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dronehive_interfaces__srv__DroneLandingService_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DroneLandingService_Response = {
  "dronehive_interfaces::srv",
  "DroneLandingService_Response",
  _DroneLandingService_Response__cdr_serialize,
  _DroneLandingService_Response__cdr_deserialize,
  _DroneLandingService_Response__get_serialized_size,
  _DroneLandingService_Response__max_serialized_size
};

static rosidl_message_type_support_t _DroneLandingService_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DroneLandingService_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, srv, DroneLandingService_Response)() {
  return &_DroneLandingService_Response__type_support;
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
#include "dronehive_interfaces/srv/drone_landing_service.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t DroneLandingService__callbacks = {
  "dronehive_interfaces::srv",
  "DroneLandingService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, srv, DroneLandingService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, srv, DroneLandingService_Response)(),
};

static rosidl_service_type_support_t DroneLandingService__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &DroneLandingService__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dronehive_interfaces, srv, DroneLandingService)() {
  return &DroneLandingService__handle;
}

#if defined(__cplusplus)
}
#endif
