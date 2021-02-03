#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{

    //Calculate t using equation
    // t = -n * (e-p0)/(n*d)

    //temp_n = normal of plane  = this->normal
    //p0 = point of intersection = this -> point
    //e = ray origin = ray.origin
    //d = ray direction = ray.direction

    Eigen::Vector3d temp_n = this->normal;
    Eigen::Vector3d p0 = this->point;
    Eigen::Vector3d e = ray.origin;
    Eigen::Vector3d d = ray.direction;

    //check if t greater than t min

    if(temp_n.dot(d) == 0){
      return false;
    }

    double temp_t = -1* (temp_n.dot(e-p0)/(temp_n.dot(d)));

    if(temp_t >= min_t){ //intersection found
      t = temp_t;
      n = this->normal.normalized();
      return true;
    }

  return false; //base case -- no intersection found

}