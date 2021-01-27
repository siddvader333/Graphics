#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{

  //We know that the ray's origin is the cameras origin
  ray.origin = camera.e;

  //Calculate u and v and -d as found in slides
  //p  = e + [ u v w ]*transpose([ u(j) v(i) -d])

  Eigen::Vector3d vector1;
  vector1[0] = (camera.width/width) *(j+0.5) - (camera.width/2);
  vector1[1] = -1*((camera.height/height) *(i+0.5) - (camera.height/2));
  vector1[2] = -1*camera.d;

  Eigen::Matrix3d matrix1;
  matrix1 << camera.u, camera.v, camera.w;

  ray.direction = matrix1*vector1;
}