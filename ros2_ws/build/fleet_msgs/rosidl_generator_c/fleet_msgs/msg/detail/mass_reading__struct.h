// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fleet_msgs:msg/MassReading.idl
// generated code does not contain a copyright notice

#ifndef FLEET_MSGS__MSG__DETAIL__MASS_READING__STRUCT_H_
#define FLEET_MSGS__MSG__DETAIL__MASS_READING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'unit_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MassReading in the package fleet_msgs.
/**
  * Mass reading message for fleet operations
 */
typedef struct fleet_msgs__msg__MassReading
{
  std_msgs__msg__Header header;
  /// Mass in kilograms
  double mass_kg;
  /// Unit/vehicle identifier
  rosidl_runtime_c__String unit_id;
} fleet_msgs__msg__MassReading;

// Struct for a sequence of fleet_msgs__msg__MassReading.
typedef struct fleet_msgs__msg__MassReading__Sequence
{
  fleet_msgs__msg__MassReading * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fleet_msgs__msg__MassReading__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLEET_MSGS__MSG__DETAIL__MASS_READING__STRUCT_H_
