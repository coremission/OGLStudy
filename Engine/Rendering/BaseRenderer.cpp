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
}

BaseRenderer* BaseRenderer::create(GameObject* gameObject, std::shared_ptr<Material> material, std::shared_ptr<Mesh> mesh)
{
	return new BaseRenderer(gameObject, material, mesh);
}
