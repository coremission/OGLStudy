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

	GameObject* cameraGo = new GameObject("camera");
	Camera* camera = new Camera(cameraGo, 60.0f, 4.0f/3.0f, 1.0f, 100.0f);
	cameraGo->AddComponent(camera);
	camera->transform->setLocalPosition(vec3(0.0f, 0.0f, 0.0f));

	vec4 point = vec4(0.0f, 0.0f, -1.0f, 1.0f);

	cout << "initial point: " << point << endl;
	mat4 mvp = camera->getViewProjectionMatrix();

	cout << "mvp: " << endl;
	cout << mvp << endl;

	vec4 result = mvp * point;

	auto divided = vec3(result.x / result.w, result.y / result.w, result.z / result.w);

	cout << "result: " << result << endl;
	cout << "after division: " << divided << endl;

	cout << endl << "Press any key to exit..." << endl;
	cin.get();

	return 0;
}
