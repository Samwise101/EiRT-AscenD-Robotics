// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:msg/GuiCommand.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__msg__GuiCommand __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__msg__GuiCommand __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GuiCommand_
{
  using Type = GuiCommand_<ContainerAllocator>;

  explicit GuiCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->confirm = false;
      this->box_id = "";
    }
  }

  explicit GuiCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : box_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->confirm = false;
      this->box_id = "";
    }
  }

  // field types and members
  using _command_type =
    uint8_t;
  _command_type command;
  using _confirm_type =
    bool;
  _confirm_type confirm;
  using _box_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _box_id_type box_id;

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
  Type & set__box_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->box_id = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t SEARCH_FOR_NEW_BOX =
    0u;
  static constexpr uint8_t REMOVE_BOX =
    1u;
  static constexpr uint8_t REQUEST_BOX_STATUS =
    2u;
  static constexpr uint8_t REQUEST_LANDING =
    3u;
  static constexpr uint8_t REQUEST_RETURN_HOME =
    4u;
  static constexpr uint8_t REQUEST_TAKEOFF =
    5u;
  static constexpr uint8_t REQUEST_ARMING =
    6u;
  static constexpr uint8_t PATH_UPLOAD =
    7u;
  static constexpr uint8_t REQUEST_LOG =
    8u;
  static constexpr uint8_t TRACK_DRONE =
    9u;
  static constexpr uint8_t REQUEST_EXECUTE_PATH =
    10u;
  static constexpr uint8_t REQUEST_FULL_SYSTEM_STATUS =
    11u;
  static constexpr uint8_t REQUEST_DRONE_STATUS =
    12u;
  static constexpr uint8_t SEARCH_FOR_NEW_DRONE =
    13u;

  // pointer types
  using RawPtr =
    dronehive_interfaces::msg::GuiCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::msg::GuiCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::GuiCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::GuiCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::GuiCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::GuiCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::GuiCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::GuiCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::GuiCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::GuiCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__msg__GuiCommand
    std::shared_ptr<dronehive_interfaces::msg::GuiCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__msg__GuiCommand
    std::shared_ptr<dronehive_interfaces::msg::GuiCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GuiCommand_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->confirm != other.confirm) {
      return false;
    }
    if (this->box_id != other.box_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const GuiCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GuiCommand_

// alias to use template instance with default allocator
using GuiCommand =
  dronehive_interfaces::msg::GuiCommand_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::SEARCH_FOR_NEW_BOX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::REMOVE_BOX;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::REQUEST_BOX_STATUS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::REQUEST_LANDING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::REQUEST_RETURN_HOME;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::REQUEST_TAKEOFF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::REQUEST_ARMING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::PATH_UPLOAD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::REQUEST_LOG;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::TRACK_DRONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::REQUEST_EXECUTE_PATH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::REQUEST_FULL_SYSTEM_STATUS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::REQUEST_DRONE_STATUS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GuiCommand_<ContainerAllocator>::SEARCH_FOR_NEW_DRONE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_COMMAND__STRUCT_HPP_
