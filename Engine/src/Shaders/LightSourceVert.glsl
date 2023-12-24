#version 450 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 transformation;
out vec2 uvCoord;
void main(){
	gl_Position = projection * view * transformation * vec4(position,1.0);
	uvCoord=uv;
}
