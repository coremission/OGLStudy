#ifndef APPLICATION_h
#define APPLICATION_h
#include "Model/GameObject.h"
#include "Model/Scene.h"

class Application
{
private:
	static Models::Scene* _scene;
	static void renderScene();
	static void processInput(unsigned char, int, int);
	static void exit();
	static void drawGameObject(GameObject&, float);
public:
	void initialize(int* argc, char** argv);
	void runMainLoop();
	
	~Application();
};

#endif // APPLICATION_h