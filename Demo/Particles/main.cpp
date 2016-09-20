#include <Application.h>
#include <Rendering/SpriteRenderer.h>
#include <ParticleSystem/ParticleSystem.h>

#include <iostream>

using namespace std;

void _do(int, char**);
void setUpScene();

int main(int argc, char **argv)
{
	_do(argc, argv);
	cout << endl << "Press any key to exit..." << endl;
	cin.get();

	return 0;
}

// this one exist to see destructors outputs
void _do(int argc, char **argv) {
	try {
		Application::initialize(&argc, argv);
		setUpScene();
		Application::runMainLoop();
		Application::exit();
	}
	catch (exception exc) {
		Application::leaveMainLoop();
		Application::exit();
		cout << exc.what();
	}
}

void setUpScene()
{
	GameObject* go = new GameObject("particleSystem");
	ParticleSystem * particleSystem = new ParticleSystem(go);
	go->AddComponent<ParticleSystem>(particleSystem);
}