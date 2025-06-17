// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fleet_msgs:msg/MassReading.idl
// generated code does not contain a copyright notice

#ifndef FLEET_MSGS__MSG__DETAIL__MASS_READING__BUILDER_HPP_
#define FLEET_MSGS__MSG__DETAIL__MASS_READING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fleet_msgs/msg/detail/mass_reading__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fleet_msgs
{

namespace msg
{

namespace builder
{

class Init_MassReading_unit_id
{
public:
  explicit Init_MassReading_unit_id(::fleet_msgs::msg::MassReading & msg)
  : msg_(msg)
  {}
  ::fleet_msgs::msg::MassReading unit_id(::fleet_msgs::msg::MassReading::_unit_id_type arg)
  {
    msg_.unit_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fleet_msgs::msg::MassReading msg_;
};

class Init_MassReading_mass_kg
{
public:
  explicit Init_MassReading_mass_kg(::fleet_msgs::msg::MassReading & msg)
  : msg_(msg)
  {}
  Init_MassReading_unit_id mass_kg(::fleet_msgs::msg::MassReading::_mass_kg_type arg)
  {
    msg_.mass_kg = std::move(arg);
    return Init_MassReading_unit_id(msg_);
  }

private:
  ::fleet_msgs::msg::MassReading msg_;
};

class Init_MassReading_header
{
public:
  Init_MassReading_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MassReading_mass_kg header(::fleet_msgs::msg::MassReading::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MassReading_mass_kg(msg_);
  }

private:
  ::fleet_msgs::msg::MassReading msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fleet_msgs::msg::MassReading>()
{
  return fleet_msgs::msg::builder::Init_MassReading_header();
}

}  // namespace fleet_msgs

#endif  // FLEET_MSGS__MSG__DETAIL__MASS_READING__BUILDER_HPP_
