# include our custom formatting commands
cmake_minimum_required(VERSION 3.1)

project(Sorting)

enable_testing()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-O0)

set(SOURCES main.cpp containers/vector.cpp containers/container.hpp
	strategies/sort_strategy.hpp strategies/insert_sort.cpp)

add_subdirectory( tests )

add_executable(Sorting ${SOURCES})

target_include_directories(Sorting BEFORE PUBLIC ./include)


