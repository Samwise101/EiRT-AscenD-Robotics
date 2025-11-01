// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dronehive_interfaces:srv/DroneStatusService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_STATUS_SERVICE__FUNCTIONS_H_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_STATUS_SERVICE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dronehive_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "dronehive_interfaces/srv/detail/drone_status_service__struct.h"

/// Initialize srv/DroneStatusService message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dronehive_interfaces__srv__DroneStatusService_Request
 * )) before or use
 * dronehive_interfaces__srv__DroneStatusService_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Request__init(dronehive_interfaces__srv__DroneStatusService_Request * msg);

/// Finalize srv/DroneStatusService message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__DroneStatusService_Request__fini(dronehive_interfaces__srv__DroneStatusService_Request * msg);

/// Create srv/DroneStatusService message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dronehive_interfaces__srv__DroneStatusService_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__srv__DroneStatusService_Request *
dronehive_interfaces__srv__DroneStatusService_Request__create();

/// Destroy srv/DroneStatusService message.
/**
 * It calls
 * dronehive_interfaces__srv__DroneStatusService_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__DroneStatusService_Request__destroy(dronehive_interfaces__srv__DroneStatusService_Request * msg);

/// Check for srv/DroneStatusService message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Request__are_equal(const dronehive_interfaces__srv__DroneStatusService_Request * lhs, const dronehive_interfaces__srv__DroneStatusService_Request * rhs);

/// Copy a srv/DroneStatusService message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Request__copy(
  const dronehive_interfaces__srv__DroneStatusService_Request * input,
  dronehive_interfaces__srv__DroneStatusService_Request * output);

/// Initialize array of srv/DroneStatusService messages.
/**
 * It allocates the memory for the number of elements and calls
 * dronehive_interfaces__srv__DroneStatusService_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Request__Sequence__init(dronehive_interfaces__srv__DroneStatusService_Request__Sequence * array, size_t size);

/// Finalize array of srv/DroneStatusService messages.
/**
 * It calls
 * dronehive_interfaces__srv__DroneStatusService_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__DroneStatusService_Request__Sequence__fini(dronehive_interfaces__srv__DroneStatusService_Request__Sequence * array);

/// Create array of srv/DroneStatusService messages.
/**
 * It allocates the memory for the array and calls
 * dronehive_interfaces__srv__DroneStatusService_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__srv__DroneStatusService_Request__Sequence *
dronehive_interfaces__srv__DroneStatusService_Request__Sequence__create(size_t size);

/// Destroy array of srv/DroneStatusService messages.
/**
 * It calls
 * dronehive_interfaces__srv__DroneStatusService_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__DroneStatusService_Request__Sequence__destroy(dronehive_interfaces__srv__DroneStatusService_Request__Sequence * array);

/// Check for srv/DroneStatusService message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Request__Sequence__are_equal(const dronehive_interfaces__srv__DroneStatusService_Request__Sequence * lhs, const dronehive_interfaces__srv__DroneStatusService_Request__Sequence * rhs);

/// Copy an array of srv/DroneStatusService messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Request__Sequence__copy(
  const dronehive_interfaces__srv__DroneStatusService_Request__Sequence * input,
  dronehive_interfaces__srv__DroneStatusService_Request__Sequence * output);

/// Initialize srv/DroneStatusService message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dronehive_interfaces__srv__DroneStatusService_Response
 * )) before or use
 * dronehive_interfaces__srv__DroneStatusService_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Response__init(dronehive_interfaces__srv__DroneStatusService_Response * msg);

/// Finalize srv/DroneStatusService message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__DroneStatusService_Response__fini(dronehive_interfaces__srv__DroneStatusService_Response * msg);

/// Create srv/DroneStatusService message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dronehive_interfaces__srv__DroneStatusService_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__srv__DroneStatusService_Response *
dronehive_interfaces__srv__DroneStatusService_Response__create();

/// Destroy srv/DroneStatusService message.
/**
 * It calls
 * dronehive_interfaces__srv__DroneStatusService_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__DroneStatusService_Response__destroy(dronehive_interfaces__srv__DroneStatusService_Response * msg);

/// Check for srv/DroneStatusService message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Response__are_equal(const dronehive_interfaces__srv__DroneStatusService_Response * lhs, const dronehive_interfaces__srv__DroneStatusService_Response * rhs);

/// Copy a srv/DroneStatusService message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Response__copy(
  const dronehive_interfaces__srv__DroneStatusService_Response * input,
  dronehive_interfaces__srv__DroneStatusService_Response * output);

/// Initialize array of srv/DroneStatusService messages.
/**
 * It allocates the memory for the number of elements and calls
 * dronehive_interfaces__srv__DroneStatusService_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Response__Sequence__init(dronehive_interfaces__srv__DroneStatusService_Response__Sequence * array, size_t size);

/// Finalize array of srv/DroneStatusService messages.
/**
 * It calls
 * dronehive_interfaces__srv__DroneStatusService_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__DroneStatusService_Response__Sequence__fini(dronehive_interfaces__srv__DroneStatusService_Response__Sequence * array);

/// Create array of srv/DroneStatusService messages.
/**
 * It allocates the memory for the array and calls
 * dronehive_interfaces__srv__DroneStatusService_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__srv__DroneStatusService_Response__Sequence *
dronehive_interfaces__srv__DroneStatusService_Response__Sequence__create(size_t size);

/// Destroy array of srv/DroneStatusService messages.
/**
 * It calls
 * dronehive_interfaces__srv__DroneStatusService_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__DroneStatusService_Response__Sequence__destroy(dronehive_interfaces__srv__DroneStatusService_Response__Sequence * array);

/// Check for srv/DroneStatusService message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Response__Sequence__are_equal(const dronehive_interfaces__srv__DroneStatusService_Response__Sequence * lhs, const dronehive_interfaces__srv__DroneStatusService_Response__Sequence * rhs);

/// Copy an array of srv/DroneStatusService messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__DroneStatusService_Response__Sequence__copy(
  const dronehive_interfaces__srv__DroneStatusService_Response__Sequence * input,
  dronehive_interfaces__srv__DroneStatusService_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_STATUS_SERVICE__FUNCTIONS_H_
