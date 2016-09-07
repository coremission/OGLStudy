#ifndef GAMEOBJECT_h
#define GAMEOBJECT_h

#include <Rendering/BaseRenderer.h>
#include "Behaviour.h"
#include "Transform.h"

#include <vector>
#include <glew/glew.h>
#include <string>
#include <memory>

class BaseRenderer;
class Behaviour;

class GameObject {
private:
	std::vector<std::unique_ptr<Behaviour>> components;
public:
	std::string name;
	std::shared_ptr<Transform> transform;
	BaseRenderer* renderer;

	GameObject();
	GameObject(const GameObject& m);
	~GameObject();
	void Update();
	void AddComponent(std::unique_ptr<Behaviour>);
};

#endif // GAMEOBJECT_h