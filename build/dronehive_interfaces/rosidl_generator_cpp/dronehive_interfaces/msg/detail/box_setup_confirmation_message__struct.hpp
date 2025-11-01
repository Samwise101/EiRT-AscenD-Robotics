// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:msg/BoxSetupConfirmationMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_SETUP_CONFIRMATION_MESSAGE__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_SETUP_CONFIRMATION_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'landing_pos'
#include "dronehive_interfaces/msg/detail/position_message__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__msg__BoxSetupConfirmationMessage __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__msg__BoxSetupConfirmationMessage __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BoxSetupConfirmationMessage_
{
  using Type = BoxSetupConfirmationMessage_<ContainerAllocator>;

  explicit BoxSetupConfirmationMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : landing_pos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->confirm = false;
      this->box_id = "";
    }
  }

  explicit BoxSetupConfirmationMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : box_id(_alloc),
    landing_pos(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->confirm = false;
      this->box_id = "";
    }
  }

  // field types and members
  using _confirm_type =
    bool;
  _confirm_type confirm;
  using _box_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _box_id_type box_id;
  using _landing_pos_type =
    dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>;
  _landing_pos_type landing_pos;

  // setters for named parameter idiom
  Type & set__confirm(
    const bool & _arg)
  {
    this->confirm = _arg;
    return *this;
  }
  Type & set__box_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->box_id = _arg;
    return *this;
  }
  Type & set__landing_pos(
    const dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> & _arg)
  {
    this->landing_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__msg__BoxSetupConfirmationMessage
    std::shared_ptr<dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__msg__BoxSetupConfirmationMessage
    std::shared_ptr<dronehive_interfaces::msg::BoxSetupConfirmationMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoxSetupConfirmationMessage_ & other) const
  {
    if (this->confirm != other.confirm) {
      return false;
    }
    if (this->box_id != other.box_id) {
      return false;
    }
    if (this->landing_pos != other.landing_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoxSetupConfirmationMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoxSetupConfirmationMessage_

// alias to use template instance with default allocator
using BoxSetupConfirmationMessage =
  dronehive_interfaces::msg::BoxSetupConfirmationMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_SETUP_CONFIRMATION_MESSAGE__STRUCT_HPP_
