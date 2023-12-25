#version 450 core
layout (location = 0) in vec3 vert;
layout (location = 1) in vec3 norm;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 transformation;
uniform vec4 lightPosition;

out float diffuseFactor; 
void main(){
    vec3 newNorm = normalize(projection * view * transformation * vec4(norm, 1.0)).xyz;
    vec3 toLight  = normalize(lightPosition.xyz - vert);
    diffuseFactor = dot(toLight, newNorm)*0.5 + 0.5;

    gl_Position = projection * view * transformation * vec4(vert, 1.0);
}