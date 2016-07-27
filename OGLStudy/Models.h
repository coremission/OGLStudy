#ifndef MODELS_H
#define MODELS_H

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include <vector>
#include <map>

namespace Models
{
	class Model {
	public:
		GLuint vao;
		std::vector<unsigned int> vbos;
		Model();
		~Model();
	};

	class GameModels
	{
	private:
		std::map<std::string, Model> _gameModelList;
	public:
		GameModels();
		~GameModels();
		void CreateTriangleModel(const std::string &gameModelName);
		void DeleteModel(const std::string &gameModelName);
		GLuint GetModel(const std::string &gameModelName);
	};
}

#endif // MODELS_H