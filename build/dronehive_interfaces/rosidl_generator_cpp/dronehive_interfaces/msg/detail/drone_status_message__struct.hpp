// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:msg/DroneStatusMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'current_position'
#include "dronehive_interfaces/msg/detail/position_message__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__msg__DroneStatusMessage __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__msg__DroneStatusMessage __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DroneStatusMessage_
{
  using Type = DroneStatusMessage_<ContainerAllocator>;

  explicit DroneStatusMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
      this->battery_voltage = 0.0f;
      this->battery_percentage = 0.0f;
      this->fligt_state = "";
      this->reached_first_waypoint = false;
    }
  }

  explicit DroneStatusMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : drone_id(_alloc),
    fligt_state(_alloc),
    current_position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
      this->battery_voltage = 0.0f;
      this->battery_percentage = 0.0f;
      this->fligt_state = "";
      this->reached_first_waypoint = false;
    }
  }

  // field types and members
  using _drone_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _drone_id_type drone_id;
  using _battery_voltage_type =
    float;
  _battery_voltage_type battery_voltage;
  using _battery_percentage_type =
    float;
  _battery_percentage_type battery_percentage;
  using _fligt_state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fligt_state_type fligt_state;
  using _reached_first_waypoint_type =
    bool;
  _reached_first_waypoint_type reached_first_waypoint;
  using _current_position_type =
    dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>;
  _current_position_type current_position;

  // setters for named parameter idiom
  Type & set__drone_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->drone_id = _arg;
    return *this;
  }
  Type & set__battery_voltage(
    const float & _arg)
  {
    this->battery_voltage = _arg;
    return *this;
  }
  Type & set__battery_percentage(
    const float & _arg)
  {
    this->battery_percentage = _arg;
    return *this;
  }
  Type & set__fligt_state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fligt_state = _arg;
    return *this;
  }
  Type & set__reached_first_waypoint(
    const bool & _arg)
  {
    this->reached_first_waypoint = _arg;
    return *this;
  }
  Type & set__current_position(
    const dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> & _arg)
  {
    this->current_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__msg__DroneStatusMessage
    std::shared_ptr<dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__msg__DroneStatusMessage
    std::shared_ptr<dronehive_interfaces::msg::DroneStatusMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneStatusMessage_ & other) const
  {
    if (this->drone_id != other.drone_id) {
      return false;
    }
    if (this->battery_voltage != other.battery_voltage) {
      return false;
    }
    if (this->battery_percentage != other.battery_percentage) {
      return false;
    }
    if (this->fligt_state != other.fligt_state) {
      return false;
    }
    if (this->reached_first_waypoint != other.reached_first_waypoint) {
      return false;
    }
    if (this->current_position != other.current_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneStatusMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneStatusMessage_

// alias to use template instance with default allocator
using DroneStatusMessage =
  dronehive_interfaces::msg::DroneStatusMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__DRONE_STATUS_MESSAGE__STRUCT_HPP_
