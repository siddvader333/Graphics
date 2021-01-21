#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  //https://en.wikipedia.org/wiki/Grayscale#Converting_color_to_grayscale
  //Use the equation Y = 0.2126*R + 0.7152*G + 0.0722*B
  int grayCount =0 ;
  for(int i =0; i<rgb.size(); i++){
      if((i+1) %3 == 0){
        gray[grayCount] = 0.2126*rgb[i-2] + 0.7152*rgb[i-1] + 0.0722*rgb[i]; 
        grayCount++;
      }
  }
}


