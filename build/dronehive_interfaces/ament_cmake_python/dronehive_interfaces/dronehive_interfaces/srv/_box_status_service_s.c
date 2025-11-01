// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from dronehive_interfaces:srv/BoxStatusService.idl
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
#include "dronehive_interfaces/srv/detail/box_status_service__struct.h"
#include "dronehive_interfaces/srv/detail/box_status_service__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool dronehive_interfaces__srv__box_status_service__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[70];
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
    assert(strncmp("dronehive_interfaces.srv._box_status_service.BoxStatusService_Request", full_classname_dest, 69) == 0);
  }
  dronehive_interfaces__srv__BoxStatusService_Request * ros_message = _ros_message;
  {  // box_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "box_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->box_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * dronehive_interfaces__srv__box_status_service__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BoxStatusService_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("dronehive_interfaces.srv._box_status_service");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BoxStatusService_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  dronehive_interfaces__srv__BoxStatusService_Request * ros_message = (dronehive_interfaces__srv__BoxStatusService_Request *)raw_ros_message;
  {  // box_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->box_id.data,
      strlen(ros_message->box_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "box_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "dronehive_interfaces/srv/detail/box_status_service__struct.h"
// already included above
// #include "dronehive_interfaces/srv/detail/box_status_service__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool dronehive_interfaces__msg__position_message__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * dronehive_interfaces__msg__position_message__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool dronehive_interfaces__srv__box_status_service__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[71];
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
    assert(strncmp("dronehive_interfaces.srv._box_status_service.BoxStatusService_Response", full_classname_dest, 70) == 0);
  }
  dronehive_interfaces__srv__BoxStatusService_Response * ros_message = _ros_message;
  {  // accept
    PyObject * field = PyObject_GetAttrString(_pymsg, "accept");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->accept = (Py_True == field);
    Py_DECREF(field);
  }
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
  {  // landing_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "landing_pos");
    if (!field) {
      return false;
    }
    if (!dronehive_interfaces__msg__position_message__convert_from_py(field, &ros_message->landing_pos)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * dronehive_interfaces__srv__box_status_service__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BoxStatusService_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("dronehive_interfaces.srv._box_status_service");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BoxStatusService_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  dronehive_interfaces__srv__BoxStatusService_Response * ros_message = (dronehive_interfaces__srv__BoxStatusService_Response *)raw_ros_message;
  {  // accept
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->accept ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "accept", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
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
  {  // landing_pos
    PyObject * field = NULL;
    field = dronehive_interfaces__msg__position_message__convert_to_py(&ros_message->landing_pos);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "landing_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
