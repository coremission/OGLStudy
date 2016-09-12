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
	// keyboard (key up/down)
	static void processKeyDown(unsigned char, int, int);
	static void processKeyUp(unsigned char, int, int);

	static void processMousePress(int, int, int, int);
	static void processMouseFreeMove(int, int);
	static void processMousePressedMove(int, int);
	static void drawGameObject(GameObject&);
	Application();
	Application(const Application&);
	const Application& operator=(Application&);
public:
	static void setUpScene(std::shared_ptr<Models::Scene>);
	static void initialize(int* argc, char** argv);
	static void runMainLoop();
	static void leaveMainLoop();
	static void exit();
};

#endif // APPLICATION_h