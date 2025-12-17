// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dronehive_interfaces:msg/BoxStatusMessage.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/msg/detail/box_status_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `landing_pos`
#include "dronehive_interfaces/msg/detail/position_message__functions.h"
// Member `box_id`
// Member `drone_id`
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

bool
dronehive_interfaces__msg__BoxStatusMessage__init(dronehive_interfaces__msg__BoxStatusMessage * msg)
{
  if (!msg) {
    return false;
  }
  // landing_pos
  if (!dronehive_interfaces__msg__PositionMessage__init(&msg->landing_pos)) {
    dronehive_interfaces__msg__BoxStatusMessage__fini(msg);
    return false;
  }
  // box_battery_level
  // box_id
  if (!rosidl_runtime_c__String__init(&msg->box_id)) {
    dronehive_interfaces__msg__BoxStatusMessage__fini(msg);
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__init(&msg->drone_id)) {
    dronehive_interfaces__msg__BoxStatusMessage__fini(msg);
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    dronehive_interfaces__msg__BoxStatusMessage__fini(msg);
    return false;
  }
  return true;
}

void
dronehive_interfaces__msg__BoxStatusMessage__fini(dronehive_interfaces__msg__BoxStatusMessage * msg)
{
  if (!msg) {
    return;
  }
  // landing_pos
  dronehive_interfaces__msg__PositionMessage__fini(&msg->landing_pos);
  // box_battery_level
  // box_id
  rosidl_runtime_c__String__fini(&msg->box_id);
  // drone_id
  rosidl_runtime_c__String__fini(&msg->drone_id);
  // status
  rosidl_runtime_c__String__fini(&msg->status);
}

bool
dronehive_interfaces__msg__BoxStatusMessage__are_equal(const dronehive_interfaces__msg__BoxStatusMessage * lhs, const dronehive_interfaces__msg__BoxStatusMessage * rhs)
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
  // box_battery_level
  if (lhs->box_battery_level != rhs->box_battery_level) {
    return false;
  }
  // box_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->box_id), &(rhs->box_id)))
  {
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->drone_id), &(rhs->drone_id)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
dronehive_interfaces__msg__BoxStatusMessage__copy(
  const dronehive_interfaces__msg__BoxStatusMessage * input,
  dronehive_interfaces__msg__BoxStatusMessage * output)
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
  // box_battery_level
  output->box_battery_level = input->box_battery_level;
  // box_id
  if (!rosidl_runtime_c__String__copy(
      &(input->box_id), &(output->box_id)))
  {
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__copy(
      &(input->drone_id), &(output->drone_id)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

dronehive_interfaces__msg__BoxStatusMessage *
dronehive_interfaces__msg__BoxStatusMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__BoxStatusMessage * msg = (dronehive_interfaces__msg__BoxStatusMessage *)allocator.allocate(sizeof(dronehive_interfaces__msg__BoxStatusMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dronehive_interfaces__msg__BoxStatusMessage));
  bool success = dronehive_interfaces__msg__BoxStatusMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dronehive_interfaces__msg__BoxStatusMessage__destroy(dronehive_interfaces__msg__BoxStatusMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dronehive_interfaces__msg__BoxStatusMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dronehive_interfaces__msg__BoxStatusMessage__Sequence__init(dronehive_interfaces__msg__BoxStatusMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__BoxStatusMessage * data = NULL;

  if (size) {
    data = (dronehive_interfaces__msg__BoxStatusMessage *)allocator.zero_allocate(size, sizeof(dronehive_interfaces__msg__BoxStatusMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dronehive_interfaces__msg__BoxStatusMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dronehive_interfaces__msg__BoxStatusMessage__fini(&data[i - 1]);
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
dronehive_interfaces__msg__BoxStatusMessage__Sequence__fini(dronehive_interfaces__msg__BoxStatusMessage__Sequence * array)
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
      dronehive_interfaces__msg__BoxStatusMessage__fini(&array->data[i]);
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

dronehive_interfaces__msg__BoxStatusMessage__Sequence *
dronehive_interfaces__msg__BoxStatusMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__BoxStatusMessage__Sequence * array = (dronehive_interfaces__msg__BoxStatusMessage__Sequence *)allocator.allocate(sizeof(dronehive_interfaces__msg__BoxStatusMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dronehive_interfaces__msg__BoxStatusMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dronehive_interfaces__msg__BoxStatusMessage__Sequence__destroy(dronehive_interfaces__msg__BoxStatusMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dronehive_interfaces__msg__BoxStatusMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dronehive_interfaces__msg__BoxStatusMessage__Sequence__are_equal(const dronehive_interfaces__msg__BoxStatusMessage__Sequence * lhs, const dronehive_interfaces__msg__BoxStatusMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dronehive_interfaces__msg__BoxStatusMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dronehive_interfaces__msg__BoxStatusMessage__Sequence__copy(
  const dronehive_interfaces__msg__BoxStatusMessage__Sequence * input,
  dronehive_interfaces__msg__BoxStatusMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dronehive_interfaces__msg__BoxStatusMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dronehive_interfaces__msg__BoxStatusMessage * data =
      (dronehive_interfaces__msg__BoxStatusMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dronehive_interfaces__msg__BoxStatusMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dronehive_interfaces__msg__BoxStatusMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dronehive_interfaces__msg__BoxStatusMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
