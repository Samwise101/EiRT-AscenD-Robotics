// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/BackendCommand.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BACKEND_COMMAND__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BACKEND_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'CONFIRM_NEW_BOX_MSG'.
enum
{
  dronehive_interfaces__msg__BackendCommand__CONFIRM_NEW_BOX_MSG = 0
};

/// Constant 'DECLINE_NEW_BOX_MSG'.
enum
{
  dronehive_interfaces__msg__BackendCommand__DECLINE_NEW_BOX_MSG = 1
};

/// Constant 'NEW_BOX_SEARCH_TIMEOUT'.
enum
{
  dronehive_interfaces__msg__BackendCommand__NEW_BOX_SEARCH_TIMEOUT = 2
};

/// Struct defined in msg/BackendCommand in the package dronehive_interfaces.
typedef struct dronehive_interfaces__msg__BackendCommand
{
  uint8_t command;
  bool confirm;
} dronehive_interfaces__msg__BackendCommand;

// Struct for a sequence of dronehive_interfaces__msg__BackendCommand.
typedef struct dronehive_interfaces__msg__BackendCommand__Sequence
{
  dronehive_interfaces__msg__BackendCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__BackendCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BACKEND_COMMAND__STRUCT_H_
