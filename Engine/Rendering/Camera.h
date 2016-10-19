﻿#ifndef CAMERA_h
#define CAMERA_h

#include <Model/Component.h>
#include <glm/glm.hpp>

class Camera: public Component
{
private:
	float horizontalFov;
	float ratio; // width/height;
	mutable glm::mat4 viewMatrix;
	mutable glm::mat4 projectionMatrix;

	void recalculateMatrices() const;
public:
	explicit Camera(GameObject*);
	virtual void Update() override;
	virtual void Start() override;
	glm::mat4 getViewProjectionMatrix() const;

	float getHorizontalFov() const { return horizontalFov; }
	float getRatio() const { return ratio; }
	glm::mat4 getViewMatrix() const { return viewMatrix; }
	glm::mat4 getProjectionMatrix() const { return projectionMatrix; }
};

#endif //CAMERA_h