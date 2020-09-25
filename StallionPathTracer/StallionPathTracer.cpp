// StallionPathTracer.cpp : Defines the entry point for the console application.
//


//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "libraries/stb_image_write.h"


#include "libraries/stb_image.h"
#include "libraries/glm/glm/glm.hpp"
using namespace std;
using namespace glm;

#include "Ray.h"
#include "Sphere.h"
#include "HitableList.h"
#include "Camera.h"
#include "Lambertian.h"
#include "Metal.h"
#include <vector>

 

glm::vec3 colorCalculation(Ray& r, Hitable *world, int depth)
{
	hit_record rec;
 
	if(world->hit(r, 0, MAXFLOAT, rec))
	{
		Ray scattered;
		vec3 attenuation;
 		if (depth < 50 && rec.mtr_ptr->scatter(r, rec, attenuation, scattered))
		{
			return attenuation * colorCalculation(scattered, world, depth + 1);
		}
		else
		{
			return vec3(0);
		}
	}
	else
	{
		vec3 unit_direction = normalize(r.Direction());
		float t = 0.5*(unit_direction.y + 1);
		return float((1.0-t)) * vec3(1.0) + t * vec3(0.5, 0.7, 1.0);
	}

}

int main()
{
	int nx = 512;
	int ny = 256;
	int ns = 100;
	unsigned char* renderOut = new unsigned char[(int)nx * (int)ny * 3];

	Hitable *list[4];
	list[0] = new Sphere(glm::vec3(0,0,-1), 0.5, new Lambertian(vec3(0.8,0.3,0.3)));
	list[1] = new Sphere(glm::vec3(0,-100.5,-1), 100, new Lambertian(vec3(0.8,0.8,0.0)));
	list[2] = new Sphere(glm::vec3(1,0,-1), 0.5, new Metal(vec3(0.8,0.6,0.2)));
	list[3] = new Sphere(glm::vec3(-1,0,-1), 0.5, new Metal(vec3(0.8,0.8,0.8)));

	Hitable *world = new HitableList(list, 4);
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
				col += colorCalculation(r, world,0);
			}
			col /= float(ns);
			col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
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





