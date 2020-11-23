#include <iostream>
#include <Windows.h>
#include <thread>
#include "Component.h"
#include "TimeHandler.h"

void bla() {

}
int main() {
	TimePoint d(1, 54, 50);
	TimePoint d2(1, 55, 5);
	std::thread clock([&]() {
		while (true) {
			d.UpdateClock();
			Sleep(1);
		}
		});
	//ComponentSystem::Button sensor2("Sensor22", 0);
	//clock.join();
	//std::chrono::seconds start = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());
	//std::chrono::seconds next;
	//while (true) {
	//	next = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());
	//	if ((next - start).count() == 5) {
	//		start = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch());
	//		std::cout << "Second passed" << "\n";
	//	}
	//	Sleep(1);
	//}
	clock.join();
}