#include "TimePoint.h"

#define TimePointToSeconds(timepoint) (timepoint.m_Hour * hoursToSeconds) + (timepoint.m_Minute * minutesToSeconds) + timepoint.m_Second

namespace TimeSystem {
	/* Better than using magic numbers */
	static constexpr int hoursToSeconds = 3600;
	static constexpr int minutesToSeconds = 60;

	/* Operator overloads used to add logic to the LED */
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
		if (this->m_Hour > other.m_Hour &&
			this->m_Minute > other.m_Minute &&
			this->m_Second > other.m_Second)
		{
			return true;
		}
		return false;
	}

	bool TimePoint::operator>=(const TimePoint& other)
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
	TimePoint TimePoint::operator+(const TimePoint& other)
	{
		/* Sets all time to seconds */
		int tempTotalSec = TimePointToSeconds((*this)) + TimePointToSeconds(other);
		/* Converts the seconds to H:M:S */
		TimePoint re((tempTotalSec / hoursToSeconds) % 24, (tempTotalSec / minutesToSeconds) % 600, tempTotalSec % 60);
		return re;
	}
	TimePoint TimePoint::operator-(const TimePoint& other)
	{
		/* Sets all time to seconds */
		int tempTotalSec = TimePointToSeconds((*this)) - TimePointToSeconds(other);
		/* Converts the seconds to H:M:S */
		TimePoint re((tempTotalSec / hoursToSeconds) % 24, (tempTotalSec / minutesToSeconds) % 600, tempTotalSec % 60);
		return re;
	}
}