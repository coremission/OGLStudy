#include "Transform.h"

#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.inl>

using namespace glm;

Transform::Transform():
	localPosition(vec3()),
	localRotation(vec3()),
	localScale(vec3(1, 1, 1)),
	parent(nullptr)
{
}

Transform::~Transform()
{
}

void Transform::recalculateMatrices() const
{
	auto result = translate(localPosition) * scale(localScale) * orientate4(localRotation);
	if (parent != nullptr)
		result = parent->localToWorldMatrix * result;

	localToWorldMatrix = result;
}

void Transform::setLocalPosition(vec3 value)
{
	localPosition = value;
	recalculateMatrices();
}

void Transform::setLocalYawPitchRoll(glm::vec3 yawPitchRoll)
{
	localRotation = yawPitchRoll;
	recalculateMatrices();
}

const mat4& Transform::getLocalToWorldMatrix() const
{
	recalculateMatrices();
	return localToWorldMatrix;
}
