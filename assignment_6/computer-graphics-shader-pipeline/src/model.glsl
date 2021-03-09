// Construct the model transformation matrix. The moon should orbit around the
// origin. The other object should stay still.
//
// Inputs:
//   is_moon  whether we're considering the moon
//   time  seconds on animation clock
// Returns affine model transformation as 4x4 matrix
//
// expects: identity, rotate_about_y, translate, PI
mat4 model(bool is_moon, float time)
{

  if !is_moon
    return identity(); //if not moon just return identity

  float angle_degrees = (mod(time, 4.0)/4) *360;
  float angle_radians = angle_degrees* M_PI/180;

  mat4 rotation_matrix = rotate_about_y(angle_radians);

  mat4 translation_matrix = translate(vec3(2,0,2))); 

  mat4 resize_matrix = uniform_scale(0.3);

  return rotation_matrix*translation_matrix*resize_matrix;
}
