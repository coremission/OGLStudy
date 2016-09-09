#ifndef INPUT_h
#define INPUT_h

#include <Application.h>

#include <glm/glm.hpp>
#include <set>

typedef unsigned char uchar;
class Input
{
private:
	static glm::vec2 mousePosition;
	static std::set<uchar> keysPressed;
	static void registerKeyPressed(uchar);
	static void resetKeyPressed(uchar);
public:
	inline static const glm::vec2 getMousePosition() { return mousePosition; }
	static bool const checkIfKeyPressed(uchar key);
	friend class Application;
};

#endif //INPUT_h