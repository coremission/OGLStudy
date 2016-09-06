#ifndef MESH_h
#define MESH_h
#include <vector>
#include <Model/VertexData.h>
#include <glew/glew.h>

class Mesh
{
private:
	std::vector<VertexData> vertices;
	std::vector<GLuint> vbos;
public:
	GLuint vao;
	Mesh(std::vector<VertexData>);
	~Mesh();
};

#endif MESH_h