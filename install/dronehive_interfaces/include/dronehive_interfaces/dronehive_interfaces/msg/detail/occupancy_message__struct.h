// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/OccupancyMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__OCCUPANCY_MESSAGE__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__OCCUPANCY_MESSAGE__STRUCT_H_

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
// Member 'drone_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/OccupancyMessage in the package dronehive_interfaces.
typedef struct dronehive_interfaces__msg__OccupancyMessage
{
  rosidl_runtime_c__String box_id;
  rosidl_runtime_c__String drone_id;
  bool occupancy;
} dronehive_interfaces__msg__OccupancyMessage;

// Struct for a sequence of dronehive_interfaces__msg__OccupancyMessage.
typedef struct dronehive_interfaces__msg__OccupancyMessage__Sequence
{
  dronehive_interfaces__msg__OccupancyMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__OccupancyMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__OCCUPANCY_MESSAGE__STRUCT_H_
