#include "SpriteRenderer.h"
#include "MaterialManager.h"
#include "MeshManager.h"

#include <memory>
#include <iostream>
#include "TextureManager.h"

SpriteRenderer::SpriteRenderer(GameObject* _gameObject, std::shared_ptr<Texture> _texture):
	BaseRenderer(_gameObject, MaterialManager::getDefaultSpriteMaterial(), MeshManager::getQuadMesh()),
	sprite(std::make_unique<Sprite>(_texture))
{
}

void SpriteRenderer::render() const
{
	// TODO: introduce time
	float time = 1.0f;

	// bind VAO
	glBindVertexArray(mesh->vao);

	GLuint program = material->programId();
	glUseProgram(program);

	glBindTexture(GL_TEXTURE_2D, sprite->getTextureId());

	// set uniform variables
	//GLuint timeLocation = glGetUniformLocation(program, "time");
	//glUniform1f(timeLocation, time);

	GLuint rotationLocation = glGetUniformLocation(program, "Model2World");
	glm::mat4 combined = _gameObject->transform->getLocalToWorldMatrix();
	glUniformMatrix4fv(rotationLocation, 1, GL_FALSE, &combined[0][0]);

	//GLuint textureLocation = glGetUniformLocation(material->programId(), "mySampler");
	//glUniform1f(textureLocation, 0);// sprite->getTextureId());
	//glBindTexture(GL_TEXTURE_2D, sprite->getTextureId());
	// use texture
	glActiveTexture(GL_TEXTURE0);

	//draw 6 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// unbind program and VAO
	glUseProgram(0);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

SpriteRenderer::~SpriteRenderer()
{
	std::cout << "~spriteRenderer.destructor " << std::endl;
}

std::unique_ptr<SpriteRenderer> SpriteRenderer::create(GameObject* _gameObject, const std::string& spriteFileName)
{
	auto renderer = std::make_unique<SpriteRenderer>(_gameObject, TextureManager::getTexture(spriteFileName));
	return renderer;
}
