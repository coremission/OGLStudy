#ifndef CAMERA_h
#define CAMERA_h

#include <Model/Component.h>

class Camera: public Component
{
public:
	explicit Camera(GameObject*);
	virtual void Update() override;
	virtual void Start() override;
};

#endif //CAMERA_h