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
	constexpr float mouseSensX = 0.0001f;
	constexpr float mouseSensY = 0.0001f;

	if (Input::checkIfKeyPressed(KeyCodes::D)) {
		transform->addLocalYawPitchRoll(vec3(0.0f, 0.0f, 0.01f));
	}
	if (Input::checkIfKeyPressed(KeyCodes::A)) {
		transform->addLocalYawPitchRoll(vec3(0.0f, 0.0f, -0.01f));
	}
	if (Input::checkIfKeyPressed(KeyCodes::W)) {
		transform->addLocalYawPitchRoll(vec3(0.01f, 0.0f, 0.0));
	}
	if (Input::checkIfKeyPressed(KeyCodes::S)) {
		transform->addLocalYawPitchRoll(vec3(-0.01f, 0.0f, 0.0));
	}

	//auto mousePos = Input::getMousePosition() - vec2(Screen::width / 2.0f, Screen::height / 2.0f);

	Input::setMouseToCenter();

	//cout << mousePos.x << ", " << mousePos.y << endl;

	//this->transform->addLocalYawPitchRoll(vec3(mousePos.y * mouseSensY, 0.0f, mousePos.x * mouseSensX));
}