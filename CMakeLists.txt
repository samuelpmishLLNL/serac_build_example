cmake_minimum_required(VERSION 3.18)
project(serac_project LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(axom)

add_executable(serac main.cpp)
target_link_libraries(serac PUBLIC axom)

if(ENABLE_CUDA) 
  enable_language(CUDA)
  add_executable(serac_cuda main.cu)
  target_link_libraries(serac_cuda PUBLIC axom)
endif()

