// StallionPathTracer.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "libraries/stb_image_write.h"


#include "libraries/stb_image.h"
#include "libraries/glm/glm/glm.hpp"
#include "Ray.h"
#include "Sphere.h"
#include "HitableList.h"
#include "Camera.h"
#include <vector>

using namespace std;
using namespace glm;
 

vec3 random_in_unit_sphere()
{
	vec3 p;

	do {
		p = float(2.0) * vec3(drand48(),drand48(),drand48()) - vec3(1,1,1);
	}while (length(p)>= 1.0);
	return p;
};


glm::vec3 colorCalculation(Ray& r, Hitable *world)
{
	hit_record rec;

	if(world->hit(r, 0.0, MAXFLOAT, rec))
	{
		vec3 target = rec.p + rec.normal + random_in_unit_sphere();
		Ray bounce = Ray(rec.p, target-rec.p);
		return float(0.5) * colorCalculation( bounce, world);
	}
	else
	{
			vec3 unit_direction = normalize(r.Direction());
			float t = 0.5*(unit_direction.y + 1.0);
			return float(1.0-t) * vec3(1, 1, 1) + t * vec3(0.5,0.7,1.0);
	}

}

int main()
{
	int nx = 512;
	int ny = 256;
	int ns = 100;
	unsigned char* renderOut = new unsigned char[(int)nx * (int)ny * 3];
	vec3 lower_left_corner(-2.0f, -1.0f, -1.0f);
	vec3 horizontal(4.0f, 0.0f, 0.0f);
	vec3 vertical(0.0f, 2.0f, 0.0f);
	vec3 origin(0.0f, 0.0f, 0.0f);

	Hitable *list[2];
	list[0] = new Sphere(glm::vec3(0,0,-1), 0.5);
	list[1] = new Sphere(glm::vec3(0,-100.5,-1), 100);
	
	Hitable *world = new HitableList (list, 2);
	Camera cam;

	int k = 0;
	for (int j=ny - 1; j>=0; j--) 
	{
		for (int i = 0; i < nx; i++)
		{
			glm::vec3 col = glm::vec3(0,0,0);
			for (int s=0; s<ns; s++)
			{
				float u = float( i + drand48() ) / float(nx);
				float v = float( j + drand48() ) / float(ny);
				Ray r = cam.getRay(u,v);
				glm::vec3 p = r.PointAtParameter(2.0);
				col += colorCalculation(r, world);
			}
			col /= float(ns);
			int ir = int(255.99*col.x);
			int ig = int(255.99*col.y);
			int ib = int(255.99*col.z);       

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





