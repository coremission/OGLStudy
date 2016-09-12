#ifndef APPLICATION_h
#define APPLICATION_h
#include "Model/GameObject.h"
#include "Model/Scene.h"

class Application
{
private:
	static std::unique_ptr<Models::Scene> scene;
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
	static void initialize(int* argc, char** argv);
	static void runMainLoop();
	static void leaveMainLoop();
	static void exit();

	friend class GameObject;
};

#endif // APPLICATION_h