// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/PositionMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__POSITION_MESSAGE__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__POSITION_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PositionMessage in the package dronehive_interfaces.
/**
  * contains the position of a point in latitude, longitude, elevation
 */
typedef struct dronehive_interfaces__msg__PositionMessage
{
  double lat;
  double lon;
  double elv;
} dronehive_interfaces__msg__PositionMessage;

// Struct for a sequence of dronehive_interfaces__msg__PositionMessage.
typedef struct dronehive_interfaces__msg__PositionMessage__Sequence
{
  dronehive_interfaces__msg__PositionMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__PositionMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__POSITION_MESSAGE__STRUCT_H_
