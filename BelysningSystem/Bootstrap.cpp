#include <iostream>
#include <thread>

#include "Time/Clock.h"

/* Components we will be using */
#include "Component/Button/Button.h"
#include "Component/LED/LED.h"

static bool StartUp() {
	/* Setup GPIO here... */
	return true;
}

int main() {
	/* Initializes everything needed at startup */
	if (!StartUp()) return 93;
	int as[4] = { 1,2,3,4 };
	/* Main clock */
	TimeSystem::Clock cl({ 0,0,5 });
	/* Time points */
	TimeSystem::TimePoint p1(0, 0, 5);
	TimeSystem::TimePoint p2(0, 0, 10);
	/* Components */
	ComponentSystem::Button sensor("Sensor", 1);
	ComponentSystem::LED stralkastare("Light", 2);

	TimeSystem::TimePoint clicked1(0, 0, 0);
	TimeSystem::TimePoint clicked2(0, 0, 0);

	/* Logic loop */
	while (true) {
		sensor.Update();
		if (sensor.GetState())
			clicked2 = cl.time + TimeSystem::TimePoint(0, 0, 5);
		stralkastare.Logic(cl < clicked2);



		if (cl.Update()) {
			std::cout << cl << L". Strålkastare: " << std::boolalpha << (stralkastare.GetBool() ? "On" : "Off") << "\n";
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}