// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fleet_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice
#include "fleet_msgs/msg/detail/battery_status__functions.h"

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
fleet_msgs__msg__BatteryStatus__init(fleet_msgs__msg__BatteryStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    fleet_msgs__msg__BatteryStatus__fini(msg);
    return false;
  }
  // unit_id
  if (!rosidl_runtime_c__String__init(&msg->unit_id)) {
    fleet_msgs__msg__BatteryStatus__fini(msg);
    return false;
  }
  // soc_percentage
  // voltage_v
  // charging
  return true;
}

void
fleet_msgs__msg__BatteryStatus__fini(fleet_msgs__msg__BatteryStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // unit_id
  rosidl_runtime_c__String__fini(&msg->unit_id);
  // soc_percentage
  // voltage_v
  // charging
}

bool
fleet_msgs__msg__BatteryStatus__are_equal(const fleet_msgs__msg__BatteryStatus * lhs, const fleet_msgs__msg__BatteryStatus * rhs)
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
  // unit_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->unit_id), &(rhs->unit_id)))
  {
    return false;
  }
  // soc_percentage
  if (lhs->soc_percentage != rhs->soc_percentage) {
    return false;
  }
  // voltage_v
  if (lhs->voltage_v != rhs->voltage_v) {
    return false;
  }
  // charging
  if (lhs->charging != rhs->charging) {
    return false;
  }
  return true;
}

bool
fleet_msgs__msg__BatteryStatus__copy(
  const fleet_msgs__msg__BatteryStatus * input,
  fleet_msgs__msg__BatteryStatus * output)
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
  // unit_id
  if (!rosidl_runtime_c__String__copy(
      &(input->unit_id), &(output->unit_id)))
  {
    return false;
  }
  // soc_percentage
  output->soc_percentage = input->soc_percentage;
  // voltage_v
  output->voltage_v = input->voltage_v;
  // charging
  output->charging = input->charging;
  return true;
}

fleet_msgs__msg__BatteryStatus *
fleet_msgs__msg__BatteryStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fleet_msgs__msg__BatteryStatus * msg = (fleet_msgs__msg__BatteryStatus *)allocator.allocate(sizeof(fleet_msgs__msg__BatteryStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fleet_msgs__msg__BatteryStatus));
  bool success = fleet_msgs__msg__BatteryStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
fleet_msgs__msg__BatteryStatus__destroy(fleet_msgs__msg__BatteryStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    fleet_msgs__msg__BatteryStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
fleet_msgs__msg__BatteryStatus__Sequence__init(fleet_msgs__msg__BatteryStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fleet_msgs__msg__BatteryStatus * data = NULL;

  if (size) {
    data = (fleet_msgs__msg__BatteryStatus *)allocator.zero_allocate(size, sizeof(fleet_msgs__msg__BatteryStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fleet_msgs__msg__BatteryStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fleet_msgs__msg__BatteryStatus__fini(&data[i - 1]);
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
fleet_msgs__msg__BatteryStatus__Sequence__fini(fleet_msgs__msg__BatteryStatus__Sequence * array)
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
      fleet_msgs__msg__BatteryStatus__fini(&array->data[i]);
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

fleet_msgs__msg__BatteryStatus__Sequence *
fleet_msgs__msg__BatteryStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  fleet_msgs__msg__BatteryStatus__Sequence * array = (fleet_msgs__msg__BatteryStatus__Sequence *)allocator.allocate(sizeof(fleet_msgs__msg__BatteryStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = fleet_msgs__msg__BatteryStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
fleet_msgs__msg__BatteryStatus__Sequence__destroy(fleet_msgs__msg__BatteryStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    fleet_msgs__msg__BatteryStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
fleet_msgs__msg__BatteryStatus__Sequence__are_equal(const fleet_msgs__msg__BatteryStatus__Sequence * lhs, const fleet_msgs__msg__BatteryStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!fleet_msgs__msg__BatteryStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
fleet_msgs__msg__BatteryStatus__Sequence__copy(
  const fleet_msgs__msg__BatteryStatus__Sequence * input,
  fleet_msgs__msg__BatteryStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(fleet_msgs__msg__BatteryStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    fleet_msgs__msg__BatteryStatus * data =
      (fleet_msgs__msg__BatteryStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!fleet_msgs__msg__BatteryStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          fleet_msgs__msg__BatteryStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!fleet_msgs__msg__BatteryStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
