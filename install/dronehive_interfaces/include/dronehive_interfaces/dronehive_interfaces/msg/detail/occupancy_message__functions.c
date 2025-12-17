// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dronehive_interfaces:msg/OccupancyMessage.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/msg/detail/occupancy_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `box_id`
// Member `drone_id`
#include "rosidl_runtime_c/string_functions.h"

bool
dronehive_interfaces__msg__OccupancyMessage__init(dronehive_interfaces__msg__OccupancyMessage * msg)
{
  if (!msg) {
    return false;
  }
  // box_id
  if (!rosidl_runtime_c__String__init(&msg->box_id)) {
    dronehive_interfaces__msg__OccupancyMessage__fini(msg);
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__init(&msg->drone_id)) {
    dronehive_interfaces__msg__OccupancyMessage__fini(msg);
    return false;
  }
  // occupancy
  return true;
}

void
dronehive_interfaces__msg__OccupancyMessage__fini(dronehive_interfaces__msg__OccupancyMessage * msg)
{
  if (!msg) {
    return;
  }
  // box_id
  rosidl_runtime_c__String__fini(&msg->box_id);
  // drone_id
  rosidl_runtime_c__String__fini(&msg->drone_id);
  // occupancy
}

bool
dronehive_interfaces__msg__OccupancyMessage__are_equal(const dronehive_interfaces__msg__OccupancyMessage * lhs, const dronehive_interfaces__msg__OccupancyMessage * rhs)
{
  if (!lhs || !rhs) {
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
  // occupancy
  if (lhs->occupancy != rhs->occupancy) {
    return false;
  }
  return true;
}

bool
dronehive_interfaces__msg__OccupancyMessage__copy(
  const dronehive_interfaces__msg__OccupancyMessage * input,
  dronehive_interfaces__msg__OccupancyMessage * output)
{
  if (!input || !output) {
    return false;
  }
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
  // occupancy
  output->occupancy = input->occupancy;
  return true;
}

dronehive_interfaces__msg__OccupancyMessage *
dronehive_interfaces__msg__OccupancyMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__OccupancyMessage * msg = (dronehive_interfaces__msg__OccupancyMessage *)allocator.allocate(sizeof(dronehive_interfaces__msg__OccupancyMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dronehive_interfaces__msg__OccupancyMessage));
  bool success = dronehive_interfaces__msg__OccupancyMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dronehive_interfaces__msg__OccupancyMessage__destroy(dronehive_interfaces__msg__OccupancyMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dronehive_interfaces__msg__OccupancyMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dronehive_interfaces__msg__OccupancyMessage__Sequence__init(dronehive_interfaces__msg__OccupancyMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__OccupancyMessage * data = NULL;

  if (size) {
    data = (dronehive_interfaces__msg__OccupancyMessage *)allocator.zero_allocate(size, sizeof(dronehive_interfaces__msg__OccupancyMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dronehive_interfaces__msg__OccupancyMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dronehive_interfaces__msg__OccupancyMessage__fini(&data[i - 1]);
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
dronehive_interfaces__msg__OccupancyMessage__Sequence__fini(dronehive_interfaces__msg__OccupancyMessage__Sequence * array)
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
      dronehive_interfaces__msg__OccupancyMessage__fini(&array->data[i]);
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

dronehive_interfaces__msg__OccupancyMessage__Sequence *
dronehive_interfaces__msg__OccupancyMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__OccupancyMessage__Sequence * array = (dronehive_interfaces__msg__OccupancyMessage__Sequence *)allocator.allocate(sizeof(dronehive_interfaces__msg__OccupancyMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dronehive_interfaces__msg__OccupancyMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dronehive_interfaces__msg__OccupancyMessage__Sequence__destroy(dronehive_interfaces__msg__OccupancyMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dronehive_interfaces__msg__OccupancyMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dronehive_interfaces__msg__OccupancyMessage__Sequence__are_equal(const dronehive_interfaces__msg__OccupancyMessage__Sequence * lhs, const dronehive_interfaces__msg__OccupancyMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dronehive_interfaces__msg__OccupancyMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dronehive_interfaces__msg__OccupancyMessage__Sequence__copy(
  const dronehive_interfaces__msg__OccupancyMessage__Sequence * input,
  dronehive_interfaces__msg__OccupancyMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dronehive_interfaces__msg__OccupancyMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dronehive_interfaces__msg__OccupancyMessage * data =
      (dronehive_interfaces__msg__OccupancyMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dronehive_interfaces__msg__OccupancyMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dronehive_interfaces__msg__OccupancyMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dronehive_interfaces__msg__OccupancyMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
