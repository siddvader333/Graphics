#include "rgb_to_hsv.h"
#include <cstdlib>
#include <cmath>
#include <algorithm>
void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  double maxValue =  std::max({r, g, b});
  double minValue = std::min({r, g, b});

  double diff = maxValue - minValue; 

  v = maxValue;
  if(diff == 0){
    h = 0;
  }else {
    if(maxValue == r){
      h = 60* std::fmod(((g-b)/diff), 6);
    }

    if(maxValue == g){
      h = 60 *(2 + (b-r)/diff);
    }

    if(maxValue == b){
      h = 60 * (4 + (r-g)/diff);
    }
  }

  if (h < 0) {
    h *= -1;
    h = std::fmod(h, 360);
    h = 360 - h;
  } else {
    h = std::fmod(h, 360);
  }
   
  if (v == 0){
    s = 0;
  }else {
    s = diff/v;
  }

  return;
  ////////////////////////////////////////////////////////////////////////////
}
