// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dronehive_interfaces:msg/BoxStatusMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__FUNCTIONS_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dronehive_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "dronehive_interfaces/msg/detail/box_status_message__struct.h"

/// Initialize msg/BoxStatusMessage message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dronehive_interfaces__msg__BoxStatusMessage
 * )) before or use
 * dronehive_interfaces__msg__BoxStatusMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__BoxStatusMessage__init(dronehive_interfaces__msg__BoxStatusMessage * msg);

/// Finalize msg/BoxStatusMessage message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__BoxStatusMessage__fini(dronehive_interfaces__msg__BoxStatusMessage * msg);

/// Create msg/BoxStatusMessage message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dronehive_interfaces__msg__BoxStatusMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__msg__BoxStatusMessage *
dronehive_interfaces__msg__BoxStatusMessage__create();

/// Destroy msg/BoxStatusMessage message.
/**
 * It calls
 * dronehive_interfaces__msg__BoxStatusMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__BoxStatusMessage__destroy(dronehive_interfaces__msg__BoxStatusMessage * msg);

/// Check for msg/BoxStatusMessage message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__BoxStatusMessage__are_equal(const dronehive_interfaces__msg__BoxStatusMessage * lhs, const dronehive_interfaces__msg__BoxStatusMessage * rhs);

/// Copy a msg/BoxStatusMessage message.
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
dronehive_interfaces__msg__BoxStatusMessage__copy(
  const dronehive_interfaces__msg__BoxStatusMessage * input,
  dronehive_interfaces__msg__BoxStatusMessage * output);

/// Initialize array of msg/BoxStatusMessage messages.
/**
 * It allocates the memory for the number of elements and calls
 * dronehive_interfaces__msg__BoxStatusMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__BoxStatusMessage__Sequence__init(dronehive_interfaces__msg__BoxStatusMessage__Sequence * array, size_t size);

/// Finalize array of msg/BoxStatusMessage messages.
/**
 * It calls
 * dronehive_interfaces__msg__BoxStatusMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__BoxStatusMessage__Sequence__fini(dronehive_interfaces__msg__BoxStatusMessage__Sequence * array);

/// Create array of msg/BoxStatusMessage messages.
/**
 * It allocates the memory for the array and calls
 * dronehive_interfaces__msg__BoxStatusMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__msg__BoxStatusMessage__Sequence *
dronehive_interfaces__msg__BoxStatusMessage__Sequence__create(size_t size);

/// Destroy array of msg/BoxStatusMessage messages.
/**
 * It calls
 * dronehive_interfaces__msg__BoxStatusMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__BoxStatusMessage__Sequence__destroy(dronehive_interfaces__msg__BoxStatusMessage__Sequence * array);

/// Check for msg/BoxStatusMessage message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__BoxStatusMessage__Sequence__are_equal(const dronehive_interfaces__msg__BoxStatusMessage__Sequence * lhs, const dronehive_interfaces__msg__BoxStatusMessage__Sequence * rhs);

/// Copy an array of msg/BoxStatusMessage messages.
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
dronehive_interfaces__msg__BoxStatusMessage__Sequence__copy(
  const dronehive_interfaces__msg__BoxStatusMessage__Sequence * input,
  dronehive_interfaces__msg__BoxStatusMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__FUNCTIONS_H_
