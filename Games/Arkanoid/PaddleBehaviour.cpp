#include "PaddleBehaviour.h"

PaddleBehaviour::PaddleBehaviour(GameObject* go)
	:Component(go),
	halfWidth(0),
	halfHeight(0), 
	ball(nullptr)
{
}

void PaddleBehaviour::Start()
{
	halfWidth = 0.2;
	halfHeight = 0.1f;
	gameObject->transform->setLocalScale(glm::vec3(halfWidth, halfHeight, 1));
}

void PaddleBehaviour::Update()
{
}

void PaddleBehaviour::setUpBall(std::shared_ptr<BallBehaviour> _ball)
{
	ball = _ball;
}

PaddleBehaviour::~PaddleBehaviour()
{
}
