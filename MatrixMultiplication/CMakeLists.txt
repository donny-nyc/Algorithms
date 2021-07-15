cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

project(hello_world)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(matrix matrix.cpp)
