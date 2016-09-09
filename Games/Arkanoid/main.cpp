#include "BallBehaviour.h"
#include "Controller.h"

#include <Rendering/MeshManager.h>
#include <Rendering/MaterialManager.h>

#include <glm/glm.hpp>
#include <Application.h>
#include <iostream>
#include <memory>
#include <Rendering/SpriteRenderer.h>

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
	}
	catch (exception exc) {
		Application::exit();
		cout << exc.what();
	}
}

shared_ptr<Models::Scene> setUpScene() {
	auto sceneShared = make_shared<Models::Scene>();
	
	// BALL
	GameObject* ball = new GameObject;
	ball->AddComponent<BallBehaviour>();
	ball->name = "ball";
	// create renderer
	// ball->renderer = SpriteRenderer::create(ball, "some_sprite_name");
	sceneShared->AddModel(ball->name, ball);
	// TODO: add controller
	// CONTROLLER
	//GameObject* controller = new GameObject;
	//controller->AddComponent(make_unique<Controller>());

	return sceneShared;
}