#include <iostream>
#include "TimeHandler.h"

namespace TimeSystem {
	bool TimePoint::operator==(const TimePoint& other)
	{
		if (other.m_Hour == this->m_Hour &&
			other.m_Minute == this->m_Minute &&
			other.m_Second == this->m_Second)
		{
			return true;
		}
		return false;
	}

	bool TimePoint::operator>(const TimePoint& other)
	{
		if (this->m_Hour >= other.m_Hour &&
			this->m_Minute >= other.m_Minute &&
			this->m_Second >= other.m_Second)
		{
			return true;
		}
		return false;
	}

	bool TimePoint::operator<(const TimePoint& other)
	{
		if (this->m_Hour <= other.m_Hour &&
			this->m_Minute <= other.m_Minute &&
			this->m_Second <= other.m_Second)
		{
			return true;
		}
		return false;
	}

	void Clock::Update()
	{
		/* Uses chrono instead of Sleep() because we don't want to sleep the thread and pause all our executions. */
		nextUpdater = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());


		/* Logic of our clock */
		if (startUpTime.m_Second >= 59) {
			startUpTime.m_Second = 0;
			startUpTime.m_Minute = startUpTime.m_Minute + 1;

			if (startUpTime.m_Minute >= 60) {
				startUpTime.m_Minute = 0;
				startUpTime.m_Hour = startUpTime.m_Hour + 1;

				if (startUpTime.m_Hour >= 24) {
					startUpTime.m_Hour = 0;
				}
			}
		}

		if ((nextUpdater - startUpdater).count() >= 1000) {
			startUpdater = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
			startUpTime.m_Second++;
			std::cout << startUpTime << "\n";
		}
	}

	bool Clock::operator==(const TimePoint& other)
	{
		return startUpTime == other;
	}
	bool Clock::operator>(const TimePoint& other)
	{
		return this->startUpTime > other;
	}
	bool Clock::operator<(const TimePoint& other)
	{
		return this->startUpTime < other;

	}
	std::ostream& operator<<(std::ostream& os, const TimePoint& other)
	{
		os << other.m_Hour << ":" << other.m_Minute << ":" << other.m_Second;
		return os;
	}
}