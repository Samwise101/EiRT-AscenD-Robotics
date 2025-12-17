// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:msg/GuiDroneLandingRequest.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_LANDING_REQUEST__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_LANDING_REQUEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__msg__GuiDroneLandingRequest __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__msg__GuiDroneLandingRequest __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GuiDroneLandingRequest_
{
  using Type = GuiDroneLandingRequest_<ContainerAllocator>;

  explicit GuiDroneLandingRequest_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
    }
  }

  explicit GuiDroneLandingRequest_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : drone_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
    }
  }

  // field types and members
  using _drone_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _drone_id_type drone_id;

  // setters for named parameter idiom
  Type & set__drone_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->drone_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__msg__GuiDroneLandingRequest
    std::shared_ptr<dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__msg__GuiDroneLandingRequest
    std::shared_ptr<dronehive_interfaces::msg::GuiDroneLandingRequest_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GuiDroneLandingRequest_ & other) const
  {
    if (this->drone_id != other.drone_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const GuiDroneLandingRequest_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GuiDroneLandingRequest_

// alias to use template instance with default allocator
using GuiDroneLandingRequest =
  dronehive_interfaces::msg::GuiDroneLandingRequest_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__MSG__DETAIL__GUI_DRONE_LANDING_REQUEST__STRUCT_HPP_
