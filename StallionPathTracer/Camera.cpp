#include "Camera.h"

Camera::Camera()
{
    this->lower_left_corner = glm::vec3(-2.0, -1.0, -1.0);
    this->horizontal = glm::vec3(4.0, 0.0, 0.0);
    this->vertical = glm::vec3(0.0, 2.0, 0.0);
    this->origin = glm::vec3(0.0, 0.0, 0.0);
};

Ray Camera::getRay(float u, float v)
{
    return Ray(this->origin, this->lower_left_corner + u*this->horizontal + v*this->vertical - this->origin);
};