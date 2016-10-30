#include "CameraController.h"
#include <System/Input.h>

using namespace glm;

CameraController::CameraController(GameObject* game_object)
	: Component(game_object)
{
}

void CameraController::Start()
{
}

void CameraController::Update()
{
	if (Input::checkIfKeyPressed(KeyCodes::W)) {
		transform->setLocalPosition(transform->getLocalPosition() + vec3(0.0, 0.01f, 0.0));
	}
	if (Input::checkIfKeyPressed(KeyCodes::S)) {
		transform->setLocalPosition(transform->getLocalPosition() - vec3(0.0, 0.01f, 0.0));
	}
}