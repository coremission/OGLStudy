#include <Rendering/SpriteRenderer.h>
#include <Rendering/Camera.h>
#include <Rendering/SkyboxRenderer.h>
#include "CameraController.h"
#include <Application.h>
#include <System/system.hpp>

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

	float screenRatio = static_cast<float>(Screen::width) / static_cast<float>(Screen::height);

	Camera* camera = new Camera(cameraGo, 60.0f, screenRatio, 0.1f, 1000.0f);
	cameraGo->AddComponent(camera);
	CameraController* cameraController = new CameraController(cameraGo);
	cameraGo->AddComponent(cameraController);
	
	/*
	GL_TEXTURE_CUBE_MAP_POSITIVE_X
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	*/
	auto filenames = std::vector<string>{
		"Skyboxes\\mp_drakeq\\drakeq_rt.png",
		"Skyboxes\\mp_drakeq\\drakeq_lf.png",
		"Skyboxes\\mp_drakeq\\drakeq_up.png",
		"Skyboxes\\mp_drakeq\\drakeq_dn.png",
		"Skyboxes\\mp_drakeq\\drakeq_bk.png",
		"Skyboxes\\mp_drakeq\\drakeq_ft.png",
	};

	camera->loadSkybox(filenames);
}