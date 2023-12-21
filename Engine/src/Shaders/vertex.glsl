#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 uv;
out vec2 texCoord;
uniform float time;
#define TAU 6.28318530718
void main()
{
	gl_Position = vec4(aPos,1.0);
	texCoord = vec2(uv.x,uv.y + sin(TAU * time * 0.1));
}