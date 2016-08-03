#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>
#include "ShaderLoader.h"
#include "Models.h"
#include "Dependencies/glm/glm.hpp"
#include "Dependencies/glm/gtx/transform.hpp"

Models::GameModels* gameModel;

void renderScene(void);
GLuint program;
const char * TRIANGLE_NAME = "triangle1";

void Init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	ShaderLoader loader;

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
	static float time = 0.0f;
	time += 0.001f;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//
	glBindVertexArray(gameModel->GetModel(TRIANGLE_NAME));

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