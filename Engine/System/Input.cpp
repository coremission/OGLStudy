#include "Input.h"
#include <set>

using namespace std;

// static fields
glm::vec2 Input::mousePosition;
set<uchar> Input::keysPressed;

void Input::registerKeyPressed(uchar key)
{
	keysPressed.insert(key);
}

void Input::resetKeyPressed(uchar key)
{
	for (auto it = keysPressed.begin(); it != keysPressed.end();) {
		if (*it == key) {
			keysPressed.erase(it);
			return;
		}
		else
			++it;
	}
}

bool const Input::checkIfKeyPressed(uchar key)
{
	return find(keysPressed.begin(), keysPressed.end(), key) != keysPressed.end();
}
