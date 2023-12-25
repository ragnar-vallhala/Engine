#version 450 core

out vec4 FragColor;
uniform vec4 lightColor;
in vec2 uvCoord;
void main() {
	FragColor = lightColor;
}