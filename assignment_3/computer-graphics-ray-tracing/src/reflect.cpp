#include <Eigen/Core>

Eigen::Vector3d reflect(const Eigen::Vector3d & in, const Eigen::Vector3d & n)
{
  Eigen::Vector3d vec = 2.0 * n.dot(in) *n;
  return in - vec;
}
