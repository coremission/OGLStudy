#include "Controller.h"
#include <Model/Component.h>
#include "BrickBehaviour.h"
#include <Rendering/SpriteRenderer.h>

#include <cmath>

constexpr float diff = 0.0001f;

Controller::Controller(GameObject* go, BallBehaviour* _ball):
	Component(go),
	ball(_ball)
{

}

void Controller::Update()
{
	bool velocityWasChanged = false;
	// check collisions
	for (auto brick : bricks) {
		glm::vec3 distance = ball->position() - brick->position();
		// from above/below
		if ((abs(distance.y) < ball->radius + brick->halfHeight) &&
			((ball->right() < brick->right() && ball->right() > brick->left()) ||
			(ball->left() > brick->left() && ball->left() < brick->right()) &&
			(ball->top() > brick->top() || ball->bottom() < brick->bottom())
				)) {
			ball->negateVelocityY();
			continue;
		}
		// from side
		if ((abs(distance.x) < ball->radius + brick->halfWidth) &&
			((ball->bottom() > brick->bottom() && ball->bottom() < brick->top()) ||
			 (ball->top() < brick->top() && ball->top() > brick->bottom())
			)) {
			ball->negateVelocityX();
			continue;
		}
	}
}

void Controller::Start()
{
	glm::vec3 start(-0.8f, 0.7f, 0);
	glm::vec3 offset(0.3f, -0.6f, 0);
	float halfWidth = 0.1f;
	float halfHeight = 0.1f;

	for(int i = 0; i < 2; ++i) {
		for (int j = 0; j < 6; ++j) {
			GameObject* brick = new GameObject("brick" + std::to_string(i) + std::to_string(j));
			BrickBehaviour* brickBehaviour = new BrickBehaviour(brick);
			brickBehaviour->setHalfSize(halfWidth, halfHeight);
			brick->transform->setLocalPosition(start + glm::vec3(offset.x * j, offset.y * i, start.z));
			brick->AddComponent(brickBehaviour);
			brick->renderer = SpriteRenderer::create(brick, "some_sprite_name");
			bricks.push_back(brickBehaviour);
		}
	}
}

Controller::~Controller() {

}
