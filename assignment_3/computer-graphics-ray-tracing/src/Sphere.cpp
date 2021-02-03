#include "Sphere.h"
#include "Ray.h"
bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{

  //d = ray direction
  Eigen::Vector3d  d = ray.direction;

  //e = origin
  Eigen::Vector3d e = ray.origin;

  //c = sphere center
  Eigen::Vector3d c = this->center;

  //Calculate Discriminant to see if an intersection is found --> B^2 -4AC
  //A = (d*d)
  //B = 2*d*(e-c)
  //C = (e-c) * (e-c) -R^2

  double A = d.dot(d);
  double B = 2.0*d.dot(e-c);
  double C = (e-c).dot(e-c) - (this->radius*this->radius);

  double descrim = B*B - (4*A*C);

  if(descrim<=0){
    return false;
  }

  //calculat t value if true

  //first solution
  double solution_1 = (-1*B - sqrt(descrim))/(2.0*A);

  if(solution_1 >= min_t){
    //calculate n and return true
    //n = 2*(p-c)
    n = (e + solution_1*d-c).normalized();
    t = solution_1;
    return true;
  }

  //second solution if first fails
  double solution_2 = (-1*B + sqrt(descrim))/(2.0*A);

  if(solution_2 >= min_t){
    //calculate n and return true
    //n = 2*(p-c)
    n = (e + solution_2*d-c).normalized();
    t = solution_2;
    return true;
  }


 return false; //base case

}