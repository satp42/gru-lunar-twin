// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fleet_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef FLEET_MSGS__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_
#define FLEET_MSGS__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "fleet_msgs/msg/detail/battery_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace fleet_msgs
{

namespace msg
{

namespace builder
{

class Init_BatteryStatus_charging
{
public:
  explicit Init_BatteryStatus_charging(::fleet_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  ::fleet_msgs::msg::BatteryStatus charging(::fleet_msgs::msg::BatteryStatus::_charging_type arg)
  {
    msg_.charging = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fleet_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_voltage_v
{
public:
  explicit Init_BatteryStatus_voltage_v(::fleet_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_charging voltage_v(::fleet_msgs::msg::BatteryStatus::_voltage_v_type arg)
  {
    msg_.voltage_v = std::move(arg);
    return Init_BatteryStatus_charging(msg_);
  }

private:
  ::fleet_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_soc_percentage
{
public:
  explicit Init_BatteryStatus_soc_percentage(::fleet_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_voltage_v soc_percentage(::fleet_msgs::msg::BatteryStatus::_soc_percentage_type arg)
  {
    msg_.soc_percentage = std::move(arg);
    return Init_BatteryStatus_voltage_v(msg_);
  }

private:
  ::fleet_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_unit_id
{
public:
  explicit Init_BatteryStatus_unit_id(::fleet_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_soc_percentage unit_id(::fleet_msgs::msg::BatteryStatus::_unit_id_type arg)
  {
    msg_.unit_id = std::move(arg);
    return Init_BatteryStatus_soc_percentage(msg_);
  }

private:
  ::fleet_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_header
{
public:
  Init_BatteryStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BatteryStatus_unit_id header(::fleet_msgs::msg::BatteryStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BatteryStatus_unit_id(msg_);
  }

private:
  ::fleet_msgs::msg::BatteryStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fleet_msgs::msg::BatteryStatus>()
{
  return fleet_msgs::msg::builder::Init_BatteryStatus_header();
}

}  // namespace fleet_msgs

#endif  // FLEET_MSGS__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_
