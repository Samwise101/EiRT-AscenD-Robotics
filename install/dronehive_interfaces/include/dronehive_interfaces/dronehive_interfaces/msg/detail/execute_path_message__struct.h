// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/ExecutePathMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__EXECUTE_PATH_MESSAGE__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__EXECUTE_PATH_MESSAGE__STRUCT_H_

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
// Member 'plan'
// Member 'execution_type'
#include "rosidl_runtime_c/string.h"
// Member 'waypoints'
#include "dronehive_interfaces/msg/detail/position_message__struct.h"

/// Struct defined in msg/ExecutePathMessage in the package dronehive_interfaces.
/**
  * command for drone to execute a flight plan
 */
typedef struct dronehive_interfaces__msg__ExecutePathMessage
{
  rosidl_runtime_c__String box_id;
  rosidl_runtime_c__String plan;
  dronehive_interfaces__msg__PositionMessage__Sequence waypoints;
  rosidl_runtime_c__String execution_type;
} dronehive_interfaces__msg__ExecutePathMessage;

// Struct for a sequence of dronehive_interfaces__msg__ExecutePathMessage.
typedef struct dronehive_interfaces__msg__ExecutePathMessage__Sequence
{
  dronehive_interfaces__msg__ExecutePathMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__ExecutePathMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__EXECUTE_PATH_MESSAGE__STRUCT_H_
