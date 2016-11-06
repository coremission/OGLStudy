﻿#ifndef TEXTUREMANAGER_h
#define TEXTUREMANAGER_h

#include "Texture.h"
#include <string>
#include <memory>
#include <vector>

class TextureManager
{
public:
	static std::shared_ptr<Texture> getTexture(std::string fileName);
	static void loadPng(const std::string& filename, std::vector<unsigned char>& outBuffer, unsigned long& width, unsigned long& height);
};

#endif //TEXTUREMANAGER_h