#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  int grayCount =0;
  for(int curr_row = 0; curr_row<height; curr_row++){
    for (int curr_col = 0; curr_col<width; curr_col++){
      int row_type = curr_row%2;
      //row type 0
      if(row_type ==0){
        if(curr_col%2 == 0){ //add green
          bayer[grayCount] = rgb[curr_row*width*3 + curr_col*3 +1];
        }else { //add blue
          bayer[grayCount] = rgb[curr_row*width*3 + curr_col*3 +2];
        }

      }else {
        //row type 1
         if(curr_col%2 == 0){ //add red
          bayer[grayCount] = rgb[curr_row*width*3 + curr_col*3];
        }else { //add green
          bayer[grayCount] = rgb[curr_row*width*3 + curr_col*3 +1];
        }
      }

      grayCount++;

    }
  }
}
