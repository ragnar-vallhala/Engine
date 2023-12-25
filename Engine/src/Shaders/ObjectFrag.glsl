#version 450 core

out vec4 FragColor;

uniform vec4 color;
uniform vec4 lightColor;
in float diffuseFactor;
float ambientFractor = 0.1;

void main(){
    vec4 ambient = ambientFractor * color * lightColor;
    vec4 diffuse = diffuseFactor * color * lightColor;
    FragColor = ambient + diffuse;
}