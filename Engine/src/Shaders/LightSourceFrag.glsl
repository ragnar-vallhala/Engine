#version 450 core

out vec4 FragColor;
uniform vec4 color;
uniform vec4 lightColor;
in vec2 uvCoord;
void main() {
	FragColor = vec4(uvCoord.xy,0.0,1.0)*lightColor;
}