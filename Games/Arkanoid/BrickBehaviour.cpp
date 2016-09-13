#include "BrickBehaviour.h"

BrickBehaviour::BrickBehaviour(GameObject* game_object)
	:Component(game_object)
{
}

void BrickBehaviour::Start()
{
	halfWidth = 0.1;
	halfHeight = 0.1f;
	gameObject->transform->setLocalScale(glm::vec3(halfWidth, halfHeight, 1));
}

void BrickBehaviour::Update()
{
}

BrickBehaviour::~BrickBehaviour()
{
}
