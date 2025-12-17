// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dronehive_interfaces:msg/GuiDroneTrajectoryUpload.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dronehive_interfaces/msg/detail/gui_drone_trajectory_upload__rosidl_typesupport_introspection_c.h"
#include "dronehive_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dronehive_interfaces/msg/detail/gui_drone_trajectory_upload__functions.h"
#include "dronehive_interfaces/msg/detail/gui_drone_trajectory_upload__struct.h"


// Include directives for member types
// Member `drone_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `waypoints`
#include "dronehive_interfaces/msg/position_message.h"
// Member `waypoints`
#include "dronehive_interfaces/msg/detail/position_message__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dronehive_interfaces__msg__GuiDroneTrajectoryUpload__init(message_memory);
}

void dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_fini_function(void * message_memory)
{
  dronehive_interfaces__msg__GuiDroneTrajectoryUpload__fini(message_memory);
}

size_t dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__size_function__GuiDroneTrajectoryUpload__waypoints(
  const void * untyped_member)
{
  const dronehive_interfaces__msg__PositionMessage__Sequence * member =
    (const dronehive_interfaces__msg__PositionMessage__Sequence *)(untyped_member);
  return member->size;
}

const void * dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__get_const_function__GuiDroneTrajectoryUpload__waypoints(
  const void * untyped_member, size_t index)
{
  const dronehive_interfaces__msg__PositionMessage__Sequence * member =
    (const dronehive_interfaces__msg__PositionMessage__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__get_function__GuiDroneTrajectoryUpload__waypoints(
  void * untyped_member, size_t index)
{
  dronehive_interfaces__msg__PositionMessage__Sequence * member =
    (dronehive_interfaces__msg__PositionMessage__Sequence *)(untyped_member);
  return &member->data[index];
}

void dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__fetch_function__GuiDroneTrajectoryUpload__waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const dronehive_interfaces__msg__PositionMessage * item =
    ((const dronehive_interfaces__msg__PositionMessage *)
    dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__get_const_function__GuiDroneTrajectoryUpload__waypoints(untyped_member, index));
  dronehive_interfaces__msg__PositionMessage * value =
    (dronehive_interfaces__msg__PositionMessage *)(untyped_value);
  *value = *item;
}

void dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__assign_function__GuiDroneTrajectoryUpload__waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  dronehive_interfaces__msg__PositionMessage * item =
    ((dronehive_interfaces__msg__PositionMessage *)
    dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__get_function__GuiDroneTrajectoryUpload__waypoints(untyped_member, index));
  const dronehive_interfaces__msg__PositionMessage * value =
    (const dronehive_interfaces__msg__PositionMessage *)(untyped_value);
  *item = *value;
}

bool dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__resize_function__GuiDroneTrajectoryUpload__waypoints(
  void * untyped_member, size_t size)
{
  dronehive_interfaces__msg__PositionMessage__Sequence * member =
    (dronehive_interfaces__msg__PositionMessage__Sequence *)(untyped_member);
  dronehive_interfaces__msg__PositionMessage__Sequence__fini(member);
  return dronehive_interfaces__msg__PositionMessage__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_message_member_array[2] = {
  {
    "drone_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dronehive_interfaces__msg__GuiDroneTrajectoryUpload, drone_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "waypoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dronehive_interfaces__msg__GuiDroneTrajectoryUpload, waypoints),  // bytes offset in struct
    NULL,  // default value
    dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__size_function__GuiDroneTrajectoryUpload__waypoints,  // size() function pointer
    dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__get_const_function__GuiDroneTrajectoryUpload__waypoints,  // get_const(index) function pointer
    dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__get_function__GuiDroneTrajectoryUpload__waypoints,  // get(index) function pointer
    dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__fetch_function__GuiDroneTrajectoryUpload__waypoints,  // fetch(index, &value) function pointer
    dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__assign_function__GuiDroneTrajectoryUpload__waypoints,  // assign(index, value) function pointer
    dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__resize_function__GuiDroneTrajectoryUpload__waypoints  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_message_members = {
  "dronehive_interfaces__msg",  // message namespace
  "GuiDroneTrajectoryUpload",  // message name
  2,  // number of fields
  sizeof(dronehive_interfaces__msg__GuiDroneTrajectoryUpload),
  dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_message_member_array,  // message members
  dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_init_function,  // function to initialize message memory (memory has to be allocated)
  dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_message_type_support_handle = {
  0,
  &dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dronehive_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, msg, GuiDroneTrajectoryUpload)() {
  dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, msg, PositionMessage)();
  if (!dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_message_type_support_handle.typesupport_identifier) {
    dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dronehive_interfaces__msg__GuiDroneTrajectoryUpload__rosidl_typesupport_introspection_c__GuiDroneTrajectoryUpload_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
