// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fleet_msgs:msg/MassReading.idl
// generated code does not contain a copyright notice
#include "fleet_msgs/msg/detail/mass_reading__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `unit_id`
#include "rosidl_runtime_c/string_functions.h"

bool
fleet_msgs__msg__MassReading__init(fleet_msgs__msg__MassReading * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    fleet_msgs__msg__MassReading__fini(msg);
    return false;
  }
  // mass_kg
  // unit_id
  if (!rosidl_runtime_c__String__init(&msg->unit_id)) {
    fleet_msgs__msg__MassReading__fini(msg);
    return false;
  }
  return true;
}

void
fleet_msgs__msg__MassReading__fini(fleet_msgs__msg__MassReading * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // mass_kg
  // unit_id
  rosidl_runtime_c__String__fini(&msg->unit_id);
}

bool
fleet_msgs__msg__MassReading__are_equal(const fleet_msgs__msg__MassReading * lhs, const fleet_msgs__msg__MassReading * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // mass_kg
  if (lhs->mass_kg != rhs->mass_kg) {
    return false;
  }
  // unit_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->unit_id), &(rhs->unit_id)))
  {
    return false;
  }
  return true;
}

bool
fleet_msgs__msg__MassReading__copy(
  const fleet_msgs__msg__MassReading * input,
  fleet_msgs__msg__MassReading * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // mass_kg
  output->mass_kg = input->mass_kg;
  // unit_id
  if (!rosidl_runtime_c__String__copy(
      &(input->unit_id), &(output->unit_id)))
  {
    return false;
  }
  return true;
}

fleet_msgs__msg__MassReading *
fleet_msgs__msg__MassReading__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fleet_msgs__msg__MassReading * msg = (fleet_msgs__msg__MassReading *)allocator.allocate(sizeof(fleet_msgs__msg__MassReading), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fleet_msgs__msg__MassReading));
  bool success = fleet_msgs__msg__MassReading__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fleet_msgs__msg__MassReading__destroy(fleet_msgs__msg__MassReading * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fleet_msgs__msg__MassReading__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fleet_msgs__msg__MassReading__Sequence__init(fleet_msgs__msg__MassReading__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fleet_msgs__msg__MassReading * data = NULL;

  if (size) {
    data = (fleet_msgs__msg__MassReading *)allocator.zero_allocate(size, sizeof(fleet_msgs__msg__MassReading), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fleet_msgs__msg__MassReading__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fleet_msgs__msg__MassReading__fini(&data[i - 1]);
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
fleet_msgs__msg__MassReading__Sequence__fini(fleet_msgs__msg__MassReading__Sequence * array)
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
      fleet_msgs__msg__MassReading__fini(&array->data[i]);
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

fleet_msgs__msg__MassReading__Sequence *
fleet_msgs__msg__MassReading__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fleet_msgs__msg__MassReading__Sequence * array = (fleet_msgs__msg__MassReading__Sequence *)allocator.allocate(sizeof(fleet_msgs__msg__MassReading__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fleet_msgs__msg__MassReading__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fleet_msgs__msg__MassReading__Sequence__destroy(fleet_msgs__msg__MassReading__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fleet_msgs__msg__MassReading__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fleet_msgs__msg__MassReading__Sequence__are_equal(const fleet_msgs__msg__MassReading__Sequence * lhs, const fleet_msgs__msg__MassReading__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fleet_msgs__msg__MassReading__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fleet_msgs__msg__MassReading__Sequence__copy(
  const fleet_msgs__msg__MassReading__Sequence * input,
  fleet_msgs__msg__MassReading__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fleet_msgs__msg__MassReading);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fleet_msgs__msg__MassReading * data =
      (fleet_msgs__msg__MassReading *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fleet_msgs__msg__MassReading__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fleet_msgs__msg__MassReading__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fleet_msgs__msg__MassReading__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
