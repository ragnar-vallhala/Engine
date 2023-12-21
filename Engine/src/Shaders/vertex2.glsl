#version 450 core


layout (location = 0) in vec3 bPos;
layout (location = 1) in vec3 col;
out vec4 bg;
void main(){
	
	gl_Position  = vec4(bPos.x,bPos.y,bPos.z,1.0);
	bg = vec4(col,1.0);
}