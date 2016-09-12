#ifndef BALLBEHAVIOUR_h
#define BALLBEHAVIOUR_h
#include <Model/Component.h>
#include <glm/vec2.hpp>

class BallBehaviour: public Component
{
private:
	float radius;
	glm::vec2 velocity;
	glm::vec3 position() const { return gameObject->transform->getLocalPosition(); }

	float top() const { return position().y + radius; }
	float bottom() const { return position().y - radius; }
	float left() const { return position().x - radius; }
	float right() const { return position().x + radius; }
public:
	explicit BallBehaviour(GameObject*);
	virtual void Update() override;
	virtual void Start() override;
};

#endif // BALLBEHAVIOUR_h