#include "GameObject.h"
#include <iostream>

// Model
GameObject::GameObject() : vao(0)
{
}

GameObject::GameObject(const GameObject & m) : vao(m.vao)
{
	std::cout << "model copy constructor";
}

GameObject::~GameObject() {
	std::cout << "~ gameObject.destructor";
}
