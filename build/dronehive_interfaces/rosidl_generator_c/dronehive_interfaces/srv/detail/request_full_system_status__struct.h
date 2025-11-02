// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:srv/RequestFullSystemStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__STRUCT_H_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/RequestFullSystemStatus in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__RequestFullSystemStatus_Request
{
  uint8_t structure_needs_at_least_one_member;
} dronehive_interfaces__srv__RequestFullSystemStatus_Request;

// Struct for a sequence of dronehive_interfaces__srv__RequestFullSystemStatus_Request.
typedef struct dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence
{
  dronehive_interfaces__srv__RequestFullSystemStatus_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'statuses'
#include "dronehive_interfaces/msg/detail/box_full_status__struct.h"

/// Struct defined in srv/RequestFullSystemStatus in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__RequestFullSystemStatus_Response
{
  /// Response
  dronehive_interfaces__msg__BoxFullStatus__Sequence statuses;
} dronehive_interfaces__srv__RequestFullSystemStatus_Response;

// Struct for a sequence of dronehive_interfaces__srv__RequestFullSystemStatus_Response.
typedef struct dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence
{
  dronehive_interfaces__srv__RequestFullSystemStatus_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__STRUCT_H_
