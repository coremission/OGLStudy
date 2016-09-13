#ifndef MATERIALMANAGER_h
#define MATERIALMANAGER_h
#include "Material.h"
#include <memory>
#include <map>
class MaterialManager
{
private:
	static std::map<std::string, std::shared_ptr<Material> > materials;
public:
	static std::shared_ptr<Material> getMaterial(const std::string& materialName, const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	static std::shared_ptr<Material> getDefaultSpriteMaterial();
};

#endif // MATERIALMANAGER_h