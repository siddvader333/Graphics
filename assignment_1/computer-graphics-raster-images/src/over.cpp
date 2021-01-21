#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  double currentAlpha1 =0;
  double currentAlpha2 = 0;

  for(int i =0; i< A.size(); i++){
    if(i%4 ==0){
      //set new alphas for next 4 array elements
      currentAlpha1 = A[i+3]/255.0;
      currentAlpha2 = B[i+3]/255.0;
      C[i+3] = (unsigned char) ((currentAlpha1 + currentAlpha2 * (1 - currentAlpha1)) *255); //set new alpha value for pixel
    }

    if(i+1%4 != 0){ //if not an alpha value, set new color
      C[i] = (unsigned char) ((double) A[i]*currentAlpha1 + (double) B[i]*currentAlpha2*(1-currentAlpha1));
    }
  }
}
