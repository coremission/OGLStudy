#ifndef SPRITERENDERER_h
#define SPRITERENDERER_h
#include "BaseRenderer.h"
#include <Model/GameObject.h>

class GameObject;
class SpriteRenderer: public BaseRenderer
{
public:
	SpriteRenderer(GameObject*);
	virtual ~SpriteRenderer();

	static SpriteRenderer* create(GameObject*, const std::string&);
};

#endif //SPRITERENDERER_h