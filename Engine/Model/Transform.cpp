#include "Transform.h"

#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/euler_angles.inl>

using namespace glm;

Transform::Transform():
	localPosition(vec3()),
	localScale(vec3(1, 1, 1)),
	localRotation(vec3()),
	parent(nullptr)
{
}

Transform::~Transform()
{
}

void Transform::recalculateMatrices() const
{
	auto result = translate(localPosition) * scale(localScale) * glm::mat4_cast(localRotation);
	if (parent != nullptr)
		result = parent->localToWorldMatrix * result;

	if (parent != nullptr)
		rotation = parent->getRotation() * localRotation;
	else
		rotation = localRotation;

	localToWorldMatrix = result;
	worldToLocalMatrix = glm::inverse(localToWorldMatrix);
}

void Transform::setLocalPosition(vec3 value)
{
	localPosition = value;
	recalculateMatrices();
}

void Transform::setLocalYawPitchRoll(glm::vec3 yawPitchRoll)
{
	localRotation = quat(yawPitchRoll);
	recalculateMatrices();
}

void Transform::addLocalYawPitchRoll(glm::vec3 yawPitchRoll)
{
	localRotation = localRotation * quat(yawPitchRoll);
	recalculateMatrices();
}

void Transform::setLocalScale(glm::vec3 value)
{
	localScale = value;
	recalculateMatrices();
}

const mat4& Transform::getLocalToWorldMatrix() const
{
	recalculateMatrices();
	return localToWorldMatrix;
}

const glm::mat4& Transform::getWorldToLocalMatrix() const
{
	recalculateMatrices();
	return worldToLocalMatrix;
}

const glm::vec3 Transform::transformPoint(const glm::vec3& p)
{
	return vec3(getLocalToWorldMatrix() * vec4(p, 1.0f));
}

const glm::vec3 Transform::inverseTransformPoint(const glm::vec3& p)
{
	return vec3(getWorldToLocalMatrix() * vec4(p, 1.0f));
}
