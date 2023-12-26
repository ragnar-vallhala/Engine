#version 450 core
layout (location = 0) in vec3 vert;
layout (location = 1) in vec3 norm;
layout (location = 2) in vec2 texCoord;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 transformation;

out vec3 normal;
out vec4 fragPos; 
out vec2 uv;
void main(){
    normal = normalize(mat3(transpose(inverse(transformation))) * norm);
    fragPos = transformation * vec4(vert,1.0);
    gl_Position = projection * view * transformation * vec4(vert, 1.0);
    uv = texCoord;
}