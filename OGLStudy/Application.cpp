#include "Application.h"
#include <iostream>
#include <freeglut/freeglut.h>
#include <glew/glew.h>
#include "Models.h"
#include "Rendering/ShaderLoader.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

GLuint program;
const char * TRIANGLE_NAME = "triangle1";

Models::Scene* Application::_gameModel = nullptr;

void Application::initialize(int* argc, char ** argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);//optional
	glutInitWindowSize(800, 600); //optional
	glutCreateWindow("OpenGL First Window");
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glutKeyboardFunc(processInput);
	glewInit();

	_gameModel = new Models::Scene();
	_gameModel->CreateTriangleModel(TRIANGLE_NAME);

	program = ShaderLoader::CreateProgram("Shaders\\Vertex.glsl", "Shaders\\Fragment.glsl");
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
	delete _gameModel;
	glDeleteProgram(program);
}

void Application::renderScene() {
	static float time = 0.0f;
	time += 0.001f;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//
	const GameObject& gameObject = _gameModel->GetModel(TRIANGLE_NAME);
	glBindVertexArray(gameObject.vao);

	//use the created program
	glUseProgram(program);
	GLuint timeLocation = glGetUniformLocation(program, "time");
	GLuint rotationLocation = glGetUniformLocation(program, "rotationMatrix");

	glUniform1f(timeLocation, time);
	glm::mat4 rotation;
	rotation = glm::rotate(time, glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(rotationLocation, 1, GL_FALSE, &rotation[0][0]);

	//draw 6 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glUseProgram(0);
	glBindVertexArray(0);

	glutSwapBuffers();
	glutPostRedisplay();
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