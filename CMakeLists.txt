# include our custom formatting commands
cmake_minimum_required(VERSION 3.1)

project(Sorting)

enable_testing()
# enable_testing()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-O0)

add_subdirectory( src )

# set(SOURCES src/containers/container.cpp sort/sort.cpp src/main.cpp)

# add_subdirectory( tests )

# so include_directories(...) should apply to all targets in this
# CMakeList

# include_directories("./include")
# seems like an older method, requires additional work
