# include our custom formatting commands
cmake_minimum_required(VERSION 3.1)

project(Sorting)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-O0)

set(SOURCES main.cpp containers/list.cpp containers/container.hpp
	strategies/sort_strategy.hpp strategies/insert_sort.cpp)

add_subdirectory( tests )

add_executable(Sorting ${SOURCES})

target_include_directories(Sorting BEFORE PUBLIC ./include)


