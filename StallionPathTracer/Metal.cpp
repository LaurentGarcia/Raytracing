#include "Metal.h"

glm::vec3 reflect(const glm::vec3& v, const glm::vec3& n)
{
    return v - 2*glm::dot(v,n)*n;
}

Metal::Metal(const glm::vec3& a)
{
    this->albedo = a;
};


bool Metal::scatter(Ray& r_in, const hit_record& rec, glm::vec3& attenuation, Ray& scattered) const
{
    glm::vec3 reflected = reflect(glm::normalize(r_in.Direction()), rec.normal);
    //scattered = Ray(rec.p, reflected);
   // attenuation = albedo;
    return (glm::dot(scattered.Direction(), rec.normal) > 0);
};