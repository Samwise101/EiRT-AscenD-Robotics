// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dronehive_interfaces:srv/RequestBoxOpenService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_BOX_OPEN_SERVICE__STRUCT_H_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_BOX_OPEN_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/RequestBoxOpenService in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__RequestBoxOpenService_Request
{
  uint8_t structure_needs_at_least_one_member;
} dronehive_interfaces__srv__RequestBoxOpenService_Request;

// Struct for a sequence of dronehive_interfaces__srv__RequestBoxOpenService_Request.
typedef struct dronehive_interfaces__srv__RequestBoxOpenService_Request__Sequence
{
  dronehive_interfaces__srv__RequestBoxOpenService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__RequestBoxOpenService_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/RequestBoxOpenService in the package dronehive_interfaces.
typedef struct dronehive_interfaces__srv__RequestBoxOpenService_Response
{
  bool ack;
} dronehive_interfaces__srv__RequestBoxOpenService_Response;

// Struct for a sequence of dronehive_interfaces__srv__RequestBoxOpenService_Response.
typedef struct dronehive_interfaces__srv__RequestBoxOpenService_Response__Sequence
{
  dronehive_interfaces__srv__RequestBoxOpenService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dronehive_interfaces__srv__RequestBoxOpenService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_BOX_OPEN_SERVICE__STRUCT_H_
