#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>
#include <algorithm>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{

  Ray curr_ray {ray.origin + t*ray.direction };

  double t_max;
  int curr_hit_id;
  double curr_t;
  Eigen::Vector3d curr_n;

  //Ambient light
  Eigen::Vector3d  rgb = objects[hit_id]->material->ka * 0.1;

  //iterate through lights and determing if object gets light from source
  for(int i =0; i< lights.size(); i++){
    lights[i]->direction(curr_ray.origin, curr_ray.direction, t_max);
    if(!first_hit(curr_ray, 1e-6, objects, curr_hit_id, curr_t, curr_n) || curr_t >= t_max){

        //Specular Light
        Eigen::Vector3d h = (curr_ray.direction - ray.direction).normalized();
        Eigen::Vector3d specular_light = objects[hit_id]->material->ks * (pow(std::max(0.0, n.dot(h)), objects[hit_id]->material->phong_exponent));
        rgb += (specular_light.array() * lights[i]->I.array()).matrix();

        //Lambertian Light
        Eigen::Vector3d lambertian_light = objects[hit_id]->material->kd * std::max(0.0, n.dot(curr_ray.direction));
        rgb += (lambertian_light.array() * lights[i]->I.array()).matrix();
      }
 
  }

  return rgb.cwiseMin(1.0);

}
