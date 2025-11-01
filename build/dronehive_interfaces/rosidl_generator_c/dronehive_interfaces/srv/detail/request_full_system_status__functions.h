// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dronehive_interfaces:srv/RequestFullSystemStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__FUNCTIONS_H_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dronehive_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "dronehive_interfaces/srv/detail/request_full_system_status__struct.h"

/// Initialize srv/RequestFullSystemStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dronehive_interfaces__srv__RequestFullSystemStatus_Request
 * )) before or use
 * dronehive_interfaces__srv__RequestFullSystemStatus_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__RequestFullSystemStatus_Request__init(dronehive_interfaces__srv__RequestFullSystemStatus_Request * msg);

/// Finalize srv/RequestFullSystemStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__RequestFullSystemStatus_Request__fini(dronehive_interfaces__srv__RequestFullSystemStatus_Request * msg);

/// Create srv/RequestFullSystemStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__srv__RequestFullSystemStatus_Request *
dronehive_interfaces__srv__RequestFullSystemStatus_Request__create();

/// Destroy srv/RequestFullSystemStatus message.
/**
 * It calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__RequestFullSystemStatus_Request__destroy(dronehive_interfaces__srv__RequestFullSystemStatus_Request * msg);

/// Check for srv/RequestFullSystemStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__RequestFullSystemStatus_Request__are_equal(const dronehive_interfaces__srv__RequestFullSystemStatus_Request * lhs, const dronehive_interfaces__srv__RequestFullSystemStatus_Request * rhs);

/// Copy a srv/RequestFullSystemStatus message.
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
dronehive_interfaces__srv__RequestFullSystemStatus_Request__copy(
  const dronehive_interfaces__srv__RequestFullSystemStatus_Request * input,
  dronehive_interfaces__srv__RequestFullSystemStatus_Request * output);

/// Initialize array of srv/RequestFullSystemStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence__init(dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence * array, size_t size);

/// Finalize array of srv/RequestFullSystemStatus messages.
/**
 * It calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence__fini(dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence * array);

/// Create array of srv/RequestFullSystemStatus messages.
/**
 * It allocates the memory for the array and calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence *
dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence__create(size_t size);

/// Destroy array of srv/RequestFullSystemStatus messages.
/**
 * It calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence__destroy(dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence * array);

/// Check for srv/RequestFullSystemStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence__are_equal(const dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence * lhs, const dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence * rhs);

/// Copy an array of srv/RequestFullSystemStatus messages.
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
dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence__copy(
  const dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence * input,
  dronehive_interfaces__srv__RequestFullSystemStatus_Request__Sequence * output);

/// Initialize srv/RequestFullSystemStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dronehive_interfaces__srv__RequestFullSystemStatus_Response
 * )) before or use
 * dronehive_interfaces__srv__RequestFullSystemStatus_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__RequestFullSystemStatus_Response__init(dronehive_interfaces__srv__RequestFullSystemStatus_Response * msg);

/// Finalize srv/RequestFullSystemStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__RequestFullSystemStatus_Response__fini(dronehive_interfaces__srv__RequestFullSystemStatus_Response * msg);

/// Create srv/RequestFullSystemStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__srv__RequestFullSystemStatus_Response *
dronehive_interfaces__srv__RequestFullSystemStatus_Response__create();

/// Destroy srv/RequestFullSystemStatus message.
/**
 * It calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__RequestFullSystemStatus_Response__destroy(dronehive_interfaces__srv__RequestFullSystemStatus_Response * msg);

/// Check for srv/RequestFullSystemStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__RequestFullSystemStatus_Response__are_equal(const dronehive_interfaces__srv__RequestFullSystemStatus_Response * lhs, const dronehive_interfaces__srv__RequestFullSystemStatus_Response * rhs);

/// Copy a srv/RequestFullSystemStatus message.
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
dronehive_interfaces__srv__RequestFullSystemStatus_Response__copy(
  const dronehive_interfaces__srv__RequestFullSystemStatus_Response * input,
  dronehive_interfaces__srv__RequestFullSystemStatus_Response * output);

/// Initialize array of srv/RequestFullSystemStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence__init(dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence * array, size_t size);

/// Finalize array of srv/RequestFullSystemStatus messages.
/**
 * It calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence__fini(dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence * array);

/// Create array of srv/RequestFullSystemStatus messages.
/**
 * It allocates the memory for the array and calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence *
dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence__create(size_t size);

/// Destroy array of srv/RequestFullSystemStatus messages.
/**
 * It calls
 * dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence__destroy(dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence * array);

/// Check for srv/RequestFullSystemStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence__are_equal(const dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence * lhs, const dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence * rhs);

/// Copy an array of srv/RequestFullSystemStatus messages.
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
dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence__copy(
  const dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence * input,
  dronehive_interfaces__srv__RequestFullSystemStatus_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__FUNCTIONS_H_
