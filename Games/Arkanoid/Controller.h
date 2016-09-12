#ifndef CONTROLLER_h
#define CONTROLLER_h

#include <Model/Component.h>
#include <Model/Scene.h>

class Controller: public Component {
private:
	
public:
	explicit Controller(GameObject*);
	virtual void Update() override;
	virtual void Start() override;
	virtual ~Controller() override;
};
#endif //CONTROLLER_h