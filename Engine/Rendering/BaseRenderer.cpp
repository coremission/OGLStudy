#include "BaseRenderer.h"
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

	GLuint rotationLocation = glGetUniformLocation(program, "Model2World");
	glm::mat4 combined = _gameObject->transform->getLocalToWorldMatrix();
	glUniformMatrix4fv(rotationLocation, 1, GL_FALSE, &combined[0][0]);


	if (mesh->isIndexed())
		glDrawElements(GL_TRIANGLES, mesh->verticesCount(), GL_UNSIGNED_INT, reinterpret_cast<void *>(0));
	else
		glDrawArrays(GL_TRIANGLES, 0, mesh->verticesCount());
}

std::unique_ptr<BaseRenderer> BaseRenderer::create(GameObject* gameObject, std::shared_ptr<Material> material, std::shared_ptr<Mesh> mesh)
{
	return std::make_unique<BaseRenderer>(gameObject, material, mesh);
}
