#version 450 core

out vec4 FragColor;
uniform vec4 color;
uniform vec4 lightColor;
void main(){
    FragColor = color * lightColor;
}