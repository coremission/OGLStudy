#include "GameObject.h"
#include <iostream>

// Model
GameObject::GameObject() : vao(0), material(nullptr)
{
}

GameObject::GameObject(const GameObject & m) : vao(m.vao), material(m.material)
{
	std::cout << "model copy constructor";
}

GameObject::~GameObject() {
	std::cout << "model destuctor";
}
