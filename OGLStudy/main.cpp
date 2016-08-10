#include "Application.h"

int main(int argc, char **argv)
{
	Application app;
	app.initialize(&argc, argv);
	app.runMainLoop();
	
	return 0;
}
