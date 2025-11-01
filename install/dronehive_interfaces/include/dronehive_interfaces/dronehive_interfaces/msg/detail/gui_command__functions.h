// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dronehive_interfaces:msg/GuiCommand.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__FUNCTIONS_H_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dronehive_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "dronehive_interfaces/msg/detail/gui_command__struct.h"

/// Initialize msg/GuiCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dronehive_interfaces__msg__GuiCommand
 * )) before or use
 * dronehive_interfaces__msg__GuiCommand__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__GuiCommand__init(dronehive_interfaces__msg__GuiCommand * msg);

/// Finalize msg/GuiCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__GuiCommand__fini(dronehive_interfaces__msg__GuiCommand * msg);

/// Create msg/GuiCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dronehive_interfaces__msg__GuiCommand__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__msg__GuiCommand *
dronehive_interfaces__msg__GuiCommand__create();

/// Destroy msg/GuiCommand message.
/**
 * It calls
 * dronehive_interfaces__msg__GuiCommand__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__GuiCommand__destroy(dronehive_interfaces__msg__GuiCommand * msg);

/// Check for msg/GuiCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__GuiCommand__are_equal(const dronehive_interfaces__msg__GuiCommand * lhs, const dronehive_interfaces__msg__GuiCommand * rhs);

/// Copy a msg/GuiCommand message.
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
dronehive_interfaces__msg__GuiCommand__copy(
  const dronehive_interfaces__msg__GuiCommand * input,
  dronehive_interfaces__msg__GuiCommand * output);

/// Initialize array of msg/GuiCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * dronehive_interfaces__msg__GuiCommand__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__GuiCommand__Sequence__init(dronehive_interfaces__msg__GuiCommand__Sequence * array, size_t size);

/// Finalize array of msg/GuiCommand messages.
/**
 * It calls
 * dronehive_interfaces__msg__GuiCommand__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__GuiCommand__Sequence__fini(dronehive_interfaces__msg__GuiCommand__Sequence * array);

/// Create array of msg/GuiCommand messages.
/**
 * It allocates the memory for the array and calls
 * dronehive_interfaces__msg__GuiCommand__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
dronehive_interfaces__msg__GuiCommand__Sequence *
dronehive_interfaces__msg__GuiCommand__Sequence__create(size_t size);

/// Destroy array of msg/GuiCommand messages.
/**
 * It calls
 * dronehive_interfaces__msg__GuiCommand__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
void
dronehive_interfaces__msg__GuiCommand__Sequence__destroy(dronehive_interfaces__msg__GuiCommand__Sequence * array);

/// Check for msg/GuiCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dronehive_interfaces
bool
dronehive_interfaces__msg__GuiCommand__Sequence__are_equal(const dronehive_interfaces__msg__GuiCommand__Sequence * lhs, const dronehive_interfaces__msg__GuiCommand__Sequence * rhs);

/// Copy an array of msg/GuiCommand messages.
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
dronehive_interfaces__msg__GuiCommand__Sequence__copy(
  const dronehive_interfaces__msg__GuiCommand__Sequence * input,
  dronehive_interfaces__msg__GuiCommand__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__FUNCTIONS_H_
