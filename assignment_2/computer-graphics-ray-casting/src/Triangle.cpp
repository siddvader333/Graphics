#include "Triangle.h"
#include "Ray.h"

#include <Eigen/Dense>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  //Construct Matrix A and vector a-e
  Eigen::Vector3d vector_jkl = std::get<0>(this->corners) - ray.origin;

  //Matrix Columns are 
  //a-b
  //a-c
  //d -- ray.direction
  Eigen::Vector3d vector_ab = std::get<0>(this->corners) - std::get<1>(this->corners);
  Eigen::Vector3d vector_ac = std::get<0>(this->corners) - std::get<2>(this->corners);
  Eigen::Vector3d vector_d = ray.direction;


  Eigen::Matrix3d A;

  A <<vector_ab, vector_ac, vector_d;

  //check if invertible by calculating determinnat
  if(A.determinant() == 0){
    return false;
  }

  Eigen::Vector3d solution = A.inverse() * (vector_jkl);

  double gamma = solution[1];
  double beta = solution[0];
  double temp_t = solution[2];

  if(temp_t >= min_t) {
    if(beta>=0 && beta <= 1-gamma){
      if(gamma >=0 && gamma <=1){
        t = temp_t;
        n = vector_ab.cross(vector_ac).normalized();
        return true;
      }
    }
  }

  return false;
  
}


