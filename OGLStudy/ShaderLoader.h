#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include <iostream>
#include "Dependencies/glew/glew.h"

class ShaderLoader
{
private:
	static std::string ReadShader(const char *filename);
	static GLuint CreateShader(GLenum shaderType, std::string& source, const char *shaderName);
public:
	static GLuint CreateProgram(const char * vertexShaderFilename, const char * fragmentShaderFilename);
};
#endif // SHADERLOADER_H