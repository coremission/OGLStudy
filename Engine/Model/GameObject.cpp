#include "GameObject.h"
#include "Component.h"

#include <iostream>
#include <memory>
#include "Scene.h"
#include <Application.h>

using namespace std;
// Model
GameObject::GameObject():
	transform(make_shared<Transform>()), renderer(nullptr)
{
	// fixme name
	Application::scene->AddModel("newGameObject", this);
}

GameObject::GameObject(const std::string& _name)
	: name(_name), transform(make_shared<Transform>()), renderer(nullptr)
{
	Application::scene->AddModel(name, this);
}

GameObject::GameObject(const GameObject & m):
	transform(m.transform), renderer(nullptr)
{
	std::cout << "gameObject copy constructor";
}

GameObject::~GameObject() {
	// must be deleted from scene here
	std::cout << "~gameObject.destructor " << name << endl;
	delete renderer;
}

void GameObject::Update()
{
	for (auto it = components.begin(); it != components.end(); ++it) {
		(*it)->Update();
	}
}

