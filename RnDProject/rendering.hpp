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
struct Mesh {
	std::vector<VertexData> data;
};

template<typename DerivedRenderer, typename Traits>
class Renderer : public IRenderer {
	Mesh<typename Traits::PerVertexData> mesh;
	typename Traits::UniformData uniformData;

	constexpr DerivedRenderer* derived() { return static_cast<DerivedRenderer*>(this); }
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
	class PerVertexData {
		int position;
		int normal;
		int color;
		int uv;
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