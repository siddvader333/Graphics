// Add (hard code) an orbiting (point or directional) light to the scene. Light
// the scene using the Blinn-Phong Lighting Model.
//
// Uniforms:
uniform mat4 view;
uniform mat4 proj;
uniform float animation_seconds;
uniform bool is_moon;
// Inputs:
in vec3 sphere_fs_in;
in vec3 normal_fs_in;
in vec4 pos_fs_in; 
in vec4 view_pos_fs_in; 
// Outputs:
out vec3 color;
// expects: PI, blinn_phong
void main()
{

  vec4 rotation = view * vec4(2 * vec3(cos(animation_seconds*M_PI/3), 1, sin(animation_seconds*M_PI/3)), 1.0);

  vec3 ka, kd, ks, base;
  float p;

  vec3 n = normalize(normal_fs_in);
  vec3 v = -normalize(view_pos_fs_in.xyz);
  vec3 l = normalize((rotation/rotation.w).xyz - view_pos_fs_in.xyz/view_pos_fs_in.w);

  if (is_moon){
    ka = vec3(0.1);
    kd = vec3(0.6);
    ks = vec3(0.3);
    p = 100;
    base = vec3(0.4);
  }else{
    ka = vec3(0.1);
    kd = vec3(0.7);
    ks = vec3(0.9);
    p = 1000;
    base = vec3(0,0,1);
  }

  color = base * blinn_phong(ka, kd, ks, p, n, v, l);
  return;
}
