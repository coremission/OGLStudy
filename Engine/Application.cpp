#include "Application.h"
#include "Model/Scene.h"
#include "System/system.hpp"

#include <iostream>
#include <freeglut/freeglut.h>
#include <glew/glew.h>
#include <memory>

using namespace std;

// static field initialization
shared_ptr<Models::Scene> Application::_scene;

void Application::initialize(int* argc, char ** argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);//optional
	Screen::width = 800;
	Screen::height = 600;
	glutInitWindowSize(Screen::width, Screen::height);
	glutCreateWindow("OpenGL First Window");
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// key down
	glutKeyboardFunc(processKeyDown);
	glutKeyboardUpFunc(processKeyUp);
	// mouse click
	glutMouseFunc(processMousePress);
	// mouse move
    glutMotionFunc(processMousePressedMove);
	glutPassiveMotionFunc(processMouseFreeMove);

	glewInit();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (glewIsSupported("GL_VERSION_4_3"))
	{
		std::cout << " GLEW Version is 4.3\n ";
	}
	else
	{
		std::cout << "GLEW 4.3 not supported\n ";
	}

	glutDisplayFunc(renderScene);
}

void Application::setUpScene(shared_ptr<Models::Scene> scene) {
	Application::_scene = scene;
	std::cout << "scene was set up" << std::endl;
}

void Application::runMainLoop()
{
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutMainLoop();
}

void Application::renderScene() {
	Time::time += 0.0001f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//
	for(auto it = _scene->begin(); it != _scene->end(); ++it)
	{
		drawGameObject(*it->second);
		// todo: there maybe must be base Update call for Component
		// Component::Update();
		it->second->Update();
	}
	
	glutSwapBuffers();
	glutPostRedisplay();
}

void Application::drawGameObject(GameObject& gameObject)
{
	if (gameObject.renderer == nullptr)
		return;

	gameObject.renderer->render();
}

void Application::processKeyDown(unsigned char key, int x, int y)
{
	Input::registerKeyPressed(key);
	std::cout << "down " << key << std::endl;
	// TODO: move this to game controllers
	if (key == 27) // ESCAPE
		exit();
}

void Application::processKeyUp(unsigned char key, int x, int y)
{
	Input::resetKeyPressed(key);
	std::cout << "up " << key << std::endl;
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

void Application::exit()
{
	glutLeaveMainLoop();
}
