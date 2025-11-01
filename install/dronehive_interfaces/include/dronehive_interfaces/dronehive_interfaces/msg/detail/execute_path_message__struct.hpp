// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:msg/ExecutePathMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__EXECUTE_PATH_MESSAGE__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__EXECUTE_PATH_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'waypoints'
#include "dronehive_interfaces/msg/detail/position_message__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__msg__ExecutePathMessage __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__msg__ExecutePathMessage __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ExecutePathMessage_
{
  using Type = ExecutePathMessage_<ContainerAllocator>;

  explicit ExecutePathMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->box_id = "";
      this->plan = "";
      this->execution_type = "";
    }
  }

  explicit ExecutePathMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : box_id(_alloc),
    plan(_alloc),
    execution_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->box_id = "";
      this->plan = "";
      this->execution_type = "";
    }
  }

  // field types and members
  using _box_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _box_id_type box_id;
  using _plan_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _plan_type plan;
  using _waypoints_type =
    std::vector<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>>>;
  _waypoints_type waypoints;
  using _execution_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _execution_type_type execution_type;

  // setters for named parameter idiom
  Type & set__box_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->box_id = _arg;
    return *this;
  }
  Type & set__plan(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->plan = _arg;
    return *this;
  }
  Type & set__waypoints(
    const std::vector<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>>> & _arg)
  {
    this->waypoints = _arg;
    return *this;
  }
  Type & set__execution_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->execution_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__msg__ExecutePathMessage
    std::shared_ptr<dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__msg__ExecutePathMessage
    std::shared_ptr<dronehive_interfaces::msg::ExecutePathMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecutePathMessage_ & other) const
  {
    if (this->box_id != other.box_id) {
      return false;
    }
    if (this->plan != other.plan) {
      return false;
    }
    if (this->waypoints != other.waypoints) {
      return false;
    }
    if (this->execution_type != other.execution_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecutePathMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecutePathMessage_

// alias to use template instance with default allocator
using ExecutePathMessage =
  dronehive_interfaces::msg::ExecutePathMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__EXECUTE_PATH_MESSAGE__STRUCT_HPP_
