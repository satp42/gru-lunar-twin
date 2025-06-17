cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(lunar_gravity_plugin)

# Find Gazebo packages (Fortress uses version 6)
find_package(gz-cmake2 REQUIRED)
find_package(gz-sim6 REQUIRED)
find_package(gz-transport11 REQUIRED)
find_package(gz-msgs8 REQUIRED)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build the gravity plugin as a shared library
add_library(LunarGravityPlugin SHARED gravity_plugin.cc)

# Set target properties
set_property(TARGET LunarGravityPlugin PROPERTY CXX_STANDARD 17)

# Link with Gazebo libraries
target_link_libraries(LunarGravityPlugin
  gz-sim6::gz-sim6
  gz-transport11::gz-transport11
  gz-msgs8::gz-msgs8
) 