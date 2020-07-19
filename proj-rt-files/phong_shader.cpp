#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
	vec3 color;
    //TODO; //determine the color
    color = world.ambient_color * world.ambient_intensity * color_ambient;

    for (unsigned int i = 0; i < world.lights.size(); ++i)
    {
    	vec3 l = world.lights.at(i)->position - intersection_point;

    	if (world.enable_shadows)
    	{
    		Ray temp;
    		temp.endpoint = intersection_point;
    		temp.direction = l.normalized();

    		Hit temp_hit = world.Closest_Intersection(temp);

    		if (temp_hit.object != NULL)
    		{
    			if (temp_hit.dist < l.magnitude())
    			{
    				continue;
    			}
    		}
    	}

    	vec3 r = (2 * dot(l, normal) * normal - l).normalized();
        vec3 light_color = world.lights.at(i)->Emitted_Light(ray.direction) / (l.magnitude_squared());
        double diffuse_intensity = std::max(0.0, dot(l.normalized(), normal));
        double specular_intensity = pow(std::max(0.0, dot(r, (ray.endpoint - intersection_point).normalized())), specular_power);
		color = light_color * (color_diffuse * diffuse_intensity + color_specular * specular_intensity) + color;
    }
    return color;
}
