#include "MaterialManager.h"

constexpr char * DEFAULT_SPRITE_MATERIAL = "simple_sprite_material";

// static field declaration
std::map<std::string, std::shared_ptr<Material> > MaterialManager::materials;

std::shared_ptr<Material> MaterialManager::getMaterial(const std::string& materialName, const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	bool quadMeshCreated = materials.find(materialName) != materials.end();
	if (quadMeshCreated)
		return materials[materialName];

	auto sharedMaterial = std::make_shared<Material>(materialName, vertexShaderPath, fragmentShaderPath);
	materials[materialName] = sharedMaterial;
	return sharedMaterial;
}

std::shared_ptr<Material> MaterialManager::getDefaultSpriteMaterial()
{
	return MaterialManager::getMaterial(DEFAULT_SPRITE_MATERIAL, "Shaders\\Vertex.glsl", "Shaders\\Fragment.glsl");
}
