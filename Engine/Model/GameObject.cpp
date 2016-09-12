#include "GameObject.h"
#include "Component.h"

#include <iostream>
#include <memory>

using namespace std;
// Model
GameObject::GameObject():
	transform(make_shared<Transform>()), renderer(nullptr)
{
}

GameObject::GameObject(const std::string& _name)
	: name(_name), transform(make_shared<Transform>()), renderer(nullptr)
{
}

GameObject::GameObject(const GameObject & m):
	transform(m.transform), renderer(nullptr)
{
	std::cout << "gameObject copy constructor";
}

GameObject::~GameObject() {
	std::cout << "~gameObject.destructor " << name << endl;
}

void GameObject::Update()
{
	for (auto it = components.begin(); it != components.end(); ++it) {
		(*it)->Update();
	}
}

