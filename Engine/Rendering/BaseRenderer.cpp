#include "BaseRenderer.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace std;

BaseRenderer::BaseRenderer(GameObject* gameObject, shared_ptr<Material> _material, shared_ptr<Mesh> _mesh): 
	_gameObject(gameObject), material(_material), mesh(_mesh)
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
	glBindVertexArray(mesh->vao);

	GLuint program = material->programId();
	glUseProgram(program);

	// set uniform variables
	GLuint timeLocation = glGetUniformLocation(program, "time");
	glUniform1f(timeLocation, time);

	GLuint rotationLocation = glGetUniformLocation(program, "Model2World");
	glm::mat4 combined = _gameObject->transform->getLocalToWorldMatrix();

	glUniformMatrix4fv(rotationLocation, 1, GL_FALSE, &combined[0][0]);

	//draw 6 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// unbind program and VAO
	glUseProgram(0);
	glBindVertexArray(0);
}

BaseRenderer* BaseRenderer::createBaseRenderer(GameObject* gameObject, std::shared_ptr<Material> material, std::shared_ptr<Mesh> mesh)
{
	return new BaseRenderer(gameObject, material, mesh);
}
