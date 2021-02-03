#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  // Replace with your code here:
  //rgb = Eigen::Vector3d(0,0,0);
  int hit_id;
  double t;
  Eigen::Vector3d n;

  //Check if ray hit something
  if(first_hit(ray, min_t, objects, hit_id, t, n)){
    //We hit something

    //Calculate Color based on hit
    Eigen::Vector3d current_rgb = blinn_phong_shading(ray, hit_id, t, n, objects, lights);

    //Check if we are at max depth
    if(num_recursive_calls < 3){ // use max depth as 10 here
      //  if not, recursively call on constructed reflected ray
      //check reflective properties
      if(!objects[hit_id]->material->km.isZero(1e-4)){
        Ray reflected { ray.origin + t*ray.direction, reflect(ray.direction, n)};

        Eigen::Vector3d reflected_color;
        bool reflected_hit_found = raycolor(reflected, 1e-4, objects, lights, num_recursive_calls+1, reflected_color);

        if(reflected_hit_found){
          current_rgb += (reflected_color.array() * objects[hit_id]->material->km.array()).matrix();
        }
      }
    }

    //  if yes, return out
    rgb = current_rgb;
    return true;

  }
  //If ray didnt hit anything return false
  return false;

}
