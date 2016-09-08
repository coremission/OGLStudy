#ifndef BALLBEHAVIOUR_h
#define BALLBEHAVIOUR_h
#include <Model/Component.h>

class BallBehaviour: public Component
{
public:
	explicit BallBehaviour(GameObject*);
	virtual void Update() override;
	virtual void Start() override;
};

#endif // BALLBEHAVIOUR_h