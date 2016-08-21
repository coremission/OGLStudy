#include "BaseRenderer.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

BaseRenderer::BaseRenderer(GLuint _vao, std::shared_ptr<Material> _material): 
	vao(_vao), material(_material)
{
}

BaseRenderer::~BaseRenderer()
{
}

void BaseRenderer::render() const
{
	// TODO: introduce time
	float time = 1.0f;

	// bind VAO
	glBindVertexArray(vao);

	GLuint program = material->programId();
	// apply material
	//use created program
	glUseProgram(program);
	// set uniform variables
	GLuint timeLocation = glGetUniformLocation(program, "time");
	GLuint rotationLocation = glGetUniformLocation(program, "rotationMatrix");

	glUniform1f(timeLocation, time);
	glm::mat4 rotation;
	rotation = glm::rotate(time, glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(rotationLocation, 1, GL_FALSE, &rotation[0][0]);

	//draw 6 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// unbind program and VAO
	glUseProgram(0);
	glBindVertexArray(0);
}

BaseRenderer* BaseRenderer::createBaseRenderer(GLuint vao, std::shared_ptr<Material> material)
{
	return new BaseRenderer(vao, material);
}
