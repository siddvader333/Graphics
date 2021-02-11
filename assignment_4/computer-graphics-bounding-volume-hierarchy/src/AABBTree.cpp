#include "AABBTree.h"
#include "insert_box_into_box.h"
#include <iostream>
AABBTree::AABBTree(
  const std::vector<std::shared_ptr<Object> > & objects,
  int a_depth): 
  depth(std::move(a_depth)), 
  num_leaves(objects.size())
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  //base case -- 0-1 objects left --> must be leaves
  //std::cout<<"number of objects left in this iteration "<<objects.size()<<std::endl;
  if(objects.size() == 0){
    return;
  }
  if(objects.size() == 1){
    this->left = objects[0];
    insert_box_into_box(objects[0]->box, this->box);
    return;
  }

  //add all objects to current box and calculate longest axis and center from that 
  for (int i = 0; i< objects.size(); i++){
    insert_box_into_box(objects[i]->box, this->box);
  }

  //std::cout<<"hjere"<<std::endl;
  int longest_axis = -1;
  double longest_axis_length = -std::numeric_limits<double>::infinity();
  for(int i = 0; i< 3; i++){
    if(this->box.max_corner[i] - this->box.min_corner[i] > longest_axis_length){
      longest_axis_length = this->box.max_corner[i] - this->box.min_corner[i];
      longest_axis = i;
    }
  }

  auto longest_axis_midpoint = this->box.center()[longest_axis];
  //std::cout<<"longest axis is: "<<longest_axis<<std::endl;
  //std::cout<<"longest_axis length: "<<longest_axis_length<<std::endl;
  //std::cout<<"center point is "<<longest_axis_midpoint<<std::endl;

  //sort objects along selected axis
  //std::cout<<"length of objects: "<<objects.size()<<std::endl;
  std::vector<std::shared_ptr<Object>> sorted_objs(objects);
  //std::cout<<"sortedobjs length before sorting: "<<sorted_objs.size()<<std::endl;

  //use lambda function to sort based off of longest axis
  std::sort(sorted_objs.begin(), sorted_objs.end(), [longest_axis](std::shared_ptr<Object> a, std::shared_ptr<Object> b) 
  { 
    return a->box.center()[longest_axis] < b->box.center()[longest_axis];
  });
  

  std::vector<std::shared_ptr<Object>> left_vector(sorted_objs.begin(), sorted_objs.begin()+objects.size()/2);
  std::vector<std::shared_ptr<Object>> right_vector(sorted_objs.begin()+objects.size()/2, sorted_objs.end());

  //for(int i = 0; i< sorted_objs.size(); i++){
   // if(i <idx){
    //  left_vector.push_back(sorted_objs[i]);
    //}else {
     // right_vector.push_back(sorted_objs[i]);
    //}
  //}

  //std::cout<<"h0"<<std::endl;
  //auto midPointIterator = sorted_objs.begin() + idx;
  //std::cout<<"h1"<<std::endl;
  //std::vector<std::shared_ptr<Object>> left_vector(sorted_objs.begin(), sorted_objs.begin() +idx);
  //std::vector<std::shared_ptr<Object>> right_vector(midPointIterator, sorted_objs.end());


  //std::cout<<"we split the vectors into sizes: "<<left_vector.size()<<" "<<right_vector.size()<<std::endl;

  this->left = std::make_shared<AABBTree>(left_vector, this->depth+1);
  this->right = std::make_shared<AABBTree>(right_vector, this->depth+1);

  insert_box_into_box(this->left->box, this->box);
  insert_box_into_box(this->right->box, this->box);


}
