// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:srv/BoxStatusSlaveUpdateService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'status'
#include "dronehive_interfaces/msg/detail/box_status_message__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Request __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Request __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BoxStatusSlaveUpdateService_Request_
{
  using Type = BoxStatusSlaveUpdateService_Request_<ContainerAllocator>;

  explicit BoxStatusSlaveUpdateService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_init)
  {
    (void)_init;
  }

  explicit BoxStatusSlaveUpdateService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _status_type =
    dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const dronehive_interfaces::msg::BoxStatusMessage_<ContainerAllocator> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Request
    std::shared_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Request
    std::shared_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoxStatusSlaveUpdateService_Request_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoxStatusSlaveUpdateService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoxStatusSlaveUpdateService_Request_

// alias to use template instance with default allocator
using BoxStatusSlaveUpdateService_Request =
  dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Response __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Response __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BoxStatusSlaveUpdateService_Response_
{
  using Type = BoxStatusSlaveUpdateService_Response_<ContainerAllocator>;

  explicit BoxStatusSlaveUpdateService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ack = false;
    }
  }

  explicit BoxStatusSlaveUpdateService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Response
    std::shared_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__BoxStatusSlaveUpdateService_Response
    std::shared_ptr<dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoxStatusSlaveUpdateService_Response_ & other) const
  {
    if (this->ack != other.ack) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoxStatusSlaveUpdateService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoxStatusSlaveUpdateService_Response_

// alias to use template instance with default allocator
using BoxStatusSlaveUpdateService_Response =
  dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces

namespace dronehive_interfaces
{

namespace srv
{

struct BoxStatusSlaveUpdateService
{
  using Request = dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Request;
  using Response = dronehive_interfaces::srv::BoxStatusSlaveUpdateService_Response;
};

}  // namespace srv

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__BOX_STATUS_SLAVE_UPDATE_SERVICE__STRUCT_HPP_
