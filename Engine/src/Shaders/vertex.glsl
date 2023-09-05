#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_explicit_attrib_location : enable
layout (location = 0) in vec3 aPos;
uniform mat4 transform;
void main()
{
	gl_Position = transform*vec4(aPos,1.0);
	
}