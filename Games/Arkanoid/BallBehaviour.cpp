#include "BallBehaviour.h"
#include <iostream>
#include <System/system.hpp>

BallBehaviour::BallBehaviour(GameObject* _gameObject)
	:Component(_gameObject)
{
}

void BallBehaviour::Update()
{
	float time = Time::time;
	gameObject->transform->setLocalYawPitchRoll(glm::vec3(0, time, 0));

	if (Input::checkIfKeyPressed('w')) {
		std::cout << "w pressed" << std::endl;
		gameObject->transform->setLocalPosition(glm::vec3(0, 2*time, 0));
	}
	
	//gameObject->transform->setLocalScale(glm::vec3(time, time, time));
	//std::cout << "ball update" << std::endl;
}

void BallBehaviour::Start()
{
	gameObject->transform->setLocalScale(glm::vec3(0.05f, 0.05f, 1));
}
