#pragma once
#include <vector>
#include <iostream>

// Basic interface to Use in GameObject
class IRenderer {
public:
	virtual void render() {};
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
	Mesh<typename Traits::PerVertexData> mesh;
	typename Traits::UniformData uniformData;

	constexpr DerivedRenderer* derived() { return static_cast<DerivedRenderer*>(this); }
	// constructor
	Renderer() {
		// 1. Load mesh

		// 2. Load shader program

		// 3. Validate shader program (IF DEBUG)
	}
public:
	virtual void render() override {
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
	const char * VertexShaderPath = "";
	const char * FragmentShaderPath = "";

	struct PerVertexData {
		int position;
		int normal;
		int color;
		int uv;
	};
	typedef std::vector<PerVertexData> MeshDataContainer;

	class MeshAllocator {
	public:
		static void allocate(MeshDataContainer&& dataContainer) {};
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
	virtual void render() override { std::cout << "render cube perfectly"; };
	virtual ~CubeRenderer() override { std::cout << std::endl << "~CubeRenderer" << std::endl; };
};