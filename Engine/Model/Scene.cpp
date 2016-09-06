#include "Scene.h"
#include "VertexData.h"
#include <Rendering/MaterialManager.h>
#include <glm/glm.hpp>

using namespace std;
using namespace Models;
using namespace glm;

// Scene
Scene::Scene()
{
}

Scene::~Scene()
{
	for (auto it = _gameModelList.begin(); it != _gameModelList.end(); ++it) {
		delete it->second;
	}
	_gameModelList.clear();
}

void Scene::CreateTriangleModel(const string &gameModelName)
{
	vector<VertexData> vertices;
	vertices.push_back(VertexData(vec3(-1, -1, 0.0), vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	vertices.push_back(VertexData(vec3(-1, 1, 0.0), vec4(1.0f, 0.0f, 0.0f, 1.0f)));
	vertices.push_back(VertexData(vec3(1, -1, 0.0), vec4(0.0f, 0.0f, 1.0f, 1.0f)));
	
	vertices.push_back(VertexData(vec3(-1, 1, 0.0), vec4(1.0, 0, 0, 1.0)));
	vertices.push_back(VertexData(vec3(1, 1, 0.0), vec4(1.0, 0, 0, 1.0)));
	vertices.push_back(VertexData(vec3(1, -1, 0.0), vec4(0, 0, 1.0, 1)));

	auto mesh = std::make_shared<Mesh>(vertices);

	GameObject* myModel = new GameObject;
	myModel->name = gameModelName;
	
	// create material
	auto mat = MaterialManager::getMaterial("simple", "Shaders\\Vertex.glsl", "Shaders\\Fragment.glsl");

	// create renderer
	myModel->renderer = BaseRenderer::createBaseRenderer(myModel, mat, mesh);
	_gameModelList[gameModelName] = myModel;
}

void Scene::DeleteModel(const std::string &gameModelName)
{
}

const GameObject& Scene::GetModel(const std::string &gameModelName)
{
	return *_gameModelList[gameModelName];
}

std::map<std::string, GameObject*>::iterator Scene::begin()
{
	return _gameModelList.begin();
}

std::map<std::string, GameObject*>::iterator Scene::end()
{
	return _gameModelList.end();
}
