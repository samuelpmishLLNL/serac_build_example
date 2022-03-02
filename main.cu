#include "core.hpp"

__global__ void some_kernel_that_uses_axom(double * ptr) {
  axom::transform(ptr[threadIdx.x]);
}

int main() {
  axom::foo_device();

  double * ptr;
  cudaMalloc(&ptr, sizeof(double) * 64);
  some_kernel_that_uses_axom<<<1,64>>>(ptr);
  cudaDeviceSynchronize();
}
