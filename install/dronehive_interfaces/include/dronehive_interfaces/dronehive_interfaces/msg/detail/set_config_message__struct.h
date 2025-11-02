// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/SetConfigMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__SET_CONFIG_MESSAGE__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__SET_CONFIG_MESSAGE__STRUCT_H_

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
// Member 'drone_name'
// Member 'drone_type'
// Member 'drone_setup'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SetConfigMessage in the package dronehive_interfaces.
/**
  * command to set drone config
 */
typedef struct dronehive_interfaces__msg__SetConfigMessage
{
  rosidl_runtime_c__String box_id;
  rosidl_runtime_c__String drone_id;
  rosidl_runtime_c__String drone_name;
  rosidl_runtime_c__String drone_type;
  rosidl_runtime_c__String drone_setup;
} dronehive_interfaces__msg__SetConfigMessage;

// Struct for a sequence of dronehive_interfaces__msg__SetConfigMessage.
typedef struct dronehive_interfaces__msg__SetConfigMessage__Sequence
{
  dronehive_interfaces__msg__SetConfigMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__SetConfigMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__SET_CONFIG_MESSAGE__STRUCT_H_
