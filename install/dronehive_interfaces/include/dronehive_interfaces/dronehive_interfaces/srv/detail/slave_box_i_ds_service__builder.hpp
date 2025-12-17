// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dronehive_interfaces:srv/SlaveBoxIDsService.idl
// generated code does not contain a copyright notice

#ifndef DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_I_DS_SERVICE__BUILDER_HPP_
#define DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_I_DS_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dronehive_interfaces/srv/detail/slave_box_i_ds_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dronehive_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::SlaveBoxIDsService_Request>()
{
  return ::dronehive_interfaces::srv::SlaveBoxIDsService_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace dronehive_interfaces


namespace dronehive_interfaces
{

namespace srv
{

namespace builder
{

class Init_SlaveBoxIDsService_Response_size
{
public:
  explicit Init_SlaveBoxIDsService_Response_size(::dronehive_interfaces::srv::SlaveBoxIDsService_Response & msg)
  : msg_(msg)
  {}
  ::dronehive_interfaces::srv::SlaveBoxIDsService_Response size(::dronehive_interfaces::srv::SlaveBoxIDsService_Response::_size_type arg)
  {
    msg_.size = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dronehive_interfaces::srv::SlaveBoxIDsService_Response msg_;
};

class Init_SlaveBoxIDsService_Response_box_ids
{
public:
  Init_SlaveBoxIDsService_Response_box_ids()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SlaveBoxIDsService_Response_size box_ids(::dronehive_interfaces::srv::SlaveBoxIDsService_Response::_box_ids_type arg)
  {
    msg_.box_ids = std::move(arg);
    return Init_SlaveBoxIDsService_Response_size(msg_);
  }

private:
  ::dronehive_interfaces::srv::SlaveBoxIDsService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dronehive_interfaces::srv::SlaveBoxIDsService_Response>()
{
  return dronehive_interfaces::srv::builder::Init_SlaveBoxIDsService_Response_box_ids();
}

}  // namespace dronehive_interfaces

#endif  // DRONEHIVE_INTERFACES__SRV__DETAIL__SLAVE_BOX_I_DS_SERVICE__BUILDER_HPP_
