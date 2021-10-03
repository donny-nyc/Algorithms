# include our custom formatting commands
cmake_minimum_required(VERSION 3.1)

project(Sorting)

# enable_testing()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-O0)

add_subdirectory( src )

# set(SOURCES src/containers/container.cpp sort/sort.cpp src/main.cpp)

# add_subdirectory( tests )

target_include_directories(Sorting BEFORE PUBLIC ./include)

