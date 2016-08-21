#ifndef BASERENDERER_h
#define BASERENDERER_h
#include <Model/GameObject.h>
#include "Material.h"
#include <memory>

class GameObject;

class BaseRenderer
{
private:
	const GameObject* _gameObject;
	const GLuint vao;

	BaseRenderer(GLuint vao, std::shared_ptr<Material>);
public:
	std::shared_ptr<Material> material;
	
	virtual ~BaseRenderer();
	virtual void render() const;

	static BaseRenderer* createBaseRenderer(GLuint vao, std::shared_ptr<Material> material);
};

#endif // BASERENDERER_h
