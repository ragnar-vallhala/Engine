#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_explicit_attrib_location : enable
out vec4 FragColor;
uniform vec4 c;        
void main()
{
	FragColor = c;
}