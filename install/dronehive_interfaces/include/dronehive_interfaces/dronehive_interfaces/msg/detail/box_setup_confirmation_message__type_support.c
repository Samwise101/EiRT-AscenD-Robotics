// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dronehive_interfaces:msg/BoxSetupConfirmationMessage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dronehive_interfaces/msg/detail/box_setup_confirmation_message__rosidl_typesupport_introspection_c.h"
#include "dronehive_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dronehive_interfaces/msg/detail/box_setup_confirmation_message__functions.h"
#include "dronehive_interfaces/msg/detail/box_setup_confirmation_message__struct.h"


// Include directives for member types
// Member `box_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `landing_pos`
#include "dronehive_interfaces/msg/position_message.h"
// Member `landing_pos`
#include "dronehive_interfaces/msg/detail/position_message__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dronehive_interfaces__msg__BoxSetupConfirmationMessage__init(message_memory);
}

void dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_fini_function(void * message_memory)
{
  dronehive_interfaces__msg__BoxSetupConfirmationMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_message_member_array[3] = {
  {
    "confirm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dronehive_interfaces__msg__BoxSetupConfirmationMessage, confirm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "box_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dronehive_interfaces__msg__BoxSetupConfirmationMessage, box_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "landing_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dronehive_interfaces__msg__BoxSetupConfirmationMessage, landing_pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_message_members = {
  "dronehive_interfaces__msg",  // message namespace
  "BoxSetupConfirmationMessage",  // message name
  3,  // number of fields
  sizeof(dronehive_interfaces__msg__BoxSetupConfirmationMessage),
  dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_message_member_array,  // message members
  dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_message_type_support_handle = {
  0,
  &dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dronehive_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, msg, BoxSetupConfirmationMessage)() {
  dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, msg, PositionMessage)();
  if (!dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_message_type_support_handle.typesupport_identifier) {
    dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dronehive_interfaces__msg__BoxSetupConfirmationMessage__rosidl_typesupport_introspection_c__BoxSetupConfirmationMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
