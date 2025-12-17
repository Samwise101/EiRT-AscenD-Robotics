// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:msg/BoxStatusMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__STRUCT_HPP_

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
# define DEPRECATED__dronehive_interfaces__msg__BoxStatusMessage __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__msg__BoxStatusMessage __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BoxStatusMessage_
{
  using Type = BoxStatusMessage_<ContainerAllocator>;

  explicit BoxStatusMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : landing_pos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->box_battery_level = 0.0;
      this->box_id = "";
      this->drone_id = "";
      this->status = "";
    }
  }

  explicit BoxStatusMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : landing_pos(_alloc, _init),
    box_id(_alloc),
    drone_id(_alloc),
    status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->box_battery_level = 0.0;
      this->box_id = "";
      this->drone_id = "";
      this->status = "";
    }
  }

  // field types and members
  using _landing_pos_type =
    dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>;
  _landing_pos_type landing_pos;
  using _box_battery_level_type =
    double;
  _box_battery_level_type box_battery_level;
  using _box_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _box_id_type box_id;
  using _drone_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _drone_id_type drone_id;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__landing_pos(
    const dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> & _arg)
  {
    this->landing_pos = _arg;
    return *this;
  }
  Type & set__box_battery_level(
    const double & _arg)
  {
    this->box_battery_level = _arg;
    return *this;
  }
  Type & set__box_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->box_id = _arg;
    return *this;
  }
  Type & set__drone_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->drone_id = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__msg__BoxStatusMessage
    std::shared_ptr<dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__msg__BoxStatusMessage
    std::shared_ptr<dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoxStatusMessage_ & other) const
  {
    if (this->landing_pos != other.landing_pos) {
      return false;
    }
    if (this->box_battery_level != other.box_battery_level) {
      return false;
    }
    if (this->box_id != other.box_id) {
      return false;
    }
    if (this->drone_id != other.drone_id) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoxStatusMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoxStatusMessage_

// alias to use template instance with default allocator
using BoxStatusMessage =
  dronehive_interfaces::msg::BoxStatusMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__BOX_STATUS_MESSAGE__STRUCT_HPP_
