// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/DroneStatusMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'drone_id'
// Member 'fligt_state'
#include "rosidl_runtime_c/string.h"
// Member 'current_position'
#include "dronehive_interfaces/msg/detail/position_message__struct.h"

/// Struct defined in msg/DroneStatusMessage in the package dronehive_interfaces.
/**
  * Message containning the status of the drone
 */
typedef struct dronehive_interfaces__msg__DroneStatusMessage
{
  rosidl_runtime_c__String drone_id;
  float battery_voltage;
  float battery_percentage;
  rosidl_runtime_c__String fligt_state;
  bool reached_first_waypoint;
  dronehive_interfaces__msg__PositionMessage current_position;
} dronehive_interfaces__msg__DroneStatusMessage;

// Struct for a sequence of dronehive_interfaces__msg__DroneStatusMessage.
typedef struct dronehive_interfaces__msg__DroneStatusMessage__Sequence
{
  dronehive_interfaces__msg__DroneStatusMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__DroneStatusMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__STRUCT_H_
