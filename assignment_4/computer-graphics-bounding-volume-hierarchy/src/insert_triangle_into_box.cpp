#include "insert_triangle_into_box.h"

void insert_triangle_into_box(
  const Eigen::RowVector3d & a,
  const Eigen::RowVector3d & b,
  const Eigen::RowVector3d & c,
  BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  //grow box min and max corners to fit min and max of all 3 triangle corners

  for(int i = 0; i< 3; i++){
    std::vector<double> minvalues;
    minvalues.push_back(B.min_corner[i]);
    minvalues.push_back(a(i));
    minvalues.push_back(b(i));
    minvalues.push_back(c(i));

    std::vector<double> maxvalues;
    maxvalues.push_back(B.max_corner[i]);
    maxvalues.push_back(a(i));
    maxvalues.push_back(b(i));
    maxvalues.push_back(c(i));


    B.max_corner[i] = *std::max_element(maxvalues.begin(), maxvalues.end());
    B.min_corner[i] = *std::min_element(minvalues.begin(), minvalues.end());
  }
}

