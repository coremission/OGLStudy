#include "Camera.h"
#include "Model/Transform.h"
#include <glm/gtx/transform.hpp>

void Camera::recalculateMatrices() const
{
	projectionMatrix = glm::perspective(glm::radians(horizontalFov), ratio, 0.1f, 100.0f);
	viewMatrix = glm::inverse(transform->getLocalToWorldMatrix());
}

Camera::Camera(GameObject* go)
	:Component(go), horizontalFov(45), ratio(4.0f/3.0f)
{
}

void Camera::Update()
{
}

void Camera::Start()
{
}

glm::mat4 Camera::getViewProjectionMatrix() const
{
	return projectionMatrix * viewMatrix;
}
