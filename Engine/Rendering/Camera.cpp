#include "Camera.h"
#include "Model/Transform.h"
#include "TextureManager.h"
#include <vector>
#include <glm/gtx/transform.hpp>

// static fields
Camera* Camera::main = nullptr;

Camera::Camera(GameObject* go)
	:Component(go), horizontalFov(45), ratio(4.0f/3.0f), nearClippingPlane(1.0f), farClippingPlane(100.0f)
{
	Camera::main = this;
	recalculateMatrices();
}

Camera::Camera(GameObject * _gameObject, float _fov, float _ratio, float _near, float _far)
	:Component(_gameObject), horizontalFov(_fov), ratio(_ratio), nearClippingPlane(_near), farClippingPlane(_far)
{
	Camera::main = this;
	recalculateMatrices();
}

void Camera::Update()
{
}

void Camera::Start()
{
}

glm::mat4 Camera::getViewProjectionMatrix() const
{
	recalculateMatrices();
	return projectionMatrix * viewMatrix;
}

void Camera::initializeSkybox(std::vector<std::string> filenames)
{
	// 1. generate skybox texture
	glGenTextures(1, &skyBoxTextureId);
	glBindTexture(GL_TEXTURE_CUBE_MAP, skyBoxTextureId);

	// 2. load 6 images
	for (GLuint i = 0; i < 6; i++)
	{
		unsigned long width, height;
		std::vector<unsigned char> image;
		TextureManager::loadPng(filenames[i], image, width, height);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB,
			width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, &image[0]);
	}

	// 3. set cubemap texture parameters
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

void Camera::clearWithSkybox()
{

}

glm::mat4 Camera::getViewMatrix() const
{
	recalculateMatrices();
	return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix() const
{
	recalculateMatrices();
	return projectionMatrix;
}

void Camera::recalculateMatrices() const
{
	projectionMatrix = glm::perspective(glm::radians(horizontalFov), ratio, nearClippingPlane, farClippingPlane);
	viewMatrix = transform->getWorldToLocalMatrix();
}
