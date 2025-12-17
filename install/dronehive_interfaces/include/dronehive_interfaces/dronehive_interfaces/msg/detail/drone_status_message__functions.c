// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dronehive_interfaces:msg/DroneStatusMessage.idl
// generated code does not contain a copyright notice
#include "dronehive_interfaces/msg/detail/drone_status_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `drone_id`
// Member `fligt_state`
#include "rosidl_runtime_c/string_functions.h"
// Member `current_position`
#include "dronehive_interfaces/msg/detail/position_message__functions.h"

bool
dronehive_interfaces__msg__DroneStatusMessage__init(dronehive_interfaces__msg__DroneStatusMessage * msg)
{
  if (!msg) {
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__init(&msg->drone_id)) {
    dronehive_interfaces__msg__DroneStatusMessage__fini(msg);
    return false;
  }
  // battery_voltage
  // battery_percentage
  // fligt_state
  if (!rosidl_runtime_c__String__init(&msg->fligt_state)) {
    dronehive_interfaces__msg__DroneStatusMessage__fini(msg);
    return false;
  }
  // reached_first_waypoint
  // current_position
  if (!dronehive_interfaces__msg__PositionMessage__init(&msg->current_position)) {
    dronehive_interfaces__msg__DroneStatusMessage__fini(msg);
    return false;
  }
  return true;
}

void
dronehive_interfaces__msg__DroneStatusMessage__fini(dronehive_interfaces__msg__DroneStatusMessage * msg)
{
  if (!msg) {
    return;
  }
  // drone_id
  rosidl_runtime_c__String__fini(&msg->drone_id);
  // battery_voltage
  // battery_percentage
  // fligt_state
  rosidl_runtime_c__String__fini(&msg->fligt_state);
  // reached_first_waypoint
  // current_position
  dronehive_interfaces__msg__PositionMessage__fini(&msg->current_position);
}

bool
dronehive_interfaces__msg__DroneStatusMessage__are_equal(const dronehive_interfaces__msg__DroneStatusMessage * lhs, const dronehive_interfaces__msg__DroneStatusMessage * rhs)
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
  // battery_voltage
  if (lhs->battery_voltage != rhs->battery_voltage) {
    return false;
  }
  // battery_percentage
  if (lhs->battery_percentage != rhs->battery_percentage) {
    return false;
  }
  // fligt_state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->fligt_state), &(rhs->fligt_state)))
  {
    return false;
  }
  // reached_first_waypoint
  if (lhs->reached_first_waypoint != rhs->reached_first_waypoint) {
    return false;
  }
  // current_position
  if (!dronehive_interfaces__msg__PositionMessage__are_equal(
      &(lhs->current_position), &(rhs->current_position)))
  {
    return false;
  }
  return true;
}

bool
dronehive_interfaces__msg__DroneStatusMessage__copy(
  const dronehive_interfaces__msg__DroneStatusMessage * input,
  dronehive_interfaces__msg__DroneStatusMessage * output)
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
  // battery_voltage
  output->battery_voltage = input->battery_voltage;
  // battery_percentage
  output->battery_percentage = input->battery_percentage;
  // fligt_state
  if (!rosidl_runtime_c__String__copy(
      &(input->fligt_state), &(output->fligt_state)))
  {
    return false;
  }
  // reached_first_waypoint
  output->reached_first_waypoint = input->reached_first_waypoint;
  // current_position
  if (!dronehive_interfaces__msg__PositionMessage__copy(
      &(input->current_position), &(output->current_position)))
  {
    return false;
  }
  return true;
}

dronehive_interfaces__msg__DroneStatusMessage *
dronehive_interfaces__msg__DroneStatusMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__DroneStatusMessage * msg = (dronehive_interfaces__msg__DroneStatusMessage *)allocator.allocate(sizeof(dronehive_interfaces__msg__DroneStatusMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dronehive_interfaces__msg__DroneStatusMessage));
  bool success = dronehive_interfaces__msg__DroneStatusMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dronehive_interfaces__msg__DroneStatusMessage__destroy(dronehive_interfaces__msg__DroneStatusMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dronehive_interfaces__msg__DroneStatusMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dronehive_interfaces__msg__DroneStatusMessage__Sequence__init(dronehive_interfaces__msg__DroneStatusMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__DroneStatusMessage * data = NULL;

  if (size) {
    data = (dronehive_interfaces__msg__DroneStatusMessage *)allocator.zero_allocate(size, sizeof(dronehive_interfaces__msg__DroneStatusMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dronehive_interfaces__msg__DroneStatusMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dronehive_interfaces__msg__DroneStatusMessage__fini(&data[i - 1]);
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
dronehive_interfaces__msg__DroneStatusMessage__Sequence__fini(dronehive_interfaces__msg__DroneStatusMessage__Sequence * array)
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
      dronehive_interfaces__msg__DroneStatusMessage__fini(&array->data[i]);
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

dronehive_interfaces__msg__DroneStatusMessage__Sequence *
dronehive_interfaces__msg__DroneStatusMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dronehive_interfaces__msg__DroneStatusMessage__Sequence * array = (dronehive_interfaces__msg__DroneStatusMessage__Sequence *)allocator.allocate(sizeof(dronehive_interfaces__msg__DroneStatusMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dronehive_interfaces__msg__DroneStatusMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dronehive_interfaces__msg__DroneStatusMessage__Sequence__destroy(dronehive_interfaces__msg__DroneStatusMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dronehive_interfaces__msg__DroneStatusMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dronehive_interfaces__msg__DroneStatusMessage__Sequence__are_equal(const dronehive_interfaces__msg__DroneStatusMessage__Sequence * lhs, const dronehive_interfaces__msg__DroneStatusMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dronehive_interfaces__msg__DroneStatusMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dronehive_interfaces__msg__DroneStatusMessage__Sequence__copy(
  const dronehive_interfaces__msg__DroneStatusMessage__Sequence * input,
  dronehive_interfaces__msg__DroneStatusMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dronehive_interfaces__msg__DroneStatusMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dronehive_interfaces__msg__DroneStatusMessage * data =
      (dronehive_interfaces__msg__DroneStatusMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dronehive_interfaces__msg__DroneStatusMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dronehive_interfaces__msg__DroneStatusMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dronehive_interfaces__msg__DroneStatusMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
