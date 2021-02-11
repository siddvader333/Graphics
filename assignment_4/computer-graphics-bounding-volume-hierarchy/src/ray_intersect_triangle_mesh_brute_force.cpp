#include "ray_intersect_triangle_mesh_brute_force.h"
#include "ray_intersect_triangle.h"

bool ray_intersect_triangle_mesh_brute_force(
  const Ray & ray,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double min_t,
  const double max_t,
  double & hit_t,
  int & hit_f)
{

  //initialize min hit distance, and index
  double temp_hit_t = std::numeric_limits<double>::infinity();
  hit_t = std::numeric_limits<double>::infinity();
  int temp_hit_f = -1;

  //iterate through all triangles and see if hit found (using ray_intersect_trianlge)
  //if a hit was found, compare it to current smallest distance and update index and distance
  for(int i =0; i< F.rows(); i++){
    bool hit_found = ray_intersect_triangle(ray, V.row(F(i, 0)),  V.row(F(i,1)), V.row(F(i, 2)), min_t, max_t, temp_hit_t);
    if(hit_found){
      if(temp_hit_t < hit_t){
        hit_t = temp_hit_t;
        hit_f = i;
      }
    }
  }


  if(hit_t != std::numeric_limits<double>::infinity()){
    return true;
  }

  return false;
  
}