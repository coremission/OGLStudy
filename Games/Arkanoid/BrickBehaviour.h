#ifndef BRICKBEHAVIOUR_h
#define BRICKBEHAVIOUR_h
#include <Model/Component.h>

class BrickBehaviour: public Component
{
public:
	explicit BrickBehaviour(GameObject* game_object);
	void Start() override;
	void Update() override;
	~BrickBehaviour() override;
};

#endif //BRICKBEHAVIOUR_h