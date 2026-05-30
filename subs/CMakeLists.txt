set(REFLECTCPP_YAML ON)
set(REFLECTCPP_BUILD_TESTS OFF)
set(REFLECTCPP_BUILD_BENCHMARKS OFF)

add_subdirectory(yaml-cpp EXCLUDE_FROM_ALL)
add_subdirectory(reflect-cpp EXCLUDE_FROM_ALL)
add_subdirectory(redux-cpp)
