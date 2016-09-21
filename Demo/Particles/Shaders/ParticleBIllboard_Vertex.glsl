#version 330 core

layout (location = 0) in vec4 in_position;
layout (location = 1) in float offset;

out vec4 color;

void main(void)
{	
	gl_Position = vec4(in_position.x + offset, in_position.y, in_position.z, in_position.w);
	color = vec4(1, 0, offset, 1);
}
