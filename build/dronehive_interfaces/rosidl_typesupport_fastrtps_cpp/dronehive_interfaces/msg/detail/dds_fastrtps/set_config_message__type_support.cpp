// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from dronehive_interfaces:msg/SetConfigMessage.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/msg/detail/set_config_message__rosidl_typesupport_fastrtps_cpp.hpp"
#include "dronehive_interfaces/msg/detail/set_config_message__struct.hpp"

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

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
cdr_serialize(
  const dronehive_interfaces::msg::SetConfigMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: box_id
  cdr << ros_message.box_id;
  // Member: drone_id
  cdr << ros_message.drone_id;
  // Member: drone_name
  cdr << ros_message.drone_name;
  // Member: drone_type
  cdr << ros_message.drone_type;
  // Member: drone_setup
  cdr << ros_message.drone_setup;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dronehive_interfaces::msg::SetConfigMessage & ros_message)
{
  // Member: box_id
  cdr >> ros_message.box_id;

  // Member: drone_id
  cdr >> ros_message.drone_id;

  // Member: drone_name
  cdr >> ros_message.drone_name;

  // Member: drone_type
  cdr >> ros_message.drone_type;

  // Member: drone_setup
  cdr >> ros_message.drone_setup;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
get_serialized_size(
  const dronehive_interfaces::msg::SetConfigMessage & ros_message,
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
  // Member: drone_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.drone_id.size() + 1);
  // Member: drone_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.drone_name.size() + 1);
  // Member: drone_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.drone_type.size() + 1);
  // Member: drone_setup
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.drone_setup.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dronehive_interfaces
max_serialized_size_SetConfigMessage(
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

  // Member: drone_id
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

  // Member: drone_name
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

  // Member: drone_type
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

  // Member: drone_setup
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
    using DataType = dronehive_interfaces::msg::SetConfigMessage;
    is_plain =
      (
      offsetof(DataType, drone_setup) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SetConfigMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const dronehive_interfaces::msg::SetConfigMessage *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetConfigMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dronehive_interfaces::msg::SetConfigMessage *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetConfigMessage__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dronehive_interfaces::msg::SetConfigMessage *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetConfigMessage__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetConfigMessage(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetConfigMessage__callbacks = {
  "dronehive_interfaces::msg",
  "SetConfigMessage",
  _SetConfigMessage__cdr_serialize,
  _SetConfigMessage__cdr_deserialize,
  _SetConfigMessage__get_serialized_size,
  _SetConfigMessage__max_serialized_size
};

static rosidl_message_type_support_t _SetConfigMessage__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetConfigMessage__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace dronehive_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_dronehive_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<dronehive_interfaces::msg::SetConfigMessage>()
{
  return &dronehive_interfaces::msg::typesupport_fastrtps_cpp::_SetConfigMessage__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dronehive_interfaces, msg, SetConfigMessage)() {
  return &dronehive_interfaces::msg::typesupport_fastrtps_cpp::_SetConfigMessage__handle;
}

#ifdef __cplusplus
}
#endif
