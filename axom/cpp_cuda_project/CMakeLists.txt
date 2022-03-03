cmake_minimum_required(VERSION 3.18)
project(core_project LANGUAGES CXX CUDA)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CUDA_STANDARD 14)

set(sources "geometry.hpp" "geometry.cu") 

add_library(cpp_cuda STATIC ${sources})
target_include_directories(cpp_cuda PUBLIC ${AXOM_PROJECT_DIR})
target_link_libraries(cpp_cuda PUBLIC core)
set_target_properties(cpp_cuda PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(cpp_test "test.cpp")
target_link_libraries(cpp_test PUBLIC cpp_cuda)

add_executable(cuda_test "test.cu")
target_link_libraries(cuda_test PUBLIC cpp_cuda)
set_target_properties(cuda_test PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
