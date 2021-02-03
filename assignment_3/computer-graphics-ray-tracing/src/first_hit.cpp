#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{

  bool hitFound = false;
  double current_hit_t;
  Eigen::Vector3d current_n;

  //Iterate through objects and look for hit
  for(int i =0; i<objects.size(); i++){
    if(objects[i]->intersect(ray, min_t, current_hit_t, current_n)){ //A hit was found
        if(!hitFound || current_hit_t < t){
          hitFound = true;
          t = current_hit_t;
          n = current_n;
          hit_id = i;
        }

    }
  }

  return hitFound;
}