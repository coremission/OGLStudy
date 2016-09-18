#ifndef VERTEX_DATA_H
#define VERTEX_DATA_H

#include <glm/glm.hpp>

struct VertexData
{
	glm::vec3 _position;
	glm::vec4 _color;
	glm::vec4 _color2;
	glm::vec2 _uv;

	VertexData() = default;
	~VertexData();
};

#endif //VERTEX_DATA_H