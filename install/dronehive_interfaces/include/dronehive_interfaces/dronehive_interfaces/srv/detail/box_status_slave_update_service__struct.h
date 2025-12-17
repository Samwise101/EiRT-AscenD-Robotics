// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:srv/BoxStatusSlaveUpdateService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__STRUCT_H_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "dronehive_interfaces/msg/detail/box_status_message__struct.h"

/// Struct defined in srv/BoxStatusSlaveUpdateService in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Request
{
  dronehive_interfaces__msg__BoxStatusMessage status;
} dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Request;

// Struct for a sequence of dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Request.
typedef struct dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Request__Sequence
{
  dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/BoxStatusSlaveUpdateService in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Response
{
  bool ack;
} dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Response;

// Struct for a sequence of dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Response.
typedef struct dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Response__Sequence
{
  dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__STRUCT_H_
