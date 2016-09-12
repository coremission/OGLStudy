#include "BallBehaviour.h"
#include "Controller.h"

#include <Rendering/MeshManager.h>
#include <Rendering/MaterialManager.h>
#include <Rendering/Camera.h>

#include <glm/glm.hpp>
#include <Application.h>
#include <iostream>
#include <memory>
#include <Rendering/SpriteRenderer.h>
#include "PaddleBehaviour.h"

using namespace std;
using namespace glm;

void _do(int, char**);
shared_ptr<Models::Scene> setUpScene();

int main(int argc, char **argv)
{
	_do(argc, argv);
	cout << endl << "Press any key to exit..." << endl;
	cin.get();

	return 0;
}

// this one exist to see destructors outputs
void _do(int argc, char **argv) {
	try {
		Application::initialize(&argc, argv);
		Application::setUpScene(setUpScene());
		Application::runMainLoop();
		Application::exit();
	}
	catch (exception exc) {
		Application::leaveMainLoop();
		Application::exit();
		cout << exc.what();
	}
}

shared_ptr<Models::Scene> setUpScene() {
	auto sceneShared = make_shared<Models::Scene>();
	
	// BALL
	GameObject* ball = new GameObject("ball");
	BallBehaviour* ballBehaviour = new BallBehaviour(ball);
	ball->AddComponent<BallBehaviour>(ballBehaviour);

	// create renderer
	ball->renderer = SpriteRenderer::create(ball, "some_sprite_name");
	sceneShared->AddModel(ball->name, ball);

	// PADDLE
	GameObject* paddle = new GameObject("paddle");
	//auto paddleBehaviour = paddle->AddComponent<PaddleBehaviour>();
	//paddleBehaviour->setUpBall(ballBehaviour);
	paddle->renderer = SpriteRenderer::create(paddle, "some_sprite_name");
	sceneShared->AddModel(paddle->name, paddle);
	
	// TODO: add controller
	// CONTROLLER
	GameObject* controller = new GameObject("controller");
	controller->AddComponent<Controller>();
	sceneShared->AddModel(controller->name, controller);

	// TODO: add camera
	// CAMERA
	GameObject* camera = new GameObject;
	camera->name = "camera";
	camera->AddComponent<Camera>();
	sceneShared->AddModel(camera->name, camera);

	return sceneShared;
}