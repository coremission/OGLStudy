#include "Mesh.h"
#include <glew/glew.h>

Mesh::~Mesh() {
	// delete VAO and VBOs
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

void Mesh::fillVertexBuffer()
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData),
		reinterpret_cast<void *>(offsetof(VertexData, VertexData::_position)));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData),
		reinterpret_cast<void *>(offsetof(VertexData, VertexData::_color)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData),
		reinterpret_cast<void *>(offsetof(VertexData, VertexData::_uv)));
	glEnableVertexAttribArray(2);
}

void Mesh::fillIndicesBuffer()
{
	glGenBuffers(1, &indicesVbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesVbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
}

Mesh::Mesh(std::vector<VertexData> _vertices) 
	:indexedMesh(false), vertices(_vertices)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	fillVertexBuffer();

	glBindVertexArray(0);
}


Mesh::Mesh(std::vector<VertexData> _vertices, std::vector<GLuint> _indices)
	:indexedMesh(true), vertices(_vertices), indices(_indices)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	fillVertexBuffer();
	fillIndicesBuffer();

	glBindVertexArray(0);
}
