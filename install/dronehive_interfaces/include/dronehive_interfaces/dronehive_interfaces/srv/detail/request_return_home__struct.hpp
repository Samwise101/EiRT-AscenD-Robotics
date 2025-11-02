// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:srv/RequestReturnHome.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_RETURN_HOME__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_RETURN_HOME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__RequestReturnHome_Request __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__RequestReturnHome_Request __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RequestReturnHome_Request_
{
  using Type = RequestReturnHome_Request_<ContainerAllocator>;

  explicit RequestReturnHome_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->box_id = "";
    }
  }

  explicit RequestReturnHome_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : box_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->box_id = "";
    }
  }

  // field types and members
  using _box_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _box_id_type box_id;

  // setters for named parameter idiom
  Type & set__box_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->box_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__RequestReturnHome_Request
    std::shared_ptr<dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__RequestReturnHome_Request
    std::shared_ptr<dronehive_interfaces::srv::RequestReturnHome_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RequestReturnHome_Request_ & other) const
  {
    if (this->box_id != other.box_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const RequestReturnHome_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RequestReturnHome_Request_

// alias to use template instance with default allocator
using RequestReturnHome_Request =
  dronehive_interfaces::srv::RequestReturnHome_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__RequestReturnHome_Response __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__RequestReturnHome_Response __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RequestReturnHome_Response_
{
  using Type = RequestReturnHome_Response_<ContainerAllocator>;

  explicit RequestReturnHome_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->confirm = false;
    }
  }

  explicit RequestReturnHome_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->confirm = false;
    }
  }

  // field types and members
  using _confirm_type =
    bool;
  _confirm_type confirm;

  // setters for named parameter idiom
  Type & set__confirm(
    const bool & _arg)
  {
    this->confirm = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__RequestReturnHome_Response
    std::shared_ptr<dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__RequestReturnHome_Response
    std::shared_ptr<dronehive_interfaces::srv::RequestReturnHome_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RequestReturnHome_Response_ & other) const
  {
    if (this->confirm != other.confirm) {
      return false;
    }
    return true;
  }
  bool operator!=(const RequestReturnHome_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RequestReturnHome_Response_

// alias to use template instance with default allocator
using RequestReturnHome_Response =
  dronehive_interfaces::srv::RequestReturnHome_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces

namespace dronehive_interfaces
{

namespace srv
{

struct RequestReturnHome
{
  using Request = dronehive_interfaces::srv::RequestReturnHome_Request;
  using Response = dronehive_interfaces::srv::RequestReturnHome_Response;
};

}  // namespace srv

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__REQUEST_RETURN_HOME__STRUCT_HPP_
