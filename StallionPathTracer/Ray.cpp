#include "stdafx.h"
#include "Ray.h"


Ray::Ray()
{
}

Ray::~Ray()
{
}

glm::vec3 Ray::Origin() 
{
	return this->A;
};

glm::vec3 Ray::Direction() 
{
	return this->B;
};

glm::vec3 Ray::PointAtParameter(float t) 
{
	return this->A + t *this-> B;
};
