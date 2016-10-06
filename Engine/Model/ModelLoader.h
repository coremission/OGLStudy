﻿#ifndef MODELLOADER_h
#define MODELLOADER_h

#include "GameObject.h"
#include <assimp/scene.h>

#include <memory>

class ModelLoader
{
private:
	static void processNode(GameObject*, aiNode* node, const aiScene* scene);
	static std::shared_ptr<Mesh> processMesh(aiMesh* mesh, const aiScene* scene);
	static std::shared_ptr<Material> processMaterial();
public:
	static GameObject* LoadModel(const std::string&, const std::string&);
};

#endif //MODELLOADER_h