#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  //row style 0 -> gbgbgb
  //row style 1 -> rgrgrg

  bool isRed = false;
  bool isGreen = false;
  bool isBlue = false;

  for(int i = 0; i< height; i++){
    for(int j = 0; j< width; j++){
      //determine row type
      int rowType = i%2;
      isRed = (rowType == 1) && (j%2 ==0);
      isBlue = (rowType == 0) && (j%2 ==1);
      isGreen = ((rowType == 0) && (j%2 ==0)) || ( (rowType == 1) && (j%2 ==1));

      int r, g, b;
      int arr_index = i*width +j;

      //Get R value for current pixel
      if(isRed){
        //Red value
        r = bayer[arr_index];

        //green value --> vertical and horizontals
        int greenCount =0;
        int totalGreen = 0;
        //green is diagonal coordinates
        //top
          if(i-1 >=0){
            totalGreen += bayer[(i-1)*width];
            greenCount++;
          }
        //right
          if(j+1 <=width-1){
            totalGreen += bayer[(i)*width + (j+1)];
            greenCount++;
          }

        //left 
          if(j-1 >=0){
            totalGreen += bayer[(i)*width + (j-1)];
            greenCount++;
          }
        //bottom
          if(i+1 <=height){
            totalGreen += bayer[(i+1)*width + j];
            greenCount++;
          }

          totalGreen/=greenCount;
          g = totalGreen;

        //blue value --> diagonals
        int blueCount =0;
        int totalBlue = 0;
        //red is diagonal coordinates
        //left top
          if(i-1 >=0 && j-1 >=0){
            totalBlue += bayer[(i-1)*width + (j-1)];
            blueCount++;
          }
        //right top
          if(i-1 >=0 && j+1 <=width-1){
            totalBlue += bayer[(i-1)*width + (j+1)];
            blueCount++;
          }

        //left bottom
          if(i+1 <= height-1 && j-1 >=0){
            totalBlue += bayer[(i-1)*width + (j-1)];
            blueCount++;
          }
        //right bottom
          if(i+1 <=height && j+1 <=width -1){
            totalBlue += bayer[(i+1)*width + (j+1)];
            blueCount++;
          }

          totalBlue/=blueCount;
          b = totalBlue;
      }
      if(isBlue){
        int count =0;
        int totalRed = 0;
        //red is diagonal coordinates
        //left top
          if(i-1 >=0 && j-1 >=0){
            totalRed += bayer[(i-1)*width + (j-1)];
            count++;
          }
        //right top
          if(i-1 >=0 && j+1 <=width-1){
            totalRed += bayer[(i-1)*width + (j+1)];
            count++;
          }

        //left bottom
          if(i+1 <= height-1 && j-1 >=0){
            totalRed += bayer[(i-1)*width + (j-1)];
            count++;
          }
        //right bottom
          if(i+1 <=height && j+1 <=width -1){
            totalRed += bayer[(i+1)*width + (j+1)];
            count++;
          }

          totalRed/=count;
          r = totalRed;

          //blue is current pixel
          b = bayer[arr_index];

          //green is vertical and horizontal
        int greenCount =0;
        int totalGreen = 0;
        //green is diagonal coordinates
        //top
          if(i-1 >=0){
            totalGreen += bayer[(i-1)*width];
            greenCount++;
          }
        //right
          if(j+1 <=width-1){
            totalGreen += bayer[(i)*width + (j+1)];
            greenCount++;
          }

        //left 
          if(j-1 >=0){
            totalGreen += bayer[(i)*width + (j-1)];
            greenCount++;
          }
        //bottom
          if(i+1 <=height){
            totalGreen += bayer[(i+1)*width + j];
            greenCount++;
          }

          totalGreen/=greenCount;
          g = totalGreen;
      }

      if(isGreen){
        int redCount = 0;
        int blueCount = 0;

        int totalRed = 0;
        int totalBlue = 0;
        //row 0
        if(rowType == 0){
        //top red
          if(i-1 >=0 ){
            totalRed += bayer[(i-1)*width];
            redCount++;
          }
        //right blue
          if(j+1 <=width-1){
            totalBlue += bayer[(i)*width + (j+1)];
            blueCount++;
          }

        //left blue
          if(j-1 >=0){
            totalBlue += bayer[(i)*width + (j-1)];
            blueCount++;
          }
        //red bottom
          if(i+1 <=height){
            totalRed += bayer[(i+1)*width + (j)];
            redCount++;
          }

          totalRed/=redCount;
          totalBlue/=blueCount;
          r = totalRed;
          b = totalBlue;
        }

        //row 1
        if(rowType == 1){       
        //top blue
          if(i-1 >=0 ){
            totalBlue += bayer[(i-1)*width];
            blueCount++;
          }
        //right red
          if(j+1 <=width-1){
            totalRed += bayer[(i)*width + (j+1)];
            redCount++;
          }

        //left red
          if(j-1 >=0){
            totalRed += bayer[(i)*width + (j-1)];
            redCount++;
          }
        //blue bottom
          if(i+1 <=height){
            totalBlue += bayer[(i+1)*width + (j)];
            blueCount++;
          }

          totalRed/=redCount;
          totalBlue/=blueCount;
          r = totalRed;
          b = totalBlue;

        }
      }

      //Add values to new array
      rgb[arr_index*3] = r;
      rgb[arr_index*3 +1] = g;
      rgb[arr_index*3 +2] = b;

    }
  }
}
