#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include <iostream>
#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"

namespace Core
{
	class ShaderLoader
	{
	private:
		std::string ReadShader(char *filename);
		GLuint CreateShader(GLenum shaderType, std::string source, char *shaderName);
	public:
		ShaderLoader();
		~ShaderLoader();
		GLuint CreateProgram(char * vertexShaderFilename, char * fragmentShaderFilename);
	};
}
#endif // SHADERLOADER_H