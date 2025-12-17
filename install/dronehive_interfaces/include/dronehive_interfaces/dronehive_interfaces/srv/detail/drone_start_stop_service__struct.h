// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:srv/DroneStartStopService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_START_STOP_SERVICE__STRUCT_H_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_START_STOP_SERVICE__STRUCT_H_

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

/// Struct defined in srv/DroneStartStopService in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__DroneStartStopService_Request
{
  rosidl_runtime_c__String drone_id;
  /// 0: resume, 1: pause, 2: stop
  int8_t control_var;
} dronehive_interfaces__srv__DroneStartStopService_Request;

// Struct for a sequence of dronehive_interfaces__srv__DroneStartStopService_Request.
typedef struct dronehive_interfaces__srv__DroneStartStopService_Request__Sequence
{
  dronehive_interfaces__srv__DroneStartStopService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__DroneStartStopService_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/DroneStartStopService in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__DroneStartStopService_Response
{
  bool ack;
} dronehive_interfaces__srv__DroneStartStopService_Response;

// Struct for a sequence of dronehive_interfaces__srv__DroneStartStopService_Response.
typedef struct dronehive_interfaces__srv__DroneStartStopService_Response__Sequence
{
  dronehive_interfaces__srv__DroneStartStopService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__DroneStartStopService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_START_STOP_SERVICE__STRUCT_H_
