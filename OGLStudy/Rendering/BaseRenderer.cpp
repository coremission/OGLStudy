#include "BaseRenderer.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>

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
	glUseProgram(program);

	// set uniform variables
	GLuint timeLocation = glGetUniformLocation(program, "time");
	glUniform1f(timeLocation, time);

	GLuint rotationLocation = glGetUniformLocation(program, "rotationMatrix");

	glm::mat4 rotation = glm::orientate4(_gameObject->transform.rotation);
	glm::mat4 translation = glm::translate(_gameObject->transform.position);

	glm::mat4 combined = rotation * translation;
	glUniformMatrix4fv(rotationLocation, 1, GL_FALSE, &combined[0][0]);

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
