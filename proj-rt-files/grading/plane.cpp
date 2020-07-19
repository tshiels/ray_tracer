#include "plane.h"
#include "ray.h"
#include <cfloat>
#include <limits>

// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
Hit Plane::Intersection(const Ray& ray, int part) const
{
    //TODO;
    Hit temp;

    double t = dot(x1 - ray.endpoint, normal) / dot(normal, ray.direction);

    if (t >= small_t && dot(normal, ray.direction) != small_t)
    {
    	temp.object = this;
    	temp.dist = t;
    	temp.part = -1;
    }
    else
    {
    	temp.object = NULL;
    	temp.dist = 0;
    	temp.part = -1;
    }

    return temp;
}

vec3 Plane::Normal(const vec3& point, int part) const
{
    return normal;
}

// There is not a good answer for the bounding box of an infinite object.
// The safe thing to do is to return a box that contains everything.
Box Plane::Bounding_Box(int part) const
{
    Box b;
    b.hi.fill(std::numeric_limits<double>::max());
    b.lo=-b.hi;
    return b;
}
