#include "Application.h"
#include "Model/Scene.h"
#include "System/system.hpp"

#include <iostream>
#include <freeglut/freeglut.h>
#include <glew/glew.h>

using namespace std;

std::unique_ptr<Models::Scene> Application::scene = std::make_unique<Models::Scene>();

void Application::initialize(int* argc, char ** argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);//optional
	Screen::width = 640;
	Screen::height = 480;
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

	if (glewIsSupported("GL_VERSION_4_3")) {
		std::cout << " GLEW Version is 4.3\n ";
	}
	else {
		std::cout << "GLEW 4.3 not supported\n ";
	}

	glutDisplayFunc(renderScene);
}

void Application::runMainLoop()
{
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutMainLoop();
}

void Application::renderScene() {
	Time::updateClock();

	std::cout << 1.0f / Time::deltaTime << std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//
	for(auto it = scene->begin(); it != scene->end(); ++it)
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
	if (!gameObject.renderer)
		return;

	gameObject.renderer->render();
}

void Application::processKeyDown(unsigned char key, int x, int y)
{
	Input::registerKeyPressed(key);
	// TODO: move this to game controllers
	if (key == 27) // ESCAPE
		leaveMainLoop();
}

void Application::processKeyUp(unsigned char key, int x, int y)
{
	Input::resetKeyPressed(key);
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
	glutLeaveMainLoop();
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
