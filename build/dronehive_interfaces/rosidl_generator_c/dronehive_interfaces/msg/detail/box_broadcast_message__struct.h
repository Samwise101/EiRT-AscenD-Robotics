// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/BoxBroadcastMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_BROADCAST_MESSAGE__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_BROADCAST_MESSAGE__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"
// Member 'landing_pos'
#include "dronehive_interfaces/msg/detail/position_message__struct.h"

/// Struct defined in msg/BoxBroadcastMessage in the package dronehive_interfaces.
/**
  * If the box is not initialized this message will be broadcasted on a specific topic
 */
typedef struct dronehive_interfaces__msg__BoxBroadcastMessage
{
  rosidl_runtime_c__String box_id;
  dronehive_interfaces__msg__PositionMessage landing_pos;
} dronehive_interfaces__msg__BoxBroadcastMessage;

// Struct for a sequence of dronehive_interfaces__msg__BoxBroadcastMessage.
typedef struct dronehive_interfaces__msg__BoxBroadcastMessage__Sequence
{
  dronehive_interfaces__msg__BoxBroadcastMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__BoxBroadcastMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_BROADCAST_MESSAGE__STRUCT_H_
