#ifndef VERTEX_FORMAT_H
#define VERTEX_FORMAT_H

#include "Dependencies\glm\glm.hpp"

class VertexFormat
{
private:
	glm::vec3 _position;

public:
	VertexFormat(const glm::vec3 &position) {
		_position = position;
	}
	~VertexFormat();
};

#endif //VERTEX_FORMAT_H