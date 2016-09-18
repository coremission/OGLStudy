#include "Mesh.h"
#include <glew/glew.h>

Mesh::~Mesh() {
	// delete VAO and VBOs
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();
}

Mesh::Mesh(std::vector<VertexData> _vertices) 
	:vertices(_vertices)
{
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData),
		reinterpret_cast<void *>(offsetof(VertexData, VertexData::_position)));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData),
		reinterpret_cast<void *>(offsetof(VertexData, VertexData::_color)));	
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData),
		reinterpret_cast<void *>(offsetof(VertexData, VertexData::_color2)));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData),
		reinterpret_cast<void *>(offsetof(VertexData, VertexData::_uv)));
	glEnableVertexAttribArray(3);

	vbos.push_back(vbo);
}