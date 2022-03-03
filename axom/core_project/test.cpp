#include <iostream>

#include "core_project/vec3.hpp"

int main() {
    axom::core_project::vec3 a{1.0, 2.0, 3.0};
    axom::core_project::vec3 b{1.0, 1.0, 1.0};
    std::cout << dot(a + (b * 2), a) << std::endl;
}