#include "lib.hpp"

#include <iostream>

#include "cpp_cuda_project/geometry.hpp"

namespace serac{

void do_some_calculation_on_CPU() {
  axom::cpp_cuda_project::sphere a{{0.0f, 0.0f, 0.0f}, 1.0f};
  axom::cpp_cuda_project::sphere b{{3.0f, 0.0f, 0.0f}, 1.0f};

  std::cout << axom::cpp_cuda_project::separation(a, b) << std::endl;
  std::cout << axom::cpp_cuda_project::intersecting(a, b) << std::endl;
}

}