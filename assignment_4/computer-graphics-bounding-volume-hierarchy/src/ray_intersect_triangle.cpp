#include "ray_intersect_triangle.h"
#include <Eigen/Dense>

bool ray_intersect_triangle(
  const Ray & ray,
  const Eigen::RowVector3d & A,
  const Eigen::RowVector3d & B,
  const Eigen::RowVector3d & C,
  const double min_t,
  const double max_t,
  double & t)
{
  //Construct Matrix A and vector a-e
  Eigen::Vector3d vector_jkl = A.transpose() - ray.origin;

  //Matrix Columns are 
  //a-b
  //a-c
  //d -- ray.direction
  Eigen::Vector3d vector_ab = A.transpose() - B.transpose();
  Eigen::Vector3d vector_ac = A.transpose()-C.transpose();
  Eigen::Vector3d vector_d = ray.direction;


  Eigen::Matrix3d matrix;

  matrix <<vector_ab, vector_ac, vector_d;

  //check if invertible by calculating determinnat
  if(matrix.determinant() == 0){
    return false;
  }

  Eigen::Vector3d solution = matrix.inverse() * (vector_jkl);

  double gamma = solution[1];
  double beta = solution[0];
  double temp_t = solution[2];

  if(temp_t >= min_t && temp_t < max_t) {
    if(beta>=0 && beta <= 1-gamma){
      if(gamma >=0 && gamma <=1){
        t = temp_t;
        return true;
      }
    }
  }

  return false;
}
