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
}

void Controller::Start()
{
	std::vector<BrickBehaviour *> bricks;
	glm::vec3 start(-0.8f, 0.8f, 0);
	glm::vec3 offset(0.1f, 0, 0);

	for(int i = 0; i < 5; ++i)
	{
		GameObject* brick = new GameObject("brick" + std::to_string(i));
		BrickBehaviour* brickBehaviour = new BrickBehaviour(brick);
		brick->transform->setLocalPosition(start + glm::vec3(offset.x * i, offset.y, offset.z));
		brick->AddComponent(brickBehaviour);
		brick->renderer = SpriteRenderer::create(brick, "some_sprite_name");
	}
}

Controller::~Controller() {

}
