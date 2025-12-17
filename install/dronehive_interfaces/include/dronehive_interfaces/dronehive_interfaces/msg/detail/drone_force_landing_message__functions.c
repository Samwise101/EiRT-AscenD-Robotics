// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dronehive_interfaces:msg/DroneForceLandingMessage.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/msg/detail/drone_force_landing_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `landing_pos`
#include "dronehive_interfaces/msg/detail/position_message__functions.h"
// Member `drone_id`
#include "rosidl_runtime_c/string_functions.h"

bool
dronehive_interfaces__msg__DroneForceLandingMessage__init(dronehive_interfaces__msg__DroneForceLandingMessage * msg)
{
  if (!msg) {
    return false;
  }
  // landing_pos
  if (!dronehive_interfaces__msg__PositionMessage__init(&msg->landing_pos)) {
    dronehive_interfaces__msg__DroneForceLandingMessage__fini(msg);
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__init(&msg->drone_id)) {
    dronehive_interfaces__msg__DroneForceLandingMessage__fini(msg);
    return false;
  }
  return true;
}

void
dronehive_interfaces__msg__DroneForceLandingMessage__fini(dronehive_interfaces__msg__DroneForceLandingMessage * msg)
{
  if (!msg) {
    return;
  }
  // landing_pos
  dronehive_interfaces__msg__PositionMessage__fini(&msg->landing_pos);
  // drone_id
  rosidl_runtime_c__String__fini(&msg->drone_id);
}

bool
dronehive_interfaces__msg__DroneForceLandingMessage__are_equal(const dronehive_interfaces__msg__DroneForceLandingMessage * lhs, const dronehive_interfaces__msg__DroneForceLandingMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // landing_pos
  if (!dronehive_interfaces__msg__PositionMessage__are_equal(
      &(lhs->landing_pos), &(rhs->landing_pos)))
  {
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->drone_id), &(rhs->drone_id)))
  {
    return false;
  }
  return true;
}

bool
dronehive_interfaces__msg__DroneForceLandingMessage__copy(
  const dronehive_interfaces__msg__DroneForceLandingMessage * input,
  dronehive_interfaces__msg__DroneForceLandingMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // landing_pos
  if (!dronehive_interfaces__msg__PositionMessage__copy(
      &(input->landing_pos), &(output->landing_pos)))
  {
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__copy(
      &(input->drone_id), &(output->drone_id)))
  {
    return false;
  }
  return true;
}

dronehive_interfaces__msg__DroneForceLandingMessage *
dronehive_interfaces__msg__DroneForceLandingMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__DroneForceLandingMessage * msg = (dronehive_interfaces__msg__DroneForceLandingMessage *)allocator.allocate(sizeof(dronehive_interfaces__msg__DroneForceLandingMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dronehive_interfaces__msg__DroneForceLandingMessage));
  bool success = dronehive_interfaces__msg__DroneForceLandingMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dronehive_interfaces__msg__DroneForceLandingMessage__destroy(dronehive_interfaces__msg__DroneForceLandingMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dronehive_interfaces__msg__DroneForceLandingMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dronehive_interfaces__msg__DroneForceLandingMessage__Sequence__init(dronehive_interfaces__msg__DroneForceLandingMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__DroneForceLandingMessage * data = NULL;

  if (size) {
    data = (dronehive_interfaces__msg__DroneForceLandingMessage *)allocator.zero_allocate(size, sizeof(dronehive_interfaces__msg__DroneForceLandingMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dronehive_interfaces__msg__DroneForceLandingMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dronehive_interfaces__msg__DroneForceLandingMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
dronehive_interfaces__msg__DroneForceLandingMessage__Sequence__fini(dronehive_interfaces__msg__DroneForceLandingMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dronehive_interfaces__msg__DroneForceLandingMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

dronehive_interfaces__msg__DroneForceLandingMessage__Sequence *
dronehive_interfaces__msg__DroneForceLandingMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__DroneForceLandingMessage__Sequence * array = (dronehive_interfaces__msg__DroneForceLandingMessage__Sequence *)allocator.allocate(sizeof(dronehive_interfaces__msg__DroneForceLandingMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dronehive_interfaces__msg__DroneForceLandingMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dronehive_interfaces__msg__DroneForceLandingMessage__Sequence__destroy(dronehive_interfaces__msg__DroneForceLandingMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dronehive_interfaces__msg__DroneForceLandingMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dronehive_interfaces__msg__DroneForceLandingMessage__Sequence__are_equal(const dronehive_interfaces__msg__DroneForceLandingMessage__Sequence * lhs, const dronehive_interfaces__msg__DroneForceLandingMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dronehive_interfaces__msg__DroneForceLandingMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dronehive_interfaces__msg__DroneForceLandingMessage__Sequence__copy(
  const dronehive_interfaces__msg__DroneForceLandingMessage__Sequence * input,
  dronehive_interfaces__msg__DroneForceLandingMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dronehive_interfaces__msg__DroneForceLandingMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dronehive_interfaces__msg__DroneForceLandingMessage * data =
      (dronehive_interfaces__msg__DroneForceLandingMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dronehive_interfaces__msg__DroneForceLandingMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dronehive_interfaces__msg__DroneForceLandingMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dronehive_interfaces__msg__DroneForceLandingMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
