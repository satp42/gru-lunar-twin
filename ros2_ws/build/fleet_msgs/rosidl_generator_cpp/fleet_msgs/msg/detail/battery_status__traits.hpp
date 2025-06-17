// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fleet_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef FLEET_MSGS__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_
#define FLEET_MSGS__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "fleet_msgs/msg/detail/battery_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace fleet_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BatteryStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: unit_id
  {
    out << "unit_id: ";
    rosidl_generator_traits::value_to_yaml(msg.unit_id, out);
    out << ", ";
  }

  // member: soc_percentage
  {
    out << "soc_percentage: ";
    rosidl_generator_traits::value_to_yaml(msg.soc_percentage, out);
    out << ", ";
  }

  // member: voltage_v
  {
    out << "voltage_v: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_v, out);
    out << ", ";
  }

  // member: charging
  {
    out << "charging: ";
    rosidl_generator_traits::value_to_yaml(msg.charging, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BatteryStatus & msg,
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

  // member: unit_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "unit_id: ";
    rosidl_generator_traits::value_to_yaml(msg.unit_id, out);
    out << "\n";
  }

  // member: soc_percentage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "soc_percentage: ";
    rosidl_generator_traits::value_to_yaml(msg.soc_percentage, out);
    out << "\n";
  }

  // member: voltage_v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage_v: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_v, out);
    out << "\n";
  }

  // member: charging
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charging: ";
    rosidl_generator_traits::value_to_yaml(msg.charging, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BatteryStatus & msg, bool use_flow_style = false)
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
  const fleet_msgs::msg::BatteryStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  fleet_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use fleet_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const fleet_msgs::msg::BatteryStatus & msg)
{
  return fleet_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<fleet_msgs::msg::BatteryStatus>()
{
  return "fleet_msgs::msg::BatteryStatus";
}

template<>
inline const char * name<fleet_msgs::msg::BatteryStatus>()
{
  return "fleet_msgs/msg/BatteryStatus";
}

template<>
struct has_fixed_size<fleet_msgs::msg::BatteryStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<fleet_msgs::msg::BatteryStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<fleet_msgs::msg::BatteryStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLEET_MSGS__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_
