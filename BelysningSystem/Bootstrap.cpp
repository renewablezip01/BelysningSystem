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

	/* Main clock */
	TimeSystem::Clock cl({ 0,0,5 });

	/* Time points */
	TimeSystem::TimePoint p1(0, 0, 10);
	TimeSystem::TimePoint p2(0, 0, 15);

	/* Components */
	ComponentSystem::Button sensor("Sensor", 1);
	ComponentSystem::LED led("Light", 2);

	/* Logic loop */
	while (true) {
		sensor.Update();
		led.Logic(cl > p1 && cl < p2 || sensor.GetState());

		if (cl.Update()) {
			std::cout << cl << "\n";
			std::cout << "Led: " << std::boolalpha << (led.GetBool() ? "On" : "Off") << "\n";
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}