# include our custom formatting commands
include(cmake/clang-cxx-dev-tools.cmake)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

project(RadixSort)

include_directories()

add_executable(RadixSort test.cpp)
