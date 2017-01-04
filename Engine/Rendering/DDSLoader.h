#pragma once
#include <string>
#include <glew/glew.h>

class DDSLoader
{
public:
	GLuint loadDDSTexture(const std::string& filename);
};
