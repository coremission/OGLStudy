#ifndef SPRITERENDERER_h
#define SPRITERENDERER_h
#include "BaseRenderer.h"
#include <Model/GameObject.h>

#include <memory>

class GameObject;
class SpriteRenderer: public BaseRenderer
{
public:
	SpriteRenderer(GameObject*);
	virtual ~SpriteRenderer() override;

	static std::unique_ptr<SpriteRenderer> create(GameObject*, const std::string&);
};

#endif //SPRITERENDERER_h