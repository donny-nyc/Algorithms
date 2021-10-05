# This might be relevant https://stackoverflow.com/a/31969632/15016489
# target_include_directory _only_ affects the named target scope
add_executable (base_test base_test.cpp)
target_include_directories(base_test BEFORE PUBLIC "../../include")

add_test (BaseTest base_test)

