#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_explicit_attrib_location : enable
layout (location = 0) in vec3 bPos;
layout (location = 1) in vec3 col;
layout (location = 2) in vec2 aTexCoord;

out vec4 bg;
out vec2 texCoord;
uniform float tim;
uniform float offsetx;
uniform float offsety;
void main(){
	
	gl_Position  = vec4(bPos.x*abs(sin(0.1*tim)) + offsetx,-bPos.y + offsety,bPos.z,1.0);
	bg = vec4(col,1.0);
	texCoord = vec2(aTexCoord.x,-aTexCoord.y);
}