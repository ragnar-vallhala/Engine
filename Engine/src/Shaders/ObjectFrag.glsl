#version 450 core

out vec4 FragColor;

uniform vec4 color;
uniform vec4 lightColor;
uniform vec4 lightPosition;
uniform vec4 cameraPos;
in vec3 normal;
in vec4 fragPos;
float ambientFractor = 0.3;
float specStrength = 5.0;

void main(){
    vec4 ambient = ambientFractor * color * lightColor;

    vec3 toLight  = normalize(lightPosition.xyz - (fragPos.xyz)/fragPos.w);
    float diffuseFactor = dot(toLight,normal)*0.5+0.5;
    vec4 diffuse = diffuseFactor * color * lightColor;
    
    vec3 viewDir = normalize(cameraPos.xyz - fragPos.xyz);
    vec3 reflectDir = reflect(-toLight,normal);
    float spec = pow((dot(viewDir,reflectDir)*0.5+0.5),128);
    vec4 specular = spec * specStrength * color * lightColor;

    FragColor = specular + ambient + diffuse;
}

