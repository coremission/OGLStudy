#ifndef RUDY_RENDERING_HPP
#define RUDY_RENDERING_HPP

#include "ShaderProgram.h"

#include <vector>
#include <iostream>
#include <memory>

// Basic interface to Use in GameObject
class IRenderer {
public:
	virtual void render() const {};
	virtual ~IRenderer() = default;
};

template<typename VertexData>
class Mesh {
	int vao;
	std::vector<VertexData> data;
};

template<typename DerivedRenderer, typename Traits>
class Renderer : public IRenderer {
protected:
	typename Traits::MeshData meshData;
	typename Traits::UniformData uniformData;
	std::shared_ptr<typename Traits::Mesh> mesh;
	std::shared_ptr<ShaderProgram> shaderProgram;

	constexpr DerivedRenderer* derived() { return static_cast<DerivedRenderer*>(this); }
	// constructor
	Renderer():
		// 1. Load mesh
		mesh(nullptr),
		// 2. Load shader program
		shaderProgram(ShaderProgram::get("spriteProgram", Traits::VertexShaderPath, Traits::FragmentShaderPath))
	{
		// 3. Validate shader program (IF DEBUG)
	}
public:
	virtual void render() const override {
		// 1. bind mesh to context (bind VAO)

		// 2. use shader program

		// 3. set up uniform parameters

		// 4. draw (glDrawArrays, glDrawElements if mesh is indexed)
	};
	virtual ~Renderer() = default;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SPECIFIC RENDERER IMPLEMENTATION //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CubeMaterialTraits {
	const char * ShaderProgramName = "";
	const char * VertexShaderPath = "";
	const char * FragmentShaderPath = "";

	struct PerVertexData {
		int position;
		int normal;
		int color;
		int uv;
	};
	typedef std::vector<PerVertexData> MeshData;
	typedef Mesh<PerVertexData> Mesh;

	class MeshAllocator {
	public:
		static std::shared_ptr<Mesh> allocate(MeshData&& dataContainer) {};
		static void deallocate() {};
	};

	struct UniformData {
		int diffuseTexture;
		int specularTexture;
		int Time;
		int ModelingMatrix;
		int MVPMatrix;
		int IT_MVPMatrix;
		// ... etc
	};
};

class CubeRenderer : public Renderer<CubeRenderer, CubeMaterialTraits> {
	friend class Renderer<CubeRenderer, CubeMaterialTraits>;
public:
	virtual void render() const override { std::cout << "render cube perfectly"; };
	virtual ~CubeRenderer() override { std::cout << std::endl << "~CubeRenderer" << std::endl; };
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SKYBOX RENDERER IMPLEMENTATION ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct SkyboxMaterialTraits {
	const char * ShaderProgramName = "";
	const char * VertexShaderPath = "";
	const char * FragmentShaderPath = "";
	// skybox is simple positions-only mesh (here must be glm::vec3);
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

class SkyboxRenderer : public Renderer<SkyboxRenderer, SkyboxMaterialTraits> {
	friend class Renderer<SkyboxRenderer, SkyboxMaterialTraits>;
public:
	virtual void render() const override { std::cout << "render skybox perfectly"; };
	virtual ~SkyboxRenderer() override { std::cout << std::endl << "~SkyboxRenderer" << std::endl; };
};

#endif //RUDY_RENDERING_HPP