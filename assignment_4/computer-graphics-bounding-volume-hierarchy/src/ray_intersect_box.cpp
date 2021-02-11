#include "ray_intersect_box.h"
#include <iostream>

bool ray_intersect_box(
  const Ray & ray,
  const BoundingBox& box,
  const double min_t,
  const double max_t)
{
  std::vector<double> minValues(3);
  std::vector<double> maxValues(3);

  minValues[0] = -std::numeric_limits<double>::infinity(); //txmin
  minValues[1] = -std::numeric_limits<double>::infinity(); //tymin
  minValues[2] = -std::numeric_limits<double>::infinity(); //tzmin

  maxValues[0] = std::numeric_limits<double>::infinity(); //txmax
  maxValues[1] = std::numeric_limits<double>::infinity(); //tymax
  maxValues[2] = std::numeric_limits<double>::infinity(); //tzmax

  //calculate txmin, txmax
  
  for(int i = 0; i<3; i++){
    //calculate tmax and min for x, y, z

    //3 cases, xd ==0, xd >=0, xd <0
    if(ray.direction[i] == 0){
      //return true if xmin<xe<xmax
      //else
      if(ray.origin[i] < box.min_corner[i] || ray.origin[i] > box.max_corner[i]){
        return false;
      }
      //if true, set interval to -inf to inf
      //already initialized, do nothing
    }
    else if (ray.direction[i] >= 0){
      minValues[i] = (box.min_corner[i] - ray.origin[i])/ray.direction[i];
      maxValues[i] = (box.max_corner[i] - ray.origin[i])/ray.direction[i];
    }else {
      minValues[i] = (box.max_corner[i] - ray.origin[i])/ray.direction[i];
      maxValues[i] = (box.min_corner[i] - ray.origin[i])/ray.direction[i];
    }

  }

  double start = *std::max_element(minValues.begin(), minValues.end());
  double end = *std::min_element(maxValues.begin(), maxValues.begin());
  //check intervals
  if(start <  max_t && end> min_t && start < end){
    return true;
  }

  return false; //default case


}
