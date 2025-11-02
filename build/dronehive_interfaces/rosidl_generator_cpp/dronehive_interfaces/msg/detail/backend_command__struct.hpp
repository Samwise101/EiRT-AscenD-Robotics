// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:msg/BackendCommand.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BACKEND_COMMAND__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BACKEND_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__msg__BackendCommand __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__msg__BackendCommand __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BackendCommand_
{
  using Type = BackendCommand_<ContainerAllocator>;

  explicit BackendCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->confirm = false;
    }
  }

  explicit BackendCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->confirm = false;
    }
  }

  // field types and members
  using _command_type =
    uint8_t;
  _command_type command;
  using _confirm_type =
    bool;
  _confirm_type confirm;

  // setters for named parameter idiom
  Type & set__command(
    const uint8_t & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__confirm(
    const bool & _arg)
  {
    this->confirm = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CONFIRM_NEW_BOX_MSG =
    0u;
  static constexpr uint8_t DECLINE_NEW_BOX_MSG =
    1u;
  static constexpr uint8_t NEW_BOX_SEARCH_TIMEOUT =
    2u;

  // pointer types
  using RawPtr =
    dronehive_interfaces::msg::BackendCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::msg::BackendCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::BackendCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::BackendCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::BackendCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::BackendCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::BackendCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::BackendCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::BackendCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::BackendCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__msg__BackendCommand
    std::shared_ptr<dronehive_interfaces::msg::BackendCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__msg__BackendCommand
    std::shared_ptr<dronehive_interfaces::msg::BackendCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BackendCommand_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->confirm != other.confirm) {
      return false;
    }
    return true;
  }
  bool operator!=(const BackendCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BackendCommand_

// alias to use template instance with default allocator
using BackendCommand =
  dronehive_interfaces::msg::BackendCommand_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BackendCommand_<ContainerAllocator>::CONFIRM_NEW_BOX_MSG;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BackendCommand_<ContainerAllocator>::DECLINE_NEW_BOX_MSG;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BackendCommand_<ContainerAllocator>::NEW_BOX_SEARCH_TIMEOUT;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BACKEND_COMMAND__STRUCT_HPP_
