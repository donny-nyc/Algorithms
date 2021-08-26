# include our custom formatting commands
include(cmake/clang-cxx-dev-tools.cmake)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

project(CountingSort)

include_directories(src)

add_executable(CountingSort src/CountingSort.tpp src/test.cpp)
