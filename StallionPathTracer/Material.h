#pragma once

#include "Ray.h"
#include "Hitable.h"

class Material{

    public:
        virtual bool scatter(Ray& r_in, const hit_record& rec, glm::vec3& attenuation, Ray& scattered) const = 0;

};
