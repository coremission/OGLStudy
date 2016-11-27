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

// Basic Mesh
class BaseMesh {
public:
	GLuint vao;
	virtual ~BaseMesh() = default; // there must be glDeleteArrayObjects
};

template<typename VertexData>
class Mesh: public BaseMesh {
	std::vector<VertexData> data;
};

template<typename DerivedRenderer, typename Traits>
class Renderer : public IRenderer {
protected:
	typename Traits::MeshData meshData;
	std::shared_ptr<BaseMesh> mesh;
	std::shared_ptr<ShaderProgram> shaderProgram;

	constexpr DerivedRenderer* derived() { return static_cast<DerivedRenderer*>(this); }
	// constructor
	Renderer(std::shared_ptr<BaseMesh>);
public:
	virtual void render() const override {
		// 1. bind mesh to context (bind VAO)

		// 2. use shader program

		// 3. set up uniform parameters

		// 4. draw (glDrawArrays, glDrawElements if mesh is indexed)
	};
	virtual ~Renderer() = default;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////DEFINITIONS///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

template <typename DerivedRenderer, typename Traits>
Renderer<DerivedRenderer, Traits>::Renderer(std::shared_ptr<BaseMesh> _mesh):
	// 1. Load mesh
	mesh(_mesh),
	// 2. Load shader program
	shaderProgram(ShaderProgram::get(Traits::ShaderProgramName, Traits::VertexShaderPath, Traits::FragmentShaderPath))
{
	// 3. Validate shader program (IF DEBUG)
}

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
};

class SkyboxRenderer : public Renderer<SkyboxRenderer, SkyboxMaterialTraits> {
	friend class Renderer<SkyboxRenderer, SkyboxMaterialTraits>;
public:
	virtual void render() const override { std::cout << "render skybox perfectly"; };
	virtual ~SkyboxRenderer() override { std::cout << std::endl << "~SkyboxRenderer" << std::endl; };
};

#endif //RUDY_RENDERING_HPP