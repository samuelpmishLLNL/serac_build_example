cmake_minimum_required(VERSION 3.18)
project(axom_project LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CUDA_STANDARD 14)

set(sources "core.hpp" "core.cpp") 

if(ENABLE_CUDA) 
  enable_language(CUDA)
  set(sources ${sources} "core.cu" "core.cuh")
  add_executable(device_main main.cu)
  target_link_libraries(device_main PUBLIC axom)
endif()

add_library(axom ${sources})

target_include_directories(axom PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(host_main main.cpp)

target_link_libraries(host_main PUBLIC axom)
