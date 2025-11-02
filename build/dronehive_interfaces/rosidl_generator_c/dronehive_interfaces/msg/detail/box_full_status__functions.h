// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dronehive_interfaces:msg/BoxFullStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_FULL_STATUS__FUNCTIONS_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_FULL_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dronehive_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "dronehive_interfaces/msg/detail/box_full_status__struct.h"

/// Initialize msg/BoxFullStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dronehive_interfaces__msg__BoxFullStatus
 * )) before or use
 * dronehive_interfaces__msg__BoxFullStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__BoxFullStatus__init(dronehive_interfaces__msg__BoxFullStatus * msg);

/// Finalize msg/BoxFullStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__BoxFullStatus__fini(dronehive_interfaces__msg__BoxFullStatus * msg);

/// Create msg/BoxFullStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dronehive_interfaces__msg__BoxFullStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__msg__BoxFullStatus *
dronehive_interfaces__msg__BoxFullStatus__create();

/// Destroy msg/BoxFullStatus message.
/**
 * It calls
 * dronehive_interfaces__msg__BoxFullStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__BoxFullStatus__destroy(dronehive_interfaces__msg__BoxFullStatus * msg);

/// Check for msg/BoxFullStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__BoxFullStatus__are_equal(const dronehive_interfaces__msg__BoxFullStatus * lhs, const dronehive_interfaces__msg__BoxFullStatus * rhs);

/// Copy a msg/BoxFullStatus message.
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
dronehive_interfaces__msg__BoxFullStatus__copy(
  const dronehive_interfaces__msg__BoxFullStatus * input,
  dronehive_interfaces__msg__BoxFullStatus * output);

/// Initialize array of msg/BoxFullStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * dronehive_interfaces__msg__BoxFullStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__BoxFullStatus__Sequence__init(dronehive_interfaces__msg__BoxFullStatus__Sequence * array, size_t size);

/// Finalize array of msg/BoxFullStatus messages.
/**
 * It calls
 * dronehive_interfaces__msg__BoxFullStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__BoxFullStatus__Sequence__fini(dronehive_interfaces__msg__BoxFullStatus__Sequence * array);

/// Create array of msg/BoxFullStatus messages.
/**
 * It allocates the memory for the array and calls
 * dronehive_interfaces__msg__BoxFullStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__msg__BoxFullStatus__Sequence *
dronehive_interfaces__msg__BoxFullStatus__Sequence__create(size_t size);

/// Destroy array of msg/BoxFullStatus messages.
/**
 * It calls
 * dronehive_interfaces__msg__BoxFullStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__BoxFullStatus__Sequence__destroy(dronehive_interfaces__msg__BoxFullStatus__Sequence * array);

/// Check for msg/BoxFullStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__BoxFullStatus__Sequence__are_equal(const dronehive_interfaces__msg__BoxFullStatus__Sequence * lhs, const dronehive_interfaces__msg__BoxFullStatus__Sequence * rhs);

/// Copy an array of msg/BoxFullStatus messages.
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
dronehive_interfaces__msg__BoxFullStatus__Sequence__copy(
  const dronehive_interfaces__msg__BoxFullStatus__Sequence * input,
  dronehive_interfaces__msg__BoxFullStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_FULL_STATUS__FUNCTIONS_H_
