cmake_minimum_required(VERSION 3.18)
project(serac_project LANGUAGES CXX CUDA)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(axom)

add_library(serac_lib STATIC lib.cpp lib.cu lib.hpp)
target_link_libraries(serac_lib PUBLIC axom)
set_target_properties(serac_lib PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(serac main.cpp)
target_link_libraries(serac PUBLIC serac_lib)

add_executable(serac_cuda main.cu)
target_link_libraries(serac_cuda PUBLIC axom)
set_target_properties(serac_cuda PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
