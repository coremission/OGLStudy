#ifndef VERTEX_DATA_H
#define VERTEX_DATA_H

#include <glm/glm.hpp>

class VertexData
{
public:
	glm::vec3 _position;
	glm::vec4 _color;

	VertexData(const glm::vec3 &position, const glm::vec4 &color) {
		_position = position;
		_color = color;
	}
	~VertexData();
};

#endif //VERTEX_DATA_H