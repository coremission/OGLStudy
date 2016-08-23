#include "Application.h"
#include <iostream>
#include <memory>

const char * TRIANGLE_NAME = "triangle1";

int main(int argc, char **argv)
{
	auto sceneShared = std::make_shared<Models::Scene>();
	sceneShared->CreateTriangleModel(TRIANGLE_NAME);

	try {
		Application::initialize(&argc, argv);
		Application::setUpScene(sceneShared);
		Application::runMainLoop();
	}
	catch (std::exception exc) {
		Application::exit();
		std::cout << exc.what();
	}

	std::cout << std::endl << "Press any key to exit..." << std::endl;
	char temp = std::cin.get();

	return 0;
}
