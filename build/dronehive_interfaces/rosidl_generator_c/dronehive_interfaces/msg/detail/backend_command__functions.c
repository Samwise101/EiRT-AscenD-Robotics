// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dronehive_interfaces:msg/BackendCommand.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/msg/detail/backend_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
dronehive_interfaces__msg__BackendCommand__init(dronehive_interfaces__msg__BackendCommand * msg)
{
  if (!msg) {
    return false;
  }
  // command
  // confirm
  return true;
}

void
dronehive_interfaces__msg__BackendCommand__fini(dronehive_interfaces__msg__BackendCommand * msg)
{
  if (!msg) {
    return;
  }
  // command
  // confirm
}

bool
dronehive_interfaces__msg__BackendCommand__are_equal(const dronehive_interfaces__msg__BackendCommand * lhs, const dronehive_interfaces__msg__BackendCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (lhs->command != rhs->command) {
    return false;
  }
  // confirm
  if (lhs->confirm != rhs->confirm) {
    return false;
  }
  return true;
}

bool
dronehive_interfaces__msg__BackendCommand__copy(
  const dronehive_interfaces__msg__BackendCommand * input,
  dronehive_interfaces__msg__BackendCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  output->command = input->command;
  // confirm
  output->confirm = input->confirm;
  return true;
}

dronehive_interfaces__msg__BackendCommand *
dronehive_interfaces__msg__BackendCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__BackendCommand * msg = (dronehive_interfaces__msg__BackendCommand *)allocator.allocate(sizeof(dronehive_interfaces__msg__BackendCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dronehive_interfaces__msg__BackendCommand));
  bool success = dronehive_interfaces__msg__BackendCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dronehive_interfaces__msg__BackendCommand__destroy(dronehive_interfaces__msg__BackendCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dronehive_interfaces__msg__BackendCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dronehive_interfaces__msg__BackendCommand__Sequence__init(dronehive_interfaces__msg__BackendCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__BackendCommand * data = NULL;

  if (size) {
    data = (dronehive_interfaces__msg__BackendCommand *)allocator.zero_allocate(size, sizeof(dronehive_interfaces__msg__BackendCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dronehive_interfaces__msg__BackendCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dronehive_interfaces__msg__BackendCommand__fini(&data[i - 1]);
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
dronehive_interfaces__msg__BackendCommand__Sequence__fini(dronehive_interfaces__msg__BackendCommand__Sequence * array)
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
      dronehive_interfaces__msg__BackendCommand__fini(&array->data[i]);
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

dronehive_interfaces__msg__BackendCommand__Sequence *
dronehive_interfaces__msg__BackendCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__BackendCommand__Sequence * array = (dronehive_interfaces__msg__BackendCommand__Sequence *)allocator.allocate(sizeof(dronehive_interfaces__msg__BackendCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dronehive_interfaces__msg__BackendCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dronehive_interfaces__msg__BackendCommand__Sequence__destroy(dronehive_interfaces__msg__BackendCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dronehive_interfaces__msg__BackendCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dronehive_interfaces__msg__BackendCommand__Sequence__are_equal(const dronehive_interfaces__msg__BackendCommand__Sequence * lhs, const dronehive_interfaces__msg__BackendCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dronehive_interfaces__msg__BackendCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dronehive_interfaces__msg__BackendCommand__Sequence__copy(
  const dronehive_interfaces__msg__BackendCommand__Sequence * input,
  dronehive_interfaces__msg__BackendCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dronehive_interfaces__msg__BackendCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dronehive_interfaces__msg__BackendCommand * data =
      (dronehive_interfaces__msg__BackendCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dronehive_interfaces__msg__BackendCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dronehive_interfaces__msg__BackendCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dronehive_interfaces__msg__BackendCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
