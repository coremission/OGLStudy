#ifndef MATERIAL_H
#define MATERIAL_H

#include <glew/glew.h>
#include <string>
#include <map>

class Material
{
private:
	GLuint _programId;
	std::string _materialName;
	std::map<std::string, GLuint> _uniformsMap;
public:
	~Material();
	GLuint programId() const;
	Material(const std::string &materialName, const std::string &vertexShaderPath, const std::string &fragmentShaderPath);
};
#endif // MATERIAL_H