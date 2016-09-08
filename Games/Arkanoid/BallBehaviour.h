#ifndef BALLBEHAVIOUR_h
#define BALLBEHAVIOUR_h
#include <Model/Behaviour.h>

class BallBehaviour: public Behaviour
{
public:
	explicit BallBehaviour(GameObject*);
	virtual void Update() override;
	virtual void Start() override;
};

#endif // BALLBEHAVIOUR_h