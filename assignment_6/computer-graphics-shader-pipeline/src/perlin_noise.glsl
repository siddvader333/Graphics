// Given a 3d position as a seed, compute a smooth procedural noise
// value: "Perlin Noise", also known as "Gradient noise".
//
// Inputs:
//   st  3D seed
// Returns a smooth value between (-1,1)
//
// expects: random_direction, smooth_step
float perlin_noise(vec3 st) 
{

  //https://flafla2.github.io/2014/08/09/perlinnoise.html

  vec3 bottom = floor(st);
  vec3 top = ceil(st);

  //Unit cube
  vec3 p_000 = vec3(bottom.x, bottom.y, bottom.z);
  vec3 p_100 = vec3(top.x, bottom.y, bottom.z);
  vec3 p_010 = vec3(bottom.x, top.y, bottom.z);
  vec3 p_001 = vec3(bottom.x, bottom.y, top.z);
  vec3 p_101 = vec3(top.x, bottom.y, top.z);
  vec3 p_110 = vec3(top.x, top.y, bottom.z);
  vec3 p_011 = vec3(bottom.x, top.y, top.z);
  vec3 p_111 = vec3(top.x, top.y, top.z);

  //Gradient
  vec3 g_000 = random_direction(p_000);
  vec3 g_100 = random_direction(p_100);
  vec3 g_010 = random_direction(p_010);
  vec3 g_001 = random_direction(p_001);
  vec3 g_101 = random_direction(p_101);
  vec3 g_110 = random_direction(p_110);
  vec3 g_011 = random_direction(p_011);
  vec3 g_111 = random_direction(p_111);

  //Distance Vector
  vec3 d_000 = normalize(st - p_000);
  vec3 d_100 = normalize(st - p_100);
  vec3 d_010 = normalize(st - p_010);
  vec3 d_001 = normalize(st - p_001);
  vec3 d_101 = normalize(st - p_101);
  vec3 d_110 = normalize(st - p_110);
  vec3 d_011 = normalize(st - p_011);
  vec3 d_111 = normalize(st - p_111);

  //Influence

  float i_000 = dot(g_000, d_000);
  float i_100 = dot(g_100, d_000);
  float i_010 = dot(g_010, d_000);
  float i_001 = dot(g_001, d_000);
  float i_101 = dot(g_101, d_000);
  float i_110 = dot(g_110, d_000);
  float i_011 = dot(g_011, d_000);
  float i_111 = dot(g_111, d_111);

  vec3 interpolated_weights = smooth_step(fract(st));
  float i1x = mix(i_000, i_100, interpolated_weights.x);
  float i2x = mix(i_010, i_001, interpolated_weights.x);
  float i3x = mix(i_101, i_110, interpolated_weights.x);
  float i4x = mix(i_011, i_111, interpolated_weights.x);

  float i1y = mix(i1x, i2x, interpolated_weights.y);
  float i2y = mix(i3x, i4x, interpolated_weights.y);
  float i1z = mix(i1y, i2y, interpolated_weights.z);

  return i1z -0.5;
}

