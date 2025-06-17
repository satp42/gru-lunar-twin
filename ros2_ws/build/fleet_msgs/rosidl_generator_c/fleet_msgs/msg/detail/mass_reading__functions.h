// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from fleet_msgs:msg/MassReading.idl
// generated code does not contain a copyright notice

#ifndef FLEET_MSGS__MSG__DETAIL__MASS_READING__FUNCTIONS_H_
#define FLEET_MSGS__MSG__DETAIL__MASS_READING__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "fleet_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "fleet_msgs/msg/detail/mass_reading__struct.h"

/// Initialize msg/MassReading message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fleet_msgs__msg__MassReading
 * )) before or use
 * fleet_msgs__msg__MassReading__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
bool
fleet_msgs__msg__MassReading__init(fleet_msgs__msg__MassReading * msg);

/// Finalize msg/MassReading message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
void
fleet_msgs__msg__MassReading__fini(fleet_msgs__msg__MassReading * msg);

/// Create msg/MassReading message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fleet_msgs__msg__MassReading__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
fleet_msgs__msg__MassReading *
fleet_msgs__msg__MassReading__create();

/// Destroy msg/MassReading message.
/**
 * It calls
 * fleet_msgs__msg__MassReading__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
void
fleet_msgs__msg__MassReading__destroy(fleet_msgs__msg__MassReading * msg);

/// Check for msg/MassReading message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
bool
fleet_msgs__msg__MassReading__are_equal(const fleet_msgs__msg__MassReading * lhs, const fleet_msgs__msg__MassReading * rhs);

/// Copy a msg/MassReading message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
bool
fleet_msgs__msg__MassReading__copy(
  const fleet_msgs__msg__MassReading * input,
  fleet_msgs__msg__MassReading * output);

/// Initialize array of msg/MassReading messages.
/**
 * It allocates the memory for the number of elements and calls
 * fleet_msgs__msg__MassReading__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
bool
fleet_msgs__msg__MassReading__Sequence__init(fleet_msgs__msg__MassReading__Sequence * array, size_t size);

/// Finalize array of msg/MassReading messages.
/**
 * It calls
 * fleet_msgs__msg__MassReading__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
void
fleet_msgs__msg__MassReading__Sequence__fini(fleet_msgs__msg__MassReading__Sequence * array);

/// Create array of msg/MassReading messages.
/**
 * It allocates the memory for the array and calls
 * fleet_msgs__msg__MassReading__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
fleet_msgs__msg__MassReading__Sequence *
fleet_msgs__msg__MassReading__Sequence__create(size_t size);

/// Destroy array of msg/MassReading messages.
/**
 * It calls
 * fleet_msgs__msg__MassReading__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
void
fleet_msgs__msg__MassReading__Sequence__destroy(fleet_msgs__msg__MassReading__Sequence * array);

/// Check for msg/MassReading message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
bool
fleet_msgs__msg__MassReading__Sequence__are_equal(const fleet_msgs__msg__MassReading__Sequence * lhs, const fleet_msgs__msg__MassReading__Sequence * rhs);

/// Copy an array of msg/MassReading messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_fleet_msgs
bool
fleet_msgs__msg__MassReading__Sequence__copy(
  const fleet_msgs__msg__MassReading__Sequence * input,
  fleet_msgs__msg__MassReading__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FLEET_MSGS__MSG__DETAIL__MASS_READING__FUNCTIONS_H_
