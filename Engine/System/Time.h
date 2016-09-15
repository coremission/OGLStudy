#ifndef TIME_h
#define TIME_h

#include <ctime>
#include <Application.h>

class Time
{
public:
	static float time;
	static float realTimeSinceStartup;
	static float deltaTime;

	static void updateClock();
	friend class Application;
};

#endif //TIME_h