#include <iostream>
#include <vector>
#include <memory>

#include "rendering.hpp"

using namespace std;

void _do();

int main(int argc, char** argv)
{
	_do();

	cout << endl << "Press any key to exit..." << endl;
	cin.get();
	return 0;
}

void _do() {
	unique_ptr<IRenderer> renderer = std::make_unique<CubeRenderer>();
	unique_ptr<IRenderer> skyboxRenderer = std::make_unique<SkyboxRenderer>();
	renderer->render();
}