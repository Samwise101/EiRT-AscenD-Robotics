// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:msg/PositionMessage.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__POSITION_MESSAGE__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__POSITION_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__msg__PositionMessage __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__msg__PositionMessage __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PositionMessage_
{
  using Type = PositionMessage_<ContainerAllocator>;

  explicit PositionMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lat = 0.0;
      this->lon = 0.0;
      this->elv = 0.0;
    }
  }

  explicit PositionMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lat = 0.0;
      this->lon = 0.0;
      this->elv = 0.0;
    }
  }

  // field types and members
  using _lat_type =
    double;
  _lat_type lat;
  using _lon_type =
    double;
  _lon_type lon;
  using _elv_type =
    double;
  _elv_type elv;

  // setters for named parameter idiom
  Type & set__lat(
    const double & _arg)
  {
    this->lat = _arg;
    return *this;
  }
  Type & set__lon(
    const double & _arg)
  {
    this->lon = _arg;
    return *this;
  }
  Type & set__elv(
    const double & _arg)
  {
    this->elv = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__msg__PositionMessage
    std::shared_ptr<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__msg__PositionMessage
    std::shared_ptr<dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PositionMessage_ & other) const
  {
    if (this->lat != other.lat) {
      return false;
    }
    if (this->lon != other.lon) {
      return false;
    }
    if (this->elv != other.elv) {
      return false;
    }
    return true;
  }
  bool operator!=(const PositionMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PositionMessage_

// alias to use template instance with default allocator
using PositionMessage =
  dronehive_interfaces::msg::PositionMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__POSITION_MESSAGE__STRUCT_HPP_
