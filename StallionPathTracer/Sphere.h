#ifndef SPHEREH
#define SPHEREH

#include "Hitable.h"

class Sphere: public Hitable 
{
    public:
        Sphere(glm::vec3 center, float r);
        virtual bool hit (Ray& r, float t_min, float t_max, hit_record& rec) const;

    private:
        glm::vec3 center;
        float     radius;

};

#endif