#include "MaterialManager.h"

std::shared_ptr<Material> MaterialManager::getMaterial(const std::string& materialName, const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	return std::make_shared<Material>(materialName, vertexShaderPath, fragmentShaderPath);
}
