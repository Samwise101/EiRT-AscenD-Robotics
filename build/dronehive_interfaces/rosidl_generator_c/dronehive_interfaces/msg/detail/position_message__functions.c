// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dronehive_interfaces:msg/PositionMessage.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/msg/detail/position_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
dronehive_interfaces__msg__PositionMessage__init(dronehive_interfaces__msg__PositionMessage * msg)
{
  if (!msg) {
    return false;
  }
  // lat
  // lon
  // elv
  return true;
}

void
dronehive_interfaces__msg__PositionMessage__fini(dronehive_interfaces__msg__PositionMessage * msg)
{
  if (!msg) {
    return;
  }
  // lat
  // lon
  // elv
}

bool
dronehive_interfaces__msg__PositionMessage__are_equal(const dronehive_interfaces__msg__PositionMessage * lhs, const dronehive_interfaces__msg__PositionMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // lat
  if (lhs->lat != rhs->lat) {
    return false;
  }
  // lon
  if (lhs->lon != rhs->lon) {
    return false;
  }
  // elv
  if (lhs->elv != rhs->elv) {
    return false;
  }
  return true;
}

bool
dronehive_interfaces__msg__PositionMessage__copy(
  const dronehive_interfaces__msg__PositionMessage * input,
  dronehive_interfaces__msg__PositionMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // lat
  output->lat = input->lat;
  // lon
  output->lon = input->lon;
  // elv
  output->elv = input->elv;
  return true;
}

dronehive_interfaces__msg__PositionMessage *
dronehive_interfaces__msg__PositionMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__PositionMessage * msg = (dronehive_interfaces__msg__PositionMessage *)allocator.allocate(sizeof(dronehive_interfaces__msg__PositionMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dronehive_interfaces__msg__PositionMessage));
  bool success = dronehive_interfaces__msg__PositionMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dronehive_interfaces__msg__PositionMessage__destroy(dronehive_interfaces__msg__PositionMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dronehive_interfaces__msg__PositionMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dronehive_interfaces__msg__PositionMessage__Sequence__init(dronehive_interfaces__msg__PositionMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__PositionMessage * data = NULL;

  if (size) {
    data = (dronehive_interfaces__msg__PositionMessage *)allocator.zero_allocate(size, sizeof(dronehive_interfaces__msg__PositionMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dronehive_interfaces__msg__PositionMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dronehive_interfaces__msg__PositionMessage__fini(&data[i - 1]);
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
dronehive_interfaces__msg__PositionMessage__Sequence__fini(dronehive_interfaces__msg__PositionMessage__Sequence * array)
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
      dronehive_interfaces__msg__PositionMessage__fini(&array->data[i]);
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

dronehive_interfaces__msg__PositionMessage__Sequence *
dronehive_interfaces__msg__PositionMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__PositionMessage__Sequence * array = (dronehive_interfaces__msg__PositionMessage__Sequence *)allocator.allocate(sizeof(dronehive_interfaces__msg__PositionMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dronehive_interfaces__msg__PositionMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dronehive_interfaces__msg__PositionMessage__Sequence__destroy(dronehive_interfaces__msg__PositionMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dronehive_interfaces__msg__PositionMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dronehive_interfaces__msg__PositionMessage__Sequence__are_equal(const dronehive_interfaces__msg__PositionMessage__Sequence * lhs, const dronehive_interfaces__msg__PositionMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dronehive_interfaces__msg__PositionMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dronehive_interfaces__msg__PositionMessage__Sequence__copy(
  const dronehive_interfaces__msg__PositionMessage__Sequence * input,
  dronehive_interfaces__msg__PositionMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dronehive_interfaces__msg__PositionMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dronehive_interfaces__msg__PositionMessage * data =
      (dronehive_interfaces__msg__PositionMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dronehive_interfaces__msg__PositionMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dronehive_interfaces__msg__PositionMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dronehive_interfaces__msg__PositionMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
