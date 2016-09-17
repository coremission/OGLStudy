#version 330 core
layout (location = 0) out vec4 out_color;
in vec4 color;
in vec3 fragmentPosition;
in vec2 uv;

uniform sampler2D mySampler;

void main(void)
{
  vec4 textureColor = texture(mySampler, vec2(0.5, 0.5));
  vec4 out_color2 = textureColor + vec4(uv.x, uv.y, 0.1, 1);
  out_color = color;
}
