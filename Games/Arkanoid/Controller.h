#ifndef CONTROLLER_h
#define CONTROLLER_h

#include <Model/Component.h>

class Controller: public Component {
public:
	Controller();
	virtual ~Controller() override;
};
#endif //CONTROLLER_h