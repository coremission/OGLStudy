#ifndef PARTICLE_SYSTEM_h
#define PARTICLE_SYSTEM_h
#include <Model/Component.h>
#include <memory>
#include <Rendering/Material.h>

class ParticleSystem: public Component
{
private:
	const int MaxParticlesCount;
	std::shared_ptr<Material> material;
	GLuint vao;
	void createBaseQuad();
public:
	explicit ParticleSystem(GameObject* game_object);
	void Start() override;
	void Update() override;
	~ParticleSystem() override;
};

#endif //PARTICLE_SYSTEM_h