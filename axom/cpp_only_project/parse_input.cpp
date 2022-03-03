#include "cpp_only_project/parse_input.hpp"

#include <sstream>

namespace axom::cpp_only_project {

  axom::core_project::vec3 parse_vec3(std::string str) {
    std::istringstream iss(str);
    axom::core_project::vec3 output;
    iss >> output.x;
    iss >> output.y;
    iss >> output.z;
    return output;
  }

  float parse_float(std::string str) {
    return std::stof(str);
  }

}