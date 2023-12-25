#version 450 core
layout (location = 0) in vec3 vert;
layout (location = 1) in vec2 uv;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 transformation;
void main(){
    gl_Position = projection * view * transformation * vec4(vert, 1.0);
}