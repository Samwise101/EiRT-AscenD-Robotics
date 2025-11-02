// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dronehive_interfaces:msg/BoxSetupConfirmationMessage.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dronehive_interfaces/msg/detail/box_setup_confirmation_message__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dronehive_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void BoxSetupConfirmationMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dronehive_interfaces::msg::BoxSetupConfirmationMessage(_init);
}

void BoxSetupConfirmationMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dronehive_interfaces::msg::BoxSetupConfirmationMessage *>(message_memory);
  typed_message->~BoxSetupConfirmationMessage();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BoxSetupConfirmationMessage_message_member_array[3] = {
  {
    "confirm",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dronehive_interfaces::msg::BoxSetupConfirmationMessage, confirm),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "box_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dronehive_interfaces::msg::BoxSetupConfirmationMessage, box_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "landing_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<dronehive_interfaces::msg::PositionMessage>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dronehive_interfaces::msg::BoxSetupConfirmationMessage, landing_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BoxSetupConfirmationMessage_message_members = {
  "dronehive_interfaces::msg",  // message namespace
  "BoxSetupConfirmationMessage",  // message name
  3,  // number of fields
  sizeof(dronehive_interfaces::msg::BoxSetupConfirmationMessage),
  BoxSetupConfirmationMessage_message_member_array,  // message members
  BoxSetupConfirmationMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  BoxSetupConfirmationMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BoxSetupConfirmationMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BoxSetupConfirmationMessage_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dronehive_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dronehive_interfaces::msg::BoxSetupConfirmationMessage>()
{
  return &::dronehive_interfaces::msg::rosidl_typesupport_introspection_cpp::BoxSetupConfirmationMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dronehive_interfaces, msg, BoxSetupConfirmationMessage)() {
  return &::dronehive_interfaces::msg::rosidl_typesupport_introspection_cpp::BoxSetupConfirmationMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
