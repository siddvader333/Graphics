#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <iostream>

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int i =0; i< rgb.size(); i+=3){
    double r = (unsigned int) rgb[i]/255.0;
    double g = (unsigned int) rgb[i+1]/255.0;
    double b = (unsigned int) rgb[i+2]/255.0;
    double h = 0;
    double s = 0;
    double v = 0;

    //Convert to HSV
    rgb_to_hsv(r, g, b, h, s, v);

     /* std::cout<<"r value is" <<r*255<<std::endl;
  std::cout<<" g value is" <<g*255<<std::endl;
  std::cout<<"b value is "<<b*255<<std::endl;

    std::cout<<"h value is" <<h<<std::endl;
  std::cout<<" s value is" <<s<<std::endl;
  std::cout<<"v value is "<<v<<std::endl;
  std::cout<<"shift to apply" <<shift<<std::endl;*/

    //Apply hue shift

    h = h+shift;

    if(h <= 0){
      h+=360;
    }else if(h >=360){
      h-=360;
    }

    //convert back to rgb
    hsv_to_rgb(h, s, v, r, g, b);
  /*std::cout<<"r value is" <<r*255<<std::endl;
  std::cout<<" g value is" <<g*255<<std::endl;
  std::cout<<"b value is "<<b*255<<std::endl;

    std::cout<<"h value is" <<h<<std::endl;
  std::cout<<" s value is" <<s<<std::endl;
  std::cout<<"v value is "<<v<<std::endl;*/


    shifted[i] =  r*255;
    shifted[i+1] = g*255;
    shifted[i+2] = b*255;

/*
  std::cout<<"shifted i is" <<shifted[i]<<std::endl;
  std::cout<<"shifted i+1 is " <<shifted[i+1]<<std::endl;
  std::cout<<"shifted i+2 "<<shifted[i+2]<<std::endl;*/


  }
}
