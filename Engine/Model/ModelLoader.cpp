#include "ModelLoader.h"

#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <Rendering/Texture.h>
#include <Rendering/MeshManager.h>
#include <Rendering/MaterialManager.h>

using namespace std;

GameObject* ModelLoader::LoadModel(const string& name, const std::string& path)
{
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
		cout << "ERROR::ASSIMP::" << import.GetErrorString() << endl;
		return nullptr;
	}

	auto gameObject = new GameObject(name);
	processNode(gameObject, scene->mRootNode, scene);
	
	return gameObject;
}

shared_ptr<Material> ModelLoader::processMaterial()
{
	return MaterialManager::getMaterial("temp_888", "Shaders\\Diffuse.glsl", "Shaders\\Fragment.glsl");
}

void ModelLoader::processNode(GameObject* parent, aiNode* node, const aiScene* scene)
{
	// Process all the node's meshes (if any)
	for (GLuint i = 0; i < node->mNumMeshes; i++) 	{
		aiMesh* mesh_ = scene->mMeshes[node->mMeshes[i]];
		auto mesh = processMesh(mesh_, scene);

		auto gameObject = new GameObject(parent->name + "_temp");
		auto material = processMaterial();
		gameObject->renderer = BaseRenderer::create(gameObject, material, mesh);
		//this->meshes.push_back(this->processMesh(mesh, scene));
	}


	// Then do the same for each of its children
	for (GLuint i = 0; i < node->mNumChildren; i++) {
		ModelLoader::processNode(parent, node->mChildren[i], scene);
	}
}

shared_ptr<Mesh> ModelLoader::processMesh(aiMesh* aiMesh_, const aiScene* scene)
{
	vector<VertexData> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	for (GLuint i = 0; i < aiMesh_->mNumVertices; ++i) {
		VertexData vertex{
			// positions
			glm::vec3{aiMesh_->mVertices[i].x, aiMesh_->mVertices[i].y, aiMesh_->mVertices[i].z},
			// colours
			glm::vec4{},
			// texture coordinates (uvs)
			glm::vec2{0.0f, 0.0f}
		};
		vertices.push_back(vertex);
	}
	// Process indices
	
	// Process material
	if (aiMesh_->mMaterialIndex >= 0) {
	}

	return MeshManager::registerMesh("rand888", vertices);
}