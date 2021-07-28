# include our custom formatting commands
include(cmake/clang-cxx-dev-tools.cmake)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

project(binary_heap)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(binary_heap binary_heap.cpp testing.cpp heap.cpp)
