#include "Controller.h"
#include <Model/Component.h>
#include "BrickBehaviour.h"
#include <Rendering/SpriteRenderer.h>

Controller::Controller(GameObject* go, BallBehaviour* _ball):
	Component(go),
	ball(_ball)
{

}

void Controller::Update()
{
	// check collisions
	for (auto brick : bricks) {
		// from above
		if (ball->top() > brick->top() && ball->bottom() < brick->top() &&
			 (ball->right() > brick->left() || ball->left() < brick->right())) {
			ball->negateVelocityY();
			break;
		}
		// from below
		if (ball->bottom() < brick->bottom() && ball->top() > brick->bottom() &&
			(ball->right() > brick->left() || ball->left() < brick->right())) {
			ball->negateVelocityY();
			break;
		}
		// from right
		if (ball->right() > brick->right() && ball->left() < brick->right() &&
			(true)) {
			ball->negateVelocityX();
			break;
		}
		// from left
		if (ball->left() < brick->left() && ball->right() > brick->left() &&
			(true)) {
			ball->negateVelocityX();
			break;
		}
	}
}

void Controller::Start()
{
	glm::vec3 start(-0.8f, 0.8f, 0);
	glm::vec3 offset(0.1f, 0, 0);

	for(int i = 0; i < 1; ++i) {
		GameObject* brick = new GameObject("brick" + std::to_string(i));
		BrickBehaviour* brickBehaviour = new BrickBehaviour(brick);
		brick->transform->setLocalPosition(start + glm::vec3(offset.x * i, offset.y, offset.z));
		brick->AddComponent(brickBehaviour);
		brick->renderer = SpriteRenderer::create(brick, "some_sprite_name");
		bricks.push_back(brickBehaviour);
	}
}

Controller::~Controller() {

}
