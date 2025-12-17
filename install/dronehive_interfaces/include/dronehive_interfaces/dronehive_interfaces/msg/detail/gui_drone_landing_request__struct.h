// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/GuiDroneLandingRequest.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_LANDING_REQUEST__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_LANDING_REQUEST__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GuiDroneLandingRequest in the package dronehive_interfaces.
/**
  * gui mesage to the backend for requesting a specific drone to land
 */
typedef struct dronehive_interfaces__msg__GuiDroneLandingRequest
{
  rosidl_runtime_c__String drone_id;
} dronehive_interfaces__msg__GuiDroneLandingRequest;

// Struct for a sequence of dronehive_interfaces__msg__GuiDroneLandingRequest.
typedef struct dronehive_interfaces__msg__GuiDroneLandingRequest__Sequence
{
  dronehive_interfaces__msg__GuiDroneLandingRequest * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__GuiDroneLandingRequest__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_LANDING_REQUEST__STRUCT_H_
