#include "BrickBehaviour.h"

BrickBehaviour::BrickBehaviour(GameObject* game_object)
	:Component(game_object)
{
}

void BrickBehaviour::Start()
{
	gameObject->transform->setLocalScale(glm::vec3(0.05f, 0.05f, 1));
}

void BrickBehaviour::Update()
{
}

BrickBehaviour::~BrickBehaviour()
{
}
