#ifndef GAMEOBJECT_h
#define GAMEOBJECT_h

#include <Rendering/BaseRenderer.h>

#include <vector>
#include <glew/glew.h>
#include "Transform.h"
#include <string>

class BaseRenderer;

class GameObject {
public:
	GLuint vao;
	std::string name;
	Transform transform;
	BaseRenderer* renderer;
	std::vector<GLuint> vbos;

	GameObject();
	GameObject(const GameObject& m);
	~GameObject();
};

#endif // GAMEOBJECT_h