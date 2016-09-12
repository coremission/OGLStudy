#ifndef CONTROLLER_h
#define CONTROLLER_h

#include <Model/Component.h>

class Controller: public Component {
public:
	explicit Controller(GameObject*);
	virtual void Update() override;
	virtual void Start() override;
	virtual ~Controller() override;
};
#endif //CONTROLLER_h