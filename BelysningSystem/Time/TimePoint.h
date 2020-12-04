/// <summary>
/// Sets a time point which can be used to check if the time point was hit by using operators.
/// </summary>

#pragma once
#include <iostream>

namespace TimeSystem {

	class TimePoint {
	public:
		TimePoint(int32_t hour, int32_t minute, int32_t second) : m_Hour(hour), m_Minute(minute), m_Second(second) { }
	public:
		/* Operator overloads used to add logic to the LED */
		bool operator==(const TimePoint& other);
		bool operator>(const TimePoint& other);
		bool operator>=(const TimePoint& other);
		bool operator<(const TimePoint& other);
		TimePoint operator+(const TimePoint& other);
		TimePoint operator-(const TimePoint& other);
		friend std::ostream& operator<<(std::ostream& os, const TimePoint& other);
	private:
		friend class Clock;
		int32_t m_Hour, m_Minute, m_Second;
	};

}