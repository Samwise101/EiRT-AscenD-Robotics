// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dronehive_interfaces:srv/RequestFullSystemStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dronehive_interfaces/srv/detail/request_full_system_status__rosidl_typesupport_introspection_c.h"
#include "dronehive_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dronehive_interfaces/srv/detail/request_full_system_status__functions.h"
#include "dronehive_interfaces/srv/detail/request_full_system_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dronehive_interfaces__srv__RequestFullSystemStatus_Request__init(message_memory);
}

void dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_fini_function(void * message_memory)
{
  dronehive_interfaces__srv__RequestFullSystemStatus_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dronehive_interfaces__srv__RequestFullSystemStatus_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_message_members = {
  "dronehive_interfaces__srv",  // message namespace
  "RequestFullSystemStatus_Request",  // message name
  1,  // number of fields
  sizeof(dronehive_interfaces__srv__RequestFullSystemStatus_Request),
  dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_message_member_array,  // message members
  dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_message_type_support_handle = {
  0,
  &dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dronehive_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, srv, RequestFullSystemStatus_Request)() {
  if (!dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_message_type_support_handle.typesupport_identifier) {
    dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dronehive_interfaces__srv__RequestFullSystemStatus_Request__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "dronehive_interfaces/srv/detail/request_full_system_status__rosidl_typesupport_introspection_c.h"
// already included above
// #include "dronehive_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "dronehive_interfaces/srv/detail/request_full_system_status__functions.h"
// already included above
// #include "dronehive_interfaces/srv/detail/request_full_system_status__struct.h"


// Include directives for member types
// Member `statuses`
#include "dronehive_interfaces/msg/box_full_status.h"
// Member `statuses`
#include "dronehive_interfaces/msg/detail/box_full_status__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dronehive_interfaces__srv__RequestFullSystemStatus_Response__init(message_memory);
}

void dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_fini_function(void * message_memory)
{
  dronehive_interfaces__srv__RequestFullSystemStatus_Response__fini(message_memory);
}

size_t dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__size_function__RequestFullSystemStatus_Response__statuses(
  const void * untyped_member)
{
  const dronehive_interfaces__msg__BoxFullStatus__Sequence * member =
    (const dronehive_interfaces__msg__BoxFullStatus__Sequence *)(untyped_member);
  return member->size;
}

const void * dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__get_const_function__RequestFullSystemStatus_Response__statuses(
  const void * untyped_member, size_t index)
{
  const dronehive_interfaces__msg__BoxFullStatus__Sequence * member =
    (const dronehive_interfaces__msg__BoxFullStatus__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__get_function__RequestFullSystemStatus_Response__statuses(
  void * untyped_member, size_t index)
{
  dronehive_interfaces__msg__BoxFullStatus__Sequence * member =
    (dronehive_interfaces__msg__BoxFullStatus__Sequence *)(untyped_member);
  return &member->data[index];
}

void dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__fetch_function__RequestFullSystemStatus_Response__statuses(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const dronehive_interfaces__msg__BoxFullStatus * item =
    ((const dronehive_interfaces__msg__BoxFullStatus *)
    dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__get_const_function__RequestFullSystemStatus_Response__statuses(untyped_member, index));
  dronehive_interfaces__msg__BoxFullStatus * value =
    (dronehive_interfaces__msg__BoxFullStatus *)(untyped_value);
  *value = *item;
}

void dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__assign_function__RequestFullSystemStatus_Response__statuses(
  void * untyped_member, size_t index, const void * untyped_value)
{
  dronehive_interfaces__msg__BoxFullStatus * item =
    ((dronehive_interfaces__msg__BoxFullStatus *)
    dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__get_function__RequestFullSystemStatus_Response__statuses(untyped_member, index));
  const dronehive_interfaces__msg__BoxFullStatus * value =
    (const dronehive_interfaces__msg__BoxFullStatus *)(untyped_value);
  *item = *value;
}

bool dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__resize_function__RequestFullSystemStatus_Response__statuses(
  void * untyped_member, size_t size)
{
  dronehive_interfaces__msg__BoxFullStatus__Sequence * member =
    (dronehive_interfaces__msg__BoxFullStatus__Sequence *)(untyped_member);
  dronehive_interfaces__msg__BoxFullStatus__Sequence__fini(member);
  return dronehive_interfaces__msg__BoxFullStatus__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_message_member_array[1] = {
  {
    "statuses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dronehive_interfaces__srv__RequestFullSystemStatus_Response, statuses),  // bytes offset in struct
    NULL,  // default value
    dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__size_function__RequestFullSystemStatus_Response__statuses,  // size() function pointer
    dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__get_const_function__RequestFullSystemStatus_Response__statuses,  // get_const(index) function pointer
    dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__get_function__RequestFullSystemStatus_Response__statuses,  // get(index) function pointer
    dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__fetch_function__RequestFullSystemStatus_Response__statuses,  // fetch(index, &value) function pointer
    dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__assign_function__RequestFullSystemStatus_Response__statuses,  // assign(index, value) function pointer
    dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__resize_function__RequestFullSystemStatus_Response__statuses  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_message_members = {
  "dronehive_interfaces__srv",  // message namespace
  "RequestFullSystemStatus_Response",  // message name
  1,  // number of fields
  sizeof(dronehive_interfaces__srv__RequestFullSystemStatus_Response),
  dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_message_member_array,  // message members
  dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_message_type_support_handle = {
  0,
  &dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dronehive_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, srv, RequestFullSystemStatus_Response)() {
  dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, msg, BoxFullStatus)();
  if (!dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_message_type_support_handle.typesupport_identifier) {
    dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dronehive_interfaces__srv__RequestFullSystemStatus_Response__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "dronehive_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "dronehive_interfaces/srv/detail/request_full_system_status__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers dronehive_interfaces__srv__detail__request_full_system_status__rosidl_typesupport_introspection_c__RequestFullSystemStatus_service_members = {
  "dronehive_interfaces__srv",  // service namespace
  "RequestFullSystemStatus",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // dronehive_interfaces__srv__detail__request_full_system_status__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Request_message_type_support_handle,
  NULL  // response message
  // dronehive_interfaces__srv__detail__request_full_system_status__rosidl_typesupport_introspection_c__RequestFullSystemStatus_Response_message_type_support_handle
};

static rosidl_service_type_support_t dronehive_interfaces__srv__detail__request_full_system_status__rosidl_typesupport_introspection_c__RequestFullSystemStatus_service_type_support_handle = {
  0,
  &dronehive_interfaces__srv__detail__request_full_system_status__rosidl_typesupport_introspection_c__RequestFullSystemStatus_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, srv, RequestFullSystemStatus_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, srv, RequestFullSystemStatus_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dronehive_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, srv, RequestFullSystemStatus)() {
  if (!dronehive_interfaces__srv__detail__request_full_system_status__rosidl_typesupport_introspection_c__RequestFullSystemStatus_service_type_support_handle.typesupport_identifier) {
    dronehive_interfaces__srv__detail__request_full_system_status__rosidl_typesupport_introspection_c__RequestFullSystemStatus_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)dronehive_interfaces__srv__detail__request_full_system_status__rosidl_typesupport_introspection_c__RequestFullSystemStatus_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, srv, RequestFullSystemStatus_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dronehive_interfaces, srv, RequestFullSystemStatus_Response)()->data;
  }

  return &dronehive_interfaces__srv__detail__request_full_system_status__rosidl_typesupport_introspection_c__RequestFullSystemStatus_service_type_support_handle;
}
