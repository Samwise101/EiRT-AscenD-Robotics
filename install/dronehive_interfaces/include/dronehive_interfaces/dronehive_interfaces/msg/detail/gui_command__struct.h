// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:msg/GuiCommand.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__STRUCT_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SEARCH_FOR_NEW_BOX'.
enum
{
  dronehive_interfaces__msg__GuiCommand__SEARCH_FOR_NEW_BOX = 0
};

/// Constant 'REMOVE_BOX'.
enum
{
  dronehive_interfaces__msg__GuiCommand__REMOVE_BOX = 1
};

/// Constant 'REQUEST_BOX_STATUS'.
enum
{
  dronehive_interfaces__msg__GuiCommand__REQUEST_BOX_STATUS = 2
};

/// Constant 'REQUEST_LANDING'.
enum
{
  dronehive_interfaces__msg__GuiCommand__REQUEST_LANDING = 3
};

/// Constant 'REQUEST_RETURN_HOME'.
enum
{
  dronehive_interfaces__msg__GuiCommand__REQUEST_RETURN_HOME = 4
};

/// Constant 'REQUEST_TAKEOFF'.
enum
{
  dronehive_interfaces__msg__GuiCommand__REQUEST_TAKEOFF = 5
};

/// Constant 'REQUEST_ARMING'.
enum
{
  dronehive_interfaces__msg__GuiCommand__REQUEST_ARMING = 6
};

/// Constant 'PATH_UPLOAD'.
enum
{
  dronehive_interfaces__msg__GuiCommand__PATH_UPLOAD = 7
};

/// Constant 'REQUEST_LOG'.
enum
{
  dronehive_interfaces__msg__GuiCommand__REQUEST_LOG = 8
};

/// Constant 'TRACK_DRONE'.
enum
{
  dronehive_interfaces__msg__GuiCommand__TRACK_DRONE = 9
};

/// Constant 'REQUEST_EXECUTE_PATH'.
enum
{
  dronehive_interfaces__msg__GuiCommand__REQUEST_EXECUTE_PATH = 10
};

/// Constant 'REQUEST_FULL_SYSTEM_STATUS'.
enum
{
  dronehive_interfaces__msg__GuiCommand__REQUEST_FULL_SYSTEM_STATUS = 11
};

/// Constant 'REQUEST_DRONE_STATUS'.
enum
{
  dronehive_interfaces__msg__GuiCommand__REQUEST_DRONE_STATUS = 12
};

/// Constant 'SEARCH_FOR_NEW_DRONE'.
enum
{
  dronehive_interfaces__msg__GuiCommand__SEARCH_FOR_NEW_DRONE = 13
};

// Include directives for member types
// Member 'box_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GuiCommand in the package dronehive_interfaces.
/**
  * GuiCommand.msg
 */
typedef struct dronehive_interfaces__msg__GuiCommand
{
  uint8_t command;
  bool confirm;
  rosidl_runtime_c__String box_id;
} dronehive_interfaces__msg__GuiCommand;

// Struct for a sequence of dronehive_interfaces__msg__GuiCommand.
typedef struct dronehive_interfaces__msg__GuiCommand__Sequence
{
  dronehive_interfaces__msg__GuiCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__msg__GuiCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__STRUCT_H_
