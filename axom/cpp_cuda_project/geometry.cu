#include "cpp_cuda_project/geometry.hpp"

#include <cmath>

namespace axom::cpp_cuda_project {

  AXOM_HOST_DEVICE float separation(sphere a, sphere b) {
    auto delta = b.center - a.center;
    return axom::core_project::norm(delta) - (a.radius + b.radius); 
  };

}