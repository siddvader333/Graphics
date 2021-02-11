#include "triangle_triangle_intersection.h"
#include "ray_intersect_triangle.h"
bool triangle_triangle_intersection(
  const Eigen::RowVector3d & A0,
  const Eigen::RowVector3d & A1,
  const Eigen::RowVector3d & A2,
  const Eigen::RowVector3d & B0,
  const Eigen::RowVector3d & B1,
  const Eigen::RowVector3d & B2)
{


  //construct rays from A and check if any rays intersect with triangle B

  Ray ray_a_1 (A0, A1-A0);
  Ray ray_a_2(A0, A2-A0);
  Ray ray_a_3(A1, A2-A1);
  double t;
  if(ray_intersect_triangle(ray_a_1, B0, B1, B2, 0.0, 1.0, t) ||
      ray_intersect_triangle(ray_a_2, B0, B1, B2, 0.0, 1.0, t) ||
      ray_intersect_triangle(ray_a_3, B0, B1, B2, 0.0, 1.0, t)){
        return true;
  }



  //construct rays from B and check if any rays intersect with triangle A
  Ray ray_b_1 (B0, B1-B0);
  Ray ray_b_2(B0, B2-B0);
  Ray ray_b_3(B1, B2-B1);
  if(ray_intersect_triangle(ray_b_1, A0, A1, A2, 0.0, 1.0, t) ||
      ray_intersect_triangle(ray_b_2, A0, A1, A2, 0.0, 1.0, t) ||
      ray_intersect_triangle(ray_b_3, A0, A1, A2, 0.0, 1.0, t)){
        return true;
  }

  return false;
}
