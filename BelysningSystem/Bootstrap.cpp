#include <iostream>
#include <thread>

#include "Time/Clock.h"
#include <Windows.h>

/* Components we will be using */
#include "Component/Button/Button.h"
#include "Component/LED/LED.h"

static bool StartUp() {
	/* Setup wiringPi here... */
	return true;
}

int main() {

	/* Initializes everything needed at startup */
	if (!StartUp()) return 1;

	/* Used to grab a handle of our Console window so that we could modify the console to output colors. */
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int blinker = 1000;

	/* Main clock */
	TimeSystem::Clock cl({ 0,0,0 });
	/* Time points */
	TimeSystem::TimePoint tp_StralkastareClicked(0, 0, 0);
	TimeSystem::TimePoint tp_FramforHusetSensorClicked(0, 0, 0);
	TimeSystem::TimePoint tp_RingKlockaClicked(0, 0, 0);

	TimeSystem::TimePoint tp_BakomHusetStart(0, 0, 5);
	TimeSystem::TimePoint tp_BakomHusetStopp(0, 0, 10);

	TimeSystem::TimePoint tp_BestamdTidStart(0, 0, 5);
	TimeSystem::TimePoint tp_BestamdTidStopp(0, 0, 10);


	/* Components */
	// Buttons
	ComponentSystem::Button b_Stralkastare("Knapp Strålkastare", VK_F1);
	ComponentSystem::Button b_Porten("Knapp Porten", VK_F2);
	ComponentSystem::Button b_BakomHuset("Knapp Bakom Garagen", VK_F3);
	ComponentSystem::Button b_BakomHusetSensor("Sensor Bakom Garagen", VK_F4);
	ComponentSystem::Button b_Ringklocka("Ringklocka", VK_F5);


	// LEDS
	ComponentSystem::LED l_Stralkastare("Strålkastare", 2);
	ComponentSystem::LED l_InneIGaragen("Inne i garagen", 3);
	ComponentSystem::LED l_BakomHuset("Bakom garagen", 3);

	ComponentSystem::LED l_BlinkingLED("Blinking LED", 3);


	/* Logic loop */
	while (true) {
		cl.Update();
		b_Stralkastare.Update();
		b_Porten.Update();
		b_BakomHuset.Update();
		b_BakomHusetSensor.Update();
		b_Ringklocka.Update();

		/* Our LED login */
		l_InneIGaragen.Logic(b_Porten.GetState());
		l_Stralkastare.Logic((cl < tp_StralkastareClicked) || (cl > tp_BestamdTidStart && cl < tp_BestamdTidStopp));
		l_BakomHuset.Logic((cl > tp_BakomHusetStart && cl < tp_BakomHusetStopp) || (cl < tp_FramforHusetSensorClicked) || (cl > tp_BestamdTidStart && cl < tp_BestamdTidStopp) || (b_BakomHuset.GetState()));
		/* A quick way to make a 4 hertz blinking LED */
		l_BlinkingLED.Logic(cl < tp_RingKlockaClicked ? (blinker % 4 == 0) : false);
		
		/* Other logic goes under here */
		/* Adds time to timepoints once a button is pressed. This keep the LED on until timepoint is out of reach. */
		if (b_Stralkastare.GetState()) tp_StralkastareClicked = cl.time + TimeSystem::TimePoint(0, 0, 5);
		if (b_BakomHusetSensor.GetState()) tp_FramforHusetSensorClicked = cl.time + TimeSystem::TimePoint(0, 0, 3);
		if (b_Ringklocka.GetState()) tp_RingKlockaClicked = cl.time + TimeSystem::TimePoint(0, 0, 10);

		/* Countdown when light turns back off */
		const int& bakomHusetTime = (cl > tp_BakomHusetStart && cl < tp_BakomHusetStopp) ? (tp_BakomHusetStopp.ToSeconds() - cl.time.ToSeconds()) : 0;
		const int& bakomHusetPress = (cl < tp_FramforHusetSensorClicked) ? (tp_FramforHusetSensorClicked.ToSeconds() - cl.time.ToSeconds()) : 0;
		const int& stralkastare = l_Stralkastare.GetBool() ? (tp_StralkastareClicked.ToSeconds() - cl.time.ToSeconds()) : 0;
		const int& blinking = (cl < tp_RingKlockaClicked) ? (tp_RingKlockaClicked.ToSeconds() - cl.time.ToSeconds()) : 0;
		const int& bestamdTime = (cl > tp_BestamdTidStart && cl < tp_BestamdTidStopp) ? (tp_BestamdTidStopp.ToSeconds() - cl.time.ToSeconds()) : 0;
		
		{
			/* Clock starts here */
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << static_cast<std::string>(cl) << ". ";
			SetConsoleTextAttribute(hConsole, 15);
			/* ~ Clock ends here. */
			
			std::cout << l_Stralkastare.GetName() << (l_Stralkastare.GetBool() ? " On" : " Off") << " " << ((stralkastare) >= 0 ? ((bestamdTime > 0) ? bestamdTime : stralkastare) : bestamdTime)  << " | ";
			std::cout << l_InneIGaragen.GetName() << (l_InneIGaragen.GetBool() ? " On" : " Off") << " | ";
			std::cout << l_BlinkingLED.GetName() << (l_BlinkingLED.GetBool() ? " On " : " Off") << " " << blinking << " | ";
			std::cout << l_BakomHuset.GetName() << (l_BakomHuset.GetBool() ? " On" : " Off") << " " << ((bakomHusetTime <= 0 && bakomHusetPress > 0) ? bakomHusetPress : ((bestamdTime > 0) ? bestamdTime : bakomHusetTime)) << " | ";

			std::cout << "\r";
		}

		blinker++;
		/* Used to sleep the thread for 1 ms because C++ will use all processing power without this and can cause issues such as CPU overthrottle. */
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}