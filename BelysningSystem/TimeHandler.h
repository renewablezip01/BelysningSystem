/// <summary>
/// Takes care of all the timing we will need for our circut
/// </summary>
#pragma once
#include <chrono>
#include <Windows.h>

namespace TimeSystem {

	/// <summary>
	/// Sets a time point which can be used to check if the time point was hit.
	/// </summary>
	class TimePoint {
	public:
		TimePoint(int32_t hour, int32_t minute, int32_t second) : m_Hour(hour), m_Minute(minute), m_Second(second) { }
	public:
		bool operator==(const TimePoint& other);
		bool operator>(const TimePoint& other);
		bool operator<(const TimePoint& other);
		friend std::ostream& operator<<(std::ostream& os,const TimePoint& other);
	private:
		friend class Clock;
		int32_t m_Hour, m_Minute, m_Second;
	};

	/// <summary>
	/// Used to get a updated time from a starting time point.
	/// </summary>
	class Clock {
	public:
		Clock(const TimePoint& startTime) : startUpTime(startTime) {
			startUpdater = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		}
		/* Update this inside a new thread loop */
		void Update();

	public:
		bool operator==(const TimePoint& other);
		bool operator>(const TimePoint& other);
		bool operator<(const TimePoint& other);
	private:
		TimePoint startUpTime;
		std::chrono::milliseconds startUpdater, nextUpdater;
	};
}
