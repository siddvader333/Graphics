#include "PointLight.h"

void PointLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  //Get vector using vector algebra (difference between two points returns vector)
  Eigen::Vector3d diff = this->p - q;

  //Use norm to get magnitude of vector (distance)
  max_t = diff.norm();

  //get the normalized version of vector to get the direction vector
  d = diff.normalized();

  return;

}
