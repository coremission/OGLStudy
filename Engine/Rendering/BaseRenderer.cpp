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

std::unique_ptr<BaseRenderer> BaseRenderer::create(GameObject* gameObject, std::shared_ptr<Material> material, std::shared_ptr<Mesh> mesh)
{
	return std::make_unique<BaseRenderer>(gameObject, material, mesh);
}
