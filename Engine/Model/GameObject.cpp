#include "GameObject.h"
#include <iostream>
#include <memory>

using namespace std;
// Model
GameObject::GameObject():
	transform(make_shared<Transform>())
{
}

GameObject::GameObject(const GameObject & m):
	transform(m.transform)
{
	std::cout << "gameObject copy constructor";
}

GameObject::~GameObject() {
	std::cout << "~ gameObject.destructor";
}
