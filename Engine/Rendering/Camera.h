#ifndef CAMERA_h
#define CAMERA_h

#include <Model/Component.h>
#include <glm/glm.hpp>
#include <glew/glew.h>
#include <string>
#include <vector>

class Camera: public Component
{
	static Camera * main;

private:
	float horizontalFov;
	float ratio; // width/height;
	float nearClippingPlane;
	float farClippingPlane;
	mutable glm::mat4 viewMatrix;
	mutable glm::mat4 projectionMatrix;

	void recalculateMatrices() const;
public:
	explicit Camera(GameObject*);
	Camera(GameObject*, float, float, float, float);
	virtual void Update() override;
	virtual void Start() override;
	glm::mat4 getViewProjectionMatrix() const;
	float getHorizontalFov() const { return horizontalFov; }
	float getRatio() const { return ratio; }
	glm::mat4 getViewMatrix() const;
	glm::mat4 getProjectionMatrix() const;

	static const Camera * getMainCamera() { return main; }
};

#endif //CAMERA_h