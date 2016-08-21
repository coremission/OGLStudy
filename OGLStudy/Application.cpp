#include "Application.h"
#include "Model/Scene.h"

#include <iostream>
#include <freeglut/freeglut.h>
#include <glew/glew.h>

const char * TRIANGLE_NAME = "triangle1";

Models::Scene* Application::_scene = nullptr;

void Application::initialize(int* argc, char ** argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);//optional
	glutInitWindowSize(800, 600); //optional
	glutCreateWindow("OpenGL First Window");
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glutKeyboardFunc(processInput);
	glewInit();

	_scene = new Models::Scene();
	_scene->CreateTriangleModel(TRIANGLE_NAME);

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

void Application::runMainLoop()
{
	glutMainLoop();
}

Application::~Application()
{
	delete _scene;
}

void Application::renderScene() {
	static float time = 0.0f;
	time += 0.001f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//
	for(auto it = _scene->begin(); it != _scene->end(); ++it)
	{
		drawGameObject(it->second, time);
	}
	
	glutSwapBuffers();
	glutPostRedisplay();
}

void Application::drawGameObject(GameObject& gameObject, float time)
{
	gameObject.renderer->render();
}

void Application::processInput(unsigned char key, int x, int y)
{
	std::cout << key;

	if (key == 27) // ESCAPE
		exit();
}

void Application::exit()
{
	glutExit();
}