#include "Models.h"
using namespace Models;
using namespace std;
// Model
Model::Model()
{
}

Model::~Model() {
	cout << "model destuctor";
}


// GameModels
GameModels::GameModels()
{
}

GameModels::~GameModels()
{
	map<string, Model>::iterator it;
	for (it = _gameModelList.begin(); it != _gameModelList.end(); ++it) {
		// delete VAO and VBOs
		glDeleteVertexArrays(1, &it->second.vao);
		glDeleteBuffers(it->second.vbos.size(), &it->second.vbos[0]);
		it->second.vbos.clear();
	}
	_gameModelList.clear();
}

void GameModels::CreateTriangleModel(const std::string & gameModelName)
{
}

void GameModels::DeleteModel(const std::string & gameModelName)
{
}

GLuint GameModels::GetModel(const std::string & gameModelName)
{
	return GLuint();
}
