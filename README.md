# serac_build_example
a dummy project showing how to use cmake to build/consume mixed C++/CUDA libraries with separable compilation

# Overview

The parent project has a couple of source files that depend on "axom", which has the following nested-project structure:

```
axom
├── CMakeLists.txt
├── core_project
│   ├── CMakeLists.txt
│   ├── core.hpp
│   ├── test.cpp
│   └── vec3.hpp
├── cpp_cuda_project
│   ├── CMakeLists.txt
│   ├── geometry.cu
│   ├── geometry.hpp
│   ├── test.cpp
│   └── test.cu
├── cpp_only_project
│   ├── CMakeLists.txt
│   ├── parse_input.cpp
│   ├── parse_input.hpp
│   └── test.cpp
├── test.cpp
└── test.cu
```

At the high level, axom defines an `INTERFACE` cmake target named `axom` that links to the subprojects inside of it.
