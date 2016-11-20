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
	const char * ShaderProgramName = "";
	const char * VertexShaderPath = "";
	const char * FragmentShaderPath = "";
	typedef float PerVertexData;
	typedef std::vector<PerVertexData> MeshData;
	typedef Mesh<PerVertexData> Mesh;

	class MeshAllocator {
	public:
		static void allocate(MeshData&& dataContainer) {};
		static void deallocate() {};
	};

	struct UniformData {
		int top;
		int bottom;
		int front;
		int back;
		int left;
		int right;
		// ... etc
	};
};

class SpriteRenderer: public Renderer<SpriteRenderer, SpriteMaterialTraits>
{
	friend class Renderer<SpriteRenderer, SpriteMaterialTraits>;
public:
	virtual ~SpriteRenderer() override;
	virtual void render() const override { std::cout << "render skybox perfectly"; };
};

#endif //SPRITERENDERER_h