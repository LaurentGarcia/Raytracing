#include "Lambertian.h"

Lambertian::Lambertian(const glm::vec3& a)
{
    this->albedo = a;
};

bool Lambertian::scatter(Ray& r_in, const hit_record& rec, glm::vec3& attenuation, Ray& scattered) const
{
    glm::vec3 target = rec.p + rec.normal + random_in_unit_sphere();
    //scattered = Ray(rec.p, target - rec.p);
    //attenuation = albedo;
    return true;
};