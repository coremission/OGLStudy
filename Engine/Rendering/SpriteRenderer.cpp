#include "SpriteRenderer.h"
#include "ShaderProgram.h"
#include "MeshManager.h"

#include <memory>
#include <iostream>
#include "TextureManager.h"

LegacySpriteRenderer::LegacySpriteRenderer(GameObject* _gameObject, std::shared_ptr<Texture> _texture):
	BaseRenderer(_gameObject, ShaderProgram::getDefaultSpriteProgram(), MeshManager::getQuadMesh()),
	sprite(std::make_unique<Sprite>(_texture))
{
}

void LegacySpriteRenderer::render() const
{
	// bind VAO
	glBindVertexArray(mesh->vao);

	GLuint program = material->programId();
	glUseProgram(program);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, sprite->getTextureId());

	GLuint rotationLocation = glGetUniformLocation(program, "Model2World");
	glm::mat4 combined = _gameObject->transform->getLocalToWorldMatrix();
	glUniformMatrix4fv(rotationLocation, 1, GL_FALSE, &combined[0][0]);

	//draw 6 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// unbind program and VAO
	glUseProgram(0);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

LegacySpriteRenderer::~LegacySpriteRenderer()
{
	std::cout << "~spriteRenderer.destructor " << std::endl;
}

std::unique_ptr<LegacySpriteRenderer> LegacySpriteRenderer::create(GameObject* _gameObject, const std::string& spriteFileName)
{
	auto renderer = std::make_unique<LegacySpriteRenderer>(_gameObject, TextureManager::getTexture(spriteFileName));
	return renderer;
}

/////////////////////////////////////////////////////////////////////////
/// new sprite renderer
/////////////////////////////////////////////////////////////////////////
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