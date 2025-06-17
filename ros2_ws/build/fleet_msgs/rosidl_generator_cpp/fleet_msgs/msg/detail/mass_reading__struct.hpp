// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fleet_msgs:msg/MassReading.idl
// generated code does not contain a copyright notice

#ifndef FLEET_MSGS__MSG__DETAIL__MASS_READING__STRUCT_HPP_
#define FLEET_MSGS__MSG__DETAIL__MASS_READING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fleet_msgs__msg__MassReading __attribute__((deprecated))
#else
# define DEPRECATED__fleet_msgs__msg__MassReading __declspec(deprecated)
#endif

namespace fleet_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MassReading_
{
  using Type = MassReading_<ContainerAllocator>;

  explicit MassReading_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mass_kg = 0.0;
      this->unit_id = "";
    }
  }

  explicit MassReading_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    unit_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mass_kg = 0.0;
      this->unit_id = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _mass_kg_type =
    double;
  _mass_kg_type mass_kg;
  using _unit_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _unit_id_type unit_id;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__mass_kg(
    const double & _arg)
  {
    this->mass_kg = _arg;
    return *this;
  }
  Type & set__unit_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->unit_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fleet_msgs::msg::MassReading_<ContainerAllocator> *;
  using ConstRawPtr =
    const fleet_msgs::msg::MassReading_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fleet_msgs::msg::MassReading_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fleet_msgs::msg::MassReading_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fleet_msgs::msg::MassReading_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fleet_msgs::msg::MassReading_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fleet_msgs::msg::MassReading_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fleet_msgs::msg::MassReading_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fleet_msgs::msg::MassReading_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fleet_msgs::msg::MassReading_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fleet_msgs__msg__MassReading
    std::shared_ptr<fleet_msgs::msg::MassReading_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fleet_msgs__msg__MassReading
    std::shared_ptr<fleet_msgs::msg::MassReading_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MassReading_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->mass_kg != other.mass_kg) {
      return false;
    }
    if (this->unit_id != other.unit_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const MassReading_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MassReading_

// alias to use template instance with default allocator
using MassReading =
  fleet_msgs::msg::MassReading_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fleet_msgs

#endif  // FLEET_MSGS__MSG__DETAIL__MASS_READING__STRUCT_HPP_
