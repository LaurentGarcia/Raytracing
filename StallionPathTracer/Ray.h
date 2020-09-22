#pragma once

#include "libraries/glm/glm/glm.hpp"

class Ray
{
public:
	Ray();
	Ray(const glm::vec3& a, const glm::vec3& b) { A = a; B = b; }
	~Ray();

	glm::vec3 Origin();
	glm::vec3 Direction();
	glm::vec3 PointAtParameter(float t);

private:
	glm::vec3 A;
	glm::vec3 B;
};

