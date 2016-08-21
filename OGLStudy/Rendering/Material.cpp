#include "Material.h"
#include "ShaderLoader.h"

Material::Material(const std::string& materialName, const std::string& vertexShaderPath, const std::string& fragmentShaderPath):
	_materialName(materialName)
{
	_programId = ShaderLoader::CreateProgram(vertexShaderPath.c_str(), fragmentShaderPath.c_str());
}

Material::~Material()
{
	glDeleteProgram(_programId);
}

GLuint Material::programId() const
{
	return _programId;
}
