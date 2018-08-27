// StallionPathTracer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "libraries/stb_image_write.h"
#include "libraries/glm/glm/glm.hpp"
#include "Ray.h"
#include <vector>

using namespace std;
using namespace glm;
 

bool Hit_Sphere(vec3& center, float radius, Ray& r)
{
	vec3 oc = r.Origin() - center;
	float a = dot(r.Direction(), r.Direction());
	float b = 2.0f * dot(oc, r.Direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a*c;
	
	return (discriminant > 0);
}

glm::vec3	colorCalculation(Ray& r)
{
	vec3 center(0.0f, 0.0f, -1.0f);
	if (Hit_Sphere(center, 0.5f, r))
		return vec3(1, 0, 0);
	vec3		unit_direction	= normalize(r.Direction());
	float		t				= 0.5*(unit_direction.y + 1);

	return  vec3(1.0, 1.0, 1.0) * (1.0f - t) + t * vec3(0.5, 0.7, 1.0);
};

int main()
{
	int nx = 1920;
	int ny = 1080;
	unsigned char* renderOut = new unsigned char[(int)nx * (int)ny * 3];
	vec3 lower_left_corner(-2.0f, -1.0f, -1.0f);
	vec3 horizontal(4.0f, 0.0f, 0.0f);
	vec3 vertical(0.0f, 2.0f, 0.0f);
	vec3 origin(0.0f, 0.0f, 0.0f);


	int k = 0;
	for (int j=ny - 1; j>=0; j--) 
	{
		for (int i = 0; i < nx; i++)
		{
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			Ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			vec3 color = colorCalculation(r);
			int ir = int(255.99*color.x);
			int ig = int(255.99*color.y);
			int ib = int(255.99*color.z);

			renderOut[k]   = static_cast<unsigned char>(ir);
			renderOut[k+1] = static_cast<unsigned char>(ig);
			renderOut[k+2] = static_cast<unsigned char>(ib);
			k += 3;
		
		}
	}
	int err = stbi_write_bmp("test.bmp", nx, ny, 3, renderOut);
	printf("Image Created: %d", err);

    return 0;
}
