#include "SpriteRenderer.h"
#include "MaterialManager.h"
#include "MeshManager.h"

#include <memory>
#include <iostream>

SpriteRenderer::SpriteRenderer(GameObject* _gameObject):
	BaseRenderer(_gameObject, MaterialManager::getDefaultSpriteMaterial(), MeshManager::getQuadMesh())
{
}

SpriteRenderer::~SpriteRenderer()
{
	std::cout << "~spriteRenderer.destructor " << std::endl;
}

std::unique_ptr<SpriteRenderer> SpriteRenderer::create(GameObject* _gameObject, const std::string& _spriteName)
{
	return std::make_unique<SpriteRenderer>(_gameObject);
}
