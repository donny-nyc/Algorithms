# include our custom formatting commands
include(cmake/clang-cxx-dev-tools.cmake)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-O0)

project(RadixSort)

add_executable(RadixSort src/main.cpp)
