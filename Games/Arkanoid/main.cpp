#include <Model/VertexData.h>
#include "BallBehaviour.h"
#include <Rendering/MeshManager.h>
#include <Rendering/MaterialManager.h>

#include <glm/glm.hpp>
#include <Application.h>
#include <iostream>
#include <memory>
#include <vector>

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
	
	auto mesh = MeshManager::getQuadMesh();

	GameObject* myModel = new GameObject;
	myModel->AddComponent(make_unique<BallBehaviour>(myModel));
	myModel->name = "triangle1";

	// create material
	auto mat = MaterialManager::getMaterial("simple", "Shaders\\Vertex.glsl", "Shaders\\Fragment.glsl");

	// create renderer
	myModel->renderer = BaseRenderer::createBaseRenderer(myModel, mat, mesh);

	sceneShared->AddModel(myModel->name, myModel);

	return sceneShared;
}