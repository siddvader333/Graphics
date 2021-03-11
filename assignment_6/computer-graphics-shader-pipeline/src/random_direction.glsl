// Generate a pseudorandom unit 3D vector
// 
// Inputs:
//   seed  3D seed
// Returns psuedorandom, unit 3D vector drawn from uniform distribution over
// the unit sphere (assuming random2 is uniform over [0,1]²).
//
// expects: random2.glsl, PI.glsl
vec3 random_direction( vec3 seed)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  vec2 rand_coords = random2(seed);
  float x = rand_coords.x;
  float y = rand_coords.y;

  //converting to spherical 
  float new_x = sin (M_PI*y) * cos(2*M_PI*x);
  float new_y = sin(M_PI*y) *sin(2*M_PI*y);
  float new_z = cos(M_PI*y);

  return normalize(vec3(new_x, new_y, new_z));


  



  /////////////////////////////////////////////////////////////////////////////
}
