#ifndef PARTICLE_SYSTEM_h
#define PARTICLE_SYSTEM_h
#include <Model/Component.h>

class ParticleSystem: public Component
{
public:
	explicit ParticleSystem(GameObject* game_object);
	void Start() override;
	void Update() override;
	~ParticleSystem() override;
};

#endif //PARTICLE_SYSTEM_h