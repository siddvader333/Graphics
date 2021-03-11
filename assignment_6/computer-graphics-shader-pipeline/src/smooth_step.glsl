// Filter an input value to perform a smooth step. This function should be a
// cubic polynomial with smooth_step(0) = 0, smooth_step(1) = 1, and zero first
// derivatives at f=0 and f=1. 
//
// Inputs:
//   f  input value
// Returns filtered output value
float smooth_step( float f)
{

  //f(0) = 0, f(1) = 1, f'(0) = 0, f'(1) = 0
  //generate cubic function using these values
  // ax^3 + bx^2 + cx +d 
  return -2*pow(f,3) + 3* pow(f, 2) + 0*f + 0;


}

vec3 smooth_step( vec3 f)
{
  return vec3(smooth_step(f.x), smooth_step(f.y), smooth_step(f.z));

}
