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
	return MaterialManager::getMaterial("temp_888", "Shaders\\Diffuse_Vertex.glsl", "Shaders\\Diffuse_Fragment.glsl");
}

void ModelLoader::processNode(GameObject* parent, aiNode* node, const aiScene* scene)
{
	// Process meshes
	for (GLuint i = 0; i < node->mNumMeshes; i++) 	{
		aiMesh* mesh_ = scene->mMeshes[node->mMeshes[i]];
		auto mesh = processMesh(mesh_, scene);

		auto gameObject = new GameObject(std::string(node->mName.C_Str()));
		gameObject->transform->setParent(parent->transform.get());

		auto material = processMaterial();
		gameObject->renderer = BaseRenderer::create(gameObject, material, mesh);
		//this->meshes.push_back(this->processMesh(mesh, scene));
	}

	// Recursively process child nodes
	for (GLuint i = 0; i < node->mNumChildren; i++) {
		ModelLoader::processNode(parent, node->mChildren[i], scene);
	}
}

shared_ptr<Mesh> ModelLoader::processMesh(aiMesh* aiMesh_, const aiScene* scene)
{
	vector<VertexData> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	// Process vertex data
	for (GLuint i = 0; i < aiMesh_->mNumVertices; ++i) {
		VertexData vertex{
			// position
			glm::vec3{aiMesh_->mVertices[i].x, aiMesh_->mVertices[i].y, aiMesh_->mVertices[i].z},
			// colour
			glm::vec4{1.0f, 1.0f, 1.0f, 1.0f},
			// texture coordinates (uvs)
			//glm::vec2{aiMesh_->mTextureCoords[i][0].x, aiMesh_->mTextureCoords[i][0].y}
		};
		// normal
		if(aiMesh_->mNormals != nullptr)
			vertex._normal = glm::vec3{ aiMesh_->mNormals[i].x, aiMesh_->mNormals[i].y, aiMesh_->mNormals[i].z };
		
		vertices.push_back(vertex);
	}
	// Process indices
	for (GLuint i = 0; i < aiMesh_->mNumFaces; ++i) {
		aiFace face = aiMesh_->mFaces[i];
		for (GLuint j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	// Process material
	if (aiMesh_->mMaterialIndex >= 0) {
	}

	return MeshManager::registerMesh("rand888", vertices, indices);
}