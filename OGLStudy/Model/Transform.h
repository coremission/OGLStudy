#ifndef TRANSFORM_h
#define TRANSFORM_h

#include <glm/glm.hpp>

class Transform
{
private:
	glm::vec3 localPosition;
	glm::vec3 localScale;
	glm::mat4 localToWorldMatrix;
	glm::mat4 worldToLocalMatrix;

	Transform* parent;
public:
	const glm::vec3 getLocalPosition() const { return localPosition; };
	void setLocalPosition(glm::vec3);

	const glm::vec3 getLocalScale() const { return localScale; };
	void setLocalScale(glm::vec3);

	const Transform* getParentTransform() const { return parent; };
	void setParent(const Transform*);
	glm::vec3 position;
	glm::vec3 rotation;
	Transform();
	~Transform();
};

#endif // TRANSFORM_h