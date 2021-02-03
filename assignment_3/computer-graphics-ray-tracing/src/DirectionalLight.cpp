#include "DirectionalLight.h"
#include <limits>

void DirectionalLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{

  //want to return the direction towards the light instead of from the light
  d = -1 * this->d;

  max_t = std::numeric_limits<double>::infinity(); //Light is very far away (see slides)
}

