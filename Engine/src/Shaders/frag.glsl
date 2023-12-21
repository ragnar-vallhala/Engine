#version 450 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_explicit_attrib_location : enable
out vec4 FragColor;
uniform vec4 c;
in vec2 texCoord;
uniform sampler2D tex0;
uniform sampler2D tex1;
void main()
{
	FragColor = texture(tex0, vec2(-texCoord.x,texCoord.y)) * texture(tex1, texCoord);
}