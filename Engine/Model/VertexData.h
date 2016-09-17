#ifndef VERTEX_DATA_H
#define VERTEX_DATA_H

#include <glm/glm.hpp>

class VertexData
{
public:
	glm::vec3 _position;
	glm::vec4 _color;
	glm::vec2 _uv;

	VertexData(const glm::vec3 &position, const glm::vec4 &color, glm::vec2 uv):
		_position(position),
		_color(color),
		_uv(_uv)
	{}

	~VertexData();
};

#endif //VERTEX_DATA_H