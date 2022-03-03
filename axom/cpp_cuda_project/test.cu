#include <cstdio>

#include "cpp_cuda_project/geometry.hpp"

using axom::cpp_cuda_project::sphere;
using axom::cpp_cuda_project::separation;
using axom::cpp_cuda_project::intersecting;

__global__ void kernel(sphere a, sphere b) {
  printf("inside cuda kernel...\n");
  printf("%f\n", separation(a, b));
  printf("%d\n", intersecting(a, b));
}

int main() {
  sphere a{{0.0f, 0.0f, 0.0f}, 1.0f};
  sphere b{{3.0f, 0.0f, 0.0f}, 1.0f};

  kernel<<<1,1>>>(a, b);
  cudaDeviceSynchronize();
}