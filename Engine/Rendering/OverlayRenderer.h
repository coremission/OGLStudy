﻿#ifndef OVERLAYRENDERER_h
#define OVERLAYRENDERER_h

#include "rendering.hpp"
#include "Sprite.h"
#include <Model/GameObject.h>
#include <memory>

struct OverlayMaterialTraits {
	static constexpr const char * ShaderProgramName = "default_overlay_shader_prog";
	static constexpr const char * VertexShaderPath = "Shaders\\Overlay_Vertex.glsl";
	static constexpr const char * FragmentShaderPath = "Shaders\\Overlay_Fragment.glsl";
	typedef float PerVertexData;
	typedef std::vector<PerVertexData> MeshData;
	typedef Mesh<PerVertexData> Mesh;
};

class OverlayRenderer: public Renderer<OverlayRenderer, OverlayMaterialTraits>
{
	friend class Renderer<OverlayRenderer, OverlayMaterialTraits>;
	GameObject* gameObject;
	std::shared_ptr<Texture> spriteTexture;
public:
	OverlayRenderer(GameObject* gameObject, const std::string& spriteFileName);
	virtual ~OverlayRenderer() override;
	virtual void render() const override;
};

#endif //OVERLAYRENDERER_h