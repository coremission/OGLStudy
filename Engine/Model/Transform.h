#ifndef TRANSFORM_h
#define TRANSFORM_h

#include <glm/glm.hpp>
class Transform
{
private:
	glm::vec3 localPosition;
	glm::vec3 localScale;
	glm::vec3 localRotation;

	mutable glm::mat4 localToWorldMatrix;
	mutable glm::mat4 worldToLocalMatrix;

	const Transform* parent;

	void recalculateMatrices() const;
public:
	glm::vec3 getLocalPosition() const { return localPosition; };
	void setLocalPosition(glm::vec3);

	glm::vec3 getLocalYawPitchRoll() const { return localRotation; }
	void setLocalYawPitchRoll(glm::vec3);

	glm::vec3 getLocalScale() const { return localScale; };
	void setLocalScale(glm::vec3);

	const Transform* getParentTransform() const { return parent; };
	void setParent(const Transform* _parent) { parent = _parent; };

	const glm::mat4& getLocalToWorldMatrix() const;
	const glm::mat4& getWorldToLocalMatrix() const;

	const glm::vec3 transformPoint(const glm::vec3&);
	const glm::vec3 inverseTransformPoint(const glm::vec3&);

	glm::vec3 position;
	glm::vec3 rotation;
	Transform();
	~Transform();
};

#endif // TRANSFORM_h