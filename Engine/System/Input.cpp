﻿#include "Input.h"
#include <set>

using namespace std;

// static fields
glm::vec2 Input::mousePosition;
set<Input::KeyCodeType> Input::keysPressed;

void Input::registerKeyPressed(KeyCodeType key)
{
	keysPressed.insert(key);
}

void Input::resetKeyPressed(KeyCodeType key)
{
	for (auto it = keysPressed.begin(); it != keysPressed.end();) {
		if (*it == key) {
			keysPressed.erase(it);
			return;
		}
		++it;
	}
}

bool Input::checkIfKeyPressed(KeyCodeType key)
{
	return find(keysPressed.begin(), keysPressed.end(), key) != keysPressed.end();
}
