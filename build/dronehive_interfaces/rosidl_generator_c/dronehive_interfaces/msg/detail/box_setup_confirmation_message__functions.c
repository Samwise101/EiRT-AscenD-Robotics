// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dronehive_interfaces:msg/BoxSetupConfirmationMessage.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/msg/detail/box_setup_confirmation_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `box_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `landing_pos`
#include "dronehive_interfaces/msg/detail/position_message__functions.h"

bool
dronehive_interfaces__msg__BoxSetupConfirmationMessage__init(dronehive_interfaces__msg__BoxSetupConfirmationMessage * msg)
{
  if (!msg) {
    return false;
  }
  // confirm
  // box_id
  if (!rosidl_runtime_c__String__init(&msg->box_id)) {
    dronehive_interfaces__msg__BoxSetupConfirmationMessage__fini(msg);
    return false;
  }
  // landing_pos
  if (!dronehive_interfaces__msg__PositionMessage__init(&msg->landing_pos)) {
    dronehive_interfaces__msg__BoxSetupConfirmationMessage__fini(msg);
    return false;
  }
  return true;
}

void
dronehive_interfaces__msg__BoxSetupConfirmationMessage__fini(dronehive_interfaces__msg__BoxSetupConfirmationMessage * msg)
{
  if (!msg) {
    return;
  }
  // confirm
  // box_id
  rosidl_runtime_c__String__fini(&msg->box_id);
  // landing_pos
  dronehive_interfaces__msg__PositionMessage__fini(&msg->landing_pos);
}

bool
dronehive_interfaces__msg__BoxSetupConfirmationMessage__are_equal(const dronehive_interfaces__msg__BoxSetupConfirmationMessage * lhs, const dronehive_interfaces__msg__BoxSetupConfirmationMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // confirm
  if (lhs->confirm != rhs->confirm) {
    return false;
  }
  // box_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->box_id), &(rhs->box_id)))
  {
    return false;
  }
  // landing_pos
  if (!dronehive_interfaces__msg__PositionMessage__are_equal(
      &(lhs->landing_pos), &(rhs->landing_pos)))
  {
    return false;
  }
  return true;
}

bool
dronehive_interfaces__msg__BoxSetupConfirmationMessage__copy(
  const dronehive_interfaces__msg__BoxSetupConfirmationMessage * input,
  dronehive_interfaces__msg__BoxSetupConfirmationMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // confirm
  output->confirm = input->confirm;
  // box_id
  if (!rosidl_runtime_c__String__copy(
      &(input->box_id), &(output->box_id)))
  {
    return false;
  }
  // landing_pos
  if (!dronehive_interfaces__msg__PositionMessage__copy(
      &(input->landing_pos), &(output->landing_pos)))
  {
    return false;
  }
  return true;
}

dronehive_interfaces__msg__BoxSetupConfirmationMessage *
dronehive_interfaces__msg__BoxSetupConfirmationMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__BoxSetupConfirmationMessage * msg = (dronehive_interfaces__msg__BoxSetupConfirmationMessage *)allocator.allocate(sizeof(dronehive_interfaces__msg__BoxSetupConfirmationMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dronehive_interfaces__msg__BoxSetupConfirmationMessage));
  bool success = dronehive_interfaces__msg__BoxSetupConfirmationMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dronehive_interfaces__msg__BoxSetupConfirmationMessage__destroy(dronehive_interfaces__msg__BoxSetupConfirmationMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dronehive_interfaces__msg__BoxSetupConfirmationMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence__init(dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__BoxSetupConfirmationMessage * data = NULL;

  if (size) {
    data = (dronehive_interfaces__msg__BoxSetupConfirmationMessage *)allocator.zero_allocate(size, sizeof(dronehive_interfaces__msg__BoxSetupConfirmationMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dronehive_interfaces__msg__BoxSetupConfirmationMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dronehive_interfaces__msg__BoxSetupConfirmationMessage__fini(&data[i - 1]);
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
dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence__fini(dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence * array)
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
      dronehive_interfaces__msg__BoxSetupConfirmationMessage__fini(&array->data[i]);
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

dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence *
dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence * array = (dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence *)allocator.allocate(sizeof(dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence__destroy(dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence__are_equal(const dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence * lhs, const dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dronehive_interfaces__msg__BoxSetupConfirmationMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence__copy(
  const dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence * input,
  dronehive_interfaces__msg__BoxSetupConfirmationMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dronehive_interfaces__msg__BoxSetupConfirmationMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dronehive_interfaces__msg__BoxSetupConfirmationMessage * data =
      (dronehive_interfaces__msg__BoxSetupConfirmationMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dronehive_interfaces__msg__BoxSetupConfirmationMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dronehive_interfaces__msg__BoxSetupConfirmationMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dronehive_interfaces__msg__BoxSetupConfirmationMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
