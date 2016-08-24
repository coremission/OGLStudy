#ifndef APPLICATION_h
#define APPLICATION_h
#include "Model/GameObject.h"
#include "Model/Scene.h"
#include <memory>

class Application
{
private:
	static std::shared_ptr<Models::Scene> _scene;

	static void renderScene();
	static void processInput(unsigned char, int, int);
	static void drawGameObject(GameObject&, float);
	Application();
	Application(const Application&);
	const Application& operator=(Application&);
public:
	static void exit();
	static void setUpScene(std::shared_ptr<Models::Scene>);
	static void initialize(int* argc, char** argv);
	static void runMainLoop();
};

#endif // APPLICATION_h