#ifndef BASERENDERER_h
#define BASERENDERER_h
#include <Model/GameObject.h>
#include "Material.h"
#include <memory>

class GameObject;

class BaseRenderer
{
private:
	const GameObject * const _gameObject;

	BaseRenderer(GameObject* gameObject, std::shared_ptr<Material>);
public:
	std::shared_ptr<Material> material;
	
	virtual ~BaseRenderer();
	virtual void render() const;

	static BaseRenderer* createBaseRenderer(GameObject* gameObject, std::shared_ptr<Material> material);
};

#endif // BASERENDERER_h
