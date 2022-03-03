#include <iostream>

#include "cpp_only_project/parse_input.hpp"

int main() {
    axom::core_project::vec3 a = axom::cpp_only_project::parse_vec3("1.0 2.0 3.0");
    axom::core_project::vec3 b = axom::cpp_only_project::parse_vec3("1.0 1.0 1.0");
    float scale = axom::cpp_only_project::parse_float("2.0");
    std::cout << dot(a + (b * scale), a) << std::endl;
}