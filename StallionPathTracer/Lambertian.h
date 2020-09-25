#pragma once

#include "Material.h"

class Lambertian : public Material
{
    public:
        Lambertian(const glm::vec3& a);
        virtual bool scatter(Ray& r_in, const hit_record& rec, glm::vec3& attenuation, Ray& scattered) const;
        glm::vec3 albedo;
};