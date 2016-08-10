#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <glew/glew.h>

class Material
{
private:
	GLuint _programId;
	std::string _materialName;
public:
	explicit Material(std::string &materialName, std::string &vertexShaderPath, std::string &fragmentShaderPath);
	~Material();
};
#endif // MATERIAL_H