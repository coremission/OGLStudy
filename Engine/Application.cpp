#include "Application.h"
#include "Model/Scene.h"
#include "System/system.hpp"

#include <iostream>
#define GLEW_STATIC
#include <glew/glew.h>
#include <glfw/glfw3.h>

using namespace std;

// static fields
std::unique_ptr<Models::Scene> Application::scene = std::make_unique<Models::Scene>();
GLFWwindow* Application::window = nullptr;

void Application::initialize(int* argc, char ** argv) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_DEPTH_BITS, 32);

	Screen::width = 640;
	Screen::height = 480;

	window = glfwCreateWindow(Screen::width, Screen::height, "Rudy", nullptr, nullptr);
	if (window == nullptr) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		cout << "Failed to initialize GLEW" << endl;
		return;
	}

	glfwGetFramebufferSize(window, &Screen::width, &Screen::height);
	glViewport(0, 0, Screen::width, Screen::height);

	glPolygonMode(GL_FRONT, GL_FILL);

	if (glewIsSupported("GL_VERSION_4_3")) {
		std::cout << " GLEW Version is 4.3\n ";
	}
	else {
		std::cout << "GLEW 4.3 not supported\n ";
	}

	glfwSetKeyCallback(window, key_callback);
}

void Application::runMainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
		renderScene();
	}

	glfwTerminate();
}

void Application::renderScene() {
	Time::updateClock();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//
	for(auto it = scene->begin(); it != scene->end(); ++it)
	{
		drawGameObject(*it->second);
		// todo: there maybe must be base Update call for Component
		// Component::Update();
		it->second->Update();
	}
	
	//glutSwapBuffers();
	//glutPostRedisplay();
}

void Application::drawGameObject(GameObject& gameObject)
{
	if (!gameObject.renderer)
		return;

	gameObject.renderer->render();
}

void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	//cout << key << " scancode: " << scancode << " action: " << " " << action << " mode: " << mode << endl;

	if(action == GLFW_PRESS)
		Input::registerKeyPressed(key);
	if (action == GLFW_RELEASE)
		Input::resetKeyPressed(key);

	// When a user presses the escape key, we set the WindowShouldClose property to true, 
	// closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void Application::processMousePress(int button, int state, int x, int y)
{
	//std::cout << "button: " << button << " state:" << state << " x: "<<  x << " y: " << y;
}

void Application::processMouseFreeMove(int x, int y)
{
	Input::mousePosition.x = x;
	Input::mousePosition.y = y;

	//std::cout << x << ", " << y << std::endl;
}

void Application::processMousePressedMove(int x, int y)
{
}

void Application::leaveMainLoop()
{
	glfwSetWindowShouldClose(window, GL_TRUE);
}

void Application::exit()
{
	// fixme
	// todo: create destroyable scene api
	// Good enough will for GameObject to use something like this:
	// Engine::scene.AddModel();
	// rename Application to Engine
	scene.reset();
}
