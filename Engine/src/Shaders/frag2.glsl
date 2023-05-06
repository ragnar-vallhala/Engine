#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_explicit_attrib_location : enable
out vec4 FragColor;
in vec4 bg;
uniform float tim;
void main(){
	FragColor = vec4((sin(bg.r+tim)+1)/2,(sin(bg.g+tim)+1)/2,(sin(bg.b+tim)+1)/2,bg.a);
}
