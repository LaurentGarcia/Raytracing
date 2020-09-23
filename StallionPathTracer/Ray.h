#pragma once

#include "libraries/glm/glm/glm.hpp"

class Ray
{
public:
	Ray();
	Ray(const glm::vec3& a, const glm::vec3& b) { A = a; B = b; }
	//~Ray();

	glm::vec3 Origin(){return this->A;};
	glm::vec3 Direction(){return this->B;};
	glm::vec3 PointAtParameter(float t){return this->A + t *this-> B;};

private:
	glm::vec3 A;
	glm::vec3 B;
};

