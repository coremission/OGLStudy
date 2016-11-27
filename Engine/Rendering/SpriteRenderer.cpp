#include "SpriteRenderer.h"
#include "ShaderProgram.h"
#include "MeshManager.h"
#include "TextureManager.h"

#include <memory>

SpriteRenderer::SpriteRenderer(GameObject* _gameObject, const std::string& spriteFileName):
	Renderer(MeshManager::getDefaultSpriteMesh()),
	gameObject(_gameObject),
	spriteTexture(TextureManager::getTexture(spriteFileName))
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::render() const
{
	// 1. bind vao
	glBindVertexArray(mesh->vao);

	// 2. use program
	GLuint program = shaderProgram->programId();
	glUseProgram(program);

	// 3. fill uniform variables
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, spriteTexture->id);

	GLuint rotationLocation = glGetUniformLocation(program, "Model2World");
	glm::mat4 combined = gameObject->transform->getLocalToWorldMatrix();
	glUniformMatrix4fv(rotationLocation, 1, GL_FALSE, &combined[0][0]);

	// 4. draw	
	// 6 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// 5. unbind program, texture and VAO
	glUseProgram(0);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}