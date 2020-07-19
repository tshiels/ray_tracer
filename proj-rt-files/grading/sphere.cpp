#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    //TODO;
    Hit temp_hit = {0,0,0};
    vec3 w = ray.endpoint - center;
    double a = dot(ray.direction, ray.direction);
    double b = 2 * dot(w, ray.direction);
    double c = dot(w,w) - (radius * radius);
    double discr = b*b - 4*a*c;

    if (discr > small_t)
    {
    	temp_hit.object = this;
    	double t1 = (-1*b + sqrt(discr)) / (2.0 * a);
    	double t2 = (-1*b - sqrt(discr)) / (2.0 * a);
    	if (t1 < t2)
    	{
    		temp_hit.dist = t1;
    	}
    	else
    	{
    		temp_hit.dist = t2;
    	}
    	temp_hit.part = -1;
    }
    else
    {
    	temp_hit.object = NULL;
    	temp_hit.dist = std::numeric_limits<double>::max();
    	temp_hit.part = -1;
    }
    return temp_hit;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    //TODO; // compute the normal direction
    normal = (point - center).normalized();
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
