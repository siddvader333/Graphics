#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int curr_height =0; curr_height<height; curr_height++){
    for(int curr_column = width-1; curr_column>=0; curr_column--){
      if(num_channels == 1){ //grayscale
        reflected[curr_height*width + (width-1-curr_column)] = input[curr_height*width + curr_column];
      }

      if(num_channels == 3){
        reflected[curr_height*width*3 + 3*(width-1) - (3*curr_column)] = input[curr_height*width*3 + curr_column*3];
        reflected[curr_height*width*3 + 3*(width-1) - (3*curr_column)+1] = input[curr_height*width*3 + curr_column*3+1];
        reflected[curr_height*width*3 + 3*(width-1) - (3*curr_column)+2] = input[curr_height*width*3 + curr_column*3+2];
      }

    }
  }

}
