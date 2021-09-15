# include our custom formatting commands
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-O0)

set(SOURCES src/main.cpp include/List.hpp
	include/InsertSort.hpp include/SortStrategy.hpp)

add_executable(Sorting ${SOURCES})

target_include_directories(Sorting BEFORE PUBLIC ./include)

project(Sorting)
