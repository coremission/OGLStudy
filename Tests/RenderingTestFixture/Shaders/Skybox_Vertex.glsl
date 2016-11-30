#version 330 core

layout (location = 0) in vec3 in_position;

out vec3 TexCoords;

uniform mat4 VPMatrix;

void main(void)
{
    gl_Position = normalize(VPMatrix * vec4(in_position, 1.0));  
    TexCoords = gl_Position.xyz;
}
