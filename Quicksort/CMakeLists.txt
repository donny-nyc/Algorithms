# include our custom formatting commands
include(cmake/clang-cxx-dev-tools.cmake)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

project(Quicksort)

include_directories(./src)

add_executable(tests src/tests.cpp src/quicksort.cpp)
