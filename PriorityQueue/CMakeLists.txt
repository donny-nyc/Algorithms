# include our custom formatting commands
include(cmake/clang-cxx-dev-tools.cmake)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

project(PriorityQueue)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(PriorityQueue src/main.cpp src/Heap.cpp src/MaxHeap.cpp
    src/Heap.hpp)
