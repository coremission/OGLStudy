#ifndef BEHAVIOUR_h
#define BEHAVIOUR_h
#include "GameObject.h"

class GameObject;

class Behaviour
{
protected:
	GameObject* gameObject;
public:
	explicit Behaviour(GameObject*);
	virtual void Update();
	virtual ~Behaviour();
};

#endif BEHAVIOUR_h