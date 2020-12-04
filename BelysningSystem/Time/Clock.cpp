#include <iostream>
#include "Clock.h"

namespace TimeSystem {
	/* Our Clock constructor */
	Clock::Clock(const TimePoint& startTime) : time(startTime)
	{
		startUpdater = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	}

	/* Used inside a loop to update the clock. Returns the tick of the clock */
	bool Clock::Update()
	{
		/* Uses chrono instead of Sleep() because we don't want to sleep the thread and pause all our executions. */
		nextUpdater = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());


		/* Logic of our clock */
		if (time.m_Second > 59) {
			time.m_Second = 0;
			time.m_Minute = time.m_Minute + 1;

			if (time.m_Minute > 60) {
				time.m_Minute = 0;
				time.m_Hour = time.m_Hour + 1;

				if (time.m_Hour > 24) {
					time.m_Hour = 0;
				}
			}
		}

		if ((nextUpdater - startUpdater).count() >= 1000) {
			startUpdater = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
			time.m_Second++;
			return true;
		}
		return false;
	}
	/* Operator overloads to match those of TimePoint class */
	bool Clock::operator==(const TimePoint& other)
	{
		return time == other;
	}
	bool Clock::operator>(const TimePoint& other)
	{
		return this->time > other;
	}
	bool Clock::operator>=(const TimePoint& other)
	{
		return this->time >= other;

	}
	bool Clock::operator<(const TimePoint& other)
	{
		return this->time < other;

	}
	std::ostream& operator<<(std::ostream& os, const TimePoint& other)
	{
		os << other.m_Hour << ":" << other.m_Minute << ":" << other.m_Second;
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Clock& cl)
	{
		os << cl.time;
		return os;
	}
}