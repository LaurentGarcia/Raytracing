#ifndef SPHEREH
#define SPHEREH

#include "Hitable.h"
#include "Material.h"

class Sphere: public Hitable 
{
    public:
        Sphere(glm::vec3 center, float r, Material* mptr);
        virtual bool hit (Ray& r, float t_min, float t_max, hit_record& rec) const;
        Material  *mtr_ptr;

    private:
        glm::vec3 center;
        float     radius;
};

#endif