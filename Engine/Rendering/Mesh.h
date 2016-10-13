#ifndef MESH_h
#define MESH_h
#include <vector>
#include <Model/VertexData.h>
#include <glew/glew.h>

class Mesh
{
private:
	bool indexedMesh;
	std::vector<VertexData> vertices;
	std::vector<GLuint> indices;
	GLuint vbo;
	GLuint indicesVbo;

	void fillVertexBuffer();
	void fillIndicesBuffer();
public:
	GLuint vao;
	Mesh(std::vector<VertexData>);
	Mesh(std::vector<VertexData>, std::vector<GLuint>);
	~Mesh();
	int verticesCount() const { return vertices.size(); }
	int indicesCount() const { return indices.size(); }
	bool isIndexed() const { return indexedMesh; }
};

#endif MESH_h