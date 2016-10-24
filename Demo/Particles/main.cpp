#include <Application.h>
#include <Model/ModelLoader.h>
#include <ParticleSystem/ParticleSystem.h>

#include <iostream>
#include "RotationBehaviour.h"
#include <Rendering/MaterialManager.h>
#include <Rendering/MeshManager.h>

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
	Camera* camera = new Camera(cameraGo);
	cameraGo->AddComponent(camera);
	camera->transform->setLocalPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	/*
	GameObject* go = new GameObject("particleSystem");
	ParticleSystem * particleSystem = new ParticleSystem(go);
	go->AddComponent<ParticleSystem>(particleSystem);
	*/

	/* TEMP INDEXED */
	/*GameObject* tempGo = new GameObject("indexedGameObject");
	tempGo->renderer = BaseRenderer::create(tempGo,
		// material
		MaterialManager::getMaterial("tempIndexed", 
			"Shaders\\Diffuse_Vertex.glsl", 
			"Shaders\\Diffuse_Fragment.glsl"),
		// mesh
		MeshManager::getCubeMesh());

	tempGo->transform->setLocalScale(glm::vec3(0.2f, 0.2f, 0.2f));
	RotationBehaviour* rotation = new RotationBehaviour(tempGo);
	tempGo->AddComponent<RotationBehaviour>(rotation);*/

	auto someModel = ModelLoader::LoadModel("crate", "Assets\\lowpolytree.obj");
	RotationBehaviour* rotation = new RotationBehaviour(someModel);
	someModel->AddComponent<RotationBehaviour>(rotation);

	// here is ndc, so z > 1 will be culled
	someModel->transform->setLocalPosition(glm::vec3(0.0f, 0.0f, 0.5f));
	someModel->transform->setLocalScale(glm::vec3(0.2f, 0.2f, 0.2f));
}