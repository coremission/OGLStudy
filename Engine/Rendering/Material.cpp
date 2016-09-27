#include "Material.h"
#include "ShaderLoader.h"
#include <iostream>

Material::Material(const std::string& materialName, const std::string& vertexShaderPath, const std::string& fragmentShaderPath):
	_materialName(materialName), _programId(ShaderLoader::CreateProgram(vertexShaderPath.c_str(), fragmentShaderPath.c_str()))
{
	int count = 0;
	int bufSize = 0;
	int length = 100;
	int size = 100;
	GLuint type = 0;
	char name[100];
	GLuint uniformLocation = 0;

	glGetProgramiv(_programId, GL_ACTIVE_UNIFORMS, &count);
	printf("Active Uniforms: %d\n", count);

	for (int i = 0; i < count; i++)
	{
		glGetActiveUniform(_programId, uniformLocation, bufSize, &length, &size, &type, name);
		_uniformsMap.insert(std::make_pair(std::string(name), uniformLocation));
		
		printf("Uniform #%d Type: %u Name: %s\n", i, type, name);
	}
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
