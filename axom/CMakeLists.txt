cmake_minimum_required(VERSION 3.18)
project(axom_project LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CUDA_STANDARD 14)

set(sources "core.hpp" "core.cpp") 

add_library(axom STATIC ${sources})
target_include_directories(axom PUBLIC ${PROJECT_SOURCE_DIR})

if(ENABLE_CUDA) 
  enable_language(CUDA)
  target_sources(axom PRIVATE "core.cu" "transform.cu")
  set_property(TARGET axom PROPERTY CUDA_ARCHITECTURES 61)
  set_property(TARGET axom PROPERTY CUDA_SEPARABLE_COMPILATION ON)
  #set_property(TARGET axom PROPERTY CUDA_RESOLVE_DEVICE_SYMBOLS ON)

  add_executable(device_main main.cu)
  target_link_libraries(device_main PUBLIC axom)
  #set_property(TARGET device_main PROPERTY CUDA_SEPARABLE_COMPILATION ON)
endif()

add_executable(host_main main.cpp)

target_link_libraries(host_main PUBLIC axom)
