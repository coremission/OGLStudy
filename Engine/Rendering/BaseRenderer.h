#ifndef BASERENDERER_h
#define BASERENDERER_h
#include <Model/GameObject.h>
#include "Material.h"
#include "Mesh.h"

#include <memory>

class GameObject;

class BaseRenderer
{
protected:
	const GameObject* const _gameObject;
public:
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Material> material;
	
	BaseRenderer(GameObject* gameObject, std::shared_ptr<Material>, std::shared_ptr<Mesh> mesh);
	virtual ~BaseRenderer();
	virtual void render() const;

	static std::unique_ptr<BaseRenderer> create(GameObject* gameObject, std::shared_ptr<Material> material, std::shared_ptr<Mesh> mesh);
};

#endif // BASERENDERER_h
