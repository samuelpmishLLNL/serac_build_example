#pragma once

#include "core_project/core.hpp"

#include <cmath>

namespace axom::core_project {

    struct vec3 {
        float x, y, z;
    };

    AXOM_HOST_DEVICE inline vec3 operator+(vec3 a, vec3 b) {
        return vec3{a.x + b.x, a.y + b.y, a.z + b.z};
    }

    AXOM_HOST_DEVICE inline vec3 operator-(vec3 a, vec3 b) {
        return vec3{a.x + b.x, a.y + b.y, a.z + b.z};
    }

    AXOM_HOST_DEVICE inline vec3 operator*(vec3 a, float b) {
        return vec3{a.x * b, a.y * b, a.z * b};
    }

    AXOM_HOST_DEVICE inline double dot(vec3 a, vec3 b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    AXOM_HOST_DEVICE inline double norm(vec3 a) {
        return sqrt(dot(a, a));
    }

}