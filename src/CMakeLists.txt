set(SOURCES containers/container.cpp sort/sort.cpp main.cpp)

add_executable(Sorting ${SOURCES})
target_include_directories(Sorting BEFORE PUBLIC "../include")

# we tried doing this originally, and no header files were being found
# need to include the top-level src directory so that any directories
# inside can be #include <...>
# target_include_directories(Sorting BEFORE PUBLIC containers)

add_subdirectory (test)

#enable_testing()
