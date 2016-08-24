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
	~Material();
	GLuint programId() const;
	explicit Material(const std::string &materialName, const std::string &vertexShaderPath, const std::string &fragmentShaderPath);
};
#endif // MATERIAL_H