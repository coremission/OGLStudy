#include <Rendering/SpriteRenderer.h>
#include <Rendering/Camera.h>
#include <Rendering/SkyboxRenderer.h>
#include "CameraController.h"
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

	GameObject* cameraGo = new GameObject("camera");
	GameObject* cube = new GameObject("cube");

	Camera* camera = new Camera(cameraGo, 60.0f, 4.0f / 3.0f, 1.0f, 1000.0f);
	cameraGo->AddComponent(camera);
	CameraController* cameraController = new CameraController(cameraGo);
	cameraGo->AddComponent(cameraController);
	// BALL
	//GameObject* ball = new GameObject("ball");
	//ball->renderer = make_unique<SpriteRenderer>(ball, "Skyboxes\\mp_drakeq\\drakeq_bk.png");
	auto filenames = std::vector<string>{
		"Skyboxes\\mp_drakeq\\drakeq_bk.png",
		"Skyboxes\\mp_drakeq\\drakeq_dn.png",
		"Skyboxes\\mp_drakeq\\drakeq_ft.png",
		"Skyboxes\\mp_drakeq\\drakeq_lf.png",
		"Skyboxes\\mp_drakeq\\drakeq_rt.png",
		"Skyboxes\\mp_drakeq\\drakeq_up.png",
	};

	cube->renderer = make_unique<SkyboxRenderer>(camera, filenames);
}