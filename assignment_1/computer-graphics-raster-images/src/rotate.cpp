#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  if(num_channels == 1){

    for(int i = 0; i<height; i++){
      for(int j = 0; j<width; j++){
        rotated[(width-1-j)*(height) + i] = input[i*(width)+j];
      }
    }

  }

  if(num_channels == 3){

    for(int i = 0; i<height; i++){
      for(int j = 0; j<width; j++){
        rotated[(width-1-j)*(height)*3 + i*3 ] = input[i*(width)*3+j*3];
        rotated[(width-1-j)*(height)*3 + i*3 +1] = input[i*(width)*3+j*3+1];
        rotated[(width-1-j)*(height)*3 + i*3 +2] = input[i*(width)*3+j*3+2];
      }
    }

  }


}
