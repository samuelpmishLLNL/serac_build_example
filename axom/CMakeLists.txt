cmake_minimum_required(VERSION 3.18)
project(axom_project LANGUAGES CXX CUDA)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CUDA_STANDARD 14)

set(AXOM_PROJECT_DIR ${PROJECT_SOURCE_DIR})

add_subdirectory(core_project) 
add_subdirectory(cpp_only_project) 
add_subdirectory(cpp_cuda_project) 

add_library(axom INTERFACE)
target_link_libraries(axom INTERFACE core cpp_only cpp_cuda)

add_executable(axom_cpp_test test.cpp)
target_link_libraries(axom_cpp_test PUBLIC axom)

add_executable(axom_cuda_test test.cu)
target_link_libraries(axom_cuda_test PUBLIC axom)
set_target_properties(axom_cuda_test PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
