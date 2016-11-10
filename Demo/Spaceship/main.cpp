#include <Application.h>
#include <Model/ModelLoader.h>
#include <ParticleSystem/ParticleSystem.h>

#include <iostream>
#include "RotationBehaviour.h"
#include <Rendering/MaterialManager.h>
#include <Rendering/MeshManager.h>
#include "CameraController.h"

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
	Camera* camera = new Camera(cameraGo, 60.0f, 4.0f / 3.0f, 1.0f, 1000.0f);
	cameraGo->AddComponent(camera);
	camera->transform->setLocalPosition(glm::vec3(0.0f, 5.0f, 0.0f));
	CameraController* cameraController = new CameraController(cameraGo);
	cameraGo->AddComponent(cameraController);
	/*camera->initializeSkybox(std::vector<string>{
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_bk.png",
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_dn.png", 
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_ft.png", 
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_lf.png", 
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_rt.png", 
		"Assets\\Skyboxes\\mp_drakeq\\drakeq_up.png",
	});*/

	camera->initializeSkyboxProgram("Shaders\\Skybox_Vertex.glsl", "Shaders\\Skybox_Fragment.glsl");

	auto someModel = ModelLoader::LoadModel("spaceCruiser", "Assets\\space_cruiser_4.obj");
	RotationBehaviour* rotation = new RotationBehaviour(someModel);
	someModel->AddComponent<RotationBehaviour>(rotation);

	// negative z because glm::perspective flips z
	someModel->transform->setLocalPosition(glm::vec3(0.0f, 0.0f, -50.0f));
	someModel->transform->setLocalScale(glm::vec3(1.0f, 1.0f, 1.0f));
}