// Set the pixel color using Blinn-Phong shading (e.g., with constant blue and
// gray material color) with a bumpy texture.
// 
// Uniforms:
uniform mat4 view;
uniform mat4 proj;
uniform float animation_seconds;
uniform bool is_moon;
// Inputs:
//                     linearly interpolated from tessellation evaluation shader
//                     output
in vec3 sphere_fs_in;
in vec3 normal_fs_in;
in vec4 pos_fs_in; 
in vec4 view_pos_fs_in; 
// Outputs:
//               rgb color of this pixel
out vec3 color;
// expects: model, blinn_phong, bump_height, bump_position,
// improved_perlin_noise, tangent
void main()
{
 vec4 rotation = view * vec4(2 * vec3(cos(animation_seconds*M_PI/3), 1, sin(animation_seconds*M_PI/3)), 1.0);

  vec3 ka, kd, ks, base;
  float p;

  vec3 n = normalize(normal_fs_in);
  vec3 v = -normalize(view_pos_fs_in.xyz);
  vec3 l = normalize((rotation/rotation.w).xyz - view_pos_fs_in.xyz/view_pos_fs_in.w);

  float noise_factor;
  if(is_moon)
    noise_factor = 0.8;
  else
    noise_factor = 0.3;

  //Calculate Noise here
  float noise1 = perlin_noise(vec3(1.0, 2.0, 3.0) * sphere_fs_in * noise_factor);
  float noise2 = perlin_noise(vec3(2.0, 3.0, 4.0) * sphere_fs_in * noise_factor);
  float noise3 = perlin_noise(vec3(11.0, 15.0, 10.0) * sphere_fs_in * noise_factor);

  float final_noise = noise_factor * perlin_noise(2.3 * vec3(noise1, noise2, noise3));

  if (is_moon){
    ka = vec3(0.1)*final_noise;
    kd = vec3(0.6)*final_noise;
    ks = vec3(0.3)*final_noise;
    p = 100;
    base vec3(0.4);
  }else{
    ka = vec3(0.1)*final_noise;
    kd = vec3(0.7)*final_noise;
    ks = vec3(0.9)*final_noise;
    p = 1000;
    base vec3(0,0,1);
  }

  color = base * blinn_phong(ka, kd, ks, p, n, v, l);
}
