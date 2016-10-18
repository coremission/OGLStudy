#include "MeshManager.h"

#include <glm/glm.hpp>

using namespace std;
using namespace glm;

constexpr char * const QUAD_MESH_ID = "rudy_quad";
constexpr char * const INDEXED_CUBE_MESH_ID = "indexed_qube_mesh";

std::map<std::string, std::shared_ptr<Mesh>> MeshManager::meshMap;

shared_ptr<Mesh> MeshManager::registerMesh(std::string id, vector<VertexData> vertices)
{
	auto mesh = make_shared<Mesh>(vertices);
	meshMap[id] = mesh;
	return mesh;
}

std::shared_ptr<Mesh> MeshManager::registerMesh(std::string id, std::vector<VertexData> vertices, std::vector<GLuint> indices)
{
	auto mesh = make_shared<Mesh>(vertices, indices);
	meshMap[id] = mesh;
	return mesh;
}

shared_ptr<Mesh> MeshManager::getQuadMesh()
{
	bool quadMeshCreated = meshMap.find(QUAD_MESH_ID) != meshMap.end();
	if (quadMeshCreated)
		return meshMap[QUAD_MESH_ID];

	auto lb = VertexData{ vec3(-1.0f, -1.0f, 0.0f), vec4(0.0f, 1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f) };
	auto lt = VertexData{ vec3(-1.0f,  1.0f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f) };
	auto br = VertexData{ vec3( 1.0f, -1.0f, 0.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f), vec2(1.0f, 0.0f) };
	auto tr = VertexData{ vec3( 1.0f,  1.0f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f) };

	vector<VertexData> vertices;
	vertices.push_back(lb);
	vertices.push_back(lt);
	vertices.push_back(br);

	vertices.push_back(lt);
	vertices.push_back(tr);
	vertices.push_back(br);

	return registerMesh(QUAD_MESH_ID, vertices);
}

std::shared_ptr<Mesh> MeshManager::getCubeMesh()
{
	bool meshCreated = meshMap.find(INDEXED_CUBE_MESH_ID) != meshMap.end();
	if (meshCreated)
		return meshMap[INDEXED_CUBE_MESH_ID];

	auto lb = VertexData{ vec3(-1.0f, -1.0f, 0.0f), vec4(0.0f, 1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f) };
	auto lt = VertexData{ vec3(-1.0f,  1.0f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f) };
	auto br = VertexData{ vec3( 1.0f, -1.0f, 0.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f), vec2(1.0f, 0.0f) };
	auto tr = VertexData{ vec3( 1.0f,  1.0f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f) };

	auto lb1 = VertexData{ vec3(-1.0f, -1.0f, 1.0f), vec4(0.0f, 1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f) };
	auto lt1 = VertexData{ vec3(-1.0f,  1.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f) };
	auto br1 = VertexData{ vec3( 1.0f, -1.0f, 1.0f), vec4(0.0f, 0.0f, 1.0f, 1.0f), vec2(1.0f, 0.0f) };
	auto tr1 = VertexData{ vec3( 1.0f,  1.0f, 1.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f) };

	vector<VertexData> vertices {lb, lt, br, tr, lb1, lt1, br1, tr1};
	
	vector<GLuint> indices{ 2, 1, 0,
							1, 4, 3,
							5, 6, 7
						  };
	
	return registerMesh(QUAD_MESH_ID, vertices, indices);
}
