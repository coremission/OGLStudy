#include <iostream>
#include <Dependencies/glm/detail/type_vec3.hpp>
#include <Rendering/Camera.h>
#include <Model/GameObject.h>

using namespace std;
using namespace glm;

std::ostream& operator <<(std::ostream& stream, const vec4& vec) {
	stream << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
	return stream;
}

std::ostream& operator <<(std::ostream& stream, const vec3& vec) {
	stream << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return stream;
}

glm::vec4& operator *(const glm::mat4& matrix, const glm::vec3& point) {
	return matrix * glm::vec4(point.x, point.y, point.z, 1.0f);
}

std::ostream& operator <<(std::ostream& stream, const mat4& matrix) {

	stream << matrix[0] << endl;
	stream << matrix[1] << endl;
	stream << matrix[2] << endl;
	stream << matrix[3] << endl;
	return stream;
}

int main(int argc, char** argv)
{
	cout << "Test Runner" << endl;
	/*
		TODO: MUST IMPLEMENT World 2 Local, Local 2 World
		and make proper tests for TransformPoint, and InverseTransformPoint
	*/
	GameObject* point = new GameObject("point");
	point->transform->setLocalPosition(vec3(0.0f, 0.0f, 1.0f));

	GameObject* cameraGo = new GameObject("camera");
	Camera* camera = new Camera(cameraGo, 60.0f, 4.0f/3.0f, 1.0f, 100.0f);
	cameraGo->AddComponent(camera);
	camera->transform->setLocalPosition(vec3(0.0f, 0.0f, 0.0f));

	cout << "initial point: " << point->transform->getLocalPosition() << endl;
	mat4 mvp = camera->getViewProjectionMatrix();

	cout << "mvp: " << endl;
	cout << mvp << endl;

	vec4 result = mvp * point->transform->getLocalToWorldMatrix() * point->transform->getLocalPosition();

	auto divided = vec3(result.x / result.w, result.y / result.w, result.z / result.w);

	cout << "result: " << result << endl;
	cout << "after division: " << divided << endl;

	cout << endl << "Press any key to exit..." << endl;
	cin.get();

	return 0;
}
