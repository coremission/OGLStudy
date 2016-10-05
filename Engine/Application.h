#ifndef APPLICATION_h
#define APPLICATION_h
#include "Model/GameObject.h"
#include "Model/Scene.h"
#include <glfw/glfw3.h>

class Application
{
private:
	static GLFWwindow* window;
	static std::unique_ptr<Models::Scene> scene;
	static void renderScene();

	static void processMousePress(int, int, int, int);
	static void processMouseFreeMove(int, int);
	static void processMousePressedMove(int, int);
	static void drawGameObject(GameObject&);
	Application() = delete;
	Application(const Application&) = delete;
	const Application& operator=(Application&) = delete;

	// glfw callbacks
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
public:
	static void initialize(int* argc, char** argv);
	static void runMainLoop();
	static void leaveMainLoop();
	static void exit();

	friend class GameObject;
};

#endif // APPLICATION_h