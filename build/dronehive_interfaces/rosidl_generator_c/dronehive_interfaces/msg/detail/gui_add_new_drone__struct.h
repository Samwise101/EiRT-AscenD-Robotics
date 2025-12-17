// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/GuiAddNewDrone.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_ADD_NEW_DRONE__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_ADD_NEW_DRONE__STRUCT_H_

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
// Member 'box_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GuiAddNewDrone in the package dronehive_interfaces.
typedef struct dronehive_interfaces__msg__GuiAddNewDrone
{
  rosidl_runtime_c__String drone_id;
  rosidl_runtime_c__String box_id;
} dronehive_interfaces__msg__GuiAddNewDrone;

// Struct for a sequence of dronehive_interfaces__msg__GuiAddNewDrone.
typedef struct dronehive_interfaces__msg__GuiAddNewDrone__Sequence
{
  dronehive_interfaces__msg__GuiAddNewDrone * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__GuiAddNewDrone__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_ADD_NEW_DRONE__STRUCT_H_
