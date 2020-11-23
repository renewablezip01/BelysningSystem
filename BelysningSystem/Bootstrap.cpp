#include <iostream>
#include <Windows.h>
#include <thread>
#include "Component.h"
#include "TimeHandler.h"

int main() {
	/* Main clock */
	TimeSystem::Clock cl({ 0,0,5 });

	/* Time points */
	TimeSystem::TimePoint p1(0, 0, 10);
	TimeSystem::TimePoint p2(0, 0, 15);
	/* Components */
	ComponentSystem::Button sensor("Sensor", 1);
	ComponentSystem::LightLED led("Light", 2);
	/* Logic loop in a new thread */
	std::thread clock([&]() {
		while (true) {
			cl.Update();
			sensor.Update();
			led.Logic((cl > p1 && cl < p2) || sensor.GetState());
			//std::cout << led.GetBool() << "\n";
			Sleep(1);
		}
		});
	clock.join();
}