// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from dronehive_interfaces:msg/DroneStatusMessage.idl
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
#include "dronehive_interfaces/msg/detail/drone_status_message__struct.h"
#include "dronehive_interfaces/msg/detail/drone_status_message__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

bool dronehive_interfaces__msg__position_message__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * dronehive_interfaces__msg__position_message__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool dronehive_interfaces__msg__drone_status_message__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[66];
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
    assert(strncmp("dronehive_interfaces.msg._drone_status_message.DroneStatusMessage", full_classname_dest, 65) == 0);
  }
  dronehive_interfaces__msg__DroneStatusMessage * ros_message = _ros_message;
  {  // drone_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "drone_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->drone_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // battery_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->battery_voltage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // battery_percentage
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_percentage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->battery_percentage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // fligt_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "fligt_state");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->fligt_state, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // reached_first_waypoint
    PyObject * field = PyObject_GetAttrString(_pymsg, "reached_first_waypoint");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->reached_first_waypoint = (Py_True == field);
    Py_DECREF(field);
  }
  {  // current_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_position");
    if (!field) {
      return false;
    }
    if (!dronehive_interfaces__msg__position_message__convert_from_py(field, &ros_message->current_position)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * dronehive_interfaces__msg__drone_status_message__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DroneStatusMessage */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("dronehive_interfaces.msg._drone_status_message");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DroneStatusMessage");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  dronehive_interfaces__msg__DroneStatusMessage * ros_message = (dronehive_interfaces__msg__DroneStatusMessage *)raw_ros_message;
  {  // drone_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->drone_id.data,
      strlen(ros_message->drone_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "drone_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // battery_voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->battery_voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // battery_percentage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->battery_percentage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_percentage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fligt_state
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->fligt_state.data,
      strlen(ros_message->fligt_state.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "fligt_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reached_first_waypoint
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->reached_first_waypoint ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reached_first_waypoint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_position
    PyObject * field = NULL;
    field = dronehive_interfaces__msg__position_message__convert_to_py(&ros_message->current_position);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
