#include <Rendering/SpriteRenderer.h>
#include <Rendering/Camera.h>

#include <Application.h>
#include <iostream>
#include <memory>

using namespace std;

void _do(int, char**);
void setUpScene();

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
		
		setUpScene();

		Application::runMainLoop();
		Application::exit();
	}
	catch (exception exc) {
		Application::leaveMainLoop();
		Application::exit();
		cout << exc.what();
	}
}

void setUpScene() {
	// BALL
	GameObject* ball = new GameObject("ball");
	// create renderer
	//ball->renderer = LegacySpriteRenderer::create(ball, "Sprites\\ball.png");
	ball->renderer = make_unique<SpriteRenderer>(ball, "Sprites\\ball.png");

	// TODO: add camera
	// CAMERA
	GameObject* camera = new GameObject("camera");
	camera->AddComponent<Camera>();
}