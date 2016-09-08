#include "SpriteRenderer.h"
#include "MaterialManager.h"
#include "MeshManager.h"

SpriteRenderer::SpriteRenderer(GameObject* _gameObject):
	BaseRenderer(_gameObject, MaterialManager::getDefaultSpriteMaterial(), MeshManager::getQuadMesh())
{
}

SpriteRenderer::~SpriteRenderer()
{
}

SpriteRenderer* SpriteRenderer::create(GameObject* _gameObject, const std::string& _spriteName)
{
	return new SpriteRenderer(_gameObject);
}
