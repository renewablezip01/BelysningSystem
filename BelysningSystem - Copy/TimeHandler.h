#pragma once
#include <chrono>
#include <iostream>
#include <Windows.h>

class TimePoint {
public:
	TimePoint(int32_t hour, int32_t minute, int32_t second) : m_Hour(hour), m_Minute(minute), m_Second(second) {
		start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	}
	/* Starts to treat the timepoint as a clock */
	void UpdateClock();

public:
	bool operator==(const TimePoint& other);
private:
	int32_t m_Hour, m_Minute, m_Second;
	std::chrono::milliseconds start, next;
};

class TimeHandler
{
};

