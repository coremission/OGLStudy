#ifndef VERTEX_FORMAT_H
#define VERTEX_FORMAT_H

#include "Dependencies\glm\glm.hpp"

class VertexFormat
{
private:
	glm::vec3 _position;
	glm::vec4 _color;
public:
	VertexFormat(const glm::vec3 &position, const glm::vec4 &color) {
		_position = position;
		_color = color;
	}
	~VertexFormat();
};

#endif //VERTEX_FORMAT_H