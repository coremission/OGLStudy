#include "BallBehaviour.h"
#include <iostream>
#include <System/system.hpp>

BallBehaviour::BallBehaviour(GameObject* _gameObject)
	:Component(_gameObject),
	radius(0),
	velocity({0, 0})
{
}

void BallBehaviour::Update()
{
	gameObject->transform->setLocalPosition(position() + glm::vec3(velocity.x, velocity.y, 0));

	if (left() < -1 || right() > 1)
		velocity.x = -velocity.x;
	if (top() > 1 || bottom() < -1)
		velocity.y = -velocity.y;
}

void BallBehaviour::Start()
{
	velocity = { 0.0004f, 0.0006f };
	radius = 0.05;
	gameObject->transform->setLocalScale(glm::vec3(radius, radius, 1));
}

void BallBehaviour::negateVelocityY()
{
	velocity.y = -velocity.y;
}

void BallBehaviour::negateVelocityX()
{
	velocity.x = -velocity.x;
}
