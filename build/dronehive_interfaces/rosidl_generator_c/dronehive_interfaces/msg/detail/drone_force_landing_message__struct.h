// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/DroneForceLandingMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_FORCE_LANDING_MESSAGE__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_FORCE_LANDING_MESSAGE__STRUCT_H_

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
// Member 'drone_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DroneForceLandingMessage in the package dronehive_interfaces.
/**
  * Service used by a drone to request the position to land on
 */
typedef struct dronehive_interfaces__msg__DroneForceLandingMessage
{
  dronehive_interfaces__msg__PositionMessage landing_pos;
  rosidl_runtime_c__String drone_id;
} dronehive_interfaces__msg__DroneForceLandingMessage;

// Struct for a sequence of dronehive_interfaces__msg__DroneForceLandingMessage.
typedef struct dronehive_interfaces__msg__DroneForceLandingMessage__Sequence
{
  dronehive_interfaces__msg__DroneForceLandingMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__DroneForceLandingMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_FORCE_LANDING_MESSAGE__STRUCT_H_
