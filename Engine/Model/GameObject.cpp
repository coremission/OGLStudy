#include "GameObject.h"
#include "Behaviour.h"

#include <iostream>
#include <memory>

using namespace std;
// Model
GameObject::GameObject():
	transform(make_shared<Transform>()), renderer(nullptr)
{
}

GameObject::GameObject(const GameObject & m):
	transform(m.transform), renderer(nullptr)
{
	std::cout << "gameObject copy constructor";
}

GameObject::~GameObject() {
	std::cout << "~ gameObject.destructor";
}

void GameObject::Update()
{
	for (auto it = components.begin(); it != components.end(); ++it) {
		(*it)->Update();
	}
}

void GameObject::AddComponent(unique_ptr<Behaviour> _component)
{
	_component->Start();
	components.push_back(move(_component));
}
