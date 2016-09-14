#include "Component.h"

Component::Component(GameObject* _gameObject):
	gameObject(_gameObject), transform(_gameObject->transform.get())
{
}

void Component::Start()
{
}

void Component::Update()
{
}

Component::~Component()
{
}
