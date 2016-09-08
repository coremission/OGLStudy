#ifndef GAMEOBJECT_h
#define GAMEOBJECT_h

#include <Rendering/BaseRenderer.h>
#include "Component.h"
#include "Transform.h"

#include <vector>
#include <string>
#include <memory>

class BaseRenderer;
class Component;

class GameObject {
private:
	std::vector<std::unique_ptr<Component>> components;
public:
	std::string name;
	std::shared_ptr<Transform> transform;
	BaseRenderer* renderer;

	GameObject();
	GameObject(const GameObject& m);
	~GameObject();
	void Update();
	void AddComponent(std::unique_ptr<Component>);
};

#endif // GAMEOBJECT_h