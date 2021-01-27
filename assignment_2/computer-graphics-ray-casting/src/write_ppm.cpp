#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");

    //First Try and open the file
    std::ofstream myFile;
    myFile.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);

  //If file was unopened, an error occured, return false.
    if(!myFile.is_open()){
      return false;
    }

    //If file is open, start writing to it. 

    //Write PPM header information.
    myFile <<"P3" <<std::endl <<width<<" "<<height <<std::endl << 255<<std::endl;

    //Iterate through data points and write data to file.
    for(int i = 0; i< data.size(); i++){
      //Grayscale Iamges
      if (num_channels == 1){
        myFile<<(unsigned int) data[i] << " "<<(unsigned int) data[i] <<" "<<(unsigned int)data[i]<<std::endl;
      }
      //RGB Images
      if(num_channels == 3){
        myFile<<(unsigned int) data[i];
        //std::cout<<"the i value is"<< (unsigned int) data[i]<<std::endl;

        if( (i+1)%3 == 0){ //if it is at the end of a line, add a new line
          myFile<<std::endl;
        }
        else {
          myFile<<" "; // if not at end of line or triplet, add " "
        }

      }
    }

      //If it reaches the end, close the file and if it closes properly return true, no errors found. 
      myFile.close();
      return true; 
}
