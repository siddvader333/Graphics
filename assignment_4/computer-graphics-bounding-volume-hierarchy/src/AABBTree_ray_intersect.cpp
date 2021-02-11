#include "AABBTree.h"

// See AABBTree.h for API
bool AABBTree::ray_intersect(
  const Ray& ray,
  const double min_t,
  const double max_t,
  double & t,
  std::shared_ptr<Object> & descendant) const 
{
  if (ray_intersect_box(ray, this->box, min_t, max_t)) {

    double temp_t_left;
    double temp_t_right;
    bool left_hit = false;
    bool right_hit = false;
    std::shared_ptr<Object> left_child = this->left;
    std::shared_ptr<Object> right_child = this->right;

    if(left_child){
      left_hit = left_child->ray_intersect(ray, min_t, max_t, temp_t_left, left_child);
    }

    if(right_child){
      right_hit = right_child->ray_intersect(ray, min_t, max_t, temp_t_right, right_child);
    }


    //4 cases
    //1. both hit
    if(left_hit && right_hit){
      //take closer hit values
      if(temp_t_left < temp_t_right){
        t = temp_t_left;
        descendant = left_child;
      }else {
        t = temp_t_right;
        descendant = right_child;
      }
      return true;
    }

    //case 2: left but not right
    if(left_hit && !right_hit){
      t = temp_t_left;
      descendant = left_child;
      return true;
    }

    //case 3: right but not left
    if(!left_hit && right_hit){
      t = temp_t_right;
      descendant = right_child;
      return true;
    }
    //case 4: none
    if(!left_hit && !right_hit){
      return false;
    }
  }
  //default case -- doesnt hit box
  return false;
}
