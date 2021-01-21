#include "hsv_to_rgb.h"
#include <cmath>
void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double C = v * s;
  double hPrime = h/60;
  double X = C * (1 - std::fabs(std::fmod(hPrime, 2) -1));
  double m = v-C;

  if(hPrime == 0){
    r = 0 + m;
    g = 0+ m;
    b = 0+m;
  }else if(hPrime <=1){
      r = C +m;
      g = X +m;
      b = 0 +m;
  }else if (hPrime <=2){
      r = X +m;
      g = C +m;
      b = 0 +m;
  }else if (hPrime <=3){
      r = 0 +m;
      g = C +m;
      b = X +m;
  }else if (hPrime <=4){
      r = 0 +m;
      g = X +m;
      b = C +m;
  }else if (hPrime <=5){
      r = X +m;
      g = 0 +m;
      b = C +m;
    
  }else if (hPrime <=6){
      r = C +m;
      g = 0 +m;
      b = X +m;
  }

  ////////////////////////////////////////////////////////////////////////////
}
