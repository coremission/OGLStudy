#include "TextureManager.h"
#include <Dependencies/lodepng/picopng.h>

#include <vector>
#include <System/IOManager.h>
#include <glew/glew.h>
#include <memory>

std::shared_ptr<Texture> TextureManager::getTexture(std::string fileName)
{
	auto result = std::make_shared<Texture>();
	std::vector<unsigned char> outBuffer;

	// read png to buffer
	std::vector<unsigned char> inBufferVector;
	bool fileReadStatus = IOManager::readBinaryFileToBuffer(fileName, inBufferVector);
	if (!fileReadStatus)
		throw std::runtime_error("Can't read png file: " + fileName);

	decodePNG(outBuffer, result->width, result->height, &inBufferVector[0], inBufferVector.size());
	
	glGenTextures(1, &result->id);
	glBindTexture(GL_TEXTURE_2D, result->id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, result->width, result->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &outBuffer[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
	return result;
}

void TextureManager::loadPng(const std::string& filename, std::vector<unsigned char>& outBuffer, unsigned long& width, unsigned long& height)
{
	// read png to buffer
	std::vector<unsigned char> inBufferVector;
	bool fileReadStatus = IOManager::readBinaryFileToBuffer(filename, inBufferVector);
	if (!fileReadStatus)
		throw std::runtime_error("Can't read png file: " + filename);

	decodePNG(outBuffer, width, height, &inBufferVector[0], inBufferVector.size());
}
