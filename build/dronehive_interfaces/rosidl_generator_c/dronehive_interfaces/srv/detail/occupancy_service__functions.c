// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dronehive_interfaces:srv/OccupancyService.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/srv/detail/occupancy_service__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `drone_id`
// Member `box_id`
#include "rosidl_runtime_c/string_functions.h"

bool
dronehive_interfaces__srv__OccupancyService_Request__init(dronehive_interfaces__srv__OccupancyService_Request * msg)
{
  if (!msg) {
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__init(&msg->drone_id)) {
    dronehive_interfaces__srv__OccupancyService_Request__fini(msg);
    return false;
  }
  // box_id
  if (!rosidl_runtime_c__String__init(&msg->box_id)) {
    dronehive_interfaces__srv__OccupancyService_Request__fini(msg);
    return false;
  }
  return true;
}

void
dronehive_interfaces__srv__OccupancyService_Request__fini(dronehive_interfaces__srv__OccupancyService_Request * msg)
{
  if (!msg) {
    return;
  }
  // drone_id
  rosidl_runtime_c__String__fini(&msg->drone_id);
  // box_id
  rosidl_runtime_c__String__fini(&msg->box_id);
}

bool
dronehive_interfaces__srv__OccupancyService_Request__are_equal(const dronehive_interfaces__srv__OccupancyService_Request * lhs, const dronehive_interfaces__srv__OccupancyService_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->drone_id), &(rhs->drone_id)))
  {
    return false;
  }
  // box_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->box_id), &(rhs->box_id)))
  {
    return false;
  }
  return true;
}

bool
dronehive_interfaces__srv__OccupancyService_Request__copy(
  const dronehive_interfaces__srv__OccupancyService_Request * input,
  dronehive_interfaces__srv__OccupancyService_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__copy(
      &(input->drone_id), &(output->drone_id)))
  {
    return false;
  }
  // box_id
  if (!rosidl_runtime_c__String__copy(
      &(input->box_id), &(output->box_id)))
  {
    return false;
  }
  return true;
}

dronehive_interfaces__srv__OccupancyService_Request *
dronehive_interfaces__srv__OccupancyService_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__srv__OccupancyService_Request * msg = (dronehive_interfaces__srv__OccupancyService_Request *)allocator.allocate(sizeof(dronehive_interfaces__srv__OccupancyService_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dronehive_interfaces__srv__OccupancyService_Request));
  bool success = dronehive_interfaces__srv__OccupancyService_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dronehive_interfaces__srv__OccupancyService_Request__destroy(dronehive_interfaces__srv__OccupancyService_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dronehive_interfaces__srv__OccupancyService_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dronehive_interfaces__srv__OccupancyService_Request__Sequence__init(dronehive_interfaces__srv__OccupancyService_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__srv__OccupancyService_Request * data = NULL;

  if (size) {
    data = (dronehive_interfaces__srv__OccupancyService_Request *)allocator.zero_allocate(size, sizeof(dronehive_interfaces__srv__OccupancyService_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dronehive_interfaces__srv__OccupancyService_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dronehive_interfaces__srv__OccupancyService_Request__fini(&data[i - 1]);
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
dronehive_interfaces__srv__OccupancyService_Request__Sequence__fini(dronehive_interfaces__srv__OccupancyService_Request__Sequence * array)
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
      dronehive_interfaces__srv__OccupancyService_Request__fini(&array->data[i]);
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

dronehive_interfaces__srv__OccupancyService_Request__Sequence *
dronehive_interfaces__srv__OccupancyService_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__srv__OccupancyService_Request__Sequence * array = (dronehive_interfaces__srv__OccupancyService_Request__Sequence *)allocator.allocate(sizeof(dronehive_interfaces__srv__OccupancyService_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dronehive_interfaces__srv__OccupancyService_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dronehive_interfaces__srv__OccupancyService_Request__Sequence__destroy(dronehive_interfaces__srv__OccupancyService_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dronehive_interfaces__srv__OccupancyService_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dronehive_interfaces__srv__OccupancyService_Request__Sequence__are_equal(const dronehive_interfaces__srv__OccupancyService_Request__Sequence * lhs, const dronehive_interfaces__srv__OccupancyService_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dronehive_interfaces__srv__OccupancyService_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dronehive_interfaces__srv__OccupancyService_Request__Sequence__copy(
  const dronehive_interfaces__srv__OccupancyService_Request__Sequence * input,
  dronehive_interfaces__srv__OccupancyService_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dronehive_interfaces__srv__OccupancyService_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dronehive_interfaces__srv__OccupancyService_Request * data =
      (dronehive_interfaces__srv__OccupancyService_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dronehive_interfaces__srv__OccupancyService_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dronehive_interfaces__srv__OccupancyService_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dronehive_interfaces__srv__OccupancyService_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
dronehive_interfaces__srv__OccupancyService_Response__init(dronehive_interfaces__srv__OccupancyService_Response * msg)
{
  if (!msg) {
    return false;
  }
  // occupancy_status
  return true;
}

void
dronehive_interfaces__srv__OccupancyService_Response__fini(dronehive_interfaces__srv__OccupancyService_Response * msg)
{
  if (!msg) {
    return;
  }
  // occupancy_status
}

bool
dronehive_interfaces__srv__OccupancyService_Response__are_equal(const dronehive_interfaces__srv__OccupancyService_Response * lhs, const dronehive_interfaces__srv__OccupancyService_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // occupancy_status
  if (lhs->occupancy_status != rhs->occupancy_status) {
    return false;
  }
  return true;
}

bool
dronehive_interfaces__srv__OccupancyService_Response__copy(
  const dronehive_interfaces__srv__OccupancyService_Response * input,
  dronehive_interfaces__srv__OccupancyService_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // occupancy_status
  output->occupancy_status = input->occupancy_status;
  return true;
}

dronehive_interfaces__srv__OccupancyService_Response *
dronehive_interfaces__srv__OccupancyService_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__srv__OccupancyService_Response * msg = (dronehive_interfaces__srv__OccupancyService_Response *)allocator.allocate(sizeof(dronehive_interfaces__srv__OccupancyService_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dronehive_interfaces__srv__OccupancyService_Response));
  bool success = dronehive_interfaces__srv__OccupancyService_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dronehive_interfaces__srv__OccupancyService_Response__destroy(dronehive_interfaces__srv__OccupancyService_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dronehive_interfaces__srv__OccupancyService_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dronehive_interfaces__srv__OccupancyService_Response__Sequence__init(dronehive_interfaces__srv__OccupancyService_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__srv__OccupancyService_Response * data = NULL;

  if (size) {
    data = (dronehive_interfaces__srv__OccupancyService_Response *)allocator.zero_allocate(size, sizeof(dronehive_interfaces__srv__OccupancyService_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dronehive_interfaces__srv__OccupancyService_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dronehive_interfaces__srv__OccupancyService_Response__fini(&data[i - 1]);
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
dronehive_interfaces__srv__OccupancyService_Response__Sequence__fini(dronehive_interfaces__srv__OccupancyService_Response__Sequence * array)
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
      dronehive_interfaces__srv__OccupancyService_Response__fini(&array->data[i]);
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

dronehive_interfaces__srv__OccupancyService_Response__Sequence *
dronehive_interfaces__srv__OccupancyService_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__srv__OccupancyService_Response__Sequence * array = (dronehive_interfaces__srv__OccupancyService_Response__Sequence *)allocator.allocate(sizeof(dronehive_interfaces__srv__OccupancyService_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dronehive_interfaces__srv__OccupancyService_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dronehive_interfaces__srv__OccupancyService_Response__Sequence__destroy(dronehive_interfaces__srv__OccupancyService_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dronehive_interfaces__srv__OccupancyService_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dronehive_interfaces__srv__OccupancyService_Response__Sequence__are_equal(const dronehive_interfaces__srv__OccupancyService_Response__Sequence * lhs, const dronehive_interfaces__srv__OccupancyService_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dronehive_interfaces__srv__OccupancyService_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dronehive_interfaces__srv__OccupancyService_Response__Sequence__copy(
  const dronehive_interfaces__srv__OccupancyService_Response__Sequence * input,
  dronehive_interfaces__srv__OccupancyService_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dronehive_interfaces__srv__OccupancyService_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dronehive_interfaces__srv__OccupancyService_Response * data =
      (dronehive_interfaces__srv__OccupancyService_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dronehive_interfaces__srv__OccupancyService_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dronehive_interfaces__srv__OccupancyService_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dronehive_interfaces__srv__OccupancyService_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
