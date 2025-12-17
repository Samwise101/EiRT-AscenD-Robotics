// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/BoxStatusMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'landing_pos'
#include "dronehive_interfaces/msg/detail/position_message__struct.h"
// Member 'box_id'
// Member 'drone_id'
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BoxStatusMessage in the package dronehive_interfaces.
typedef struct dronehive_interfaces__msg__BoxStatusMessage
{
  dronehive_interfaces__msg__PositionMessage landing_pos;
  double box_battery_level;
  rosidl_runtime_c__String box_id;
  rosidl_runtime_c__String drone_id;
  rosidl_runtime_c__String status;
} dronehive_interfaces__msg__BoxStatusMessage;

// Struct for a sequence of dronehive_interfaces__msg__BoxStatusMessage.
typedef struct dronehive_interfaces__msg__BoxStatusMessage__Sequence
{
  dronehive_interfaces__msg__BoxStatusMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__BoxStatusMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__STRUCT_H_
