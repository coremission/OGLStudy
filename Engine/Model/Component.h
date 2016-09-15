#ifndef BEHAVIOUR_h
#define BEHAVIOUR_h

class GameObject;
class Transform;

class Component
{
public:
	const GameObject * const gameObject;
	const Transform * const transform;
public:
	explicit Component(GameObject*);
	virtual void Start();
	virtual void Update();
	virtual ~Component();
private:
	void operator=(const Component&);
};

#endif BEHAVIOUR_h