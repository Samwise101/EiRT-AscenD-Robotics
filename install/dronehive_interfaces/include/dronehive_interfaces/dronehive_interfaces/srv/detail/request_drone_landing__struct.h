// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:srv/RequestDroneLanding.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_DRONE_LANDING__STRUCT_H_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_DRONE_LANDING__STRUCT_H_

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
// Member 'drone_pos'
#include "dronehive_interfaces/msg/detail/position_message__struct.h"

/// Struct defined in srv/RequestDroneLanding in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__RequestDroneLanding_Request
{
  rosidl_runtime_c__String drone_id;
  dronehive_interfaces__msg__PositionMessage drone_pos;
} dronehive_interfaces__srv__RequestDroneLanding_Request;

// Struct for a sequence of dronehive_interfaces__srv__RequestDroneLanding_Request.
typedef struct dronehive_interfaces__srv__RequestDroneLanding_Request__Sequence
{
  dronehive_interfaces__srv__RequestDroneLanding_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__RequestDroneLanding_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'landing_pos'
// already included above
// #include "dronehive_interfaces/msg/detail/position_message__struct.h"

/// Struct defined in srv/RequestDroneLanding in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__RequestDroneLanding_Response
{
  dronehive_interfaces__msg__PositionMessage landing_pos;
} dronehive_interfaces__srv__RequestDroneLanding_Response;

// Struct for a sequence of dronehive_interfaces__srv__RequestDroneLanding_Response.
typedef struct dronehive_interfaces__srv__RequestDroneLanding_Response__Sequence
{
  dronehive_interfaces__srv__RequestDroneLanding_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__RequestDroneLanding_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_DRONE_LANDING__STRUCT_H_
