// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:srv/DroneStartStopService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_START_STOP_SERVICE__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_START_STOP_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__DroneStartStopService_Request __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__DroneStartStopService_Request __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DroneStartStopService_Request_
{
  using Type = DroneStartStopService_Request_<ContainerAllocator>;

  explicit DroneStartStopService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
      this->control_var = 0;
    }
  }

  explicit DroneStartStopService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : drone_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
      this->control_var = 0;
    }
  }

  // field types and members
  using _drone_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _drone_id_type drone_id;
  using _control_var_type =
    int8_t;
  _control_var_type control_var;

  // setters for named parameter idiom
  Type & set__drone_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->drone_id = _arg;
    return *this;
  }
  Type & set__control_var(
    const int8_t & _arg)
  {
    this->control_var = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__DroneStartStopService_Request
    std::shared_ptr<dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__DroneStartStopService_Request
    std::shared_ptr<dronehive_interfaces::srv::DroneStartStopService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneStartStopService_Request_ & other) const
  {
    if (this->drone_id != other.drone_id) {
      return false;
    }
    if (this->control_var != other.control_var) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneStartStopService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneStartStopService_Request_

// alias to use template instance with default allocator
using DroneStartStopService_Request =
  dronehive_interfaces::srv::DroneStartStopService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__DroneStartStopService_Response __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__DroneStartStopService_Response __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DroneStartStopService_Response_
{
  using Type = DroneStartStopService_Response_<ContainerAllocator>;

  explicit DroneStartStopService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ack = false;
    }
  }

  explicit DroneStartStopService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ack = false;
    }
  }

  // field types and members
  using _ack_type =
    bool;
  _ack_type ack;

  // setters for named parameter idiom
  Type & set__ack(
    const bool & _arg)
  {
    this->ack = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__DroneStartStopService_Response
    std::shared_ptr<dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__DroneStartStopService_Response
    std::shared_ptr<dronehive_interfaces::srv::DroneStartStopService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneStartStopService_Response_ & other) const
  {
    if (this->ack != other.ack) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneStartStopService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneStartStopService_Response_

// alias to use template instance with default allocator
using DroneStartStopService_Response =
  dronehive_interfaces::srv::DroneStartStopService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces

namespace dronehive_interfaces
{

namespace srv
{

struct DroneStartStopService
{
  using Request = dronehive_interfaces::srv::DroneStartStopService_Request;
  using Response = dronehive_interfaces::srv::DroneStartStopService_Response;
};

}  // namespace srv

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_START_STOP_SERVICE__STRUCT_HPP_
