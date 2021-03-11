// Create a bumpy surface by using procedural noise to generate a height (
// displacement in normal direction).
//
// Inputs:
//   is_moon  whether we're looking at the moon or centre planet
//   s  3D position of seed for noise generation
// Returns elevation adjust along normal (values between -0.1 and 0.1 are
//   reasonable.
float bump_height( bool is_moon, vec3 s)
{

  if(!is_moon){
    float height = improved_perlin_noises(vec3(improved_perlin_noise(vec3(9.0, 9.0, -10.0)*s));
    return 0.8 * smooth_heaviside(height, 3);
  }

  float height = improved_perlin_noises(vec3(improved_perlin_noise(vec3(1.0, 1.2, -1.0)*s));
  return 0.5 * smooth_heaviside(height, 3);

}
