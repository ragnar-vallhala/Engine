#version 450 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_explicit_attrib_location : enable
out vec4 FragColor;
in vec2 texCoord;
uniform sampler2D tex0;

void main()
{
	FragColor = texture(tex0, texCoord);
}