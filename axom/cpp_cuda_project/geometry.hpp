#include "core_project/vec3.hpp"

namespace axom::cpp_cuda_project {

  struct sphere {
    axom::core_project::vec3 center;
    float radius;
  };

  // functions defined in other source files require enabling separable compilation
  AXOM_HOST_DEVICE float separation(sphere a, sphere b);

  // functions defined in headers don't require enabling separable compilation
  AXOM_HOST_DEVICE inline bool intersecting(sphere a, sphere b) {
    return separation(a, b) < 0;
  }

}