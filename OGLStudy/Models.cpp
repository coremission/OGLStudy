#include "Models.h"
#include "VertexFormat.h"

using namespace std;
using namespace Models;
using namespace glm;

// Scene
Scene::Scene()
{
}

Scene::~Scene()
{
	map<string, GameObject>::iterator it;
	for (it = _gameModelList.begin(); it != _gameModelList.end(); ++it) {
		// delete VAO and VBOs
		glDeleteVertexArrays(1, &it->second.vao);
		glDeleteBuffers(it->second.vbos.size(), &it->second.vbos[0]);
		it->second.vbos.clear();
	}
	_gameModelList.clear();
}

void Scene::CreateTriangleModel(const std::string &gameModelName)
{
	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(vec3(-1, -1, 0.0), vec4(0.0f, 1.0f, 0.0f, 1.0f)));
	vertices.push_back(VertexFormat(vec3(-1, 1, 0.0), vec4(1.0f, 0.0f, 0.0f, 1.0f)));
	vertices.push_back(VertexFormat(vec3(1, -1, 0.0), vec4(0.0f, 0.0f, 1.0f, 1.0f)));
	
	vertices.push_back(VertexFormat(vec3(-1, 1, 0.0), vec4(1.0, 0, 0, 1.0)));
	vertices.push_back(VertexFormat(vec3(1, 1, 0.0), vec4(1.0, 0, 0, 1.0)));
	vertices.push_back(VertexFormat(vec3(1, -1, 0.0), vec4(0, 0, 1.0, 1)));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void *)offsetof(VertexFormat, VertexFormat::_position));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void *)offsetof(VertexFormat, VertexFormat::_color));

	GameObject myModel;
	myModel.vao = vao;
	myModel.vbos.push_back(vbo);
	
	_gameModelList[gameModelName] = myModel;
}

void Scene::DeleteModel(const std::string &gameModelName)
{
}

const GameObject& Scene::GetModel(const std::string &gameModelName)
{
	return _gameModelList[gameModelName];
}