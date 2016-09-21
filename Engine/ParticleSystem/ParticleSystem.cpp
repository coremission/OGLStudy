#include "ParticleSystem.h"
#include "glew/glew.h"
#include <Rendering/MaterialManager.h>

void ParticleSystem::createBaseQuad()
{
	static const GLfloat g_vertex_buffer_data[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
	};

	static const GLfloat offsets[] = { 0.1f, 0.2f, 0.9f };
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// common data
	GLuint billboard_vertex_buffer;
	glGenBuffers(1, &billboard_vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), reinterpret_cast<void *>(0));
	glEnableVertexAttribArray(0);

	// instance data
	GLuint instaceBuffer;
	glGenBuffers(1, &instaceBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, instaceBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(offsets), offsets, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(float), reinterpret_cast<void*>(0));
	glEnableVertexAttribArray(1);
	glVertexAttribDivisor(1, 1);
	// The VBO containing the positions and sizes of the particles
	//GLuint particles_position_buffer;
	//glGenBuffers(1, &particles_position_buffer);
	//glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
	//// Initialize with empty (NULL) buffer : it will be updated later, each frame.
	//glBufferData(GL_ARRAY_BUFFER, MaxParticlesCount * 4 * sizeof(GLfloat), nullptr, GL_STREAM_DRAW);

	//// The VBO containing the colors of the particles
	//GLuint particles_color_buffer;
	//glGenBuffers(1, &particles_color_buffer);
	//glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
	//// Initialize with empty (NULL) buffer : it will be updated later, each frame.
	//glBufferData(GL_ARRAY_BUFFER, MaxParticlesCount * 4 * sizeof(GLubyte), nullptr, GL_STREAM_DRAW);

	material = MaterialManager::getMaterial("ParticlesBillboard", "Shaders\\ParticleBillboard_Vertex.glsl", "Shaders\\ParticleBillboard_Fragment.glsl");
}

ParticleSystem::ParticleSystem(GameObject* game_object):
	Component(game_object), MaxParticlesCount(10), vao(0)
{
}

void ParticleSystem::Start()
{
	createBaseQuad();
}

void ParticleSystem::Update()
{
	// render in update temporary
	glUseProgram(material->programId());
	glBindVertexArray(vao);

	glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, 3);
	glBindVertexArray(0);
	glUseProgram(0);
}

ParticleSystem::~ParticleSystem()
{
}
