// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:srv/DroneLandingService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_LANDING_SERVICE__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_LANDING_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'drone_pos'
#include "dronehive_interfaces/msg/detail/position_message__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__DroneLandingService_Request __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__DroneLandingService_Request __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DroneLandingService_Request_
{
  using Type = DroneLandingService_Request_<ContainerAllocator>;

  explicit DroneLandingService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : drone_pos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
    }
  }

  explicit DroneLandingService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : drone_id(_alloc),
    drone_pos(_alloc, _init)
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
  using _drone_pos_type =
    dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>;
  _drone_pos_type drone_pos;

  // setters for named parameter idiom
  Type & set__drone_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->drone_id = _arg;
    return *this;
  }
  Type & set__drone_pos(
    const dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> & _arg)
  {
    this->drone_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__DroneLandingService_Request
    std::shared_ptr<dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__DroneLandingService_Request
    std::shared_ptr<dronehive_interfaces::srv::DroneLandingService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneLandingService_Request_ & other) const
  {
    if (this->drone_id != other.drone_id) {
      return false;
    }
    if (this->drone_pos != other.drone_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneLandingService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneLandingService_Request_

// alias to use template instance with default allocator
using DroneLandingService_Request =
  dronehive_interfaces::srv::DroneLandingService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces


// Include directives for member types
// Member 'landing_pos'
// already included above
// #include "dronehive_interfaces/msg/detail/position_message__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__DroneLandingService_Response __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__DroneLandingService_Response __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DroneLandingService_Response_
{
  using Type = DroneLandingService_Response_<ContainerAllocator>;

  explicit DroneLandingService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : landing_pos(_init)
  {
    (void)_init;
  }

  explicit DroneLandingService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : landing_pos(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _landing_pos_type =
    dronehive_interfaces::msg::PositionMessage_<ContainerAllocator>;
  _landing_pos_type landing_pos;

  // setters for named parameter idiom
  Type & set__landing_pos(
    const dronehive_interfaces::msg::PositionMessage_<ContainerAllocator> & _arg)
  {
    this->landing_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__DroneLandingService_Response
    std::shared_ptr<dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__DroneLandingService_Response
    std::shared_ptr<dronehive_interfaces::srv::DroneLandingService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneLandingService_Response_ & other) const
  {
    if (this->landing_pos != other.landing_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneLandingService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneLandingService_Response_

// alias to use template instance with default allocator
using DroneLandingService_Response =
  dronehive_interfaces::srv::DroneLandingService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces

namespace dronehive_interfaces
{

namespace srv
{

struct DroneLandingService
{
  using Request = dronehive_interfaces::srv::DroneLandingService_Request;
  using Response = dronehive_interfaces::srv::DroneLandingService_Response;
};

}  // namespace srv

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__DRONE_LANDING_SERVICE__STRUCT_HPP_
