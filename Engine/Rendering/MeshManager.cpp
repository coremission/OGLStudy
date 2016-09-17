#include "MeshManager.h"

#include <glm/glm.hpp>

using namespace std;
using namespace glm;

constexpr char * const QUAD_MESH_ID = "rudy_quad";

std::map<std::string, std::shared_ptr<Mesh>> MeshManager::meshMap;

shared_ptr<Mesh> MeshManager::registerMesh(std::string id, std::vector<VertexData> vertices)
{
	auto mesh = make_shared<Mesh>(vertices);
	meshMap[id] = mesh;
	return mesh;
}

shared_ptr<Mesh> MeshManager::getQuadMesh()
{
	bool quadMeshCreated = meshMap.find(QUAD_MESH_ID) != meshMap.end();
	if (quadMeshCreated)
		return meshMap[QUAD_MESH_ID];

	vector<VertexData> vertices;
	vertices.push_back(VertexData(vec3(-1, -1, 0.0), vec4(0.0f, 1.0f, 0.0f, 1.0f), vec2(0, 0)));
	vertices.push_back(VertexData(vec3(-1, 1, 0.0), vec4(1.0f, 0.0f, 0.0f, 1.0f), vec2(0, 1)));
	vertices.push_back(VertexData(vec3(1, -1, 0.0), vec4(0.0f, 0.0f, 1.0f, 1.0f), vec2(1, 0)));

	vertices.push_back(VertexData(vec3(-1, 1, 0.0), vec4(1.0, 0, 0, 1.0), vec2(0, 1)));
	vertices.push_back(VertexData(vec3(1, 1, 0.0), vec4(1.0, 0, 0, 1.0), vec2(1, 1)));
	vertices.push_back(VertexData(vec3(1, -1, 0.0), vec4(0, 0, 1.0, 1), vec2(1, 0)));

	return registerMesh(QUAD_MESH_ID, vertices);
}
