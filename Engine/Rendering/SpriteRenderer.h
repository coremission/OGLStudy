#ifndef SPRITERENDERER_h
#define SPRITERENDERER_h
#include "BaseRenderer.h"
#include <Model/GameObject.h>
#include "Sprite.h"

#include <memory>

class GameObject;
class SpriteRenderer: public BaseRenderer
{
private:
	std::unique_ptr<Sprite> sprite;
public:
	SpriteRenderer(GameObject*, std::shared_ptr<Texture>);
	virtual void render() const override;
	virtual ~SpriteRenderer() override;
	static std::unique_ptr<SpriteRenderer> create(GameObject*, const std::string&);
};

#endif //SPRITERENDERER_h