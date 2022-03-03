cmake_minimum_required(VERSION 3.18)
project(core_project LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CUDA_STANDARD 14)

set(sources "parse_input.hpp" "parse_input.cpp") 

add_library(cpp_only STATIC ${sources})
target_include_directories(cpp_only PUBLIC ${AXOM_PROJECT_DIR})
target_link_libraries(cpp_only PUBLIC core)

add_executable(cpp_only_test "test.cpp")
target_link_libraries(cpp_only_test PUBLIC cpp_only)
