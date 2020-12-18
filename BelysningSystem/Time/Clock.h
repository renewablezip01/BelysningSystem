/// <summary>
/// Takes care of all the timing we will need for our circut
/// </summary>

#pragma once
#include <chrono>
#include "TimePoint.h"

namespace TimeSystem {
	/// <summary>
	/// Used to get a updated time from a starting time point.
	/// </summary>
	class Clock {
	public:
		Clock(const TimePoint& startTime);

		/* Updates the clock inside a loop. Returns the tick of the clock */
		bool Update();
	public:
		/* Operator overloads to match those of TimePoint class */
		bool operator==(const TimePoint& other);
		bool operator>(const TimePoint& other);
		bool operator>=(const TimePoint& other);
		bool operator<(const TimePoint& other);
		bool operator<=(const TimePoint& other);
		friend std::ostream& operator<<(std::ostream& os, const Clock& cl);
		operator std::string();
		TimePoint time;

	private:
		std::chrono::milliseconds startUpdater, nextUpdater;
	};
}
