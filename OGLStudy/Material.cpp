#include "Material.h"
#include "ShaderLoader.h"

Material::Material(std::string& materialName, std::string& vertexShaderPath, std::string& fragmentShaderPath):
	_materialName(materialName)
{
	_programId = ShaderLoader::CreateProgram(vertexShaderPath.c_str(), fragmentShaderPath.c_str());
}

Material::~Material()
{
}
