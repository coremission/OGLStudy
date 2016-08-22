#ifndef TRANSFORM_h
#define TRANSFORM_h

#include <glm/glm.hpp>

class Transform
{
public:
	Transform* parent;

	glm::vec3 position;
	glm::vec3 rotation;
	Transform();
	~Transform();
};

#endif // TRANSFORM_h