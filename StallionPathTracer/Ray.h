#pragma once

#include "libraries/glm/glm/glm.hpp"

class Ray
{
public:
	Ray();
	Ray(glm::vec3& a, const glm::vec3& b) { A = a; B = b; }
	//~Ray();

	const glm::vec3 Origin(){return this->A;};
	const glm::vec3 Direction(){return this->B;};
	const glm::vec3 PointAtParameter(float t){return this->A + t *this-> B;};

private:
	glm::vec3 A;
	glm::vec3 B;
};

