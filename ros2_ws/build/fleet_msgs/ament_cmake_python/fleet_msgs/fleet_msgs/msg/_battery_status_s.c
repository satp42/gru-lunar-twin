// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from fleet_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "fleet_msgs/msg/detail/battery_status__struct.h"
#include "fleet_msgs/msg/detail/battery_status__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool fleet_msgs__msg__battery_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("fleet_msgs.msg._battery_status.BatteryStatus", full_classname_dest, 44) == 0);
  }
  fleet_msgs__msg__BatteryStatus * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // unit_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "unit_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->unit_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // soc_percentage
    PyObject * field = PyObject_GetAttrString(_pymsg, "soc_percentage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->soc_percentage = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // voltage_v
    PyObject * field = PyObject_GetAttrString(_pymsg, "voltage_v");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->voltage_v = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // charging
    PyObject * field = PyObject_GetAttrString(_pymsg, "charging");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->charging = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * fleet_msgs__msg__battery_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BatteryStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("fleet_msgs.msg._battery_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BatteryStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  fleet_msgs__msg__BatteryStatus * ros_message = (fleet_msgs__msg__BatteryStatus *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // unit_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->unit_id.data,
      strlen(ros_message->unit_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "unit_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // soc_percentage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->soc_percentage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "soc_percentage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // voltage_v
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->voltage_v);
    {
      int rc = PyObject_SetAttrString(_pymessage, "voltage_v", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // charging
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->charging ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "charging", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
