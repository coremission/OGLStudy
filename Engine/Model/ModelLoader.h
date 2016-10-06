#ifndef MODELLOADER_h
#define MODELLOADER_h

#include "GameObject.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class ModelLoader
{
private:
	static void processNode(aiNode* node, const aiScene* scene);
public:
	static GameObject* loadModel(const std::string&);
};

#endif //MODELLOADER_h