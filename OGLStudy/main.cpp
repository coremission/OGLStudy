#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include "Core\ShaderLoader.h"
#include "Models.h"

Models::GameModels* gameModel;

void renderScene(void);
GLuint program;
const char * TRIANGLE_NAME = "triangle1";

void Init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	Core::ShaderLoader loader;

	gameModel = new Models::GameModels();
	gameModel->CreateTriangleModel(TRIANGLE_NAME);

	program = loader.CreateProgram("Shaders\\Vertex.glsl", "Shaders\\Fragment.glsl");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);//optional
	glutInitWindowSize(800, 600); //optional
	glutCreateWindow("OpenGL First Window");
	glewInit();

	Init();

	if (glewIsSupported("GL_VERSION_4_3"))
	{
		std::cout << " GLEW Version is 4.3\n ";
	}
	else
	{
		std::cout << "GLEW 4.3 not supported\n ";
	}

	glutDisplayFunc(renderScene);
	glutMainLoop();

	delete gameModel;
	glDeleteProgram(program);
	return 0;
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//
	glBindVertexArray(gameModel->GetModel(TRIANGLE_NAME));

	//use the created program
	glUseProgram(program);

	//draw 3 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glutSwapBuffers();
}