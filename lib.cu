#include "lib.hpp"

#include "cpp_cuda_project/geometry.hpp"
#include "cpp_only_project/parse_input.hpp"

namespace serac {

  using axom::cpp_only_project::parse_vec3;
  using axom::cpp_only_project::parse_float;
  
  using axom::cpp_cuda_project::sphere;
  using axom::cpp_cuda_project::separation;
  using axom::cpp_cuda_project::intersecting;
  
  __global__ void kernel(sphere a, sphere b) {
    printf("inside serac's cuda kernel...\n");
    printf("%f\n", separation(a, b));
    printf("%d\n", intersecting(a, b));
  }

  void do_some_calculation_on_GPU() {
    sphere a{parse_vec3("0.0 0.0 0.0"), parse_float("1.0")};
    sphere b{{3.0f, 0.0f, 0.0f}, 1.0f};

    kernel<<<1,1>>>(a, b);
    cudaDeviceSynchronize();
  }

}