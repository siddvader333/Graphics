#include "box_box_intersect.h"
bool box_box_intersect(
  const BoundingBox & A,
  const BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  //check all corners to check fo intersections along everyaxis
  for(int i =0; i< 3; i++){
    if(!(A.max_corner[i] > B.min_corner[i] && A.min_corner[i] < B.max_corner[i])){// no intersection on this axis
      return false; 
    }
  }

  return true; //if there was no false cases found
}

