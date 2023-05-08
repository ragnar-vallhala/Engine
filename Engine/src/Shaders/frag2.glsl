#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_explicit_attrib_location : enable
out vec4 FragColor;
in vec4 bg;
in vec2 texCoord;
uniform float tim;
uniform sampler2D ourTexture;
void main(){
	FragColor = texture(ourTexture,texCoord)*1.0+vec4(bg)*0.0;
}
