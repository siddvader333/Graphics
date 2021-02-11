#include "point_AABBTree_squared_distance.h"
#include <queue> // std::priority_queue

bool point_AABBTree_squared_distance(
    const Eigen::RowVector3d & query,
    const std::shared_ptr<AABBTree> & root,
    const double min_sqrd,
    const double max_sqrd,
    double & sqrd,
    std::shared_ptr<Object> & descendant)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  //use a priority queue of std::pair<double, Object>
  struct compare {
    bool operator() (const std::pair<double, std::shared_ptr<Object>>& a, const std::pair<double, std::shared_ptr<Object>>& b) const
    {
      return a.first > b.first;
    }
  };

  std::priority_queue<std::pair<double, std::shared_ptr<Object>> , std::vector<std::pair<double, std::shared_ptr<Object>>>, compare> pqueue;


  //push root into pqueue and keep iterating until pqueue is empty or return out
  pqueue.push(std::make_pair(point_box_squared_distance(query, root->box), root));

  //bfs
  while(!pqueue.empty()){ //keep running until the pqueue is empty
  
    //get first element
    auto curr_element = pqueue.top();
    //remove first elemenbt from queue 
    pqueue.pop();

    if(curr_element.first > max_sqrd){
      //obj is greater than max sqrd, and since prio queue, every other obj also is greater, no obj to be found
      return false;
    }

    //distance is less than maxsqrd
    //check if leaf object, or subtree
    //https://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c to check type


    //if tree, add children to pqueue
    auto casted_obj = std::dynamic_pointer_cast<AABBTree>(curr_element.second);
    if(casted_obj){ //if a tree
      //handle right child
      if(casted_obj->right && point_box_squared_distance(query, casted_obj->right->box) < max_sqrd){
        //if right child exists and distance is valid
        pqueue.push(std::make_pair(point_box_squared_distance(query, casted_obj->right->box),casted_obj->right));
      }
      //handle left child
      if(casted_obj->left && point_box_squared_distance(query, casted_obj->left->box) < max_sqrd){
        //if left child exists and distance is valid
        pqueue.push(std::make_pair(point_box_squared_distance(query, casted_obj->left->box),casted_obj->left));
      }

    }else {
      //if leaf, check if valid distance
      if(curr_element.first > min_sqrd){//valid distance
        sqrd = curr_element.first;
        descendant = curr_element.second;
        return true;
      }
      //if not valid distance do nothing
    }
  }


  return false; //default case

}
