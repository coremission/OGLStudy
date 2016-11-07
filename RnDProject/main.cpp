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
	renderer->render();
}