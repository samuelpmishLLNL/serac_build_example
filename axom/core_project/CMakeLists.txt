cmake_minimum_required(VERSION 3.18)
project(cpp_only_project LANGUAGES CXX CUDA)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(sources "core.hpp" "vec3.hpp") 

add_library(core INTERFACE ${sources})
target_include_directories(core INTERFACE ${AXOM_PROJECT_DIR})

add_executable(core_test "test.cpp")
target_link_libraries(core_test PUBLIC core)
