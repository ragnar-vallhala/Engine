#version 450 core

out vec4 FragColor;
uniform vec4 color;
in vec2 uvCoord;
void main() {
	FragColor = vec4(uvCoord,0.0,1.0);
}