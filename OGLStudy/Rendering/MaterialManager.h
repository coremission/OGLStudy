#ifndef MATERIALMANAGER_h
#define MATERIALMANAGER_h
#include "Material.h"
#include <memory>
class MaterialManager
{
public:
	static std::shared_ptr<Material> getMaterial(const std::string& materialName, const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
};

#endif // MATERIALMANAGER_h