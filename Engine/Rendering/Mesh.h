#ifndef MESH_h
#define MESH_h
#include <vector>
#include <Model/VertexData.h>
#include <glew/glew.h>

class LegacyMesh
{
private:
	bool indexedMesh;
	std::vector<VertexData> vertices;
	std::vector<GLuint> indices;
	GLuint vbo;
	GLuint indicesVbo;

	void fillVertexBuffer();
	void fillIndicesBuffer();
	
	static void bindAttribute(GLuint location, size_t size, int type, bool doNormalize, void* offset);
public:
	GLuint vao;
	LegacyMesh(std::vector<VertexData>);
	LegacyMesh(std::vector<VertexData>, std::vector<GLuint>);
	~LegacyMesh();
	int verticesCount() const { return vertices.size(); }
	int indicesCount() const { return indices.size(); }
	bool isIndexed() const { return indexedMesh; }
};

#endif MESH_h
