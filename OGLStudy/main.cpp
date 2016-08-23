#include "Application.h"
#include <iostream>

int main(int argc, char **argv)
{
	try {
		Application app;
		app.initialize(&argc, argv);
		app.runMainLoop();
	}
	catch (std::exception exc) {
		std::cout << exc.what();
	}

	std::cout << std::endl << "Press any key to exit..." << std::endl;
	char temp = std::cin.get();

	return 0;
}
