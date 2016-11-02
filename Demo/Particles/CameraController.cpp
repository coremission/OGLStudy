#include "CameraController.h"
#include <System/system.hpp>
#include <iostream>

using namespace glm;
using namespace std;

CameraController::CameraController(GameObject* game_object)
	: Component(game_object)
{
}

void CameraController::Start()
{
}

void CameraController::Update()
{
	constexpr float mouseSensX = 0.00001f;
	constexpr float mouseSensY = 0.00002f;

	if (Input::checkIfKeyPressed(KeyCodes::W)) {
		transform->setLocalPosition(transform->getLocalPosition() + vec3(0.0, 0.01f, 0.0));
	}
	if (Input::checkIfKeyPressed(KeyCodes::S)) {
		transform->setLocalPosition(transform->getLocalPosition() - vec3(0.0, 0.01f, 0.0));
	}
	
	auto mousePos = Input::getMousePosition() - vec2(Screen::width / 2.0f, Screen::height / 2.0f);

	Input::setMouseToCenter();

	cout << mousePos.x << ", " << mousePos.y << endl;

	this->transform->addLocalYawPitchRoll(glm::vec3(mousePos.x * mouseSensX, mousePos.y * mouseSensY, 0.0f));
}