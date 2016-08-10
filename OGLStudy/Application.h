#ifndef APPLICATION_h
#define APPLICATION_h
#include "Models.h"

class Application
{
private:
	static Models::Scene* _gameModel;
	static void renderScene();
	static void processInput(unsigned char, int, int);
	static void exit();
public:
	void initialize(int* argc, char** argv);
	void runMainLoop();
	
	~Application();
};

#endif // APPLICATION_h