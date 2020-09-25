#ifndef HITABLEH
#define HITABLEH

#include "Ray.h"

class Material;

struct hit_record
{
    float t;
    glm::vec3 p;
    glm::vec3 normal;
    Material *mtr_ptr;
};

static glm::vec3 random_in_unit_sphere()
{
	glm::vec3 p;

	do {
		p = float(2.0) * glm::vec3(drand48(),drand48(),drand48()) - glm::vec3(1,1,1);
	}while (length(p)>= 1.0);
	return p;
};

class Hitable
{
    public:
        virtual bool hit(Ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

#endif