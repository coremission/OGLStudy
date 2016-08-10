#ifndef GAMEOBJECT_h
#define GAMEOBJECT_h

#include <vector>
#include <glew/glew.h>
#include "Rendering/Material.h"

class GameObject {
public:
	GLuint vao;
	Material * material;
	std::vector<unsigned int> vbos;

	GameObject();
	GameObject(const GameObject &m);
	~GameObject();
};

#endif // GAMEOBJECT_h