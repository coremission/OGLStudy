#include "GameObject.h"
#include <iostream>

// Model
GameObject::GameObject():
	vao(0), transform(Transform())
{
}

GameObject::GameObject(const GameObject & m):
	vao(m.vao),
	transform(m.transform)
{
	std::cout << "model copy constructor";
}

GameObject::~GameObject() {
	std::cout << "~ gameObject.destructor";
}
