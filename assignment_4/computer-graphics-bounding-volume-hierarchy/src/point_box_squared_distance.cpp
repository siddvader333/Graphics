#include "point_box_squared_distance.h"
#include <vector>
double point_box_squared_distance(
  const Eigen::RowVector3d & query,
  const BoundingBox & box)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  //Use this formula https://stackoverflow.com/questions/5254838/calculating-distance-between-a-point-and-a-rectangular-box-nearest-point

  std::vector<double> x_values;
  x_values.push_back(box.min_corner(0) - query(0));
  x_values.push_back(0);
  x_values.push_back(query(0) - box.max_corner(0));
  double x_max = *std::max_element(x_values.begin(), x_values.end());


  std::vector<double> y_values;
  y_values.push_back(box.min_corner(1) - query(1));
  y_values.push_back(0);
  y_values.push_back(query(1) - box.max_corner(1));
  double y_max = *std::max_element(y_values.begin(), y_values.end());

  std::vector<double> z_values;
  z_values.push_back(box.min_corner(2) - query(2));
  z_values.push_back(0);
  z_values.push_back(query(2) - box.max_corner(2));
  double z_max = *std::max_element(z_values.begin(), z_values.end());

  return pow(x_max, 2) + pow(y_max, 2) + pow(z_max, 2);
}
