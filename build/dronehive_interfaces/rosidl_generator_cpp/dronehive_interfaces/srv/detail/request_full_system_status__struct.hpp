// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:srv/RequestFullSystemStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__RequestFullSystemStatus_Request __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__RequestFullSystemStatus_Request __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RequestFullSystemStatus_Request_
{
  using Type = RequestFullSystemStatus_Request_<ContainerAllocator>;

  explicit RequestFullSystemStatus_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit RequestFullSystemStatus_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__RequestFullSystemStatus_Request
    std::shared_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__RequestFullSystemStatus_Request
    std::shared_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RequestFullSystemStatus_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const RequestFullSystemStatus_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RequestFullSystemStatus_Request_

// alias to use template instance with default allocator
using RequestFullSystemStatus_Request =
  dronehive_interfaces::srv::RequestFullSystemStatus_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces


// Include directives for member types
// Member 'statuses'
#include "dronehive_interfaces/msg/detail/box_full_status__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__RequestFullSystemStatus_Response __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__RequestFullSystemStatus_Response __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RequestFullSystemStatus_Response_
{
  using Type = RequestFullSystemStatus_Response_<ContainerAllocator>;

  explicit RequestFullSystemStatus_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit RequestFullSystemStatus_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _statuses_type =
    std::vector<dronehive_interfaces::msg::BoxFullStatus_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<dronehive_interfaces::msg::BoxFullStatus_<ContainerAllocator>>>;
  _statuses_type statuses;

  // setters for named parameter idiom
  Type & set__statuses(
    const std::vector<dronehive_interfaces::msg::BoxFullStatus_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<dronehive_interfaces::msg::BoxFullStatus_<ContainerAllocator>>> & _arg)
  {
    this->statuses = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__RequestFullSystemStatus_Response
    std::shared_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__RequestFullSystemStatus_Response
    std::shared_ptr<dronehive_interfaces::srv::RequestFullSystemStatus_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RequestFullSystemStatus_Response_ & other) const
  {
    if (this->statuses != other.statuses) {
      return false;
    }
    return true;
  }
  bool operator!=(const RequestFullSystemStatus_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RequestFullSystemStatus_Response_

// alias to use template instance with default allocator
using RequestFullSystemStatus_Response =
  dronehive_interfaces::srv::RequestFullSystemStatus_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces

namespace dronehive_interfaces
{

namespace srv
{

struct RequestFullSystemStatus
{
  using Request = dronehive_interfaces::srv::RequestFullSystemStatus_Request;
  using Response = dronehive_interfaces::srv::RequestFullSystemStatus_Response;
};

}  // namespace srv

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_FULL_SYSTEM_STATUS__STRUCT_HPP_
