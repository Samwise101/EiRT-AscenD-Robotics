// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:srv/SlaveBoxInformationService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_INFORMATION_SERVICE__STRUCT_H_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_INFORMATION_SERVICE__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SlaveBoxInformationService in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__SlaveBoxInformationService_Request
{
  rosidl_runtime_c__String box_id;
} dronehive_interfaces__srv__SlaveBoxInformationService_Request;

// Struct for a sequence of dronehive_interfaces__srv__SlaveBoxInformationService_Request.
typedef struct dronehive_interfaces__srv__SlaveBoxInformationService_Request__Sequence
{
  dronehive_interfaces__srv__SlaveBoxInformationService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__SlaveBoxInformationService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "dronehive_interfaces/msg/detail/box_status_message__struct.h"

/// Struct defined in srv/SlaveBoxInformationService in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__SlaveBoxInformationService_Response
{
  dronehive_interfaces__msg__BoxStatusMessage status;
} dronehive_interfaces__srv__SlaveBoxInformationService_Response;

// Struct for a sequence of dronehive_interfaces__srv__SlaveBoxInformationService_Response.
typedef struct dronehive_interfaces__srv__SlaveBoxInformationService_Response__Sequence
{
  dronehive_interfaces__srv__SlaveBoxInformationService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__SlaveBoxInformationService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_INFORMATION_SERVICE__STRUCT_H_
