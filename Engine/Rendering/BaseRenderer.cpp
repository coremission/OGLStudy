#include "BaseRenderer.h"
#include "Camera.h"
#include <iostream>
using namespace std;

BaseRenderer::BaseRenderer(GameObject* gameObject, shared_ptr<Material> _material, shared_ptr<Mesh> _mesh): 
	_gameObject(gameObject), mesh(_mesh), material(_material)
{
}

BaseRenderer::~BaseRenderer()
{
}

void BaseRenderer::render() const
{
	glBindVertexArray(mesh->vao);

	GLuint program = material->programId();
	glUseProgram(program);

	GLuint m2wLocation = glGetUniformLocation(program, "Model2World");
	glm::mat4 m2wMatrix = _gameObject->transform->getLocalToWorldMatrix();
	glUniformMatrix4fv(m2wLocation, 1, GL_FALSE, &m2wMatrix[0][0]);

	GLuint mvpLocation = glGetUniformLocation(program, "Model2Projection");
	glm::mat4 vpMatrix = Camera::getMainCamera()->getViewProjectionMatrix();
	glm::mat4 mvpMatrix = vpMatrix * m2wMatrix;
	glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, &mvpMatrix[0][0]);

	auto lpos = _gameObject->transform->getLocalPosition();
	auto pos = m2wMatrix * glm::vec4(lpos.x, lpos.y, lpos.z, 1.0f);

	auto result = vpMatrix * glm::vec4(pos.x, pos.y, pos.z, 1.0f);

	std::cout << result.x << " " << result.y << " " << result.z << " " << result.w << std::endl;

	if (mesh->isIndexed())
		glDrawElements(GL_TRIANGLES, mesh->indicesCount(), GL_UNSIGNED_INT, reinterpret_cast<void *>(0));
	else
		glDrawArrays(GL_TRIANGLES, 0, mesh->verticesCount());
}

std::unique_ptr<BaseRenderer> BaseRenderer::create(GameObject* gameObject, std::shared_ptr<Material> material, std::shared_ptr<Mesh> mesh)
{
	return std::make_unique<BaseRenderer>(gameObject, material, mesh);
}
