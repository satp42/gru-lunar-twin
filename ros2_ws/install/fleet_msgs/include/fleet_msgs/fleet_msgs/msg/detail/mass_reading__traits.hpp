// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fleet_msgs:msg/MassReading.idl
// generated code does not contain a copyright notice

#ifndef FLEET_MSGS__MSG__DETAIL__MASS_READING__TRAITS_HPP_
#define FLEET_MSGS__MSG__DETAIL__MASS_READING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fleet_msgs/msg/detail/mass_reading__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace fleet_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MassReading & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: mass_kg
  {
    out << "mass_kg: ";
    rosidl_generator_traits::value_to_yaml(msg.mass_kg, out);
    out << ", ";
  }

  // member: unit_id
  {
    out << "unit_id: ";
    rosidl_generator_traits::value_to_yaml(msg.unit_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MassReading & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: mass_kg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mass_kg: ";
    rosidl_generator_traits::value_to_yaml(msg.mass_kg, out);
    out << "\n";
  }

  // member: unit_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "unit_id: ";
    rosidl_generator_traits::value_to_yaml(msg.unit_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MassReading & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace fleet_msgs

namespace rosidl_generator_traits
{

[[deprecated("use fleet_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const fleet_msgs::msg::MassReading & msg,
  std::ostream & out, size_t indentation = 0)
{
  fleet_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fleet_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const fleet_msgs::msg::MassReading & msg)
{
  return fleet_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fleet_msgs::msg::MassReading>()
{
  return "fleet_msgs::msg::MassReading";
}

template<>
inline const char * name<fleet_msgs::msg::MassReading>()
{
  return "fleet_msgs/msg/MassReading";
}

template<>
struct has_fixed_size<fleet_msgs::msg::MassReading>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fleet_msgs::msg::MassReading>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fleet_msgs::msg::MassReading>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLEET_MSGS__MSG__DETAIL__MASS_READING__TRAITS_HPP_
