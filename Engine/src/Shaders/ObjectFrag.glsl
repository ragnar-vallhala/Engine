#version 450 core

out vec4 FragColor;

uniform vec4 color;
uniform vec4 lightColor;
uniform vec4 lightPosition;
uniform vec4 lightColor1;
uniform vec4 lightPosition1;
uniform vec4 cameraPos;
in vec3 normal;
in vec4 fragPos;
float ambientFractor = 0.1;
float specStrength = 2.0;

void main(){
    vec4 ambient = ambientFractor * color * lightColor;

    vec3 toLight  = normalize(lightPosition.xyz - (fragPos.xyz)/fragPos.w);
    float diffuseFactor = dot(toLight,normal)*0.5+0.5;
    vec4 diffuse = diffuseFactor * color * lightColor;
    
    vec3 viewDir = normalize(cameraPos.xyz - fragPos.xyz);
    vec3 reflectDir = reflect(-toLight,normal);
    float spec = pow((dot(viewDir,reflectDir)*0.5+0.5),128);
    vec4 specular = spec * specStrength * color * lightColor;





    vec3 toLight1  = normalize(lightPosition1.xyz - (fragPos.xyz)/fragPos.w);
    float diffuseFactor1 = dot(toLight1,normal)*0.5+0.5;
    vec4 diffuse1 = diffuseFactor * color * lightColor1;
    
    vec3 viewDir1 = normalize(cameraPos.xyz - fragPos.xyz);
    vec3 reflectDir1 = reflect(-toLight1,normal);
    float spec1 = pow((dot(viewDir1,reflectDir1)*0.5+0.5),128);
    vec4 specular1 = spec1 * specStrength * color * lightColor1;




    FragColor = specular + ambient + diffuse + specular1 + diffuse1;
}

