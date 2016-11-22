#ifndef SPRITERENDERER_h
#define SPRITERENDERER_h

#include "rendering.hpp"
#include "BaseRenderer.h"
#include <Model/GameObject.h>
#include "Sprite.h"

#include <memory>

class GameObject;
class LegacySpriteRenderer: public BaseRenderer
{
private:
	std::unique_ptr<Sprite> sprite;
public:
	LegacySpriteRenderer(GameObject*, std::shared_ptr<Texture>);
	virtual void render() const override;
	virtual ~LegacySpriteRenderer() override;
	static std::unique_ptr<LegacySpriteRenderer> create(GameObject*, const std::string&);
};


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

struct SpriteMaterialTraits {
	static constexpr const char * ShaderProgramName = "default_sprite_shader_prog";
	static constexpr const char * VertexShaderPath = "Shaders\\Vertex.glsl";
	static constexpr const char * FragmentShaderPath = "Shaders\\Fragment.glsl";
	typedef float PerVertexData;
	typedef std::vector<PerVertexData> MeshData;
	typedef Mesh<PerVertexData> Mesh;

	class MeshAllocator {
	public:
		static void allocate(MeshData&& dataContainer) {};
		static void deallocate() {};
	};
};

class SpriteRenderer: public Renderer<SpriteRenderer, SpriteMaterialTraits>
{
	friend class Renderer<SpriteRenderer, SpriteMaterialTraits>;
	GameObject* gameObject;
public:
	SpriteRenderer(GameObject* gameObject, const std::string& spriteFileName);
	virtual ~SpriteRenderer() override;
	virtual void render() const override { std::cout << "render sprite perfectly" << std::endl; };
};

#endif //SPRITERENDERER_h