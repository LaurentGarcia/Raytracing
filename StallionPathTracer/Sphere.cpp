#include "Sphere.h"

Sphere::Sphere(glm::vec3 center, float r)
{
    this->center = center;
    this->radius      = r;
}

bool Sphere::hit(Ray& r, float t_min, float t_max, hit_record& rec) const
{
	glm::vec3 oc = r.Origin() - center;
	float a = dot(r.Direction(), r.Direction());
	float b = 2.0f * dot(oc, r.Direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a*c;
	
    if (discriminant > 0)
    {
        float temp = (-b - sqrt(b*b-a*c))/a;
        if (temp < t_max && temp > t_min)
        {
            rec.t = temp;
            rec.p = r.PointAtParameter(rec.t);
            rec.normal = (rec.p - center)/radius;
            return true;
        }
        temp = (-b + sqrt(b*b-a*c))/a;
        if(temp < t_max && temp > t_min)
        {
            rec.t = temp;
            rec.p = r.PointAtParameter(rec.t);
            rec.normal = (rec.p - center)/radius;
            return true;
        }
    }
    return false;
    
}