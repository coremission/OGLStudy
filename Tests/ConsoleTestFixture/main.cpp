#include <iostream>
#include <Dependencies/glm/detail/type_vec3.hpp>
#include <Rendering/Camera.h>
#include <Model/GameObject.h>

using namespace std;
using namespace glm;

int main(int argc, char** argv)
{
	cout << "Test Runner" << endl;

	GameObject* cameraGo = new GameObject("camera");
	Camera* camera = new Camera(cameraGo);
	cameraGo->AddComponent(camera);
	camera->transform->setLocalPosition(vec3(0.0f, 0.0f, 0.0f));

	vec4 point = vec4(0.f, 0.f, 0.f, 1.0f);

	vec4 result = camera->getViewProjectionMatrix() * point;


	cout << endl << "Press any key to exit..." << endl;
	cin.get();

	return 0;
}