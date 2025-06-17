cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(lunar_gravity_plugin)

# Find Ignition packages
find_package(ignition-cmake2 REQUIRED)
find_package(ignition-gazebo6 REQUIRED)
find_package(ignition-transport11 REQUIRED)
find_package(ignition-msgs8 REQUIRED)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build the gravity plugin as a shared library
add_library(LunarGravityPlugin SHARED gravity_plugin.cc)

# Set target properties
set_property(TARGET LunarGravityPlugin PROPERTY CXX_STANDARD 17)

# Link with Ignition libraries
target_link_libraries(LunarGravityPlugin
  ignition-gazebo6::ignition-gazebo6
  ignition-transport11::ignition-transport11
  ignition-msgs8::ignition-msgs8
) 