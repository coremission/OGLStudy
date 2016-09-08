#ifndef BEHAVIOUR_h
#define BEHAVIOUR_h
#include "GameObject.h"

class GameObject;

class Component
{
protected:
	GameObject* gameObject;
public:
	explicit Component(GameObject*);
	virtual void Start();
	virtual void Update();
	virtual ~Component();
};

#endif BEHAVIOUR_h