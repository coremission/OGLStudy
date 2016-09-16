#ifndef TEXTUREMANAGER_h
#define TEXTUREMANAGER_h

#include "Texture.h"
#include <string>
#include <memory>

class TextureManager
{
public:
	static std::shared_ptr<Texture> getTexture(std::string fileName);
};

#endif //TEXTUREMANAGER_h