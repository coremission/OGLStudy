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
	template<typename T> void AddComponent();
};

template<typename T> void GameObject::AddComponent() {
	auto component = make_unique<T>(this);
	component->Start();
	components.push_back(move(component));
}
#endif // GAMEOBJECT_h