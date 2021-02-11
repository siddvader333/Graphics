#include "nearest_neighbor_brute_force.h"
#include <limits>// std::numeric_limits<double>::infinity();

void nearest_neighbor_brute_force(
  const Eigen::MatrixXd & points,
  const Eigen::RowVector3d & query,
  int & I,
  double & sqrD)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  I = -1;
  sqrD = std::numeric_limits<double>::infinity();

  //iterate through all points, calculate squared distance, if less, record distance and index
  for(int i =0; i< points.rows(); i++){
    double dist = (points.row(i) - query).squaredNorm(); // calculate squared distance
    if(dist < sqrD){
      //update new min distance and point
      sqrD = dist;
      I = i;
    }
  }
}
