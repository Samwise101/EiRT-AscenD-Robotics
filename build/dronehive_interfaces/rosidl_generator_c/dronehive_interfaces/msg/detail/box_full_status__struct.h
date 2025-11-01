// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/BoxFullStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_FULL_STATUS__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_FULL_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'box_id'
// Member 'box_status'
// Member 'drone_id'
#include "rosidl_runtime_c/string.h"
// Member 'landing_pos'
#include "dronehive_interfaces/msg/detail/position_message__struct.h"

/// Struct defined in msg/BoxFullStatus in the package dronehive_interfaces.
typedef struct dronehive_interfaces__msg__BoxFullStatus
{
  rosidl_runtime_c__String box_id;
  rosidl_runtime_c__String box_status;
  rosidl_runtime_c__String drone_id;
  dronehive_interfaces__msg__PositionMessage landing_pos;
} dronehive_interfaces__msg__BoxFullStatus;

// Struct for a sequence of dronehive_interfaces__msg__BoxFullStatus.
typedef struct dronehive_interfaces__msg__BoxFullStatus__Sequence
{
  dronehive_interfaces__msg__BoxFullStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__BoxFullStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_FULL_STATUS__STRUCT_H_
