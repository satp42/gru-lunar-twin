cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project(gravity_scale_plugin)

find_package(gz-cmake3 REQUIRED)
find_package(gz-plugin2 REQUIRED COMPONENTS register)
find_package(gz-sim9 REQUIRED)

add_library(${PROJECT_NAME} SHARED gravity_scale_plugin.cpp)

target_link_libraries(${PROJECT_NAME}
  gz-plugin2::register
  gz-sim9::gz-sim9
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) 