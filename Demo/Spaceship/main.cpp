#include <Application.h>
#include <Model/ModelLoader.h>
#include <iostream>
#include "RotationBehaviour.h"
#include "CameraController.h"
#include <Rendering/SkyboxRenderer.h>
#include <System/system.hpp>

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

void setUpScene()
{
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
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_rt.png",
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_lf.png",
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_up.png",
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_dn.png",
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_bk.png",
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_ft.png",
	};

	camera->loadSkybox(filenames);
	
	auto spaceShipGo = ModelLoader::LoadModel("spaceCruiser", "Assets\\space_cruiser_4.obj");
	RotationBehaviour* rotation = new RotationBehaviour(spaceShipGo);
	spaceShipGo->AddComponent<RotationBehaviour>(rotation);

	// negative z because glm::perspective flips z
	spaceShipGo->transform->setLocalPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	spaceShipGo->transform->setLocalScale(glm::vec3(1.0f, 1.0f, 1.0f));

	// todo: here is an issue with vp matrix
	// Place camera behing ship
	camera->transform->setParent(spaceShipGo->transform.get());
	camera->transform->setLocalPosition(glm::vec3(35, 1, 50));

	// use local position because ship is root transform
	camera->transform->LookAt(spaceShipGo->transform->getLocalPosition());
}