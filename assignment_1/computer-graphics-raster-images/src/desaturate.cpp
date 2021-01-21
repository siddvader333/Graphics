#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
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

    //Apply saturation factor

    s = s* (1-factor);

    //convert back to rgb
    hsv_to_rgb(h, s, v, r, g, b);


    desaturated[i] =  r*255;
    desaturated[i+1] = g*255;
    desaturated[i+2] = b*255;



  }
}
