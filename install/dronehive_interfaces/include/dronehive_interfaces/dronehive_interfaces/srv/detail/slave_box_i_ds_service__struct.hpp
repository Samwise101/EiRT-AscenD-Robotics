// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dronehive_interfaces:srv/SlaveBoxIDsService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_I_DS_SERVICE__STRUCT_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_I_DS_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__SlaveBoxIDsService_Request __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__SlaveBoxIDsService_Request __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SlaveBoxIDsService_Request_
{
  using Type = SlaveBoxIDsService_Request_<ContainerAllocator>;

  explicit SlaveBoxIDsService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit SlaveBoxIDsService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__SlaveBoxIDsService_Request
    std::shared_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__SlaveBoxIDsService_Request
    std::shared_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SlaveBoxIDsService_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const SlaveBoxIDsService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SlaveBoxIDsService_Request_

// alias to use template instance with default allocator
using SlaveBoxIDsService_Request =
  dronehive_interfaces::srv::SlaveBoxIDsService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces


#ifndef _WIN32
# define DEPRECATED__dronehive_interfaces__srv__SlaveBoxIDsService_Response __attribute__((deprecated))
#else
# define DEPRECATED__dronehive_interfaces__srv__SlaveBoxIDsService_Response __declspec(deprecated)
#endif

namespace dronehive_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SlaveBoxIDsService_Response_
{
  using Type = SlaveBoxIDsService_Response_<ContainerAllocator>;

  explicit SlaveBoxIDsService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->size = 0l;
    }
  }

  explicit SlaveBoxIDsService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->size = 0l;
    }
  }

  // field types and members
  using _box_ids_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _box_ids_type box_ids;
  using _size_type =
    int32_t;
  _size_type size;

  // setters for named parameter idiom
  Type & set__box_ids(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->box_ids = _arg;
    return *this;
  }
  Type & set__size(
    const int32_t & _arg)
  {
    this->size = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dronehive_interfaces__srv__SlaveBoxIDsService_Response
    std::shared_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dronehive_interfaces__srv__SlaveBoxIDsService_Response
    std::shared_ptr<dronehive_interfaces::srv::SlaveBoxIDsService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SlaveBoxIDsService_Response_ & other) const
  {
    if (this->box_ids != other.box_ids) {
      return false;
    }
    if (this->size != other.size) {
      return false;
    }
    return true;
  }
  bool operator!=(const SlaveBoxIDsService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SlaveBoxIDsService_Response_

// alias to use template instance with default allocator
using SlaveBoxIDsService_Response =
  dronehive_interfaces::srv::SlaveBoxIDsService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dronehive_interfaces

namespace dronehive_interfaces
{

namespace srv
{

struct SlaveBoxIDsService
{
  using Request = dronehive_interfaces::srv::SlaveBoxIDsService_Request;
  using Response = dronehive_interfaces::srv::SlaveBoxIDsService_Response;
};

}  // namespace srv

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_I_DS_SERVICE__STRUCT_HPP_
