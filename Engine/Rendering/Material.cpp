#include "Material.h"
#include "ShaderLoader.h"
#include <iostream>

Material::Material(const std::string& materialName, const std::string& vertexShaderPath, const std::string& fragmentShaderPath):
	_materialName(materialName)
{
	_programId = ShaderLoader::CreateProgram(vertexShaderPath.c_str(), fragmentShaderPath.c_str());
}

Material::~Material()
{
	std::cout << "~material.destructor " << _materialName << std::endl;
	glDeleteProgram(_programId);
}

GLuint Material::programId() const
{
	return _programId;
}
