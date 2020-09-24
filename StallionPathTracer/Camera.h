#pragma once

#include "Ray.h"

class Camera
{
    public:
        Camera();
        Ray getRay(float u, float v);

    private:
        glm::vec3 origin;
        glm::vec3 lower_left_corner;
        glm::vec3 horizontal;
        glm::vec3 vertical;
};