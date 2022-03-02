#include "core.hpp"

#include <iostream>

__global__ void some_kernel(double * ptr) {
  axom::transform(ptr[threadIdx.x]);
}

namespace axom{
  
  void foo_device() {
  
    std::cout << "running calculation on device" << std::endl;
  
    double * ptr;
    cudaMalloc(&ptr, sizeof(double) * 64);
    some_kernel<<<1,64>>>(ptr);
    cudaDeviceSynchronize();
      
  }
}


