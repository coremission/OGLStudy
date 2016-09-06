#ifndef GAMEOBJECT_h
#define GAMEOBJECT_h

#include <Rendering/BaseRenderer.h>

#include <vector>
#include <glew/glew.h>
#include "Transform.h"
#include <string>
#include <memory>

class BaseRenderer;

class GameObject {
public:
	std::string name;
	std::shared_ptr<Transform> transform;
	BaseRenderer* renderer;

	GameObject();
	GameObject(const GameObject& m);
	~GameObject();
};

#endif // GAMEOBJECT_h